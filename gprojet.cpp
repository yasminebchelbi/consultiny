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
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include"arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>





Gprojet::Gprojet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gprojet)
    , P()
    ,manager(new QNetworkAccessManager(this))
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
        connect(manager, &QNetworkAccessManager::finished, this, &Gprojet::handleNetworkReply);

        exporterProjetsTexte();
        afficherStatistiquesStatus() ;
        A = new Arduino();
        QObject::connect(A->getserial(), &QSerialPort::readyRead, this, [this]() {
            A->readFromArduino();
        });


        int ret = A->connect_arduino();  // Lancer la connexion à Arduino

        // Traitement du résultat de la connexion
        switch (ret) {
        case 0:  // Connexion réussie
            qDebug() << "Arduino is available and connected to:" << A->getarduino_port_name();
            break;
        case 1:  // Arduino est disponible mais la connexion a échoué
            qDebug() << "Arduino is available but not connected to:" << A->getarduino_port_name();
            break;
        case -1: // Arduino n'est pas disponible
            qDebug() << "Arduino is not available";
            break;
        default:
            qDebug() << "Unknown error";
            break;
        }





}




Gprojet::~Gprojet()
{
    delete ui;
    delete A;
}

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
        afficherStatistiquesStatus() ;

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
            afficherStatistiquesStatus() ;

            QMessageBox::information(this, tr("Succès"), tr("Projet supprimé avec succès."));
        } else {
            QMessageBox::critical(this, tr("Échec"), tr("Échec de la suppression du projet."));
        }
    }
}

//*********************************************modifier le projet**************************************************************

