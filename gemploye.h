#ifndef GEMPLOYE_H
#define GEMPLOYE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "employe.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

class access;
class Menu;

QT_BEGIN_NAMESPACE
namespace Ui { class gemploye; }
QT_END_NAMESPACE

class Gemploye : public QMainWindow {
    Q_OBJECT

public:
    explicit Gemploye(access *fenetreConnexion, QWidget *parent = nullptr);
    //explicit Gemploye(Menu *menuExistant, QWidget *parent = nullptr);
   // explicit Gemploye(QWidget *parent = nullptr); // surcharge
    ~Gemploye();

private slots:
    void on_ajouter_employe_clicked();
    void on_annuler_employe_clicked();
    void on_chercher_employe_clicked();
    void on_supprimer_employe_clicked();
    void on_modifier_employe_clicked();
    void on_telech_employe_clicked();
    void on_statsTypeCombo_currentIndexChanged(int index);
    void on_deconnexion_button_clicked();
    void on_trie_button_clicked();

    void on_consulter_employe_clicked();

private:
    Ui::gemploye *ui;
    QSqlDatabase db;
    QChartView *chartView;
    access *fenetreConnexion;
    Menu *fenetreMenu = nullptr;

    void populateTable();
    void clearFields();
    void updateStatistics();
    void updatePieChart(int type);
    bool isValidEmail(const QString &email);
    bool isValidPhoneNumber(const QString &phone);
};

#endif // GEMPLOYE_H
