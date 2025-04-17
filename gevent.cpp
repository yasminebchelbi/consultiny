#include "gevent.h"
#include "evenements.h"//**
#include "ui_gevent.h"
#include <QMessageBox>
#include <qtimer.h>
#include "evenements.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
//#include <QtCharts>
#include <QVBoxLayout>
//#include <QtCore>
#include <QToolTip>
//using namespace QtCharts;
#include <QSqlError>
#include <QInputDialog>
# include <QFormLayout>
#include<QGroupBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>

Gevent::Gevent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gevent)
    , networkManager(new QNetworkAccessManager(this))  // Initialize in member initializer list

{
    ui->setupUi(this);

    // Debug SQL drivers
    qDebug() << "Drivers SQL disponibles :" << QSqlDatabase::drivers();

    // Force refresh after short delay
    QTimer::singleShot(500, this, [this](){
        ui->tableView->setModel(etmp.afficher_evenements());
        afficherStatistiques_evenements();
    });

    // Form validation connections
    connect(ui->nom, &QLineEdit::textChanged, this, &Gevent::verifierNom);
    connect(ui->date_debut, &QDateEdit::dateChanged, this, &Gevent::verifierDates);
    connect(ui->date_fin, &QDateEdit::dateChanged, this, &Gevent::verifierDates);
    connect(ui->nbr_participants, &QSpinBox::textChanged, this, &Gevent::verifierParticipants);
    connect(ui->lieu, &QLineEdit::textChanged, this, &Gevent::verifierLieu);
    connect(ui->description, &QPlainTextEdit::textChanged, this, &Gevent::verifierDescription);
    connect(ui->type, &QComboBox::currentTextChanged, this, &Gevent::verifierType);
    verifierFormulaire();

    // Calendar connection
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &Gevent::on_calendarWidget_clicked);

    // Weather connections
    connect(ui->adviceButton, &QPushButton::clicked, this, &Gevent::on_adviceButton_clicked);
}
Gevent::~Gevent()
{
    delete ui;
}
//***************controle saisie**************************************************************************************************************
void Gevent::verifierNom() {
    QString nom = ui->nom->text().trimmed();
    if (nom.isEmpty() || nom.length() < 3)
        ui->nom->setStyleSheet("border: 2px solid red; border-radius: 5px;");
    else
        ui->nom->setStyleSheet(""); // Rétablir le style normal
}

void Gevent::verifierDates() {
    QDate debut = ui->date_debut->date();
    QDate fin = ui->date_fin->date();
    if (debut >= fin) {
        ui->date_debut->setStyleSheet("border: 2px solid red; border-radius: 5px;");
        ui->date_fin->setStyleSheet("border: 2px solid red; border-radius: 5px;");
    } else {
        ui->date_debut->setStyleSheet("");
        ui->date_fin->setStyleSheet("");
    }
}

void Gevent::verifierParticipants() {
    int participants = ui->nbr_participants->value();

    if (participants <= 1)
        ui->nbr_participants->setStyleSheet("border: 2px solid red; border-radius: 5px;");
    else
        ui->nbr_participants->setStyleSheet("");
}


void Gevent::verifierLieu() {
    QString lieu = ui->lieu->text().trimmed();
    if (lieu.isEmpty() || lieu.length() < 5)
        ui->lieu->setStyleSheet("border: 2px solid red; border-radius: 5px;");
    else
        ui->lieu->setStyleSheet("");
}

void Gevent::verifierDescription() {
    QString description = ui->description->toPlainText().trimmed();
    if (description.isEmpty() || description.length() < 10)
        ui->description->setStyleSheet("border: 2px solid red; border-radius: 5px;");
    else
        ui->description->setStyleSheet("");
}

void Gevent::verifierType() {
    QString type = ui->type->currentText().trimmed();
    if (type.isEmpty())
        ui->type->setStyleSheet("border: 2px solid red; border-radius: 5px;");
    else
        ui->type->setStyleSheet("");
}
void Gevent::verifierFormulaire() {
    bool valide =
        !ui->nom->styleSheet().contains("red") &&
        !ui->date_debut->styleSheet().contains("red") &&
        !ui->date_fin->styleSheet().contains("red") &&
        !ui->nbr_participants->styleSheet().contains("red") &&
        !ui->lieu->styleSheet().contains("red") &&
        !ui->description->styleSheet().contains("red"); //&&
        //!ui->type->styleSheet().contains("red");

    ui->ajouter_evenement->setEnabled(valide);
}

//************************************************ajout***********************************************************************************

