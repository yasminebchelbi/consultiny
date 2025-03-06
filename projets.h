#ifndef PROJETS_H
#define PROJETS_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Projets
{
public:
    Projets();
    Projets(int,QString,QDate,int,QString,QString,int,QString,QString);
    //getters
    int getId_projet(){retrun id_projet;}
    QString getNom_projet(){return nom_projet;}
    QDate getDate_debut(){return date_debut;}
    int getBudget_projet(){return budget_projet;}
    QString getSecteur_projet(){return secteur_projet;}
    QString getStatus_projet(){return secteur_projet;}
    int getCout_projet(){return cout_projet;}
    QString getAdresse_projet(){return adresse_projet;}
    QString getDescription_projet(){return description_projet;}
    //setters
    void setNom_projet(QString n){nom_projet=n;}
    void setDate_debut(QDate n){date_debut=n;}
    void setBudget_projet(int n){budget_projet=n;}
    void setSecteur_projet(QString n){secteur_projet=n;}
    void setCout_projet(QString n){cout_projet=n;}
    void setAdresse_projet(QString n){adresse_projet=n;}
    void setDescription_projet(QString n){description_projet=n;}

    //Fonctionnalité de base relatives à l'entité projet
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

private:

    int id_projet;
    QString nom_projet;
    QDate date_debut;
    int budget_projet;
    QString secteur_projet;
    QString status_projet;
    int cout_projet;
    QString adresse_projet;
    QString description_projet;

};

#endif // PROJETS_H
