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
    // 🚀 Fonctions de validation en temps réel
    void verifierNom();
    void verifierDates();
    void verifierParticipants();
    void verifierLieu();
    void verifierDescription();
    void verifierType();
    void verifierFormulaire(); // Vérifie si tous les champs sont valides

    void on_telecharger_evenement_clicked();

    void on_rechercher_evenement_clicked();

    //void on_critere_evenements_activated(int index);

    //void on_tri_evenements_clicked();

    void on_trier_evenements_clicked();
    void afficherStatistiques_evenements();

    void on_refrech_evenements_clicked();

private:
    Ui::Gevent *ui;
    Evenements etmp;


};
#endif // GEVENT_H
