#include "gprojet.h"
#include "ui_gprojet.h"

Gprojet::Gprojet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gprojet)
{
    ui->setupUi(this);
}

Gprojet::~Gprojet()
{
    delete ui;
}




void Gprojet::on_pushButton_clicked()
{
    int id_projet=ui->line
}

