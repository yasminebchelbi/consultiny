#ifndef GPROJET_H
#define GPROJET_H

#include <QMainWindow>

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Gprojet *ui;
};
#endif // GPROJET_H
