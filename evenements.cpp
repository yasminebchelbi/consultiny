#include "evenements.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>


Evenements::Evenements()
    : ID_evenement(0),
    nom_evenement(""),
    date_debut_evenement(QDate::currentDate()),
    date_fin_evenement(QDate::currentDate()),
    nbr_participants_evenement(0),
    adresse_evenement(""),
    description_evenement(""),
    type_evenement("")
{
}

Evenements::Evenements(QString nom, QDate date_debut, QDate date_fin, int nbr_participants, QString adresse, QString description, QString type) {
    this->nom_evenement = nom;
    this->date_debut_evenement = date_debut;
    this->date_fin_evenement = date_fin;
    this->nbr_participants_evenement = nbr_participants;
    this->adresse_evenement = adresse;
    this->description_evenement = description;
    this->type_evenement = type;
}


//**********************************************************l'ajout*****************************************************************
bool Evenements::ajouter_evenements() {
    QSqlQuery query;


    query.prepare("INSERT INTO EVENEMENTS(NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT) "
                  "VALUES(:nom_evenement, :date_debut_evenement, :date_fin_evenement, :nbr_participants_evenement, :adresse_evenement, :description_evenement, :type_evenement)");

    query.bindValue(":nom_evenement", nom_evenement);
    query.bindValue(":date_debut_evenement", date_debut_evenement);
    query.bindValue(":date_fin_evenement", date_fin_evenement);
    query.bindValue(":nbr_participants_evenement", nbr_participants_evenement);
    query.bindValue(":adresse_evenement", adresse_evenement);
    query.bindValue(":description_evenement",  description_evenement);
    query.bindValue(":type_evenement", type_evenement);



    return query.exec();
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
    }
}
//*****************************methode afficher j'ai utiliser QSqlTableModel au lieu de QSqlQueryModel*********************

QSqlTableModel *Evenements::afficher_evenements() {
    qDebug() << "afficher_evenements() appelée";
    QSqlTableModel * model = new QSqlTableModel();

    model->setQuery("SELECT ID_EVENEMENT,NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT FROM evenements") ;

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre des participants"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("description"));
    //return model;
    if (model->lastError().isValid()) {
        qDebug() << "Erreur de requête: " << model->lastError().text();
    } else {
        qDebug() << "Requête réussie!";
        qDebug() << "Nombre de lignes retournées: " << model->rowCount();
    }

return model;
}


//*******************************méthode de suppression****************************************************************
bool Evenements::supprimer_evenements(int ID_EVENEMENT) {
    QSqlQuery query;
    QString res=QString::number(ID_EVENEMENT);
    query.prepare(("delete from evenements where ID_EVENEMENT= :ID_EVENEMENT"));
    query.bindValue(":ID_EVENEMENT",res);
    return query.exec();

}
/************************************méthode de modifier**********************************************************************************************/
bool Evenements::modifier_evenement(int id_evenement, QString nom_evenement, QDate date_debut_evenement, QDate date_fin_evenement, int nbr_participants_evenement, QString adresse_eevenement, QString description_evenement, QString type_evenement) {
    QSqlQuery query;
    query.prepare("UPDATE evenements SET nom_evenement = :nom_evenement, date_debut_evenement = :date_debut_evenement, date_fin_evenement = :date_fin_evenement, "
                  "nbr_participants_evenement = :nbr_participants_evenement, adresse_eevenement = :adresse_eevenement, description_evenement = :description_evenement, "
                  "type_evenement = :type_evenement WHERE id_evenement = :id_evenement");
    query.bindValue(":id_evenement", id_evenement);
    query.bindValue(":nom_evenement", nom_evenement);
    query.bindValue(":date_debut_evenement", date_debut_evenement);
    query.bindValue(":date_fin_evenement", date_fin_evenement);
    query.bindValue(":nbr_participants_evenement", nbr_participants_evenement);
    query.bindValue(":adresse_eevenement", adresse_eevenement);
    query.bindValue(":description_evenement", description_evenement);
    query.bindValue(":type_evenement", type_evenement);

    return query.exec();
}


