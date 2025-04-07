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

//using namespace QtCharts;

Gevent::Gevent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gevent)
{
    ui->setupUi(this);
    //qDebug() << "Initialisation de l'affichage des événements...";
    //force l'actualisation après un petit délai
    QTimer::singleShot(500, this, [=](){
        ui->tableView->setModel(etmp.afficher_evenements());
        afficherStatistiques_evenements();

    });




    qDebug() << "Drivers SQL disponibles :" << QSqlDatabase::drivers();

    connect(ui->nom, &QLineEdit::textChanged, this, &Gevent::verifierNom);
    connect(ui->date_debut, &QDateEdit::dateChanged, this, &Gevent::verifierDates);
    connect(ui->date_fin, &QDateEdit::dateChanged, this, &Gevent::verifierDates);
    connect(ui->nbr_participants, &QSpinBox::textChanged, this, &Gevent::verifierParticipants);
    connect(ui->lieu, &QLineEdit::textChanged, this, &Gevent::verifierLieu);
    connect(ui->description, &QPlainTextEdit::textChanged, this, &Gevent::verifierDescription);
    connect(ui->type, &QComboBox::currentTextChanged, this, &Gevent::verifierType);
    verifierFormulaire(); // Vérification initiale



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

//***********************************************************************************************************************************

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

    Evenements E(nom_evenement, date_debut_evenement, date_fin_evenement, nbr_participants_evenement, adresse_evenement,  description_evenement, type_evenement);

    if (E.ajouter_evenements()) {
        ui->tableView->setModel(E.afficher_evenements());
        ui->tableView->resizeColumnsToContents();
        afficherStatistiques_evenements();
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
    } else {
        QMessageBox::critical(this, "Échec", "Ajout non effectué !");
    }
}

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
        if (E.modifier_evenement(id_evenement, nom_evenement, date_debut_evenement, date_fin_evenement, nbr_participants_evenement, adresse_evenement, description_evenement, type_evenement)) {
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
    void Gevent::on_pushButton_2_clicked()
    {
        ui->nom->clear();
        ui->lieu->clear();
        ui->date_debut->clear();
        ui->date_fin->clear();
        ui->description->clear();
        ui->nbr_participants->clear();
    }


    void Gevent::on_telecharger_evenement_clicked()
    {


       Evenements event;
       event.telecharger_pdf_evenements();

    }


    void Gevent::on_rechercher_evenement_clicked()
    {
        int id = ui->id_evenement_recherche->text().toInt(); // Récupérer l'ID depuis un champ texte

        if (id <= 0) {
            QMessageBox::warning(this, "Attention", "Veuillez entrer un ID valide !");
            return;
        }

        Evenements event;
        QSqlQueryModel* model = event.recherche_evenements(id);

        if (model->rowCount() == 0) {
            QMessageBox::information(this, "Résultat", "Aucun événement trouvé avec cet ID.");
        } else {
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre des participants"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("description"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("type"));
            ui->tableView->setModel(model);
        }

    }





 /*   void Gevent::on_tri_evenements_clicked()
    {
        QString critere = ui->critere_evenements->currentText();
        QVariant valeur;

        if (critere == "ID") {
            valeur = ui->id_input->text().toInt();
        } else if (critere == "Date de début") {
            valeur = ui->date_input->date();
        } else if (critere == "Nombre de participants") {
            valeur = ui->nbr_participants_input->text().toInt();
        }

        QSqlQueryModel* model = evenements.filtrer_evenements(critere, valeur);

        if (model) {
            ui->tableView->setModel(model);
        }
    }
*/



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
        ui->tableView->setModel(model);
    }

/********************************************************************************************/


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