void Gevent::on_ajouter_evenement_clicked() {

    // Vérification finale avant l'ajout
    verifierFormulaire();
    if (!ui->ajouter_evenement->isEnabled()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez corriger les erreurs avant d'ajouter.");
        return;
    }

    QString nom_evenement = ui->nom->text().trimmed();
    QDate date_debut_evenement = ui->date_debut->date();
    QDate date_fin_evenement = ui->date_fin->date();
    int nbr_participants_evenement = ui->nbr_participants->value();
    QString adresse_evenement = ui->lieu->text().trimmed();
    QString description_evenement = ui->description->toPlainText().trimmed();
    QString type_evenement = ui->type->currentText().trimmed();
    QString lieu_evenement = ui->lieu_2->currentText().trimmed();

    Evenements E(nom_evenement, date_debut_evenement, date_fin_evenement, nbr_participants_evenement, adresse_evenement,  description_evenement, type_evenement, lieu_evenement);

    if (E.ajouter_evenements()) {
        ui->tableView->setModel(E.afficher_evenements());
        ui->tableView->resizeColumnsToContents();
        afficherStatistiques_evenements();
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
    } else {
        QMessageBox::critical(this, "Échec", "Ajout non effectué !");
    }
}
//**********************************************************************supprimer
void Gevent::on_supprimer_evenement_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    // Vérifier si une ligne est sélectionnée
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner une ligne à supprimer."));
        return;
    }
    // Obtenir l'id du evenement depuis la première colonne
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int id_evenement = index.sibling(index.row(), 0).data().toInt();


    // Demander confirmation avant la suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirmation de suppression"),
                                  tr("Voulez-vous vraiment supprimer ce evenement ?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Supprimer le evenement de la base de données
        Evenements E;
        if (E.supprimer_evenements(id_evenement)) {
            // actualisation
            ui->tableView->setModel(E.afficher_evenements());

            afficherStatistiques_evenements();

            QMessageBox::information(this, tr("Succès"), tr("evenement supprimé avec succès."));
        } else {
            QMessageBox::critical(this, tr("Échec"), tr("Échec de la suppression du evenement."));
        }
    }
}

//******************************************************************************modifier
void Gevent::on_update_evenement_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un événement à modifier.");
        return;
    }

    // Récupérer l'index de la ligne sélectionnée
    int row = selectedIndexes.first().row();

    // Récupérer l'ID de l'événement
    int id_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();
    if (id_evenement == 0) {
        QMessageBox::warning(this, "Erreur", "L'ID de l'événement est invalide.");
        return;
    }

    // Récupérer les valeurs modifiées
    QString nom_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString().trimmed();
    QDate date_debut_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toDate();
    QDate date_fin_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toDate();
    int nbr_participants_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toInt();
    QString adresse_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 5)).toString().trimmed();
    QString description_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 6)).toString().trimmed();
    QString type_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 7)).toString().trimmed();
    QString lieu_evenement = ui->tableView->model()->data(ui->tableView->model()->index(row, 8)).toString().trimmed();


    // controle de saisie
    if (nom_evenement.isEmpty() || nom_evenement.length() < 3) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom de l'événement doit contenir au moins 3 caractères.");
        return;
    }
    if (date_debut_evenement > date_fin_evenement) {
        QMessageBox::warning(this, "Erreur de saisie", "La date de début ne peut pas être après la date de fin.");
        return;
    }
    if (nbr_participants_evenement <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nombre de participants doit être supérieur à 0.");
        return;
    }
    if (adresse_evenement.isEmpty() || adresse_evenement.length() < 5) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse doit contenir au moins 5 caractères.");
        return;
    }

    if (type_evenement.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner un type d'événement.");
        return;
    }

    // Confirmation de la mise à jour
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
                                                              "Voulez-vous enregistrer les modifications ?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Mettre à jour la base de données
        Evenements E;
        if (E.modifier_evenement(id_evenement, nom_evenement, date_debut_evenement, date_fin_evenement, nbr_participants_evenement, adresse_evenement, description_evenement, type_evenement, lieu_evenement)) {
            QMessageBox::information(this, "Succès", "Événement mis à jour avec succès.");

            // Rafraîchir l'affichage des données dans la table
            ui->tableView->setModel(E.afficher_evenements());
            ui->tableView->resizeColumnsToContents();

            afficherStatistiques_evenements();

        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la mise à jour de l'événement.");
        }
    }
}
//*********************************************************************el clerar
    void Gevent::on_pushButton_2_clicked()
    {
        ui->nom->clear();
        ui->lieu->clear();
        ui->date_debut->clear();
        ui->date_fin->clear();
        ui->description->clear();
        ui->nbr_participants->clear();
    }

//****************************************************************telechargement
    void Gevent::on_telecharger_evenement_clicked()
    {
        // Récupérer la ligne sélectionnée dans le QTableView
        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

        if (selectedIndexes.isEmpty()) {
            QMessageBox::warning(this, "Sélection invalide", "Veuillez sélectionner un événement à télécharger.");
            return;
        }

        // Récupérer l'ID de l'événement sélectionné (assurez-vous que la colonne 0 contient l'ID)
        int idEvenement = selectedIndexes.first().data().toInt();

        Evenements event;
        event.telecharger_pdf_evenement(idEvenement);  // Passer l'ID à la fonction de téléchargement
    }


