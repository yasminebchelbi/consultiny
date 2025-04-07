#include "gprojet.h"
#include "ui_gprojet.h"
#include "projets.h"
#include<QMessageBox>
#include<QInputDialog>
#include<QRegularExpression>
#include<QSortFilterProxyModel>
#include <QSqlError>
#include<QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QSqlQuery>
#include <QDate>
#include <QMessageBox>
#include <QPieSeries>
#include <QFrame>






Gprojet::Gprojet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gprojet)
    , P()
{
    ui->setupUi(this);
    ui->tableView->setModel(P.afficher());
    //pour mettre a l'utulisateur de fiare des modifications sur le tableau
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::AnyKeyPressed);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //controle de saisie

        // Connexion des champs aux signaux textChanged()
        connect(ui->lineEdit_nom, &QLineEdit::textChanged, this, &Gprojet::verifierSaisie);
        connect(ui->lineEdit_budget, &QLineEdit::textChanged, this, &Gprojet::verifierSaisie);
        connect(ui->lineEdit_secteur, &QLineEdit::textChanged, this, &Gprojet::verifierSaisie);
        connect(ui->lineEdit_cout, &QLineEdit::textChanged, this, &Gprojet::verifierSaisie);
        connect(ui->lineEdit_adresse, &QLineEdit::textChanged, this, &Gprojet::verifierSaisie);
        connect(ui->plainTextEdit_description, &QPlainTextEdit::textChanged, this, &Gprojet::verifierSaisie);
        connect(ui->dateTimeEdit, &QDateTimeEdit::dateChanged, this, &Gprojet::verifierSaisie);

        exporterProjetsTexte();
        afficherStatistiquesStatus() ;


}


Gprojet::~Gprojet()
{
    delete ui;
}
//****************************************Controle de saisie****************************************************************
void Gprojet::verifierChamps()
{
    bool nomValide = !ui->lineEdit_nom->text().trimmed().isEmpty();
    bool budgetValide = !ui->lineEdit_budget->text().isEmpty();
    bool secteurValide = !ui->lineEdit_secteur->text().trimmed().isEmpty();
    bool coutValide = !ui->lineEdit_cout->text().isEmpty();
    bool adresseValide = !ui->lineEdit_adresse->text().trimmed().isEmpty();
    bool descriptionValide = !ui->plainTextEdit_description->toPlainText().trimmed().isEmpty();
    bool dateValide = ui->dateTimeEdit->date() >= QDate::currentDate();

    // Activer/désactiver le bouton en fonction de la validité des champs
    bool tousChampsValides = nomValide && budgetValide && secteurValide &&
                             coutValide && adresseValide && descriptionValide && dateValide;

    ui->ajouter_projet->setEnabled(tousChampsValides);
}
void Gprojet::verifierSaisie()
{
    QString nom_projet = ui->lineEdit_nom->text().trimmed();
    QString budget_text = ui->lineEdit_budget->text();
    QString secteur_projet = ui->lineEdit_secteur->text().trimmed();
    QString cout_text = ui->lineEdit_cout->text();
    QString adresse_projet = ui->lineEdit_adresse->text().trimmed();
    QString description_projet = ui->plainTextEdit_description->toPlainText().trimmed();
    QDate date_projet = ui->dateTimeEdit->date();
     QRegularExpression regexNom("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");

    // Vérification du nom du projet (max 20 caractères)
    if (nom_projet.isEmpty() ||!regexNom.match(nom_projet).hasMatch() || nom_projet.length() > 20) {
        ui->lineEdit_nom->setStyleSheet("border: 2px solid red;");
        ui->lineEdit_nom->setToolTip("Le nom du projet doit contenir entre 1 et 20 caractères.");
    } else {
        ui->lineEdit_nom->setStyleSheet("");
        ui->lineEdit_nom->setToolTip("");
    }

    // Vérification du budget (doit être un nombre positif)
    bool ok;
    int budget_projet = budget_text.toInt(&ok);
    if (!ok || budget_projet <= 0) {
        ui->lineEdit_budget->setStyleSheet("border: 2px solid red;");
        ui->lineEdit_budget->setToolTip("Le budget doit être un nombre entier positif.");
    } else {
        ui->lineEdit_budget->setStyleSheet("");
        ui->lineEdit_budget->setToolTip("");
    }

    // Vérification du secteur (max 8 caractères)
    if (secteur_projet.isEmpty() || secteur_projet.length() > 20) {
        ui->lineEdit_secteur->setStyleSheet("border: 2px solid red;");
        ui->lineEdit_secteur->setToolTip("Le secteur ne doit pas dépasser 20 caractères.");
    } else {
        ui->lineEdit_secteur->setStyleSheet("");
        ui->lineEdit_secteur->setToolTip("");
    }

    // Vérification du coût (max 10 chiffres et positif)
    if (!cout_text.contains(QRegularExpression("^\\d{1,10}$"))) {
        ui->lineEdit_cout->setStyleSheet("border: 2px solid red;");
        ui->lineEdit_cout->setToolTip("Le coût doit être un entier positif de 10 chiffres maximum.");
    } else {
        ui->lineEdit_cout->setStyleSheet("");
        ui->lineEdit_cout->setToolTip("");
    }

    // Vérification de l'adresse (ne doit pas être vide)
    if (adresse_projet.isEmpty()) {
        ui->lineEdit_adresse->setStyleSheet("border: 2px solid red;");
        ui->lineEdit_adresse->setToolTip("L'adresse ne peut pas être vide.");
    } else {
        ui->lineEdit_adresse->setStyleSheet("");
        ui->lineEdit_adresse->setToolTip("");
    }

    // Vérification de la description (max 200 caractères)
    if (description_projet.isEmpty() || description_projet.length() > 200) {
        ui->plainTextEdit_description->setStyleSheet("border: 2px solid red;");
        ui->plainTextEdit_description->setToolTip("La description ne doit pas dépasser 200 caractères.");
    } else {
        ui->plainTextEdit_description->setStyleSheet("");
        ui->plainTextEdit_description->setToolTip("");
    }

    // Vérification de la date (ne doit pas être dans le passé)
    if (date_projet < QDate::currentDate()) {
        ui->dateTimeEdit->setStyleSheet("border: 2px solid red;");
        ui->dateTimeEdit->setToolTip("La date du projet ne peut pas être dans le passé.");
    } else {
        ui->dateTimeEdit->setStyleSheet("");
        ui->dateTimeEdit->setToolTip("");
    }
    verifierChamps();
}


