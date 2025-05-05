#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino
{
public:     // méthodes de la classe Arduino
    Arduino();
    int connect_arduino1(); // permet de connecter le PC à Arduino
    int close_arduino1();   // permet de fermer la connexion
    void write_to_arduino1(QByteArray); // envoyer des données vers Arduino
    void readFromArduino();            // recevoir des données de la carte Arduino
    QSerialPort* getserial1();           // accesseur
    QString getarduino_port_name1();
    QString verifierUID(QString uid);   // <<< AJOUT ici

private:
    QSerialPort *serial1; // objet de la voie série pour Arduino
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name1;
    bool arduino_is_available1;
    QByteArray data1;  // contenant les données lues à partir d'Arduino
};

#endif // ARDUINO_H
