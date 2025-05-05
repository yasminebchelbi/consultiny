#include "access.h"
#include "ui_access.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "gemploye.h"
#include "oublie.h"
#include "dialogtheme.h"
#include <QRegularExpression>
#include "gestionemp.h"
#include "menu.h"



access::access(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::access),
    fenetreMenu(nullptr),
    fenetreEmploye(nullptr)


{
    ui->setupUi(this);
    //connect(ui->seconnecter_button, &QPushButton::clicked, this, &access::on_seconnecter_button_clicked);
    //connect(ui->sinscrire_button, &QPushButton::clicked, this, &access::on_sinscrire_button_clicked);
    connect(ui->mdpOublieBtn, &QPushButton::clicked, this, [=]() {
        oublie *dlg = new oublie(this);
        dlg->exec();
    });
}

access::~access()
{
    delete ui;
    if (fenetreEmploye) delete fenetreEmploye;
    if(fenetreMenu) delete fenetreMenu;

}

void access::on_seconnecter_button_clicked()
{
    ui->mdpconnexion->setEchoMode(QLineEdit::Password);
    QString email_employe = ui->mailconnexion->text();
    QString mpd_employe = ui->mdpconnexion->text();


    if (email_employe.isEmpty() || mpd_employe.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez entrer l'e-mail et le mot de passe.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM employes WHERE email_employe = :email_employe AND mpd_employe = :mpd_employe");
    query.bindValue(":email_employe", email_employe);
    query.bindValue(":mpd_employe", mpd_employe);

    if (query.exec() && query.next()) {
        // Connexion réussie
        /*QMessageBox::information(this, "Succès", "Connexion réussie.");
        fenetreEmploye = new Gemploye(this);
        fenetreEmploye->show();
        fenetreEmploye->raise();
        fenetreEmploye->activateWindow();*/

        /*this->close();*/
       fenetreMenu = new Menu(this);
       fenetreMenu->show();
       fenetreMenu->raise();
       fenetreMenu->activateWindow();

        this->close(); // Ferme le QDialog de connexion*/

    } else {
        QMessageBox::critical(this, "Erreur", "E-mail ou mot de passe incorrect.");
    }

    /*connect(ui->mdpOublieBtn, &QPushButton::clicked, [&]() {
        // Ouvre la fenêtre de récupération de mot de passe
        oublie *dlg = new oublie(this);
        dlg->exec();
    });*/

}
QString access::getEmailConnecte() const {
    return ui->mailconnexion->text();
}