//**********************************************ajout du projet****************************************************************
void Gprojet::on_ajouter_projet_clicked()
{
    QString nom_projet = ui->lineEdit_nom->text();
    QDate date_projet = ui->dateTimeEdit->date();
    int budget_projet = ui->lineEdit_budget->text().toInt();
    QString secteur_projet = ui->lineEdit_secteur->text();
    int cout_projet = ui->lineEdit_cout->text().toInt();
    QString adresse_projet = ui->lineEdit_adresse->text();
    QString description_projet = ui->plainTextEdit_description->toPlainText();;



    Projets P(nom_projet, date_projet, budget_projet, secteur_projet, cout_projet, adresse_projet, description_projet);
    bool test = P.ajouter();

    if (test)
    {
        ui->tableView->setModel(P.afficher());
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Ajout effectué !\nCliquez sur OK pour continuer."),
                                 QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Échec"),
                              QObject::tr("Ajout non effectué !\nVérifiez vos données et réessayez."),
                              QMessageBox::Ok);
    }

}
//***********************************la suppression du projet************************************************************



void Gprojet::on_supprimer_projet_clicked(){
    // Récupérer l'index de la ligne sélectionnée dans la table
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    // Vérifier si une ligne est sélectionnée
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner une ligne à supprimer."));
        return;
    }
    // Obtenir l'id du projet depuis la première colonne (en supposant que l'id est dans la première colonne)
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int id_projet = index.sibling(index.row(), 0).data().toInt();  // Colonne du nom_projet


    // Demander confirmation avant la suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirmation de suppression"),
                                  tr("Voulez-vous vraiment supprimer ce projet ?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Supprimer le projet de la base de données
        Projets P;
        if (P.supprimer(id_projet)) {
            // Mise à jour de la vue de la table
            ui->tableView->setModel(P.afficher());
            QMessageBox::information(this, tr("Succès"), tr("Projet supprimé avec succès."));
        } else {
            QMessageBox::critical(this, tr("Échec"), tr("Échec de la suppression du projet."));
        }
    }
}

//*********************************************modifier le projet**************************************************************

