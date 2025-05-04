#include "ressource.h"
#include <QSqlTableModel>
#include <QSqlQuery>

ressource::ressource() {}
ressource::ressource(QString nom_ressource, QString type_ressource, int quantite_ressource,
                     int cout_ressource, QDate date_achat, QString description)
{
    this->nom_ressource = nom_ressource;
    this->type_ressource = type_ressource;
    this->quantite_ressource = quantite_ressource;
    this->cout_ressource = cout_ressource;
    this->date_achat = date_achat;
    this->description = description;
}

bool ressource::ajouter_ressource()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ressources (nom_ressource, type_ressource, quantite_ressource, "
                  "cout_ressource, date_achat, description) "
                  "VALUES (:nom_ressource, :type_ressource, :quantite_ressource, :cout_ressource, "
                  ":date_achat, :description)");

    query.bindValue(":nom_ressource", nom_ressource);
    query.bindValue(":type_ressource", type_ressource);
    query.bindValue(":quantite_ressource", quantite_ressource);
    query.bindValue(":cout_ressource", cout_ressource);
    query.bindValue(":date_achat", date_achat);
    query.bindValue(":description", description);

    return query.exec();
}

bool ressource::suprimer_ressource(int id_ressource)
{

        QSqlQuery query;
        QString res=QString::number(id_ressource);
        query.prepare(("delete from ressources where id_ressource= :id_ressource"));
        query.bindValue(":id_ressource",res);
        return query.exec();

    }


 QSqlTableModel *ressource::afficher_ressource()
{

        QSqlTableModel *model = new QSqlTableModel();

        model->setQuery("SELECT id_ressource, nom_ressource, type_ressource, quantite_ressource, cout_ressource, date_achat, description FROM ressources");

        // Définir les en-têtes des colonnes
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("cout"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("description"));

        return model;
    }

bool ressource::update_ressource(int id_ressource, QString nom_ressource, QString type_ressource, int quantite_ressource, int cout_ressource, QDate date_achat, QString description) {
    QSqlQuery query;
    query.prepare("UPDATE ressources SET nom_ressource = :nom_ressource, type_ressource = :type_ressource, quantite_ressource = :quantite_ressource, "
                  "cout_ressource = :cout_ressource, date_achat = :date_achat, description = :description "
                  "WHERE id_ressource = :id_ressource");

    query.bindValue(":id_ressource", id_ressource);
    query.bindValue(":nom_ressource", nom_ressource);
    query.bindValue(":type_ressource", type_ressource);  // <-- manquant dans la requête
    query.bindValue(":quantite_ressource", quantite_ressource);
    query.bindValue(":cout_ressource", cout_ressource);
    query.bindValue(":date_achat", date_achat);
    query.bindValue(":description", description);

    return query.exec();
}

























































