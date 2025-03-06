/********************************************************************************
** Form generated from reading UI file 'gprojet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPROJET_H
#define UI_GPROJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gprojet
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit_4;
    QLabel *label_10;
    QComboBox *comboBox_3;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_12;
    QFrame *frame_4;
    QLabel *label_3;
    QPushButton *pushButton_7;
    QLabel *label_14;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_17;
    QLabel *label_22;
    QWidget *tab_2;
    QLabel *label_15;
    QFrame *frame_3;
    QLabel *label_7;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_12;
    QLabel *label_16;
    QPushButton *pushButton_8;
    QFrame *frame_2;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_28;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gprojet)
    {
        if (Gprojet->objectName().isEmpty())
            Gprojet->setObjectName("Gprojet");
        Gprojet->resize(1032, 612);
        centralwidget = new QWidget(Gprojet);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 0, 1111, 581));
        tabWidget->setStyleSheet(QString::fromUtf8("/* Style du QTabWidget */\n"
"QTabWidget::pane {\n"
"    border: 1px solid ;\n"
"    background-color:#dcdcda\n"
"   \n"
"}\n"
"\n"
"/* Style des onglets */\n"
"QTabBar::tab {\n"
"    background: #6F7DAB;\n"
"    color: #E8E3DD;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    padding: 8px 15px;\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background:  #DCDCDA;\n"
"    color: #263A69;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 50, 321, 461));
        frame->setStyleSheet(QString::fromUtf8("QWidget { \n"
"    background-color: #EDECEA;\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #263A69;\n"
"}\n"
"\n"
"/* Style des boutons */\n"
"QPushButton {\n"
"    background-color: #6F7DAB;\n"
"    color: #E8E3DD;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E8E3DD;\n"
"    color: #263A69;\n"
"}\n"
"\n"
"/* Style des labels */\n"
"QLabel {\n"
"    font: 12pt \"The Year of The Camel\";\n"
"    font-weight: bold; \n"
"    color: #5A6A99; \n"
"}\n"
"\n"
"/* Style des menus d\303\251roulants */\n"
"QComboBox {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #263A69;\n"
"    background-color: #E8E3DD;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"/* Style des champs de texte */\n"
"QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    b"
                        "ackground-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
"QSpinBox {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #263A69;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"}\n"
"QDateTimeEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    color: #263A69;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
"\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 63, 20));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 91, 20));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 80, 81, 20));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 110, 63, 20));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 210, 91, 20));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 140, 81, 20));
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 170, 91, 20));
        dateTimeEdit = new QDateTimeEdit(frame);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(120, 50, 181, 29));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 20, 181, 28));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 420, 83, 29));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 420, 83, 29));
        plainTextEdit = new QPlainTextEdit(frame);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(120, 210, 181, 201));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(120, 140, 181, 28));
        lineEdit_5 = new QLineEdit(frame);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(120, 170, 181, 28));
        lineEdit_6 = new QLineEdit(frame);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(120, 80, 181, 28));
        lineEdit_7 = new QLineEdit(frame);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(120, 110, 181, 28));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(340, 80, 651, 241));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableView {\n"
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
"}"));
        tableWidget->setRowCount(7);
        tableWidget->setColumnCount(7);
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(340, 20, 201, 28));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit#searchBar {\n"
"    border: 2px solid #AAAAAA;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QLineEdit#searchBar:hover {\n"
"    border: 2px solid #1E90FF;\n"
"}"));
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(860, 10, 71, 21));
        label_10->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Times New Roman\";"));
        comboBox_3 = new QComboBox(tab);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(920, 10, 82, 28));
        comboBox_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"font: 9pt \"Times New Roman\";"));
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(850, 510, 191, 171));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/image.qrc/8025532-removebg-preview.png")));
        label_13->setScaledContents(true);
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(540, 20, 51, 31));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/Users/HP/Downloads/loupe-et-icone-de-recherche-de-couleur-grise.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(390, 370, 49, 16));
        frame_4 = new QFrame(tab);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(350, 360, 531, 181));
        frame_4->setStyleSheet(QString::fromUtf8("/* Style pour le QFrame avec fond fonc\303\251 et bords arrondis */\n"
"QFrame {\n"
"    background-color:  #6f7dab; /* Couleur de fond fonc\303\251e */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"}\n"
"\n"
"/* Style pour les QLabel */\n"
"QLabel {\n"
"    font-family: \"Arial\", sans-serif; /* Police moderne */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    color: #EDECEA; /* Texte clair pour contraste */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de contour */\n"
"    background: none; /* Pas de fond */\n"
"}\n"
""));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 10, 231, 21));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(60, 10, 201, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 11pt \"Times New Roman\";\n"
"	\n"
"\n"
"    background-color: #6F7DAB;\n"
"    color: #E8E3DD;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E8E3DD;\n"
"    color: #263A69;\n"
"}\n"
"\n"
""));
        label_14 = new QLabel(tab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(860, 450, 171, 91));
        label_14->setStyleSheet(QString::fromUtf8("QLabel#logoLabel {\n"
"    border: none;\n"
"    background: transparent;\n"
"}"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Users/HP/Downloads/8025532-removebg-preview.png")));
        label_14->setScaledContents(true);
        label_18 = new QLabel(tab);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(650, 10, 31, 41));
        label_18->setPixmap(QPixmap(QString::fromUtf8(":/image/update4.png")));
        label_18->setScaledContents(true);
        label_19 = new QLabel(tab);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(730, 10, 31, 31));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/image/supprimer.png")));
        label_19->setScaledContents(true);
        label_17 = new QLabel(tab);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(690, 10, 31, 41));
        label_17->setPixmap(QPixmap(QString::fromUtf8(":/image/enregistrer.png")));
        label_17->setScaledContents(true);
        label_22 = new QLabel(tab);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(770, 10, 31, 51));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/image/historique.png")));
        label_22->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_15 = new QLabel(tab_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(860, 460, 181, 91));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/Users/HP/Downloads/8025532-removebg-preview.png")));
        label_15->setScaledContents(true);
        frame_3 = new QFrame(tab_2);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(40, 70, 481, 371));
        frame_3->setStyleSheet(QString::fromUtf8("/* Style pour le QFrame avec fond fonc\303\251 et bords arrondis */\n"
"QFrame {\n"
"    background-color:  #6f7dab; /* Couleur de fond fonc\303\251e */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"}\n"
"\n"
"/* Style pour les QLabel */\n"
"QLabel {\n"
"    font-family: \"Arial\", sans-serif; /* Police moderne */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    color: #EDECEA; /* Texte clair pour contraste */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de contour */\n"
"    background: none; /* Pas de fond */\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 50, 81, 16));
        label_20 = new QLabel(frame_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(30, 80, 81, 16));
        label_21 = new QLabel(frame_3);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 110, 81, 16));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(90, 106, 153);\n"