void Gprojet::on_update_projet_clicked()
{
        // Vérifier si une ligne est sélectionnée
        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
        if (selectedIndexes.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner une ligne à modifier."));
            return;
        }

        // Récupérer l'index de la ligne sélectionnée
        int row = selectedIndexes.first().row();

        // Récupérer l'ID du projet
        int id_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();
        if (id_projet == 0) {
            QMessageBox::warning(this, tr("Erreur"), tr("L'ID du projet est invalide."));
            return;
        }

        // Récupérer les valeurs modifiées
        QString nom_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
        QDate date_debut = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toDate();
        int budget_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toInt();
        QString secteur_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toString();
        QString status_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 5)).toString();
        int cout_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 6)).toInt();
        QString adresse_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 7)).toString();
        QString description_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 8)).toString();

        // Vérification des champs obligatoires
        if (nom_projet.isEmpty() || secteur_projet.isEmpty() || status_projet.isEmpty() || description_projet.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Veuillez remplir tous les champs avant de mettre à jour."));
            return;
        }

        // Vérification du budget et du coût
        if (budget_projet <= 0 || cout_projet < 0) {
            QMessageBox::warning(this, tr("Erreur"), tr("Le budget et le coût doivent être des valeurs positives."));
            return;
        }

        // Vérification de la date
        if (date_debut < QDate::currentDate()) {
            QMessageBox::warning(this, tr("Erreur"), tr("La date du projet ne peut pas être dans le passé."));
            return;
        }

        // Confirmation de la mise à jour
        QMessageBox::StandardButton reply = QMessageBox::question(this, tr("Confirmation"),
                                                                  tr("Voulez-vous enregistrer les modifications ?"),
                                                                  QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            // Mettre à jour la base de données
            if (P.update(id_projet, nom_projet, date_debut, status_projet, secteur_projet, budget_projet, cout_projet, description_projet)) {

                QSqlQuery query;
                QString date_modif = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                QString modification = "Projet mis à jour (Nom: " + nom_projet +
                                       ", Date: " + date_debut.toString("yyyy-MM-dd") +
                                       ", Secteur: " + secteur_projet +
                                       ", Statut: " + status_projet +
                                       ", Budget: " + QString::number(budget_projet) +
                                       ", Coût: " + QString::number(cout_projet) +
                                       ", Adresse: " + adresse_projet +
                                       ", Description: " + description_projet +")";




                query.prepare("INSERT INTO historique (id_projet, date_modif, modification) "
                              "VALUES (:id_projet, :date_modif, :modification)");
                query.bindValue(":id_projet", id_projet);
                query.bindValue(":date_modif", date_modif);
                query.bindValue(":modification", modification);

                if (!query.exec()) {
                    qDebug() << "Erreur insertion historique : " << query.lastError().text();
                }

                QMessageBox::information(this, tr("Succès"), tr("Projet mis à jour avec succès."));
            } else {
                QMessageBox::critical(this, tr("Erreur"), tr("Échec de la mise à jour du projet."));
            }

            // Rafraîchir l'affichage des données dans la table
            ui->tableView->setModel(P.afficher());
        }
    }


void Gprojet::on_annuler_projet_clicked()
{
    ui->lineEdit_nom->clear();
    ui->dateTimeEdit->setDateTime(QDateTime());  // Correction
    ui->lineEdit_budget->clear();
    ui->lineEdit_adresse->clear();
    ui->lineEdit_secteur->clear();
    ui->plainTextEdit_description->clear();
    ui->lineEdit_cout->clear();
}



//*********************************************fonction trier**************************************************************
void Gprojet::on_trier_projet_2_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("PROJET");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Coût"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Description"));


   // ui->tableView->setColumnHidden(9, true);

    if (ui->trier_projet->currentText() == "Nom") {
        model->setSort(1, Qt::AscendingOrder);  // Tri par "Nom"
    }
    else if (ui->trier_projet->currentText() == "Date début") {
        model->setSort(2, Qt::AscendingOrder);  // Tri par "Date début"
    }

    model->select();

    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans la requête SQL: " << model->lastError().text();
        QMessageBox::warning(this, tr("Erreur SQL"), tr("Une erreur est survenue lors de l'exécution de la requête."));
        ui->tableView->setModel(nullptr);
    } else {
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(9, true);
    }
}
//********************************************************fonction de recherche********************************************