//************************************************************************recherche
    void Gevent::on_rechercher_evenement_clicked()
    {
        QString adresse = ui->adresse_evenement_recherche->text();  // Récupération de l'adresse

        if (adresse.isEmpty()) {  // Vérification si l'adresse est vide
            QMessageBox::warning(this, "Attention", "Veuillez entrer une adresse valide !");
            return;
        }

        Evenements event;
        QSqlQueryModel* model = event.recherche_evenements_par_adresse(adresse);  // Recherche par adresse

        if (model->rowCount() == 0) {
            QMessageBox::information(this, "Résultat", "Aucun événement trouvé avec cette adresse.");
        } else {
            // Définition des en-têtes pour chaque colonne
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre des participants"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("Description"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("Lieu"));

            ui->tableView->setModel(model);  // Affichage du modèle dans la vue table
        }
    }




//*******************************************************tri

    void Gevent::on_trier_evenements_clicked()
    {
        // Récupérer la valeur sélectionnée dans le QComboBox
        QString critere = ui->critere_evenements->currentText();

        // Appeler la fonction de tri
        QSqlQueryModel* model = etmp.trier_evenements(critere);

        // Appliquer ce modèle à un QTableView
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre des participants"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("description"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("lieu"));

        ui->tableView->setModel(model);
    }

/**********************************************sat**********************************************/


    void Gevent::afficherStatistiques_evenements()
    {
        Evenements ev;
        QMap<QString, int> stats = ev.stat_evenements();

        if (stats.isEmpty()) {
            qDebug() << "Aucune statistique à afficher.";
            return;
        }

        QPieSeries *series = new QPieSeries();
        for (auto it = stats.begin(); it != stats.end(); ++it) {
            series->append(it.key(), it.value());
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Répartition des événements par type");

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);


        if (ui->stat_evenement->layout() != nullptr) {
            QLayoutItem *child;
            while ((child = ui->stat_evenement->layout()->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }
        } else {
            ui->stat_evenement->setLayout(new QVBoxLayout());
        }

        ui->stat_evenement->layout()->addWidget(chartView);
    }


    void Gevent::on_refrech_evenements_clicked()
    {
        ui->tableView->setModel(etmp.afficher_evenements());

    }
    //******************************************************calendrier:affichage **********************************************************************************
    void Gevent::afficherEvenementsParDate(const QDate &date)
    {
        if (!ui || !ui->affichage_evenement)
        {
            qDebug() << "UI or frame not initialized!";
            return;
        }

        if (!ui->affichage_evenement->layout())
        {
            QVBoxLayout *layout = new QVBoxLayout(ui->affichage_evenement);
            ui->affichage_evenement->setLayout(layout);
        }

        QLayout *layout = ui->affichage_evenement->layout();

        // Clear existing widgets
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr)
        {
            if (child->widget())
                delete child->widget();
            delete child;
        }

        // Style du layout principal
        layout->setSpacing(10);  // Espacement entre les boutons
        layout->setContentsMargins(5, 5, 5, 5);  // Marges intérieures

        QSqlQuery query;
        query.prepare("SELECT * FROM evenements WHERE date_debut_evenement = :date");
        query.bindValue(":date", date);

        if (!query.exec())
        {
            qDebug() << "Erreur lors de la récupération des événements:" << query.lastError();
            return;
        }

        currentSelectedEventID = -1; // Clear selection before displaying

        while (query.next())
        {
            int id = query.value("id_evenement").toInt();
            QString nom = query.value("nom_evenement").toString();
            QString desc = query.value("description_evenement").toString();
            QDate debut = query.value("date_debut_evenement").toDate();
            QDate fin = query.value("date_fin_evenement").toDate();
            QString adresse = query.value("adresse_eevenement").toString();
            int participants = query.value("nbr_participants_evenement").toInt();
            QString type = query.value("type_evenement").toString();
            QString lieu = query.value("lieu_evenement").toString();

            QString info = QString("Nom: %1\nDate: %2 - %3\nLieu: %4\nType: %5\nParticipants: %6\nAdresse: %7\nDescription: %8")
                               .arg(nom)
                               .arg(debut.toString("dd/MM/yyyy"))
                               .arg(fin.toString("dd/MM/yyyy"))
                               .arg(lieu)
                               .arg(type)
                               .arg(participants)
                               .arg(adresse)
                               .arg(desc);

            QPushButton *eventBtn = new QPushButton(info);
            eventBtn->setCheckable(true);

            // Style amélioré des boutons
            eventBtn->setStyleSheet(R"(
            QPushButton {
                text-align: left;
                padding: 10px;
                border: 1px solid #cccccc;
                border-radius: 5px;
                background-color: #ffffff;
                color: #333333;
                font-size: 12px;
            }
            QPushButton:hover {
                background-color: #f0f0f0;
                border: 1px solid #aaaaaa;
            }
            QPushButton:checked {
                background-color: #d4e6f1;
                border: 1px solid #6b8eaf;
                font-weight: bold;
            }
        )");

            // Store the event ID as property
            eventBtn->setProperty("id_evenement", id);

            connect(eventBtn, &QPushButton::clicked, this, [=]() {
                // Select this event
                currentSelectedEventID = id;

                // Visually show it's selected
                for (int i = 0; i < layout->count(); ++i)
                {
                    QWidget *widget = layout->itemAt(i)->widget();
                    if (auto *btn = qobject_cast<QPushButton *>(widget))
                        btn->setChecked(btn == eventBtn);
                }

                qDebug() << "Événement sélectionné ID:" << id;
            });

            layout->addWidget(eventBtn);
        }

        // Ajouter un stretch pour pousser les boutons vers le haut
        static_cast<QVBoxLayout*>(layout)->addStretch();
    }
