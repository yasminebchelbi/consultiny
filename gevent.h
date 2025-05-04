#ifndef GEVENT_H
#define GEVENT_H
#include "evenements.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMainWindow>
#include "arduino.h"

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
    // Fonctions de validation en temps réel
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

 // calendrier
    void afficherEvenementsParDate(const QDate &date);

    void on_calendarWidget_clicked(const QDate &date);
    void ajouterEvenement();
    void modifierEvenement();
    void supprimerEvenement();
    void updateScoreFromArduino();



    void on_supprimer_evenement_2_clicked();

    void on_update_evenement_2_clicked();

    void on_refrech_evenements_2_clicked();

    void onWeatherDataReceived(QNetworkReply* reply);
    QStringList getWeatherTips(const QString& weather, double temp);



    void on_adviceButton_clicked();



    void on_generateFlyer_clicked();


    void on_valider_flyer_clicked();

    void on_rejeter_flyer_clicked();

    void on_lancerVote_clicked();



    void on_terminerVote_clicked();

private:
    Ui::Gevent *ui;
    Evenements etmp;
    QImage currentEventFlyer;
    int currentEventId=-1;


    int currentSelectedEventID = -1;
    QPixmap currentFlyer;
    QString currentLieu;
     QString currentLocation;
    QDate currentEventDate;
    QNetworkAccessManager *networkManager;
    void fetchWeatherData(const QDate& date, const QString& location, const QString& lieu);
    //void fetchWeatherData(const QString& location, const QString& lieu);
    void generateAdvice(const QJsonObject& weatherData, const QString& location, const QString& lieu);
    //void fetchCurrentWeather(const QString& location, const QString& lieu);
    //oid onCurrentWeatherReceived(QNetworkReply* reply);
    //arduino
    QByteArray data; // variable contenant les données reçues

    //Arduino A; // objet temporaire
    int currentScore = 0;
    QTimer *arduinoTimer;
     Arduino arduino;







};
#endif // GEVENT_H
