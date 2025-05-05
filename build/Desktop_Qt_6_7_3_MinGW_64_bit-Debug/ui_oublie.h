/********************************************************************************
** Form generated from reading UI file 'oublie.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUBLIE_H
#define UI_OUBLIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_oublie
{
public:
    QPushButton *code_button;
    QLineEdit *num_recup;
    QLabel *label_9;
    QLabel *label;

    void setupUi(QWidget *oublie)
    {
        if (oublie->objectName().isEmpty())
            oublie->setObjectName("oublie");
        oublie->resize(1461, 898);
        oublie->setStyleSheet(QString::fromUtf8("background-color: rgb(232, 227, 221);"));
        code_button = new QPushButton(oublie);
        code_button->setObjectName("code_button");
        code_button->setGeometry(QRect(870, 510, 201, 61));
        code_button->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 141, 177);\n"
"font: 600 12pt \"Segoe UI\";\n"
"color: rgb(38, 58, 105);"));
        num_recup = new QLineEdit(oublie);
        num_recup->setObjectName("num_recup");
        num_recup->setGeometry(QRect(770, 390, 421, 51));
        num_recup->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: white\n"
";\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        label_9 = new QLabel(oublie);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(770, 330, 271, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Malgun Gothic")});
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(37, 57, 103);\n"
""));
        label = new QLabel(oublie);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 130, 481, 451));
        label->setPixmap(QPixmap(QString::fromUtf8("image/logo (1).png")));

        retranslateUi(oublie);

        QMetaObject::connectSlotsByName(oublie);
    } // setupUi

    void retranslateUi(QWidget *oublie)
    {
        oublie->setWindowTitle(QCoreApplication::translate("oublie", "Form", nullptr));
        code_button->setText(QCoreApplication::translate("oublie", "Envoyer un code ", nullptr));
        num_recup->setText(QString());
        label_9->setText(QCoreApplication::translate("oublie", "Entrer votre numero", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class oublie: public Ui_oublie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUBLIE_H
