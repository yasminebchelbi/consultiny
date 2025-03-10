#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlTableModel>

class Evenements
{
private:
    int ID_evenement;
    QString nom_evenement;
    QDate date_debut_evenement;
    QDate date_fin_evenement;
    int nbr_participants_evenement;
    QString adresse_evenement;
    QString description_evenement;
    QString type_evenement;

public:
    //constructor default
    Evenements();
    // constructor
    Evenements(QString nom, QDate date_debut, QDate date_fin, int nbr_participants, QString adresse, QString description, QString type);
    // Getters
    int get_ID_evenement() const { return ID_evenement; }
    QString get_nom_evenement() const { return nom_evenement; }
    QDate get_date_debut_evenement() const { return date_debut_evenement; }
    QDate get_date_fin_evenement() const { return date_fin_evenement; }
    int get_nbr_participants_evenement() const { return nbr_participants_evenement; }
    QString get_adresse_evenement() const { return adresse_evenement; }
    QString get_description_evenement() const { return description_evenement; }
    QString get_type_evenement() const { return type_evenement; }

    // Setters
    void set_nom_evenement(const QString &n) { nom_evenement = n; }
    void set_date_debut_evenement(const QDate &n) { date_debut_evenement = n; }
    void set_date_fin_evenement(const QDate &n) { date_fin_evenement = n; }
    void set_nbr_participants_evenement(const int &n) { nbr_participants_evenement = n; }
    void set_adresse_evenement(const QString &n) { adresse_evenement = n; }
    void set_description_evenement(const QString &n) { description_evenement = n; }
    void set_type_evenement(const QString &n) { type_evenement = n; }



    //CRUD

    bool ajouter_evenements();
    QSqlTableModel * afficher_evenements();
    bool supprimer_evenements(int ID_evenement);
    bool modifier_evenement(int id, QString nom, QDate date_debut, QDate date_fin, int nbr_participants, QString adresse, QString description, QString type);
};

#endif // EVENEMENTS_H
