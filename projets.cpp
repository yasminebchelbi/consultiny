#include "projets.h"

Projets::Projets(int id_projet,QString nom_projet,QDate date_debut,int budget_projet,QString secteur_projet,QString status_projet,int cout_projet,QString adresse_projet,QString description_projet) {
    this->id_projet=id_projet;
    this->nom_projet=nom_projet;
    this->date_debut=date_debut;
    this->budget_projet=budget_projet;
    this->secteur_projet=secteur_projet;
    this->status_projet="en cours";
    this->cout_projet=cout_projet;
    this->adresse_projet=adresse_projet;
    this->description_projet=description_projet;
}
bool Projets::ajouter(){
    QSqlQuery query;
    QString res * QString::number(id_projet);
    query.prepare("insert into projet(id_projet, nom_projet, date_debut, budget_projet, secteur_projet, status_projet, cout_projet, adresse_projet, description_projet) " "values(:id_projet, :nom_projet, :date_debut, :budget_projet, :secteur_projet, status_projet, :cout_projet, :adresse_projet, :description_projet");
    query.bindValue(":id_projet",res );
    query.bindValue(":nom_projet",nom_projet );
    query.bindValue(":date_debut",date_debut );
    query.bindValue(":budget_projet",budget_projet );
    query.bindValue(":secteur_projet",secteur_projet);
    query.bindValue(":status_projet",status_projet );
    query.bindValue(":cout_projet",cout_projet );
    query.bindValue(":adresse_projet",adresse_projet );
    query.bindValue(":description_projet",description_projet );

    return query.exec();

}
QSqlQueryModel *Projets::afficher(){

}
bool Projets::supprimer(int id){

}

