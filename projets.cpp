#include "projets.h"
#include<QSqlQuery>
#include<QSqlTableModel>
#include <QMessageBox>


Projets::Projets(QString nom_projet, QDate date_debut, int budget_projet, QString secteur_projet, int cout_projet, QString adresse_projet, QString description_projet) {
    // L'id est auto-incrémenté donc tu ne l'initialises pas ici.
    this->nom_projet = nom_projet;
    this->date_debut = date_debut;
    this->budget_projet = budget_projet;
    this->secteur_projet = secteur_projet;
    this->status_projet = "en cours"; // Valeur par défaut
    this->cout_projet = cout_projet;
    this->adresse_projet = adresse_projet;
    this->description_projet = description_projet;
}
//constructeur par défaut
Projets::Projets() {
    id_projet = 0;  // ou toute autre valeur par défaut
    nom_projet = "";
    date_debut = QDate::currentDate(); // ou toute autre valeur par défaut
    budget_projet = 0;
    secteur_projet = "";
    status_projet = "en cours"; // valeur par défaut
    cout_projet = 0;
    adresse_projet = "";
    description_projet = "";
}
//**************************************************méthode ajouter**************************************************
bool Projets::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO projet(nom_projet, date_debut, budget_projet, secteur_projet, status_projet, cout_projet, adresse_projet, description_projet) "
                  "VALUES(:nom_projet, :date_debut, :budget_projet, :secteur_projet, 'en cours', :cout_projet, :adresse_projet, :description_projet)");

    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":budget_projet", budget_projet);
    query.bindValue(":secteur_projet", secteur_projet);
    query.bindValue(":cout_projet", cout_projet);
    query.bindValue(":adresse_projet", adresse_projet);
    query.bindValue(":description_projet", description_projet);

    return query.exec();
}
//*****************************methode afficher j'ai utiliser QSqlTableModel au lieu de QSqlQueryModel*********************

QSqlTableModel *Projets::afficher() {
    QSqlTableModel *model = new QSqlTableModel();

    model->setQuery("SELECT id_projet,nom_projet, date_debut, budget_projet, secteur_projet, status_projet, cout_projet, adresse_projet, description_projet FROM projet");

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Secteur"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Coût"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Description"));

    return model;
}


//*******************************méthode de suppression****************************************************************
bool Projets::supprimer(int id_projet) {
    QSqlQuery query;
    QString res=QString::number(id_projet);
    query.prepare(("delete from projet where id_projet= :id_projet"));
    query.bindValue(":id_projet",res);
    return query.exec();

}

//*************************************focntion de l'update******************************************************************

bool Projets::update(int id_projet, QString nom_projet,QDate date_debut,QString status_projet, QString secteur_projet, int budget_projet,int cout_projet,QString description_projet) {
    QSqlQuery query;
    query.prepare("UPDATE projet SET nom_projet = :nom_projet, date_debut = :date_debut, secteur_projet = :secteur_projet, budget_projet = :budget_projet, description_projet = :description_projet, status_projet = :status_projet, cout_projet = :cout_projet WHERE id_projet = :id_projet");
    query.bindValue(":nom_projet", nom_projet);
    query.bindValue(":secteur_projet", secteur_projet);
    query.bindValue(":budget_projet", budget_projet);
    query.bindValue(":cout_projet", cout_projet);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":status_projet", status_projet);
    query.bindValue(":description_projet", description_projet);
    query.bindValue(":id_projet", id_projet);
    return query.exec();
}
