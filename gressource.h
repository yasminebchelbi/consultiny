#ifndef GRESSOURCE_H
#define GRESSOURCE_H
#include <ressource.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Gressource;
}
QT_END_NAMESPACE

class Gressource : public QMainWindow
{
    Q_OBJECT

public:
    Gressource(QWidget *parent = nullptr);
    ~Gressource();

private slots:
    void on_ajouter_ressource_clicked();

    void on_delete_ressource_clicked();

    void on_update_ressource_clicked();

    void verifierSaisie();

    void on_tri_ressource_clicked();

    void on_recherche_ressource_clicked();
    void on_telecharger_ressource_clicked();

    void verifierRessourcesFaibles();
    void afficher_statistique_ressource();

    void on_preduction_ressource_clicked();


private:

    Ui::Gressource *ui;
    ressource R;
    double budgetGlobal = 2000.0; //Budget initial global
};
#endif // GRESSOURCE_H
