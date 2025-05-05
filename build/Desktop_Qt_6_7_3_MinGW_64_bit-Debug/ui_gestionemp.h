/********************************************************************************
** Form generated from reading UI file 'gestionemp.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONEMP_H
#define UI_GESTIONEMP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gestionemp
{
public:
    QFrame *frame;
    QLineEdit *lineEdit_4;
    QComboBox *trie_employe;
    QPushButton *chercher_employe;
    QPushButton *telech_employe;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *statsLayout;
    QComboBox *statsTypeCombo;
    QPushButton *deconnexion_button;
    QLabel *label;
    QTableWidget *tableview_employe;
    QPushButton *trie_button;

    void setupUi(QWidget *gestionemp)
    {
        if (gestionemp->objectName().isEmpty())
            gestionemp->setObjectName("gestionemp");
        gestionemp->resize(1389, 933);
        frame = new QFrame(gestionemp);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1651, 901));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(320, 50, 291, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        trie_employe = new QComboBox(frame);
        trie_employe->addItem(QString());
        trie_employe->addItem(QString());
        trie_employe->setObjectName("trie_employe");
        trie_employe->setGeometry(QRect(840, 60, 81, 31));
        trie_employe->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #263A69;\n"
"    background-color: #E8E3DD;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    color: black;  /* Couleur du texte des options en noir */\n"
"    background-color: #E8E3DD;  /* Conserve la couleur de fond */\n"
"    selection-background-color: #263A69;  /* Couleur de fond de l'option s\303\251lectionn\303\251e */\n"
"    selection-color: white;  /* Couleur du texte de l'option s\303\251lectionn\303\251e */\n"
"}"));
        chercher_employe = new QPushButton(frame);
        chercher_employe->setObjectName("chercher_employe");
        chercher_employe->setGeometry(QRect(620, 50, 41, 41));
        chercher_employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #1E88E5, stop:1 #0D47A1); /* D\303\251grad\303\251 de bleu */\n"
"    border: 2px solid #0D47A1;\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    text-transform: uppercase;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #0D47A1, stop:1 #1E88E5); /* Inversion du d\303\251grad\303\251 */\n"
"    border: 2px solid #1E88E5;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1565C0; /* Couleur plus fonc\303\251e au clic */\n"
"    border: 2px solid #1565C0;\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        chercher_employe->setIcon(icon);
        telech_employe = new QPushButton(frame);
        telech_employe->setObjectName("telech_employe");
        telech_employe->setGeometry(QRect(670, 50, 41, 41));
        telech_employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #6f7dab, stop:1 #3f5d7b); /* D\303\251grad\303\251 bleu fonc\303\251 */\n"
"    border: 2px solid #3f5d7b;\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    text-transform: uppercase;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #3f5d7b, stop:1 #6f7dab); /* Inversion du d\303\251grad\303\251 */\n"
"    border: 2px solid #6f7dab;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #354f73; /* Couleur plus fonc\303\251e au clic */\n"
"    border: 2px solid #354f73;\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        telech_employe->setIcon(icon1);
        telech_employe->setIconSize(QSize(30, 30));
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(320, 380, 1001, 411));
        statsLayout = new QVBoxLayout(verticalLayoutWidget);
        statsLayout->setObjectName("statsLayout");
        statsLayout->setContentsMargins(0, 0, 0, 0);
        statsTypeCombo = new QComboBox(verticalLayoutWidget);
        statsTypeCombo->setObjectName("statsTypeCombo");
        statsTypeCombo->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(0, 0, 127);\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));

        statsLayout->addWidget(statsTypeCombo);

        deconnexion_button = new QPushButton(frame);
        deconnexion_button->setObjectName("deconnexion_button");
        deconnexion_button->setGeometry(QRect(1170, 50, 141, 41));
        deconnexion_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #E53935, stop:1 #B71C1C); /* D\303\251grad\303\251 de rouge */\n"
"    border: 2px solid #B71C1C;\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    font-size: 14px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    text-transform: uppercase;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #B71C1C, stop:1 #E53935); /* Inversion du d\303\251grad\303\251 */\n"
"    border: 2px solid #E53935;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #C62828; /* Couleur plus fonc\303\251e au clic */\n"
"    border: 2px solid #C62828;\n"
"}\n"
""));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(-100, 250, 391, 331));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Desktop/Employee - Copy/image.qrc/8025532-removebg-preview.png")));
        tableview_employe = new QTableWidget(frame);
        if (tableview_employe->columnCount() < 9)
            tableview_employe->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableview_employe->setObjectName("tableview_employe");
        tableview_employe->setGeometry(QRect(320, 100, 871, 271));
        tableview_employe->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #EDECEA; /* Fond du tableau */\n"
"    border: 2px solid #838DB1; /* Bordure subtile */\n"
"    border-radius: 10px; /* Arrondi */\n"
"    gridline-color: #DCDCDA; /* Couleur des lignes du tableau */\n"
"    font-family: \"Segoe UI\", \"Arial\", sans-serif; /* Typographie moderne */\n"
"    font-size: 14px;\n"
"    selection-background-color: #838DB1; /* Couleur de s\303\251lection */\n"
"    selection-color: white; /* Texte en blanc sur s\303\251lection */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #263A69; /* En-t\303\252tes fonc\303\251s */\n"
"    color: white; /* Texte blanc */\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 6px;\n"
"    border-bottom: 1px solid #E8E3DD; /* S\303\251paration entre les lignes */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #838DB1; /* Fond des \303\251l\303\251ments s\303\251lectionn\303\251"
                        "s */\n"
"    color: white;\n"
"}\n"
""));
        tableview_employe->setRowCount(0);
        tableview_employe->setColumnCount(9);
        trie_button = new QPushButton(frame);
        trie_button->setObjectName("trie_button");
        trie_button->setGeometry(QRect(720, 60, 101, 31));
        trie_button->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 141, 177);\n"
"font: 600 12pt \"Segoe UI\";\n"
"color: rgb(38, 58, 105);"));

        retranslateUi(gestionemp);

        QMetaObject::connectSlotsByName(gestionemp);
    } // setupUi

    void retranslateUi(QWidget *gestionemp)
    {
        gestionemp->setWindowTitle(QCoreApplication::translate("gestionemp", "Form", nullptr));
        lineEdit_4->setText(QString());
        trie_employe->setItemText(0, QCoreApplication::translate("gestionemp", "plus r\303\251c.", nullptr));
        trie_employe->setItemText(1, QCoreApplication::translate("gestionemp", "plus anc.", nullptr));

        chercher_employe->setText(QString());
        telech_employe->setText(QString());
        deconnexion_button->setText(QCoreApplication::translate("gestionemp", "D\303\251connexion", nullptr));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableview_employe->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gestionemp", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableview_employe->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gestionemp", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableview_employe->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gestionemp", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableview_employe->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gestionemp", "D.naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableview_employe->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gestionemp", "Mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableview_employe->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("gestionemp", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableview_employe->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("gestionemp", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableview_employe->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("gestionemp", "D.embauche", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableview_employe->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("gestionemp", "Poste", nullptr));
        trie_button->setText(QCoreApplication::translate("gestionemp", "Trier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gestionemp: public Ui_gestionemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONEMP_H