"color: rgb(255, 255, 255);"));
        lineEdit_8 = new QLineEdit(frame_3);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(20, 130, 431, 171));
        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 50, 113, 22));
        lineEdit_12 = new QLineEdit(frame_3);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(120, 80, 113, 22));
        label_16 = new QLabel(frame_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(130, 10, 241, 31));
        pushButton_8 = new QPushButton(frame_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(314, 330, 111, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 11pt \"Times New Roman\";\n"
"	\n"
"\n"
"    background-color: #6F7DAB;\n"
"    color: #E8E3DD;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 14px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #E8E3DD;\n"
"    color: #263A69;\n"
"}\n"
"\n"
""));
        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(560, 80, 291, 341));
        frame_2->setStyleSheet(QString::fromUtf8("/* Style pour le QFrame avec fond fonc\303\251 et bords arrondis */\n"
"QFrame {\n"
"    background-color:  #6f7dab; /* Couleur de fond fonc\303\251e */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"}\n"
"\n"
"/* Style pour les QLabel */\n"
"QLabel {\n"
"    font-family: \"Arial\", sans-serif; /* Police moderne */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    color: #EDECEA; /* Texte clair pour contraste */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de contour */\n"
"    background: none; /* Pas de fond */\n"
"}\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_29 = new QLabel(frame_2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(10, 40, 49, 16));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Times New Roman\";"));
        label_30 = new QLabel(frame_2);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(10, 70, 141, 16));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Times New Roman\";"));
        label_31 = new QLabel(frame_2);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 100, 151, 16));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Times New Roman\";"));
        label_28 = new QLabel(frame_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(40, 10, 171, 20));
        label_28->setStyleSheet(QString::fromUtf8(""));
        lineEdit_9 = new QLineEdit(frame_2);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(140, 40, 113, 22));
        lineEdit_14 = new QLineEdit(frame_2);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(140, 70, 113, 22));
        lineEdit_15 = new QLineEdit(frame_2);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(50, 130, 211, 191));
        tabWidget->addTab(tab_2, QString());
        Gprojet->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gprojet);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1032, 22));
        Gprojet->setMenuBar(menubar);
        statusbar = new QStatusBar(Gprojet);
        statusbar->setObjectName("statusbar");
        Gprojet->setStatusBar(statusbar);

        retranslateUi(Gprojet);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Gprojet);
    } // setupUi

    void retranslateUi(QMainWindow *Gprojet)
    {
        Gprojet->setWindowTitle(QCoreApplication::translate("Gprojet", "Gprojet", nullptr));
        label->setText(QCoreApplication::translate("Gprojet", "Nom:", nullptr));
        label_2->setText(QCoreApplication::translate("Gprojet", "Date d\303\251but:", nullptr));
        label_4->setText(QCoreApplication::translate("Gprojet", "Budget:", nullptr));
        label_5->setText(QCoreApplication::translate("Gprojet", "Secteur:", nullptr));
        label_6->setText(QCoreApplication::translate("Gprojet", "Description:", nullptr));
        label_8->setText(QCoreApplication::translate("Gprojet", "Co\303\273t:", nullptr));
        label_9->setText(QCoreApplication::translate("Gprojet", "Adresse:", nullptr));
        pushButton->setText(QCoreApplication::translate("Gprojet", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Gprojet", "Annuler", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Gprojet", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Gprojet", "Date D\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Gprojet", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Gprojet", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Gprojet", "cout", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Gprojet", "Secteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Gprojet", "Budget", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Gprojet", "Recherche par status", nullptr));
        label_10->setText(QCoreApplication::translate("Gprojet", "Trier par", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Gprojet", "Nom", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Gprojet", "Date D\303\251but", nullptr));

        label_13->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_3->setText(QCoreApplication::translate("Gprojet", "Nombre des projets mensuelle:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Gprojet", "Consulter le menu", nullptr));
        label_14->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        label_17->setText(QString());
        label_22->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Gprojet", "Gestion des projets", nullptr));
        label_15->setText(QString());
        label_7->setText(QCoreApplication::translate("Gprojet", "Nom projet:", nullptr));
        label_20->setText(QCoreApplication::translate("Gprojet", "Id_projet", nullptr));
        label_21->setText(QString());
        label_16->setText(QCoreApplication::translate("Gprojet", "Des conseils g\303\251n\303\251r\303\251s avec l'IA", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Gprojet", "G\303\251n\303\251rer ", nullptr));
        label_29->setText(QCoreApplication::translate("Gprojet", "Date:", nullptr));
        label_30->setText(QCoreApplication::translate("Gprojet", "Nom de l'employ\303\251:", nullptr));
        label_31->setText(QCoreApplication::translate("Gprojet", "Les d\303\251tails de projet:", nullptr));
        label_28->setText(QCoreApplication::translate("Gprojet", "       Historique du projet           ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Gprojet", "Gestion des m\303\251tiers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gprojet: public Ui_Gprojet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPROJET_H
