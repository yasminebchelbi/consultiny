#include "changemdpdialog.h"
#include "ui_changemdpdialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include "dialogtheme.h"

ChangeMdpDialog::ChangeMdpDialog(const QString &tel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeMdpDialog),
    telRecup(tel)
{
    ui->setupUi(this);
    setWindowTitle("Changer le mot de passe");
    setModal(true);
    connect(ui->validerButton, &QPushButton::clicked, this, &ChangeMdpDialog::on_valider_clicked);
    connect(ui->annulerButton, &QPushButton::clicked, this, &ChangeMdpDialog::on_annuler_clicked);
}

ChangeMdpDialog::~ChangeMdpDialog()
{
    delete ui;
}

void ChangeMdpDialog::on_valider_clicked()
{
    QString newMdp = ui->nouveauMdpEdit->text();
    QString confirmMdp = ui->confirmerMdpEdit->text();
    if (newMdp.isEmpty() || confirmMdp.isEmpty()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Veuillez remplir les deux champs.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.exec();
        return;
    }
    if (newMdp != confirmMdp) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Les mots de passe ne correspondent pas.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.exec();
        return;
    }
    if (newMdp.length() < 8) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Le mot de passe doit contenir au moins 8 caractères.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.exec();
        return;
    }
    // Mettre à jour le mot de passe dans la base
    QSqlQuery query;
    // Correction : vérifier le nom exact de la colonne dans la base (Oracle est sensible à la casse)
    // Essayons sans guillemets pour la colonne, car elle semble être en majuscules par défaut
    query.prepare("UPDATE employes SET MPD_EMPLOYE = :mdp WHERE REPLACE(TELEPHONE_EMPLOYE, ' ', '') = REPLACE(:tel, ' ', '')");
    query.bindValue(":mdp", newMdp);
    query.bindValue(":tel", telRecup.trimmed());
    if (!query.exec()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Échec de la mise à jour du mot de passe.\n" + query.lastError().text());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.exec();
        return;
    }
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Succès");
    msgBox.setText("Mot de passe modifié avec succès.");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStyleSheet(dialogThemeStyle());
    msgBox.exec();
    accept();
}

void ChangeMdpDialog::on_annuler_clicked()
{
    reject();
}
