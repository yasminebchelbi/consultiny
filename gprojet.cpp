#include "gprojet.h"
#include "ui_gprojet.h"
#include "projets.h"
#include<QMessageBox>
#include<QInputDialog>
#include<QRegularExpression>

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

}


Gprojet::~Gprojet()
{
    delete ui;
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
        ui->tableView->resizeColumnsToContents();
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
            Projets P;
            if (P.update(id_projet, nom_projet, date_debut, status_projet, secteur_projet, budget_projet, cout_projet, description_projet)) {
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
        ui->dateTimeEdit->clear();
        ui->lineEdit_budget->clear();
        ui->lineEdit_adresse->clear();
        ui->lineEdit_secteur->clear();
        ui->plainTextEdit_description->clear();
        ui->lineEdit_cout->clear();

}

