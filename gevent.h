#ifndef GEVENT_H
#define GEVENT_H
#include "evenements.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Gevent;
}
QT_END_NAMESPACE

class Gevent : public QMainWindow
{
    Q_OBJECT

public:
    Gevent(QWidget *parent = nullptr);
    ~Gevent();


private slots:
    void on_ajouter_evenement_clicked();


    void on_supprimer_evenement_clicked();

    void on_update_evenement_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Gevent *ui;
    Evenements etmp;

};
#endif // GEVENT_H
