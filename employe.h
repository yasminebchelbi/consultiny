#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>

class Employe {
private:
    QString id_employe;
    QString nom_employe;
    QString prenom_employe;
    QDate date_naissance_employe;
    QString email_employe;
    QString telephone_employe;
    QString adresse_employe;
    QDate date_embauche_employe;
    QString poste_employe;
    double salaire_employe;

public:
    Employe();
    Employe(QString id, QString nom, QString prenom, QDate dateNaissance, QString email,
            QString telephone, QString adresse, QDate dateEmbauche, QString poste, double salaire);

    // Getters
    QString getIdEmploye() const;
    QString getNomEmploye() const;
    QString getPrenomEmploye() const;
    QDate getDateNaissanceEmploye() const;
    QString getEmailEmploye() const;
    QString getTelephoneEmploye() const;
    QString getAdresseEmploye() const;
    QDate getDateEmbaucheEmploye() const;
    QString getPosteEmploye() const;
    double getSalaireEmploye() const;

    // Setters
    void setIdEmploye(const QString &id);
    void setNomEmploye(const QString &nom);
    void setPrenomEmploye(const QString &prenom);
    void setDateNaissanceEmploye(const QDate &date);
    void setEmailEmploye(const QString &email);
    void setTelephoneEmploye(const QString &telephone);
    void setAdresseEmploye(const QString &adresse);
    void setDateEmbaucheEmploye(const QDate &date);
    void setPosteEmploye(const QString &poste);
    void setSalaireEmploye(double salaire);
};

#endif // EMPLOYE_H
