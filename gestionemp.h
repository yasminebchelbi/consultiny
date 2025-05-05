#ifndef GESTIONEMP_H
#define GESTIONEMP_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtCharts/QChartView>

class access;

namespace Ui {
class gestionemp;
}

class gestionemp : public QDialog
{
    Q_OBJECT

public:
    explicit gestionemp(access *fenetreConnexion, QWidget *parent = nullptr);
    ~gestionemp();

private slots:
    void on_chercher_employe_clicked();
    void on_telech_employe_clicked();
    void on_statsTypeCombo_currentIndexChanged(int index);
    void on_deconnexion_button_clicked();
    void on_trie_button_clicked();

private:
    Ui::gestionemp *ui;
    QSqlDatabase db;
    QChartView *chartView;
    access *fenetreConnexion;
    void populateTable();
    void clearFields();
    void updateStatistics();
    void updatePieChart(int type);
    bool isValidEmail(const QString &email);
    bool isValidPhoneNumber(const QString &phone);
};

#endif // GESTIONEMP_H
