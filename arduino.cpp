#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QSqlQuery>
#include <QSqlError>


Arduino::Arduino()
{
    data1="";
    arduino_port_name1="";
    arduino_is_available1=false;
    serial1=new QSerialPort;
}

QString Arduino::getarduino_port_name1()
{
    return arduino_port_name1;
}

QSerialPort *Arduino::getserial1()
{
    return serial1;
}
int Arduino::connect_arduino1()

{
    const quint16 arduino_uno_vendor_id = 0x2341;
    const quint16 arduino_uno_product_id = 0x0043;

    const quint16 ch340_vendor_id = 0x1A86;
    const quint16 ch340_product_id = 0x7523;
    // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            qDebug() << "Détection port :" << serial_port_info.portName()
                     << "- VID:" << QString::number(serial_port_info.vendorIdentifier(), 16)
                     << "- PID:" << QString::number(serial_port_info.productIdentifier(), 16);

            if ((serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_product_id) ||
                (serial_port_info.vendorIdentifier() == ch340_vendor_id && serial_port_info.productIdentifier() == ch340_product_id)) {

                arduino_is_available1 = true;
                arduino_port_name1 = serial_port_info.portName();
                break;
            }
        }
    }

    qDebug() << "arduino_port_name is :" << arduino_port_name1;
    if(arduino_is_available1){ // configuration de la communication ( débit...)
        serial1->setPortName(arduino_port_name1);
        if(serial1->open(QSerialPort::ReadWrite)){
            serial1->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
            serial1->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
            serial1->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
            serial1->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
            serial1->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int Arduino::close_arduino1()

{

    if(serial1->isOpen()){
        serial1->close();
        return 0;
    }
    return 1;


}

void Arduino::readFromArduino() {
    QByteArray receivedData = serial1->readAll();  // Lire les données envoyées par Qt
    QString uid = QString(receivedData).trimmed();

    // Débogage : afficher l'UID reçu
    qDebug() << "UID reçu : " << uid;

    // Vérification de l'UID dans la base de données
    QString reponse = verifierUID(uid);  // Appel de la méthode de vérification
    qDebug() << "Réponse envoyée : " << reponse;

    // Envoi de la réponse à Arduino
    write_to_arduino1(reponse.toUtf8() + "\n");
}


QString Arduino::verifierUID(QString uid) {

    // Vérification de l'UID dans la table "projet"
    QSqlQuery query;
    query.prepare("SELECT nom_employe , prenom_employe FROM employes WHERE code = :code");
    query.bindValue(":code", uid);

    if (query.exec() && query.next()) {
        QString nom_employe = query.value(0).toString();
        QString prenom_employe = query.value(1).toString();
        qDebug() << "Nom du employé trouvé : " << nom_employe;
        return "WELCOME:" + nom_employe +" "+ prenom_employe;
    } else {
        qDebug() << "Erreur lors de la vérification UID:" << query.lastError().text();
        return "DENIED";
    }
}






void Arduino::write_to_arduino1( QByteArray d)

{

    if(serial1->isWritable()){
        serial1->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
