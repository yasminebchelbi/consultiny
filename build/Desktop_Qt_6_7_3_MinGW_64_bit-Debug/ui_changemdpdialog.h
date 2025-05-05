/********************************************************************************
** Form generated from reading UI file 'changemdpdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEMDPDIALOG_H
#define UI_CHANGEMDPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChangeMdpDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nouveauMdpEdit;
    QLineEdit *confirmerMdpEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *validerButton;
    QPushButton *annulerButton;

    void setupUi(QDialog *ChangeMdpDialog)
    {
        if (ChangeMdpDialog->objectName().isEmpty())
            ChangeMdpDialog->setObjectName("ChangeMdpDialog");
        ChangeMdpDialog->resize(350, 180);
        verticalLayout = new QVBoxLayout(ChangeMdpDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ChangeMdpDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        nouveauMdpEdit = new QLineEdit(ChangeMdpDialog);
        nouveauMdpEdit->setObjectName("nouveauMdpEdit");
        nouveauMdpEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(nouveauMdpEdit);

        confirmerMdpEdit = new QLineEdit(ChangeMdpDialog);
        confirmerMdpEdit->setObjectName("confirmerMdpEdit");
        confirmerMdpEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(confirmerMdpEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        validerButton = new QPushButton(ChangeMdpDialog);
        validerButton->setObjectName("validerButton");

        horizontalLayout->addWidget(validerButton);

        annulerButton = new QPushButton(ChangeMdpDialog);
        annulerButton->setObjectName("annulerButton");

        horizontalLayout->addWidget(annulerButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChangeMdpDialog);

        QMetaObject::connectSlotsByName(ChangeMdpDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeMdpDialog)
    {
        ChangeMdpDialog->setWindowTitle(QCoreApplication::translate("ChangeMdpDialog", "Changer le mot de passe", nullptr));
        label->setText(QCoreApplication::translate("ChangeMdpDialog", "Veuillez entrer votre nouveau mot de passe :", nullptr));
        nouveauMdpEdit->setPlaceholderText(QCoreApplication::translate("ChangeMdpDialog", "Nouveau mot de passe", nullptr));
        confirmerMdpEdit->setPlaceholderText(QCoreApplication::translate("ChangeMdpDialog", "Confirmer nouveau mot de passe", nullptr));
        validerButton->setText(QCoreApplication::translate("ChangeMdpDialog", "Valider", nullptr));
        annulerButton->setText(QCoreApplication::translate("ChangeMdpDialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeMdpDialog: public Ui_ChangeMdpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEMDPDIALOG_H
