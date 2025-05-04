#ifndef GPROJET_H
#define GPROJET_H
#include<projets.h>
#include <QMainWindow>
#include <QtCharts>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include"arduino.h"


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
    QSqlTableModel *model;
    //void lireDonnees();

private slots:

    void on_ajouter_projet_clicked();

    void on_supprimer_projet_clicked();

    void on_update_projet_clicked();

    void on_annuler_projet_clicked();
    void verifierSaisie();
    void verifierChamps();
    void on_recherche_projet_2_clicked();
    void on_trier_projet_2_clicked();
    void on_telecharger_projet_clicked();
    void exporterProjetsTexte();
    void afficherStatistiquesStatus() ;
    void on_hist_projet_clicked();
    void on_annuler_conseil_projet_clicked();

    void on_anuuler_hist_clicked();

    void on_refresh_projet_clicked();
    QString colorizeModification(const QString& text);

    //void on_btnEnvoyer_projet_clicked();

    //void on_btnEnvoyer_projet_clicked();
    //void enregistrerQuestionDansFichier(const QString &question);

    //void on_txtQuestion_returnPressed();
    void on_btnEnvoyer_clicked();
    void handleNetworkReply(QNetworkReply* reply);

    void on_txtQuestion_returnPressed();
private:
    Ui::Gprojet *ui;
    Projets P;
    QNetworkAccessManager *manager;
    QByteArray data; // variable contenant les données reçues
    Arduino *A;
    QSerialPort *serial;
};
#endif // GPROJET_H