//***********************************************************************

    void Gevent::on_calendarWidget_clicked(const QDate &date)
    {
        afficherEvenementsParDate(date);

    }
//**************************************************calendrier ajouter
    void Gevent::ajouterEvenement()
    {
        QDate date = ui->calendarWidget->selectedDate();

        // Création du dialogue
        QDialog dialog(this);
        dialog.setWindowTitle("Ajouter un nouvel événement");
        dialog.setMinimumSize(400, 500);

        // Style QSS unifié
        dialog.setStyleSheet(R"(
        QDialog {
            background-color: #F5F5F5;
            font-family: "Segoe UI", Arial;
            font-size: 14px;
        }
        QLabel {
            color: #000000;
            margin-bottom: 3px;
        }
        QLineEdit, QTextEdit, QComboBox, QSpinBox, QDateEdit {
            background-color: white;
            border: 1px solid #cccccc;
            border-radius: 3px;
            padding: 6px;
            min-width: 200px;
            min-height: 20px;
            font-size: 12px;
            margin-bottom: 6px;
            color: black;
        }
        QTextEdit {
            min-width: 250px;
            min-height: 100px;
            padding: 8px;
            font-size: 14px;
            margin-bottom: 12px;
            color: black;
        }
        QPushButton {
            padding: 6px 12px;
            border-radius: 3px;
            min-width: 80px;
        }
        QPushButton[text="Ajouter"] {
            background-color: #4CAF50;
            color: white;
        }
        QPushButton[text="Annuler"] {
            background-color: #f44336;
            color: white;
        }
        .error {
            border: 1px solid #f44336;
        }
    )");

        // Layout principal
        QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);
        mainLayout->setContentsMargins(20, 20, 20, 20);
        mainLayout->setSpacing(10);

        // Fonction pour ajouter des champs avec libellés
        auto addFormRow = [&](const QString &label, QWidget *widget) {
            QLabel *lbl = new QLabel(label, &dialog);
            mainLayout->addWidget(lbl);
            mainLayout->addWidget(widget);
        };

        // Champs de formulaire
        QLineEdit *nomEdit = new QLineEdit(&dialog);
        QDateEdit *dateDebutEdit = new QDateEdit(date, &dialog);
        QDateEdit *dateFinEdit = new QDateEdit(date, &dialog);
        dateDebutEdit->setCalendarPopup(true);
        dateFinEdit->setCalendarPopup(true);

        QSpinBox *participantsEdit = new QSpinBox(&dialog);
        participantsEdit->setRange(1, 1000);

        QLineEdit *adresseEdit = new QLineEdit(&dialog);
        QTextEdit *descriptionEdit = new QTextEdit(&dialog);

        QComboBox *typeCombo = new QComboBox(&dialog);
        typeCombo->addItems({"formation", "workshop"});

        QComboBox *lieuCombo = new QComboBox(&dialog);
        lieuCombo->addItems({"Interieur", "Exterieur"});

        // Ajout des champs
        addFormRow("Nom*:", nomEdit);
        addFormRow("Adresse*:", adresseEdit);
        addFormRow("Date début*:", dateDebutEdit);
        addFormRow("Date fin*:", dateFinEdit);
        addFormRow("Type*:", typeCombo);
        addFormRow("Lieu*:", lieuCombo);
        addFormRow("Participants*:", participantsEdit);
        addFormRow("Description:", descriptionEdit);

        // Boutons - version corrigée avec "Ajouter"
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        QPushButton *addButton = new QPushButton("Ajouter", &dialog);
        QPushButton *cancelButton = new QPushButton("Annuler", &dialog);

        buttonLayout->addStretch(); // Pousse les boutons à droite
        buttonLayout->addWidget(addButton);
        buttonLayout->addWidget(cancelButton);
        mainLayout->addLayout(buttonLayout);

        // Validation
        auto validateInput = [&]() -> bool {
            bool valid = true;
            QStringList errors;

            if (nomEdit->text().trimmed().isEmpty()) {
                errors << "Le nom est obligatoire";
                nomEdit->setProperty("class", "error");
            } else {
                nomEdit->setProperty("class", "");
            }

            if (dateDebutEdit->date() > dateFinEdit->date()) {
                errors << "La date de fin doit être après la date de début";
                dateDebutEdit->setProperty("class", "error");
                dateFinEdit->setProperty("class", "error");
            } else {
                dateDebutEdit->setProperty("class", "");
                dateFinEdit->setProperty("class", "");
            }

            if (adresseEdit->text().trimmed().isEmpty()) {
                errors << "L'adresse est obligatoire";
                adresseEdit->setProperty("class", "error");
            } else {
                adresseEdit->setProperty("class", "");
            }

            if (!errors.isEmpty()) {
                QMessageBox::warning(&dialog, "Erreurs", "Veuillez corriger :\n" + errors.join("\n"));
                valid = false;
            }

            return valid;
        };

        // Connexions des boutons
        connect(addButton, &QPushButton::clicked, [&]() {
            if (validateInput()) dialog.accept();
        });

        connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

        // Exécution
        if (dialog.exec() == QDialog::Accepted) {
            QSqlQuery query;
            query.prepare("INSERT INTO evenements ("
                          "nom_evenement, date_debut_evenement, date_fin_evenement, "
                          "nbr_participants_evenement, adresse_eevenement, "
                          "description_evenement, type_evenement, lieu_evenement) "
                          "VALUES ("
                          ":nom, :date_debut, :date_fin, "
                          ":participants, :adresse, "
                          ":description, :type, :lieu)");

            query.bindValue(":nom", nomEdit->text().trimmed());
            query.bindValue(":date_debut", dateDebutEdit->date());
            query.bindValue(":date_fin", dateFinEdit->date());
            query.bindValue(":participants", participantsEdit->value());
            query.bindValue(":adresse", adresseEdit->text().trimmed());
            query.bindValue(":description", descriptionEdit->toPlainText().trimmed());
            query.bindValue(":type", typeCombo->currentText());
            query.bindValue(":lieu", lieuCombo->currentText());

            if (query.exec()) {
                QMessageBox::information(this, "Ajout", "Événement ajouté !");
                afficherEvenementsParDate(date);
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de l'ajout: " + query.lastError().text());
            }
        }
    }
