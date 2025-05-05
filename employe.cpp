#include "employe.h"

Employe::Employe() : salaire_employe(0.0) {}

Employe::Employe(QString id, QString nom, QString prenom, QDate dateNaissance, QString email,
                 QString telephone, QString adresse, QDate dateEmbauche, QString poste, double salaire)
    : id_employe(id), nom_employe(nom), prenom_employe(prenom), date_naissance_employe(dateNaissance),
    email_employe(email), telephone_employe(telephone), adresse_employe(adresse),
    date_embauche_employe(dateEmbauche), poste_employe(poste), salaire_employe(salaire) {}

// Getters
QString Employe::getIdEmploye() const { return id_employe; }
QString Employe::getNomEmploye() const { return nom_employe; }
QString Employe::getPrenomEmploye() const { return prenom_employe; }
QDate Employe::getDateNaissanceEmploye() const { return date_naissance_employe; }
QString Employe::getEmailEmploye() const { return email_employe; }
QString Employe::getTelephoneEmploye() const { return telephone_employe; }
QString Employe::getAdresseEmploye() const { return adresse_employe; }
QDate Employe::getDateEmbaucheEmploye() const { return date_embauche_employe; }
QString Employe::getPosteEmploye() const { return poste_employe; }
double Employe::getSalaireEmploye() const { return salaire_employe; }

// Setters
void Employe::setIdEmploye(const QString &id) { id_employe = id; }
void Employe::setNomEmploye(const QString &nom) { nom_employe = nom; }
void Employe::setPrenomEmploye(const QString &prenom) { prenom_employe = prenom; }
void Employe::setDateNaissanceEmploye(const QDate &date) { date_naissance_employe = date; }
void Employe::setEmailEmploye(const QString &email) { email_employe = email; }
void Employe::setTelephoneEmploye(const QString &telephone) { telephone_employe = telephone; }
void Employe::setAdresseEmploye(const QString &adresse) { adresse_employe = adresse; }
void Employe::setDateEmbaucheEmploye(const QDate &date) { date_embauche_employe = date; }
void Employe::setPosteEmploye(const QString &poste) { poste_employe = poste; }
void Employe::setSalaireEmploye(double salaire) { salaire_employe = salaire; }
