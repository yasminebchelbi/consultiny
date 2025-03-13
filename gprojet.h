#ifndef GPROJET_H
#define GPROJET_H
#include<projets.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Gprojet;
}
QT_END_NAMESPACE

class Gprojet : public QMainWindow
{
    Q_OBJECT

public:
    Gprojet(QWidget *parent = nullptr);
    ~Gprojet();

private slots:

    void on_ajouter_projet_clicked();

    void on_supprimer_projet_clicked();

    void on_update_projet_clicked();

    void on_annuler_projet_clicked();
    void verifierSaisie();
    void verifierChamps();

private:
    Ui::Gprojet *ui;
    Projets P;
};
#endif // GPROJET_H