//****************************************calendrier modifier
    void Gevent::modifierEvenement()
    {
        // Vérification de sélection
        if (currentSelectedEventID == -1) {
            QMessageBox::warning(this, "Modification", "Veuillez sélectionner un événement");
            return;
        }

        // Récupération des données existantes
        QSqlQuery query;
        query.prepare("SELECT * FROM evenements WHERE id_evenement = :id");
        query.bindValue(":id", currentSelectedEventID);

        if (!query.exec() || !query.next()) {
            QMessageBox::critical(this, "Erreur", "Impossible de charger l'événement");
            return;
        }

        // Création du dialogue
        QDialog dialog(this);
        dialog.setWindowTitle("Modifier Événement");
        dialog.setMinimumSize(400, 500);

        // Style simplifié
        dialog.setStyleSheet(R"(
        QDialog {
            background-color: #F5F5F5;
            font-family: "Segoe UI", Arial;
            font-size: 14px;
        }
        QLabel {
            color: #000000;
            margin-bottom: 3px;
        }
        QLineEdit, QTextEdit, QComboBox, QSpinBox, QDateEdit {
        background-color: white;
        border: 1px solid #cccccc;
        border-radius: 3px;
        padding: 6px;  /* Augmentation du padding */
        min-width: 200px;  /* Largeur minimale augmentée */
        min-height: 20px;  /* Hauteur minimale */
        font-size: 12px;
        margin-bottom: 6px;
        color: black;
        }
        QTextEdit {
        min-width: 250px;  /* Largeur minimale augmentée */
        min-height: 100px;  /* Hauteur augmentée */
        padding: 8px;
        font-size: 14px;
        margin-bottom: 12px;
        color: black;
        }
        QPushButton {
            padding: 6px 12px;
            border-radius: 3px;
            min-width: 80px;
        }
        QPushButton[text="Enregistrer"] {
            background-color: #4CAF50;
            color: white;
        }
        QPushButton[text="Annuler"] {
            background-color: #f44336;
            color: white;
        }
        .error {
            border: 1px solid #f44336;
        }
    )");

        // Layout principal
        QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);
        mainLayout->setContentsMargins(20, 20, 20, 20);
        mainLayout->setSpacing(10);

        // Fonction pour ajouter des champs avec libellés
        auto addFormRow = [&](const QString &label, QWidget *widget) {
            QLabel *lbl = new QLabel(label, &dialog);
            mainLayout->addWidget(lbl);
            mainLayout->addWidget(widget);
        };

        // Champs de formulaire
        QLineEdit *nomEdit = new QLineEdit(query.value("nom_evenement").toString(), &dialog);
        QLineEdit *adresseEdit = new QLineEdit(query.value("adresse_eevenement").toString(), &dialog);

        QDateEdit *dateDebutEdit = new QDateEdit(query.value("date_debut_evenement").toDate(), &dialog);
        dateDebutEdit->setCalendarPopup(true);

        QDateEdit *dateFinEdit = new QDateEdit(query.value("date_fin_evenement").toDate(), &dialog);
        dateFinEdit->setCalendarPopup(true);

        QComboBox *typeCombo = new QComboBox(&dialog);
        typeCombo->addItems({"formation", "workshop"});
        typeCombo->setCurrentText(query.value("type_evenement").toString());

        QComboBox *lieuCombo = new QComboBox(&dialog);
        lieuCombo->addItems({"Interieur", "Exterieur"});
        lieuCombo->setCurrentText(query.value("lieu_evenement").toString());

        QSpinBox *participantsEdit = new QSpinBox(&dialog);
        participantsEdit->setRange(1, 1000);
        participantsEdit->setValue(query.value("nbr_participants_evenement").toInt());

        QTextEdit *descriptionEdit = new QTextEdit(query.value("description_evenement").toString(), &dialog);

        // Ajout des champs
        addFormRow("Nom*:", nomEdit);
        addFormRow("Adresse*:", adresseEdit);
        addFormRow("Date début*:", dateDebutEdit);
        addFormRow("Date fin*:", dateFinEdit);
        addFormRow("Type*:", typeCombo);
        addFormRow("Lieu*:", lieuCombo);
        addFormRow("Participants*:", participantsEdit);
        addFormRow("Description*:", descriptionEdit);

        // Boutons
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        QPushButton *saveButton = new QPushButton("Enregistrer", &dialog);
        QPushButton *cancelButton = new QPushButton("Annuler", &dialog);

        buttonLayout->addStretch();
        buttonLayout->addWidget(saveButton);
        buttonLayout->addWidget(cancelButton);
        mainLayout->addLayout(buttonLayout);

        // Validation
        auto validateForm = [&]() -> bool {
            bool valid = true;
            QStringList errors;

            if (nomEdit->text().trimmed().isEmpty()) {
                errors << "Le nom est obligatoire";
                nomEdit->setProperty("class", "error");
            } else {
                nomEdit->setProperty("class", "");
            }

            if (dateDebutEdit->date() > dateFinEdit->date()) {
                errors << "La date de fin doit être après la date de début";
                dateDebutEdit->setProperty("class", "error");
                dateFinEdit->setProperty("class", "error");
            } else {
                dateDebutEdit->setProperty("class", "");
                dateFinEdit->setProperty("class", "");
            }

            if (adresseEdit->text().trimmed().isEmpty()) {
                errors << "L'adresse est obligatoire";
                adresseEdit->setProperty("class", "error");
            } else {
                adresseEdit->setProperty("class", "");
            }

            if (!errors.isEmpty()) {
                QMessageBox::warning(&dialog, "Erreurs", "Veuillez corriger :\n" + errors.join("\n"));
                valid = false;
            }

            return valid;
        };

        // Connexions
        connect(saveButton, &QPushButton::clicked, [&]() {
            if (validateForm()) dialog.accept();
        });

        connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);

        // Exécution
        if (dialog.exec() == QDialog::Accepted) {
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE evenements SET "
                                "nom_evenement = :nom, "
                                "description_evenement = :desc, "
                                "date_debut_evenement = :debut, "
                                "date_fin_evenement = :fin, "
                                "nbr_participants_evenement = :participants, "
                                "adresse_eevenement = :adresse, "
                                "type_evenement = :type, "
                                "lieu_evenement = :lieu "
                                "WHERE id_evenement = :id");

            updateQuery.bindValue(":nom", nomEdit->text().trimmed());
            updateQuery.bindValue(":desc", descriptionEdit->toPlainText().trimmed());
            updateQuery.bindValue(":debut", dateDebutEdit->date());
            updateQuery.bindValue(":fin", dateFinEdit->date());
            updateQuery.bindValue(":participants", participantsEdit->value());
            updateQuery.bindValue(":adresse", adresseEdit->text().trimmed());
            updateQuery.bindValue(":type", typeCombo->currentText());
            updateQuery.bindValue(":lieu", lieuCombo->currentText());
            updateQuery.bindValue(":id", currentSelectedEventID);

            if (updateQuery.exec()) {
                QMessageBox::information(this, "Succès", "Événement modifié");
                afficherEvenementsParDate(ui->calendarWidget->selectedDate());
            } else {
                QMessageBox::critical(this, "Erreur", "Échec : " + updateQuery.lastError().text());
            }
        }
    }
