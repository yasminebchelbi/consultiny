#ifndef RESSOURCE_H
#define RESSOURCE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
class ressource
{
public:

    ressource();
    ressource(QString nom_ressource,QString type_ressource,int quantite_ressource,int cout_ressource,QDate date_achat,QString description);
    void setnom_ressource(QString nom){nom_ressource=nom;}
    void setetype_ressource(QString type){type_ressource=type;}
    void setquantite_ressource(int quantite){quantite_ressource=quantite;}
    void setcout_ressource(int cout){cout_ressource=cout;}
    void setdescription(QString desc){description=desc;}
    void setdate_achat(QDate date){date_achat=date;}

    int getid_ressource(){return id_ressource;}
    QString getnom_ressource(){return nom_ressource;}
    QString gettype_ressource(){return type_ressource;}
    int getquantite_ressource(){return quantite_ressource;}
    int getcout_ressource(){return cout_ressource;}
    QString getdescription(){return description;}
    QDate getdate_achat(){return date_achat;}

    bool ajouter_ressource();
    QSqlTableModel *afficher_ressource();
    bool suprimer_ressource(int);
    bool update_ressource(int id_ressource,QString nom_ressource,QString type_ressource,int quantite_ressource,int cout_ressource,QDate date_achat,QString description);
private:
    int id_ressource;
    QString nom_ressource;
    QString type_ressource;
    int quantite_ressource;
    int cout_ressource;
    QDate date_achat;
    QString description;
};

#endif // RESSOURCE_H
