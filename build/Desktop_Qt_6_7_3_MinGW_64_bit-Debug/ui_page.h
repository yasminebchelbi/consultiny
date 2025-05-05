/********************************************************************************
** Form generated from reading UI file 'page.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_H
#define UI_PAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_page
{
public:
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QPushButton *telech_employe2;
    QPushButton *chercher_employe2;
    QLineEdit *lineEdit_4_2;
    QComboBox *trie_employe;
    QLabel *label_13;
    QLabel *label;
    QTableWidget *tableview_employe2;
    QVBoxLayout *statsLayout2;
    QComboBox *statsTypeCombo2;

    void setupUi(QDialog *page)
    {
        if (page->objectName().isEmpty())
            page->setObjectName("page");
        page->resize(1412, 800);
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 524, 1019));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        telech_employe2 = new QPushButton(frame);
        telech_employe2->setObjectName("telech_employe2");
        telech_employe2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        telech_employe2->setIcon(icon);
        telech_employe2->setIconSize(QSize(30, 30));

        verticalLayout_2->addWidget(telech_employe2);

        chercher_employe2 = new QPushButton(frame);
        chercher_employe2->setObjectName("chercher_employe2");
        chercher_employe2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        chercher_employe2->setIcon(icon1);

        verticalLayout_2->addWidget(chercher_employe2);

        lineEdit_4_2 = new QLineEdit(frame);
        lineEdit_4_2->setObjectName("lineEdit_4_2");
        lineEdit_4_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));

        verticalLayout_2->addWidget(lineEdit_4_2);

        trie_employe = new QComboBox(frame);
        trie_employe->addItem(QString());
        trie_employe->addItem(QString());
        trie_employe->setObjectName("trie_employe");
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

        verticalLayout_2->addWidget(trie_employe);

        label_13 = new QLabel(frame);
        label_13->setObjectName("label_13");
        QFont font;
        font.setPointSize(14);
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(37, 57, 103);"));

        verticalLayout_2->addWidget(label_13);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setMinimumSize(QSize(391, 541));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Desktop/Employee - Copy/image.qrc/8025532-removebg-preview.png")));

        verticalLayout_2->addWidget(label);

        tableview_employe2 = new QTableWidget(frame);
        if (tableview_employe2->columnCount() < 10)
            tableview_employe2->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableview_employe2->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableview_employe2->setObjectName("tableview_employe2");
        tableview_employe2->setStyleSheet(QString::fromUtf8("QTableView {\n"
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
        tableview_employe2->setRowCount(0);
        tableview_employe2->setColumnCount(10);

        verticalLayout_2->addWidget(tableview_employe2);

        statsLayout2 = new QVBoxLayout();
        statsLayout2->setObjectName("statsLayout2");
        statsTypeCombo2 = new QComboBox(frame);
        statsTypeCombo2->setObjectName("statsTypeCombo2");
        statsTypeCombo2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        statsLayout2->addWidget(statsTypeCombo2);


        verticalLayout_2->addLayout(statsLayout2);


        retranslateUi(page);

        QMetaObject::connectSlotsByName(page);
    } // setupUi

    void retranslateUi(QDialog *page)
    {
        page->setWindowTitle(QCoreApplication::translate("page", "Page Employ\303\251", nullptr));
        telech_employe2->setText(QString());
        chercher_employe2->setText(QString());
        lineEdit_4_2->setText(QString());
        trie_employe->setItemText(0, QCoreApplication::translate("page", "plus r\303\251c.", nullptr));
        trie_employe->setItemText(1, QCoreApplication::translate("page", "plus anc.", nullptr));

        label_13->setText(QCoreApplication::translate("page", "Trier ", nullptr));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableview_employe2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("page", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableview_employe2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("page", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableview_employe2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("page", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableview_employe2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("page", "D.naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableview_employe2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("page", "Mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableview_employe2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("page", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableview_employe2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("page", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableview_employe2->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("page", "D.embauche", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableview_employe2->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("page", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableview_employe2->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("page", "Salaire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page: public Ui_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_H