//************************************calendrier supprimer
    void Gevent::supprimerEvenement()
    {
        if (currentSelectedEventID == -1) {
            QMessageBox::warning(this, "Suppression", "Aucun événement sélectionné !");
            return;
        }

        QSqlQuery query;
        query.prepare("DELETE FROM evenements WHERE id_evenement = :id");
        query.bindValue(":id", currentSelectedEventID);

        if (query.exec()) {
            QMessageBox::information(this, "Suppression", "Événement supprimé avec succès.");
            afficherEvenementsParDate(ui->calendarWidget->selectedDate());
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression !");
        }
    }

    void Gevent::on_supprimer_evenement_2_clicked()
    {
        supprimerEvenement();
        afficherStatistiques_evenements();

    }


    void Gevent::on_update_evenement_2_clicked()
    {
        modifierEvenement();
        afficherStatistiques_evenements();

    }


    void Gevent::on_refrech_evenements_2_clicked()
    {
        ajouterEvenement();
        afficherStatistiques_evenements();

    }



    /***************** requete de meteo **/
    void Gevent::fetchWeatherData(const QDate& date, const QString& location, const QString& lieu)
    {
        if (date < QDate::currentDate()) {
            QMessageBox::information(this, "Info", "La date de l'événement est dans le passé");
            return;
        }

        currentLocation = location;
        currentLieu = lieu;
        currentEventDate = date;

        QString apiKey = "5063bc86b16a955447023da5858cb10b";
        QString url = QString("https://api.openweathermap.org/data/2.5/forecast?q=%1&appid=%2&units=metric&lang=fr&cnt=40").arg(location, apiKey);

        QNetworkRequest request;
        request.setUrl(QUrl(url));
        request.setRawHeader("User-Agent", "MyWeatherApp/1.0");

        // Disconnect any previous connections
        disconnect(networkManager, &QNetworkAccessManager::finished, this, &Gevent::onWeatherDataReceived);
        connect(networkManager, &QNetworkAccessManager::finished, this, &Gevent::onWeatherDataReceived);

        networkManager->get(request);
    }

    void Gevent::onWeatherDataReceived(QNetworkReply* reply)
    {
        QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> replyPtr(reply);

        if (reply->error() != QNetworkReply::NoError) {
            QMessageBox::warning(this, "Erreur", reply->errorString());
            return;
        }

        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        if (doc.isNull()) {
            QMessageBox::warning(this, "Erreur", "Données météo invalides");
            return;
        }

        QJsonObject root = doc.object();
        if (root["cod"].toString() != "200") {
            QString message = root.contains("message")
            ? root["message"].toString()
            : "Erreur inconnue de l'API météo";
            QMessageBox::warning(this, "Erreur API", message);
            return;
        }

        const QJsonArray forecasts = root["list"].toArray();
        if (forecasts.isEmpty()) {
            QMessageBox::information(this, "Info", "Pas de données météo disponibles");
            return;
        }

        // Find forecast for our event date
        QString targetDate = currentEventDate.toString("yyyy-MM-dd");
        QJsonObject bestForecast;
        qint64 minDiff = std::numeric_limits<qint64>::max();

        for (const QJsonValue& forecastValue : forecasts) {
            QJsonObject forecast = forecastValue.toObject();
            QString forecastDate = forecast["dt_txt"].toString().left(10);

            if (forecastDate == targetDate) {
                QDateTime forecastTime = QDateTime::fromString(forecast["dt_txt"].toString(), "yyyy-MM-dd HH:mm:ss");
                qint64 diff = qAbs(QDateTime(currentEventDate, QTime(12, 0)).secsTo(forecastTime));

                if (diff < minDiff) {
                    minDiff = diff;
                    bestForecast = forecast;
                }
            }
        }

        if (bestForecast.isEmpty()) {
            QMessageBox::information(this, "Info", "Pas de prévision pour cette date");
            return;
        }

        generateAdvice(bestForecast, currentLocation, currentLieu);
    }

    void Gevent::generateAdvice(const QJsonObject& weatherData, const QString& location, const QString& lieu)
    {
        // Récupérer la description du temps et la température
        QString weather = weatherData["weather"].toArray().first().toObject()["description"].toString();
        double temp = weatherData["main"].toObject()["temp"].toDouble();

        // Générer une liste de conseils basée sur la météo et la température
        QStringList tips = getWeatherTips(weather, temp);
        QString choixConseil;

        // Déterminer si la météo est favorable pour un événement en extérieur
        bool goodWeather = !weather.contains("pluie", Qt::CaseInsensitive) && temp >= 15 && temp <= 28;

        // Logique de conseil basée sur le type de lieu et les conditions météorologiques
        if (goodWeather && lieu == "Interieur") {
            choixConseil = "Il fait beau ! Vous pourriez envisager de déplacer l'événement à l'extérieur.";
        } else if (!goodWeather && lieu == "Exterieur") {
            choixConseil = "Bonne décision d'organiser l'événement à l'intérieur vu la météo.";
        } else {
            choixConseil = "Le lieu choisi semble approprié.";
        }

        // Créer un message final qui sera affiché dans la QMessageBox
        QString advice = QString("<h3>Conseils pour %1</h3>"
                                 "<p><b>Conditions :</b> %2</p>"
                                 "<p><b>Température :</b> %3°C</p>"
                                 "<ul>%4</ul>"
                                 "<p style='margin-top:10px;'>💡 %5</p>")
                             .arg(location,
                                  weather,
                                  QString::number(temp),
                                  tips.join("</li><li>"),
                                  choixConseil);

        // Créer la boîte de dialogue
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Conseils Météo");
        msgBox->setText(advice);
        msgBox->setIcon(QMessageBox::Information);
        msgBox->setStandardButtons(QMessageBox::Ok);

        // Supprimer la boîte de message après qu'elle soit fermée
        msgBox->setAttribute(Qt::WA_DeleteOnClose);
        msgBox->open();
    }

    QStringList Gevent::getWeatherTips(const QString& weather, double temp)
    {
        QStringList tips;

        if (weather.contains("pluie", Qt::CaseInsensitive)) {
            tips << "il y a la possibilite de pluie  ";
        }
        if (temp > 25) {
            tips << "ca fait trop chaud";
        }
        if (temp < 10) {
            tips << "ca fait froid ";
        }
        if (tips.isEmpty()) {
            tips << "Conditions météo normales ";
        }

        return tips;
    }

    void Gevent::on_adviceButton_clicked()
    {
        if (currentSelectedEventID == -1) {
            QMessageBox::warning(this, "Erreur", "Aucun événement sélectionné");
            return;
        }

        QSqlQuery query;
        query.prepare("SELECT date_debut_evenement, adresse_eevenement, lieu_evenement FROM evenements WHERE id_evenement = ?");
        query.addBindValue(currentSelectedEventID);

        if (!query.exec() || !query.next()) {
            QMessageBox::critical(this, "Erreur", "Impossible de charger l'événement");
            return;
        }

        QDate date = query.value(0).toDate();
        QString address = query.value(1).toString().trimmed();
        QString lieu = query.value(2).toString().toLower().trimmed();

        QString location = "Tunis"; // fallback
        if (!address.isEmpty()) {
            location = address;
        }

        fetchWeatherData(date, location, lieu);
    }