void Gprojet::on_recherche_projet_2_clicked()
{
    QString statut = ui->recherche_projet->text(); // Récupérer le statut entré par l'utilisateur

    if (statut.isEmpty()) {
        QMessageBox::warning(this, "Recherche", "Veuillez entrer un statut !");
        return;
    }

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(P.afficher()); // Associer le modèle des projets

    proxyModel->setFilterKeyColumn(P.afficher()->fieldIndex("statut")); // Filtrer par statut
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Ignorer la casse
    proxyModel->setFilterFixedString(statut); // Appliquer le filtre

    ui->tableView->setModel(proxyModel); // Afficher les résultats filtrés
}
//************************************************fonction du telechargement pdf*******************************************
void Gprojet::on_telecharger_projet_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox::warning(this, "Facture", "Veuillez sélectionner un projet !");
        return;
    }

    // Récupérer l'index de la ligne sélectionnée
    int selectedRow = selection.first().row();
    QAbstractItemModel *model = ui->tableView->model();

    // Récupérer les valeurs du projet sélectionné
    QString id_projet = model->data(model->index(selectedRow, 0)).toString();
    QString nom = model->data(model->index(selectedRow, 1)).toString();
    QString date_debut = model->data(model->index(selectedRow, 2)).toString();
    QString budget = model->data(model->index(selectedRow, 3)).toString();
    QString secteur = model->data(model->index(selectedRow, 4)).toString();
    QString statut = model->data(model->index(selectedRow, 5)).toString();
    QString cout = model->data(model->index(selectedRow, 6)).toString();
    QString adresse = model->data(model->index(selectedRow, 7)).toString();
    QString description = model->data(model->index(selectedRow, 8)).toString();

    // Génération du HTML pour la facture
    QString html = "<html><head>"
                   "<style>"
                   "body { font-family: Arial, sans-serif; padding: 20px; }"
                   "h1 { text-align: center; color:#6f7dab; }"
                   "table { width: 100%; border-collapse: collapse; margin-top: 20px; }"
                   "th, td { padding: 10px; text-align: left; border: 1px solid black; }"
                   "th { background-color: #6f7dab; color: white; }"
                   "td { background-color: #f9f9f9; }"
                   ".footer { text-align: center; margin-top: 20px; font-style: italic; }"
                   ".logo { text-align: center; margin-bottom: 10px; }"
                   "</style></head><body>";
    html += "<h1 style='text-align: center;'>Facture du Projet</h1>";
    html += "<div class='logo'><img src='file:///C:/2eme/sem2/projetc++/gclient%20interface/Gprojet/image/logo.jfif' width='150'></div>";
    html += "<style> .table-container { margin-bottom: 30px; } </style>";
    html += "<div class='table-container'>";
    html += "<table>";
    html += "<tr><th>Id projet</th><td>" + id_projet + "</td></tr>";
    html += "<tr><th>Nom projet</th><td>" + nom + "</td></tr>";
    html += "<tr><th>Date de Début</th><td>" + date_debut + "</td></tr>";
    html += "<tr><th>Budget projet</th><td>" + budget + " DT</td></tr>";
    html += "<tr><th>Secteur projet</th><td>" + secteur + "</td></tr>";
    html += "<tr><th>Statut projet</th><td>" + statut + "</td></tr>";
    html += "<tr><th>Coût projet</th><td>" + cout + " DT</td></tr>";
    html += "<tr><th>Adresse projet</th><td>" + adresse + "</td></tr>";
    html += "<tr><th>Description projet</th><td>" + description + "</td></tr>";
    html += "</table>";
    html += "</div>";
    html += "<h4>Bienvenue cher client, nous sommes ravis de vous accompagner dans la gestion de votre projet !</h4>";
    html += "<div class='footer'>Fait par <b>Consultiny</b> - Votre partenaire en consulting</div>";
    html += "<br><br><p style='text-align: right;'>Signature du Responsable</p>";
    html += "</body></html>";


    // Demander où enregistrer le PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer la Facture", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return;
    }

    // Création du document PDF
    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    document.print(&printer);

    QMessageBox::information(this, "Facture", "La facture a été générée avec succès !");
}
//*******************************************fonction des statistiques***************************************************
void Gprojet::afficherStatistiquesStatus() {
    // Créer un QPieSeries pour les statistiques
    QPieSeries *series = new QPieSeries();

    // Requête SQL pour récupérer les statistiques de statut de projet
    QSqlQuery query;
    query.prepare("SELECT status_projet, COUNT(*) FROM projet GROUP BY status_projet");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    // Ajouter des données à la série pie en fonction des résultats de la requête
    while (query.next()) {
        QString status = query.value(0).toString();
        int count = query.value(1).toInt();

        // Ajouter un secteur au graphique pour chaque statut
        series->append(status, count);
    }

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des projets par statut");

    // Créer un QChartView pour afficher le graphique
    QChartView *view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);

    // Rendre le graphique dynamique en l'ajoutant à une QFrame
    QVBoxLayout *layout = new QVBoxLayout(ui->frame_stat);  // ui->frame_stat est votre QFrame
    layout->addWidget(view);
    ui->frame_stat->setLayout(layout);
}
//****************************le timer pour fiare les mise a jour des stat chaque 5ms*************************************
void Gprojet::startStatistiquesTimer() {
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gprojet::afficherStatistiquesStatus);
    timer->start(5000);  // 5000 ms = 5 secondes
}


