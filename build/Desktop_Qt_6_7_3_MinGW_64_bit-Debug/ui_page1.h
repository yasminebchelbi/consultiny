/********************************************************************************
** Form generated from reading UI file 'page1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE1_H
#define UI_PAGE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seconnecter_button
{
public:
    QPushButton *sinscrire_button;
    QLabel *label;
    QPushButton *sinscrire_button_2;

    void setupUi(QWidget *seconnecter_button)
    {
        if (seconnecter_button->objectName().isEmpty())
            seconnecter_button->setObjectName("seconnecter_button");
        seconnecter_button->resize(1361, 879);
        seconnecter_button->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 226, 220);"));
        sinscrire_button = new QPushButton(seconnecter_button);
        sinscrire_button->setObjectName("sinscrire_button");
        sinscrire_button->setGeometry(QRect(830, 500, 201, 61));
        sinscrire_button->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 141, 177);\n"
"font: 600 12pt \"Segoe UI\";\n"
"color: rgb(38, 58, 105);"));
        label = new QLabel(seconnecter_button);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 210, 531, 471));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Desktop/Employee - Copy/image.qrc/8025532-removebg-preview.png")));
        sinscrire_button_2 = new QPushButton(seconnecter_button);
        sinscrire_button_2->setObjectName("sinscrire_button_2");
        sinscrire_button_2->setGeometry(QRect(830, 380, 201, 61));
        sinscrire_button_2->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 141, 177);\n"
"font: 600 12pt \"Segoe UI\";\n"
"color: rgb(38, 58, 105);"));

        retranslateUi(seconnecter_button);

        QMetaObject::connectSlotsByName(seconnecter_button);
    } // setupUi

    void retranslateUi(QWidget *seconnecter_button)
    {
        seconnecter_button->setWindowTitle(QCoreApplication::translate("seconnecter_button", "Form", nullptr));
        sinscrire_button->setText(QCoreApplication::translate("seconnecter_button", "S'inscrire", nullptr));
        label->setText(QString());
        sinscrire_button_2->setText(QCoreApplication::translate("seconnecter_button", "Se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seconnecter_button: public Ui_seconnecter_button {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE1_H