//***********************************************flyer

    void Gevent::on_generateFlyer_clicked()
    {
        //v01 v00 et v0.2
        /*QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

        if (selectedIndexes.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner un événement."));
            return;
        }

        QModelIndex index = selectedIndexes.first();
        int id_evenement = index.model()->data(index.model()->index(index.row(), 0)).toInt();

        // ✅ Créer une instance locale
        Evenements e;
        e.generateFlyerForEvent(id_evenement, this);

        // ✅ ou utiliser une instance membre (si définie)
        // evenements.generateFlyerForEvent(id_evenement, this);*/
        //vesrion modifie 0.1
        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
        if (selectedIndexes.isEmpty()) {
            QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner un événement."));
            return;
        }

        int id_evenement = selectedIndexes.first().data().toInt();
        currentEventId = id_evenement; // Mémoriser pour pouvoir régénérer

        Evenements e;
        currentEventFlyer = e.generateFlyerForEvent(id_evenement);

        if (currentEventFlyer.isNull()) {
            QMessageBox::critical(this, "Erreur", "La génération du flyer a échoué.");
            return;
        }

        ui->affichage_flyer->setPixmap(QPixmap::fromImage(currentEventFlyer).scaled(
            ui->affichage_flyer->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }



    void Gevent::on_valider_flyer_clicked()
    {
        if (currentEventFlyer.isNull()) {
            QMessageBox::warning(this, "Erreur", "Aucun flyer à sauvegarder.");
            return;
        }

        QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le flyer", "", "Images (*.png *.jpg)");
        if (!fileName.isEmpty()) {
            if (currentEventFlyer.save(fileName)) {
                QMessageBox::information(this, "Succès", "Le flyer a été sauvegardé !");
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la sauvegarde.");
            }
        }
    }



    void Gevent::on_rejeter_flyer_clicked()
    {
        if (currentEventId <= 0) {
            QMessageBox::warning(this, "Erreur", "Aucun événement sélectionné.");
            return;
        }

        Evenements e;
        currentEventFlyer = e.generateFlyerForEvent(currentEventId);

        if (currentEventFlyer.isNull()) {
            QMessageBox::critical(this, "Erreur", "La régénération du flyer a échoué.");
            return;
        }

        ui->affichage_flyer->setPixmap(QPixmap::fromImage(currentEventFlyer).scaled(
            ui->affichage_flyer->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