//****************************stockage des projets dans un fichier texte****************************************************

void Gprojet::exporterProjetsTexte() {
    // 1️⃣ Définir le chemin du fichier sur le Bureau
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/Historique.txt";

    // 2️⃣ Vérifier si le chemin est valide
    if (filePath.isEmpty()) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible d'obtenir l'emplacement du fichier !");
        return;
    }

    QFile file(filePath);

    // 3️⃣ Vérifier si le fichier peut être ouvert en écriture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible de créer le fichier : " + file.errorString());
        return;
    }

    QTextStream out(&file);
    QSqlQuery query;
    query.prepare("SELECT nom_projet, date_debut, secteur_projet, status_projet FROM projet");

    // 5️⃣ Vérifier si la requête a été exécutée avec succès
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        file.close();
        return;
    }

    // 6️⃣ Vérifier s'il y a des résultats avant de commencer à écrire dans le fichier
    if (!query.next()) {
        QMessageBox::information(nullptr, "Aucun Projet", "Aucun projet trouvé dans la base de données.");
        file.close();
        return;
    }

    out << "Nom du Projet || Secteur ||  Date début || Status  \n";
    out << "----------------------------------------------------------\n";

    // 8️⃣ Parcourir les résultats de la requête et écrire les données dans le fichier
    do {
        QString nom_projet = query.value(0).toString();
        QDate date_debut = query.value(1).toDate();
        QString secteur_projet = query.value(2).toString();
        QString status_projet = query.value(3).toString();

        // Écrire une ligne dans le fichier
        out  << nom_projet << " || " << secteur_projet<< " || " << date_debut.toString("dd/MM/yyyy") <<"||"<<status_projet<< "\n";
    } while (query.next());  // Passer à la prochaine ligne dans la base de données

    file.close();
    QMessageBox::information(nullptr, "Succès", "Le fichier projets.txt a été créé avec succès !\n\n Emplacement : " + filePath);
}
//******************************************pour afficher l'historique des modifcations ***********************************
void Gprojet::on_hist_projet_clicked()
{
    QString idText = ui->id_hist_projet->text();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez entrer l'ID du projet."));
        return;
    }

    bool ok;
    int id_projet = idText.toInt(&ok);
    if (!ok || id_projet <= 0) {
        QMessageBox::warning(this, tr("Erreur"), tr("ID du projet invalide."));
        return;
    }

    qDebug() << "ID du projet : " << id_projet;

    QSqlQuery query;
    query.prepare("SELECT date_modif, modification FROM historique WHERE id_projet = :id_projet ORDER BY date_modif DESC");
    query.bindValue(":id_projet", id_projet);
    qDebug() << "Requête SQL : " << query.executedQuery();

    QString historiqueHTML;

    if (query.exec()) {
        while (query.next()) {
            QString date_modif = query.value(0).toDateTime().toString("dd/MM/yyyy hh:mm:ss");
            QString modification = query.value(1).toString();

            // Mise en forme personnalisée
            QString modifStyled = colorizeModification(modification);

            historiqueHTML += "<p><span style='color:#000000; font-weight:bold;'>[" + date_modif + "]</span> "
                              + modifStyled + "</p><hr>";
        }

        if (historiqueHTML.isEmpty()) {
            historiqueHTML = "<p style='color:#888;'>Aucune modification enregistrée pour ce projet.</p>";
        }

        // Affichage stylisé dans QTextEdit
        ui->historique_projet->setHtml(historiqueHTML);
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de la récupération de l'historique."));
        qDebug() << "Erreur SQL : " << query.lastError().text();
    }
}
QString Gprojet::colorizeModification(const QString& text)
{
    QString modif = text;

    // Expression régulière pour détecter : quelque chose "changé de 'X' à 'Y'"
    QRegularExpression regex(R"((\b\w+\b\s+changé\s+de\s+'.+?'\s+à\s+'.+?'))",
                             QRegularExpression::CaseInsensitiveOption);

    // Remplacement des correspondances par la même phrase colorée
    return modif.replace(regex, "<span style='color:#007ACC;'>\\1</span>");
}

//***************************************bouton annuler des conseils*****************************************************
void Gprojet::on_annuler_conseil_projet_clicked()
{
     ui->conseil_ai_projet->clear();
     ui->id_ai_projet->clear();
}

//**************************************bouton annuler les historiques***************************************************
void Gprojet::on_anuuler_hist_clicked()
{
    ui->historique_projet->clear();
    ui->id_hist_projet->clear();
}


void Gprojet::on_refresh_projet_clicked()
{
    ui->tableView->setModel(P.afficher());
}

