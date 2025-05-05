#ifndef MENU_H
#define MENU_H
#include <QWidget>
#include "gestionemp.h"
#include "gemploye.h"
class access;
class gestionemp;
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(access *fentreConnexion ,QWidget *parent = nullptr);
    explicit Menu(Gemploye *fenetreEmp, QWidget *parent = nullptr);


    ~Menu();

private slots:
    void on_Gemploye_clicked();

private:
    Ui::Menu *ui;
    access *fenetreConnexion;
    Gemploye *fenetreEmploye = nullptr;
};

#endif // MENU_H
