#ifndef GEVENT_H
#define GEVENT_H

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


private:
    Ui::Gevent *ui;

};
#endif // GEVENT_H
