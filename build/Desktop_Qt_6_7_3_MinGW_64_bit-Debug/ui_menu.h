/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QFrame *frame_2;
    QLabel *label_12;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *se_deconnecter;
    QPushButton *Gemploye;
    QPushButton *Gclient;
    QPushButton *Gprojet;
    QPushButton *Gevenement;
    QPushButton *Gressource;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(1951, 901);
        frame_2 = new QFrame(Menu);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, -10, 1411, 711));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"  background-color: #EDECEA;\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #263A69;\n"
"}\n"
"/* Style des boutons */\n"
"QPushButton {\n"
"    font-size: 14px;\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    color: #263A69;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}\n"
"QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
"QLabel {\n"
"    font: 30pt \"The Year of The Camel\";\n"
"    font-weight: bold; \n"
"    color: #5A6A99; \n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(860, 520, 231, 241));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/8025532-removebg-preview.png")));
        label_12->setScaledContents(true);
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(280, 590, 271, 61));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(890, 590, 271, 61));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(1140, 310, 161, 61));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(640, 310, 161, 61));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(90, 310, 211, 61));
        se_deconnecter = new QPushButton(frame_2);
        se_deconnecter->setObjectName("se_deconnecter");
        se_deconnecter->setGeometry(QRect(30, 20, 111, 111));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/2-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        se_deconnecter->setIcon(icon);
        se_deconnecter->setIconSize(QSize(100, 100));
        Gemploye = new QPushButton(frame_2);
        Gemploye->setObjectName("Gemploye");
        Gemploye->setGeometry(QRect(120, 110, 161, 251));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/3-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Gemploye->setIcon(icon1);
        Gemploye->setIconSize(QSize(200, 200));
        Gclient = new QPushButton(frame_2);
        Gclient->setObjectName("Gclient");
        Gclient->setGeometry(QRect(630, 130, 161, 251));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/6-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Gclient->setIcon(icon2);
        Gclient->setIconSize(QSize(200, 200));
        Gprojet = new QPushButton(frame_2);
        Gprojet->setObjectName("Gprojet");
        Gprojet->setGeometry(QRect(1140, 110, 161, 251));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/5-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Gprojet->setIcon(icon3);
        Gprojet->setIconSize(QSize(200, 200));
        Gevenement = new QPushButton(frame_2);
        Gevenement->setObjectName("Gevenement");
        Gevenement->setGeometry(QRect(270, 390, 281, 251));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/7-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Gevenement->setIcon(icon4);
        Gevenement->setIconSize(QSize(200, 200));
        Gressource = new QPushButton(frame_2);
        Gressource->setObjectName("Gressource");
        Gressource->setGeometry(QRect(840, 390, 281, 251));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/4-removebg-preview.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Gressource->setIcon(icon5);
        Gressource->setIconSize(QSize(200, 200));

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Form", nullptr));
        label_12->setText(QString());
        label_5->setText(QCoreApplication::translate("Menu", "Ev\303\251nements", nullptr));
        label_10->setText(QCoreApplication::translate("Menu", "Ressources", nullptr));
        label_11->setText(QCoreApplication::translate("Menu", "Projets", nullptr));
        label_13->setText(QCoreApplication::translate("Menu", "Clients", nullptr));
        label_14->setText(QCoreApplication::translate("Menu", "Employ\303\251s", nullptr));
        se_deconnecter->setText(QString());
        Gemploye->setText(QString());
        Gclient->setText(QString());
        Gprojet->setText(QString());
        Gevenement->setText(QString());
        Gressource->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
