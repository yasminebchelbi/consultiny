#ifndef PROJETS_H
#define PROJETS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlTableModel>

class Projets
{
public:
    // Constructeurs
    Projets();  // Constructeur par défaut
    Projets(QString, QDate, int, QString, int, QString, QString); // Constructeur avec paramètres

    // Getters
    int getId_projet() const { return id_projet; }
    QString getNom_projet() const { return nom_projet; }
    QDate getDate_debut() const { return date_debut; }
    int getBudget_projet() const { return budget_projet; }
    QString getSecteur_projet() const { return secteur_projet; }
    QString getStatus_projet() const { return status_projet; }
    int getCout_projet() const { return cout_projet; }
    QString getAdresse_projet() const { return adresse_projet; }
    QString getDescription_projet() const { return description_projet; }

    // Setters
    void setNom_projet(const QString &n) { nom_projet = n; }
    void setDate_debut(const QDate &n) { date_debut = n; }
    void setBudget_projet(int n) { budget_projet = n; }
    void setSecteur_projet(const QString &n) { secteur_projet = n; }
    void setCout_projet(int n) { cout_projet = n; }
    void setAdresse_projet(const QString &n) { adresse_projet = n; }
    void setDescription_projet(const QString &n) { description_projet = n; }

    // Fonctionnalités de base relatives à l'entité projet
    bool ajouter();
    QSqlTableModel* afficher();
    void supprimerSelection();
    bool supprimer(int);
    bool update( int id_projet,QString nom_projet, QDate date_debut, QString status_projet,
                QString secteur_projet, int budget_projet, int cout_projet, QString description_projet);
    QVector<int> statMensuelle();

    //QMap<QString, int>statistiques_mensuelles();
    void telecharger_projet();


private:
    int id_projet;             // L'ID est auto-incrémenté par la base de données
    QString nom_projet;
    QDate date_debut;
    int budget_projet;
    QString secteur_projet;
    QString status_projet = "en cours"; // Valeur par défaut(en cours/términé/annulé)
    int cout_projet;
    QString adresse_projet;
    QString description_projet;
};

#endif // PROJETS_H
