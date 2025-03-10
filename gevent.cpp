#include "gevent.h"
#include "ui_gevent.h"
#include <QMessageBox>
#include <qtimer.h>
#include "evenements.h"


Gevent::Gevent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gevent)
{
    ui->setupUi(this);
    //qDebug() << "Initialisation de l'affichage des événements...";
    //force l'actualisation après un petit délai blha mamche
    QTimer::singleShot(500, this, [=](){
        ui->tableView->setModel(etmp.afficher_evenements());
    });

}

Gevent::~Gevent()
{
    delete ui;
}

void Gevent::on_ajouter_evenement_clicked()
{
    QString nom_evenement = ui->nom->text().trimmed();
    QDate date_debut_evenement = ui->date_debut->date();
    QDate date_fin_evenement = ui->date_fin->date();
    int nbr_participants_evenement = ui->nbr_participants->text().toInt();
    QString adresse_evenement = ui->lieu->text().trimmed();
    QString description_evenement = ui->description->toPlainText().trimmed();
    QString type_evenement = ui->type->currentText().trimmed();

    // Vérifications des champs
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
    if (description_evenement.isEmpty() || description_evenement.length() < 10) {
        QMessageBox::warning(this, "Erreur de saisie", "La description doit contenir au moins 10 caractères.");
        return;
    }
    if (type_evenement.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Veuillez sélectionner un type d'événement.");
        return;
    }

    // Création de l'objet événement après validation
    Evenements E(nom_evenement, date_debut_evenement, date_fin_evenement, nbr_participants_evenement, adresse_evenement, type_evenement, description_evenement);

    bool test = E.ajouter_evenements();

    if (test) {
        // Actualisation de la table
        ui->tableView->setModel(E.afficher_evenements());
        ui->tableView->resizeColumnsToContents();

        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
    } else {
        QMessageBox::critical(this, "Échec", "Ajout non effectué ! Vérifiez vos données et réessayez.");
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

    // Vérification des champs obligatoires et validation des données
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
    if (description_evenement.isEmpty() || description_evenement.length() < 10) {
        QMessageBox::warning(this, "Erreur de saisie", "La description doit contenir au moins 10 caractères.");
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
        ui->type->clear();
        ui->description->clear();
        ui->nbr_participants->clear();
    }

