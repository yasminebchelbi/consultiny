/********************************************************************************
** Form generated from reading UI file 'access.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESS_H
#define UI_ACCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_access
{
public:
    QFrame *frame_2;
    QLineEdit *mailconnexion;
    QLineEdit *mdpconnexion;
    QLabel *label;
    QLabel *label_2;
    QPushButton *seconnecter_button;
    QPushButton *mdpOublieBtn;
    QLabel *label_3;

    void setupUi(QWidget *access)
    {
        if (access->objectName().isEmpty())
            access->setObjectName("access");
        access->resize(1370, 869);
        access->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 227, 221);"));
        frame_2 = new QFrame(access);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(-10, 0, 1381, 721));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"  background-color: #EDECEA;\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #263A69;\n"
"}\n"
"/* Style des boutons */\n"
"QPushButton {\n"
"    background-color: #6F7DAB;\n"
"    color: #E8E3DD;\n"
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
"    font: 12pt \"The Year of The Camel\";\n"
"    font-weight: bold; \n"
"    color: #5A6A99; \n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        mailconnexion = new QLineEdit(frame_2);
        mailconnexion->setObjectName("mailconnexion");
        mailconnexion->setGeometry(QRect(700, 270, 301, 28));
        mdpconnexion = new QLineEdit(frame_2);
        mdpconnexion->setObjectName("mdpconnexion");
        mdpconnexion->setGeometry(QRect(700, 350, 301, 28));
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(700, 240, 81, 21));
        label->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(700, 320, 161, 21));
        label_2->setStyleSheet(QString::fromUtf8(""));
        seconnecter_button = new QPushButton(frame_2);
        seconnecter_button->setObjectName("seconnecter_button");
        seconnecter_button->setGeometry(QRect(750, 430, 211, 51));
        mdpOublieBtn = new QPushButton(frame_2);
        mdpOublieBtn->setObjectName("mdpOublieBtn");
        mdpOublieBtn->setGeometry(QRect(750, 500, 211, 51));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 160, 561, 381));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/image/logo (1).png")));
        label_3->setScaledContents(true);

        retranslateUi(access);

        QMetaObject::connectSlotsByName(access);
    } // setupUi

    void retranslateUi(QWidget *access)
    {
        access->setWindowTitle(QCoreApplication::translate("access", "Form", nullptr));
        label->setText(QCoreApplication::translate("access", "Email:", nullptr));
        label_2->setText(QCoreApplication::translate("access", "Mot de passe:", nullptr));
        seconnecter_button->setText(QCoreApplication::translate("access", "se connecter", nullptr));
        mdpOublieBtn->setText(QCoreApplication::translate("access", "Mot de passe oubli\303\251", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class access: public Ui_access {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESS_H
