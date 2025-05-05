#ifndef CHANGEMDPDIALOG_H
#define CHANGEMDPDIALOG_H

#include <QDialog>

namespace Ui {
class ChangeMdpDialog;
}

class ChangeMdpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeMdpDialog(const QString &tel, QWidget *parent = nullptr);
    ~ChangeMdpDialog();

private slots:
    void on_valider_clicked();
    void on_annuler_clicked();

private:
    Ui::ChangeMdpDialog *ui;
    QString telRecup;
};

#endif // CHANGEMDPDIALOG_H
