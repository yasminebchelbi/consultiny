#ifndef ACCESS_H
#define ACCESS_H


#include <QWidget>

class Gemploye;
class gestionemp;
class Menu;

namespace Ui {
class access;
}

class access : public QWidget
{
    Q_OBJECT

public:
    explicit access(QWidget *parent = nullptr);
    QString getEmailConnecte() const;
     Menu *fenetreMenu = nullptr;
     Gemploye *fenetreEmploye = nullptr;

    ~access();

private slots:
    void on_seconnecter_button_clicked();


   // void on_sinscrire_button_clicked();

private:
    Ui::access *ui;
    //Gemploye *fenetreEmploye = nullptr;
    //Menu *fenetreMenu = nullptr;
   // page *fenetrePage = nullptr;

};

#endif // ACCESS_H