/*void Gprojet::on_update_projet_clicked()
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
                                       ", Cout: " + QString::number(cout_projet) +
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
            afficherStatistiquesStatus() ;

        }
    }
*/
void Gprojet::on_update_projet_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner une ligne à modifier."));
        return;
    }

    int row = selectedIndexes.first().row();
    int id_projet = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();

    if (id_projet == 0) {
        QMessageBox::warning(this, tr("Erreur"), tr("L'ID du projet est invalide."));
        return;
    }

    // Récupérer les nouvelles valeurs
    QString new_nom = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QDate new_date = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toDate();
    int new_budget = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toInt();
    QString new_secteur = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toString();
    QString new_status = ui->tableView->model()->data(ui->tableView->model()->index(row, 5)).toString();
    int new_cout = ui->tableView->model()->data(ui->tableView->model()->index(row, 6)).toInt();
    QString new_adresse = ui->tableView->model()->data(ui->tableView->model()->index(row, 7)).toString();
    QString new_desc = ui->tableView->model()->data(ui->tableView->model()->index(row, 8)).toString();

    // Charger les anciennes valeurs depuis la base
    QSqlQuery query;
    query.prepare("SELECT nom_projet, date_debut, budget_projet, secteur_projet, status_projet, cout_projet, adresse_projet, description_projet FROM projet WHERE id_projet = :id_projet");
    query.bindValue(":id_projet", id_projet);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de charger les données du projet."));
        return;
    }

    QString old_nom = query.value(0).toString();
    QDate old_date = query.value(1).toDate();
    int old_budget = query.value(2).toInt();
    QString old_secteur = query.value(3).toString();
    QString old_status = query.value(4).toString();
    int old_cout = query.value(5).toInt();
    QString old_adresse = query.value(6).toString();
    QString old_desc = query.value(7).toString();

    // Vérifier les champs requis
    if (new_nom.isEmpty() || new_secteur.isEmpty() || new_status.isEmpty() || new_desc.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez remplir tous les champs obligatoires."));
        return;
    }

    if (new_budget <= 0 || new_cout < 0) {
        QMessageBox::warning(this, tr("Erreur"), tr("Le budget et le coût doivent être positifs."));
        return;
    }

    if (new_date < QDate::currentDate()) {
        QMessageBox::warning(this, tr("Erreur"), tr("La date ne peut pas être dans le passé."));
        return;
    }

    // Préparer la mise à jour uniquement pour les champs modifiés
    QStringList updates;
    QVariantMap params;

    if (new_nom != old_nom) { updates << "nom_projet = :nom"; params[":nom"] = new_nom; }
    if (new_date != old_date) { updates << "date_debut = :date"; params[":date"] = new_date; }
    if (new_budget != old_budget) { updates << "budget_projet = :budget"; params[":budget"] = new_budget; }
    if (new_secteur != old_secteur) { updates << "secteur_projet = :secteur"; params[":secteur"] = new_secteur; }
    if (new_status != old_status) { updates << "status_projet = :statut"; params[":statut"] = new_status; }
    if (new_cout != old_cout) { updates << "cout_projet = :cout"; params[":cout"] = new_cout; }
    if (new_adresse != old_adresse) { updates << "adresse_projet = :adresse"; params[":adresse"] = new_adresse; }
    if (new_desc != old_desc) { updates << "description_projet = :description"; params[":description"] = new_desc; }

    if (updates.isEmpty()) {
        QMessageBox::information(this, tr("Information"), tr("Aucune modification détectée."));
        return;
    }

    // Confirmer la mise à jour
    QMessageBox::StandardButton reply = QMessageBox::question(this, tr("Confirmation"),
                                                              tr("Voulez-vous enregistrer les modifications ?"),
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QString updateQueryStr = "UPDATE projet SET " + updates.join(", ") + " WHERE id_projet = :id_projet";
        QSqlQuery updateQuery;
        updateQuery.prepare(updateQueryStr);

        for (auto it = params.begin(); it != params.end(); ++it) {
            updateQuery.bindValue(it.key(), it.value());
        }
        updateQuery.bindValue(":id_projet", id_projet);

        if (!updateQuery.exec()) {
            QMessageBox::critical(this, tr("Erreur"), tr("Échec de la mise à jour: ") + updateQuery.lastError().text());
            return;
        }

        // Historique
        QString modification;
        for (auto it = params.begin(); it != params.end(); ++it) {
            modification += it.key().mid(1) + ": " + it.value().toString() + "<br>";
        }

        QSqlQuery histoQuery;
        histoQuery.prepare("INSERT INTO historique (id_projet, date_modif, modification) "
                           "VALUES (:id, :date, :modif)");
        histoQuery.bindValue(":id", id_projet);
        histoQuery.bindValue(":date", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        histoQuery.bindValue(":modif", modification);

        if (!histoQuery.exec()) {
            qDebug() << "Erreur insertion historique: " << histoQuery.lastError().text();
        }

        QMessageBox::information(this, tr("Succès"), tr("Projet mis à jour avec succès."));
        ui->tableView->setModel(P.afficher());
        afficherStatistiquesStatus();
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
                   "td { background-color: #f9f9f9 ; }"
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
    QLayout *oldLayout = ui->frame_stat->layout();
    if (oldLayout != nullptr) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                delete item->widget();  // Supprime les anciens widgets (ex : QChartView)
            }
            delete item;
        }
        delete oldLayout;
    }

    // Créer une nouvelle série pour le graphique circulaire
    QPieSeries *series = new QPieSeries();

    // Requête SQL pour récupérer les statistiques de statut
    QSqlQuery query;
    query.prepare("SELECT status_projet, COUNT(*) FROM projet GROUP BY status_projet");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "Erreur lors de l'exécution de la requête : " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QString status = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(status, count);
    }

    // Gérer le cas où aucune donnée n'est trouvée
    if (series->count() == 0) {
        QMessageBox::information(nullptr, "Statistiques vides", "Aucun projet trouvé pour afficher les statistiques.");
        return;
    }

    // Amélioration visuelle
    series->setLabelsVisible(true);
    series->setLabelsPosition(QPieSlice::LabelOutside);

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des projets par statut");
    chart->legend()->setAlignment(Qt::AlignRight);

    // Création du widget d'affichage du graphique
    QChartView *view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);

    // Création et affectation du nouveau layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(view);
    ui->frame_stat->setLayout(layout);
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
    query.prepare("SELECT nom_projet, date_debut, secteur_projet, status_projet FROM projet WHERE status_projet = 'annulé'");


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
    //QMessageBox::information(nullptr, "Succès", "Le fichier Historique.txt a été créé avec succès !\n\n Emplacement : " + filePath);
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

            // Mise en forme personnalisée — seulement les vraies modifications
            QString modifStyled = colorizeModification(modification);

            if (!modifStyled.isEmpty()) {
                historiqueHTML += "<div style='margin-bottom:10px;'>";
                historiqueHTML += "<p><span style='color:#555; font-weight:bold;'>🕒 " + date_modif + "</span></p>";
                historiqueHTML += "<p style='color:#000;'>📝 Les informations modifiées sont :<br>" + modifStyled + "</p>";
                historiqueHTML += "<hr></div>";
            }
        }

        if (historiqueHTML.isEmpty()) {
            historiqueHTML = "<p style='color:#888;'>Aucune modification enregistrée pour ce projet.</p>";
        }

        ui->historique_projet->setHtml(historiqueHTML);
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de la récupération de l'historique."));
        qDebug() << "Erreur SQL : " << query.lastError().text();
    }
}
QString Gprojet::colorizeModification(const QString& text)
{
    // Exemple : (Nom: yasminaa, Date: 2025-06-05, ...)
    QRegularExpression regex(R"((\w+):\s*([^,)\n]+))");  // Capture Nom: valeur
    QRegularExpressionMatchIterator it = regex.globalMatch(text);

    QStringList lignes;

    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        QString champ = match.captured(1);
        QString valeur = match.captured(2);

        // Colorer le champ
        QString ligne = "<span style='color:#007ACC; font-weight:bold;'>" + champ + "</span>: "
                        + "<span style='color:#000;'>" + valeur + "</span>";
        lignes << ligne;
    }

    return lignes.join("<br>");
}


