#ifndef OUBLIE_H
#define OUBLIE_H

#include <QDialog>
#include <QString>

namespace Ui {
class oublie;
}

class oublie : public QDialog
{
    Q_OBJECT

public:
    explicit oublie(QWidget *parent = nullptr);
    ~oublie();

private slots:
    void on_code_button_clicked();

private:
    Ui::oublie *ui;
    int codeRecup; // Stocke le code généré
    QString telRecup; // Stocke le numéro de téléphone de récupération
    void envoyerSmsRecup(const QString &numero, int code); // Nouvelle méthode SMS
    void ouvrirFenetreCode();
};

#endif // OUBLIE_H
