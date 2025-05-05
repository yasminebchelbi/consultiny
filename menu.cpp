#include "menu.h"
#include "ui_menu.h"
#include "gemploye.h"
#include <QSqlQuery>
#include "access.h"

Menu::Menu(access *fenetreConnexion, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Menu),
    fenetreConnexion(fenetreConnexion),
    fenetreEmploye(nullptr)


{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
    if (fenetreEmploye) delete fenetreEmploye;
}
Menu::Menu(Gemploye *fenetreEmp, QWidget *parent)
    : QWidget(parent), fenetreEmploye(fenetreEmp)
{
    ui = new Ui::Menu;
    ui->setupUi(this);
}

/*void Menu::on_Gemploye_clicked()
{

    fenetreEmploye = new Gemploye(nullptr, this); // Au lieu de new Gemploye(this);
    fenetreEmploye->show();
    fenetreEmploye->raise();
    fenetreEmploye->activateWindow();
    this->hide(); // ne détruit pas Menu, donc pas de crash


}*/
void Menu::on_Gemploye_clicked()
{
    QString email = fenetreConnexion->getEmailConnecte();
    QString poste;

    QSqlQuery query;
    query.prepare("SELECT poste_employe FROM employes WHERE email_employe = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        poste = query.value(0).toString().toLower(); // récupérer le poste
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer le poste.");
        return;
    }

    // Vérification des droits d'accès
    if (poste == "ceo" || poste == "admin" || poste == "rh") {
        fenetreEmploye = new Gemploye(fenetreConnexion, this);
        fenetreEmploye->show();
        fenetreEmploye->raise();
        fenetreEmploye->activateWindow();
        this->hide(); // Masquer la fenêtre Menu
    } else {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas les droits pour accéder à cette fonctionnalité.");
    }
}