//***************************************bouton annuler des conseils*****************************************************
void Gprojet::on_annuler_conseil_projet_clicked()
{
     ui->txtQuestion->clear();
     ui->txtReponse->clear();
     ui->image_projet->clear();
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
//********************fonction de la genration des conseils et des images aprztir d'un fichier nommé resssource********************************************

/*void Gprojet::on_txtQuestion_returnPressed()
{
    QString userInput = ui->txtQuestion->text().trimmed().toLower();

    // 🔍 Vérifier si l'utilisateur demande une image spécifique
    QRegularExpression reImage("donne moi l'image de (\\w+)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch matchImage = reImage.match(userInput);

    if (matchImage.hasMatch()) {
        QString imageName = matchImage.captured(1).toLower();  // Nom de l'image demandée
        QStringList extensions = {"jpg", "jpeg", "png", "gif", "jfif"};  // Liste des extensions possibles
        bool imageFound = false;

        // Vérifier chaque extension pour l'image
        for (const QString& ext : extensions) {
            QString imagePath = "C:/Users/HP/Desktop/image/" + imageName + "." + ext;
            QPixmap pixmap(imagePath);

            // Vérifier si l'image existe avec cette extension
            QFile file(imagePath);
            if (file.exists()) {
                QString htmlImage = "<img src='file://" + imagePath + "' width='300' height='300' />";
                if (!pixmap.isNull()) {
                    // 🔍 Redimensionne proprement l’image au QLabel
                    QPixmap scaledPixmap = pixmap.scaled(ui->image_projet->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    ui->image_projet->setPixmap(scaledPixmap);
                } else {
                    QMessageBox::warning(this, "Erreur", "L'image n'a pas pu être chargée !");
                }
                imageFound = true;
                break;  // Sortir de la boucle dès qu'une image est trouvée
            }
        }

        if (!imageFound) {
            ui->image_projet->setText("❌ L'image demandée n'existe pas.");
        }

        return;  // Sortir de la fonction après traitement de l'image
    }

    // 🔍 Vérifier si l'utilisateur demande si un projet existe en fonction de son ID
    QRegularExpression re("id du projet est[: ]*(\\d+)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = re.match(userInput);

    if (match.hasMatch()) {
        int idProjet = match.captured(1).toInt();

        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM projet WHERE id_projet = :id");
        query.bindValue(":id", idProjet);

        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            if (count > 0) {
                ui->txtReponse->setText("✅ Oui, le projet avec l'ID " + QString::number(idProjet) + " existe dans la base de données.");
            } else {
                ui->txtReponse->setText("❌ Aucun projet avec l'ID " + QString::number(idProjet) + " trouvé.");
            }
            return;
        } else {
            ui->txtReponse->setText("Erreur lors de la requête SQL.");
            return;
        }
    }

    // 🏙️ Vérifier si l'utilisateur indique une ville
    QRegularExpression reVille("la ville de projet est[: ]*(\\w+)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch matchVille = reVille.match(userInput);

    if (matchVille.hasMatch()) {
        QString nomVille = matchVille.captured(1).trimmed();
        QFile fichierVille("C:/Users/HP/Desktop/villes.txt");

        if (!fichierVille.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->txtReponse->setText("Erreur lors de la lecture du fichier des villes.");
            return;
        }

        QTextStream stream(&fichierVille);
        bool villeTrouvee = false;

        while (!stream.atEnd()) {
            QString ligne = stream.readLine();
            QStringList parts = ligne.split(":");

            if (parts.size() == 2) {
                QString ville = parts[0].trimmed();
                QString conseil = parts[1].trimmed();

                if (ville.compare(nomVille, Qt::CaseInsensitive) == 0) {
                    ui->txtReponse->setText("📍 " + conseil);
                    villeTrouvee = true;
                    break;
                }
            }
        }

        if (!villeTrouvee) {
            ui->txtReponse->setText("❌ Je n’ai pas encore d'informations sur cette ville.");
        }

        return;
    }

    // 🤖 Sinon, chercher dans le fichier ressource.txt pour d'autres réponses
    QFile file("C:/Users/HP/Desktop/ressource.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->txtReponse->setText("Erreur de lecture du fichier.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString lineQuestions = in.readLine();
        QString lineResponses = in.readLine();

        QStringList questions = lineQuestions.split("|", Qt::SkipEmptyParts);
        QStringList responses = lineResponses.split("|", Qt::SkipEmptyParts);

        for (const QString& q : questions) {
            if (userInput.contains(q.trimmed(), Qt::CaseInsensitive)) {
                int randomIndex = QRandomGenerator::global()->bounded(responses.size());
                ui->txtReponse->setText(responses[randomIndex].trimmed());
                return;
            }
        }
    }

    ui->txtReponse->setText("Je n’ai pas compris. Pouvez-vous reformuler ?");
    enregistrerQuestionDansFichier(userInput);


}

void Gprojet::enregistrerQuestionDansFichier(const QString &question) {
    // Ouvrir le fichier en mode ajout (append)
    QFile file("C:/Users/HP/Desktop/question.txt");  // Remplace ce chemin par le fichier que tu veux utiliser
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Impossible d'ouvrir le fichier pour ajouter la question.";
        return;
    }

    QTextStream out(&file);
    // Ajouter la question suivie d'un saut de ligne
    out << question << "\n";

    // Fermer le fichier après l'ajout
    file.close();
    qDebug() << "Question ajoutée dans le fichier.";
}*/
//************************fonction pour le chatbot avec un API (deepseek)************************************************
void Gprojet::on_txtQuestion_returnPressed() {
    QString question = ui->txtQuestion->text();

    QUrl url("https://openrouter.ai/api/v1/chat/completions");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 🔐 Ajoute ta clé ici
    request.setRawHeader("Authorization", "Bearer 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");
    request.setRawHeader("HTTP-Referer", "https://consultini.tn");
    request.setRawHeader("Consultiny Bot", "Consultiny Chat");

    QJsonObject message;
    message["role"] = "user";
    message["content"] = question;

    QJsonArray messages;
    messages.append(message);

    QJsonObject body;
    body["model"] = "mistralai/mistral-7b-instruct"; // modèle gratuit
    body["messages"] = messages;

    QJsonDocument doc(body);
    QByteArray data = doc.toJson();

    manager->post(request, data);
}

void Gprojet::handleNetworkReply(QNetworkReply* reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        QString result;

        QJsonArray choices = doc["choices"].toArray();
        if (!choices.isEmpty()) {
            QJsonObject message = choices[0].toObject()["message"].toObject();
            result = message["content"].toString();
        }

        ui->txtReponse->setText(result);
    } else {
        ui->txtReponse->setText("Erreur: " + reply->errorString());
    }
    reply->deleteLater();
}


