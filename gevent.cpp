#include "gevent.h"
#include "ui_gevent.h"


Gevent::Gevent(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gevent)
{
    ui->setupUi(this);
}

Gevent::~Gevent()
{
    delete ui;
}
