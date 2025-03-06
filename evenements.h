#ifndef EVENEMENTS_H
#define EVENEMENTS_H
#include <QString>
#include <QDate>
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
    Evenements();
};

#endif // EVENEMENTS_H