void Gprojet::on_btnEnvoyer_clicked()
{
    QString userInput = ui->txtQuestion->text().trimmed().toLower();

    //  Vérifier si l'utilisateur demande une image spécifique
    QRegularExpression reImage("donne moi l'image de (\\w+)", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch matchImage = reImage.match(userInput);

    if (matchImage.hasMatch()) {
        QString imageName = matchImage.captured(1).toLower();
        QStringList extensions = {"jpg", "jpeg", "png", "gif", "jfif"};  // Liste des extensions possibles
        bool imageFound = false;

        // Vérifier chaque extension pour l'image
        for (const QString& ext : extensions) {
            QString imagePath = "C:/Users/HP/Desktop/image/" + imageName + "." + ext;
            QPixmap pixmap(imagePath);

            // Vérifier si l'image existe avec cette extension
            QFile file(imagePath);
            if (file.exists()) {
                QString htmlImage = "<img src='file://" + imagePath + "' width='300' height='300' />";
                if (!pixmap.isNull()) {
                    // 🔍 Redimensionne proprement l’image au QLabel
                    QPixmap scaledPixmap = pixmap.scaled(ui->image_projet->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    ui->image_projet->setPixmap(scaledPixmap);
                } else {
                    QMessageBox::warning(this, "Erreur", "L'image n'a pas pu être chargée !");
                }
                imageFound = true;
                break;  // Sortir de la boucle dès qu'une image est trouvée
            }
        }

        if (!imageFound) {
            ui->image_projet->setText("❌ L'image demandée n'existe pas.");
        }
}
}

/*void Gprojet::on_fullscreen_clicked()
{
    this->showFullScreen();
    ui->tabWidget->setGeometry(0, 0, this->width(), this->height());  // Redimensionner le QTabWidget pour qu'il prenne toute la fenêtre
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        QWidget *tabWidget = ui->tabWidget->widget(i);
        tabWidget->setGeometry(0, 0, this->width(), this->height());
    }
}*/

