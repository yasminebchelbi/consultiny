#include "arduino.h"
#include <QThread>  // Add this line
Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
    return serial;
}
int Arduino::connect_arduino()
{
    const quint16 arduino_uno_vendor_id = 0x2341;
    const quint16 arduino_uno_product_id = 0x0043;
    const quint16 ch340_vendor_id = 0x1A86;
    const quint16 ch340_product_id = 0x7523;

    // Recherche du port sur lequel la carte Arduino est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            qDebug() << "Détection port :" << serial_port_info.portName()
                     << "- VID:" << QString::number(serial_port_info.vendorIdentifier(), 16)
                     << "- PID:" << QString::number(serial_port_info.productIdentifier(), 16);

            if ((serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_product_id) ||
                (serial_port_info.vendorIdentifier() == ch340_vendor_id && serial_port_info.productIdentifier() == ch340_product_id)) {

                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
                break;
            }
        }
    }

    qDebug() << "arduino_port_name is :" << arduino_port_name;

    if (arduino_is_available) {
        // Tentative d'ouvrir le port série
        serial->setPortName(arduino_port_name);

        // Vérifier si le port est déjà ouvert par une autre application
        if (serial->isOpen()) {
            qDebug() << "Le port est déjà ouvert, tentative de fermeture.";
            serial->close();
        }

        // Essayer d'ouvrir le port série
        if (!serial->open(QSerialPort::ReadWrite)) {
            qDebug() << "Échec de l'ouverture du port série : " << serial->errorString();
            return 1; // Échec de l'ouverture du port
        }

        qDebug() << "Port série ouvert avec succès";

        serial->setBaudRate(QSerialPort::Baud9600); // Débit : 9600 bits/s
        serial->setDataBits(QSerialPort::Data8); // Longueur des données : 8 bits
        serial->setParity(QSerialPort::NoParity); // 1 bit de parité optionnel
        serial->setStopBits(QSerialPort::OneStop); // Nombre de bits de stop : 1
        serial->setFlowControl(QSerialPort::NoFlowControl);

        // Attendre un moment pour laisser Arduino le temps de répondre
        QThread::msleep(500);  // Attente de 500ms

        return 0; // Succès
    }

    return -1; // Aucun port disponible
}


int Arduino::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}


QByteArray Arduino::read_from_arduino()
{
    QByteArray data;


    if (serial->waitForReadyRead(100)) { // attend 100ms une réponse
        data = serial->readAll();

        while (serial->waitForReadyRead(10)) {
            data += serial->readAll(); // lire tout ce qui arrive
        }
    }

    return data;
}



void Arduino::write_to_arduino(QByteArray d)
{
    qDebug() << "Vérification de l'état du port série...";
    qDebug() << "Port série ouvert:" << getserial()->isOpen();
    qDebug() << "Port série accessible en écriture:" << getserial()->isWritable();

    // Vérification d'abord si le port série est bien ouvert et en écriture
    if (serial->isOpen() && serial->isWritable()) {
        qDebug() << "Port série valide, envoi des données : " << d;
        serial->write(d);

        // Attendre un peu pour donner à l'Arduino le temps de traiter la commande
        QThread::msleep(500); // Attente de 500ms
    } else {
        qDebug() << "Port série fermé ou non accessible en écriture!";
    }
}




void Arduino::startVote(QString eventName, int maxParticipants) {
    if (serial->isWritable()) {
        QString message = QString("START:%1:%2\n").arg(eventName).arg(maxParticipants);
        serial->write(message.toUtf8());
        qDebug() << "Message envoyé à l'Arduino :" << message;
    } else {
        qDebug() << "Port série non accessible en écriture !";
    }
}
