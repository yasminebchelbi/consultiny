/********************************************************************************
** Form generated from reading UI file 'gemploye.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEMPLOYE_H
#define UI_GEMPLOYE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gemploye
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *lineEdit_4;
    QTableWidget *tableview_employe;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *ajouter_employe;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_11;
    QLineEdit *id_employe;
    QLabel *label_12;
    QDateTimeEdit *date_naissance_employe;
    QPushButton *annuler_employe;
    QLineEdit *nom_employe;
    QLineEdit *prenom_employe;
    QLineEdit *adresse_employe;
    QLineEdit *mail_employe;
    QDateTimeEdit *date_embauche_employe;
    QLineEdit *poste_employe;
    QLineEdit *salaire_employe;
    QLineEdit *numero_employe;
    QComboBox *trie_employe;
    QPushButton *supprimer_employe;
    QPushButton *chercher_employe;
    QPushButton *modifier_employe;
    QPushButton *telech_employe;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *statsLayout;
    QComboBox *statsTypeCombo;
    QPushButton *deconnexion_button;
    QPushButton *trie_button;
    QLabel *label_10;
    QPushButton *consulter_employe;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gemploye)
    {
        if (gemploye->objectName().isEmpty())
            gemploye->setObjectName("gemploye");
        gemploye->resize(1440, 889);
        centralwidget = new QWidget(gemploye);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, -20, 1651, 901));
        frame->setStyleSheet(QString::fromUtf8("/* Style du QTabWidget */\n"
"QFrame::pane {\n"
"    border: 1px solid ;\n"
"    background-color:#DCDCDA;\n"
"   \n"
"}\n"
"\n"
"/* Style des onglets */\n"
"QFrame::tab {\n"
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
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(370, 30, 241, 41));
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
        tableview_employe = new QTableWidget(frame);
        if (tableview_employe->columnCount() < 10)
            tableview_employe->setColumnCount(10);
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
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableview_employe->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableview_employe->setObjectName("tableview_employe");
        tableview_employe->setGeometry(QRect(370, 80, 951, 271));
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
        tableview_employe->setColumnCount(10);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 90, 351, 631));
        frame_2->setStyleSheet(QString::fromUtf8("QWidget { \n"
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
"\n"
"\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 110, 81, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 340, 181, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        ajouter_employe = new QPushButton(frame_2);
        ajouter_employe->setObjectName("ajouter_employe");
        ajouter_employe->setGeometry(QRect(40, 590, 121, 29));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 170, 81, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 230, 101, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 400, 171, 20));
        label_6->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 460, 171, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 520, 171, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        label = new QLabel(frame_2);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 81, 21));
        label->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 0, 81, 21));
        label_11->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Times New Roman\";\n"
"font: 700 14pt \"Times New Roman\";"));
        id_employe = new QLineEdit(frame_2);
        id_employe->setObjectName("id_employe");
        id_employe->setGeometry(QRect(20, 20, 301, 31));
        id_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 280, 181, 20));
        label_12->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));
        date_naissance_employe = new QDateTimeEdit(frame_2);
        date_naissance_employe->setObjectName("date_naissance_employe");
        date_naissance_employe->setGeometry(QRect(20, 310, 311, 31));
        date_naissance_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        annuler_employe = new QPushButton(frame_2);
        annuler_employe->setObjectName("annuler_employe");
        annuler_employe->setGeometry(QRect(210, 590, 111, 29));
        nom_employe = new QLineEdit(frame_2);
        nom_employe->setObjectName("nom_employe");
        nom_employe->setGeometry(QRect(20, 80, 301, 31));
        nom_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        prenom_employe = new QLineEdit(frame_2);
        prenom_employe->setObjectName("prenom_employe");
        prenom_employe->setGeometry(QRect(20, 140, 301, 31));
        prenom_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        adresse_employe = new QLineEdit(frame_2);
        adresse_employe->setObjectName("adresse_employe");
        adresse_employe->setGeometry(QRect(20, 200, 301, 31));
        adresse_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        mail_employe = new QLineEdit(frame_2);
        mail_employe->setObjectName("mail_employe");
        mail_employe->setGeometry(QRect(20, 250, 301, 31));
        mail_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        date_embauche_employe = new QDateTimeEdit(frame_2);
        date_embauche_employe->setObjectName("date_embauche_employe");
        date_embauche_employe->setGeometry(QRect(20, 370, 311, 31));
        date_embauche_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        poste_employe = new QLineEdit(frame_2);
        poste_employe->setObjectName("poste_employe");
        poste_employe->setGeometry(QRect(20, 430, 311, 31));
        poste_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        salaire_employe = new QLineEdit(frame_2);
        salaire_employe->setObjectName("salaire_employe");
        salaire_employe->setGeometry(QRect(20, 490, 311, 31));
        salaire_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}\n"
""));
        numero_employe = new QLineEdit(frame_2);
        numero_employe->setObjectName("numero_employe");
        numero_employe->setGeometry(QRect(20, 550, 311, 31));
        numero_employe->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        trie_employe->setGeometry(QRect(980, 30, 161, 41));
        trie_employe->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #E8E3DD; /* Couleur de fond clair */\n"
"    border: 2px solid #D1C8B9; /* Bordure subtile */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 5px 15px; /* Espacement interne */\n"
"    font-size: 14px; /* Taille de texte */\n"
"    color: #4B4B4B; /* Couleur du texte */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #D1C8B9; /* Changement de couleur au survol */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 2px solid #A89F92; /* Bordure plus fonc\303\251e au focus */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FFF; /* Couleur de fond du menu d\303\251roulant */\n"
"    border: 2px solid #D1C8B9;\n"
"    border-radius: 10px;\n"
"    selection-background-color: #D1C8B9; /* Couleur de s\303\251lection des \303\251l\303\251ments */\n"
"    selection-color: #4B4B4B; /* Couleur du texte s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/arrow.png)"
                        "; /* Ic\303\264ne de fl\303\250che personnalis\303\251e */\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
""));
        supprimer_employe = new QPushButton(frame);
        supprimer_employe->setObjectName("supprimer_employe");
        supprimer_employe->setGeometry(QRect(720, 30, 41, 41));
        supprimer_employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        supprimer_employe->setIcon(icon);
        chercher_employe = new QPushButton(frame);
        chercher_employe->setObjectName("chercher_employe");
        chercher_employe->setGeometry(QRect(620, 30, 41, 41));
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
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        chercher_employe->setIcon(icon1);
        modifier_employe = new QPushButton(frame);
        modifier_employe->setObjectName("modifier_employe");
        modifier_employe->setGeometry(QRect(820, 30, 41, 41));
        modifier_employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #0daa90, stop:1 #388E3C); /* D\303\251grad\303\251 de vert */\n"
"    border: 2px solid #388E3C;\n"
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
"                stop:0 #388E3C, stop:1 #4CAF50); /* Inversion du d\303\251grad\303\251 */\n"
"    border: 2px solid #4CAF50;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2E7D32; /* Couleur plus fonc\303\251e au clic */\n"
"    border: 2px solid #2E7D32;\n"
"}"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        modifier_employe->setIcon(icon2);
        modifier_employe->setIconSize(QSize(30, 30));
        telech_employe = new QPushButton(frame);
        telech_employe->setObjectName("telech_employe");
        telech_employe->setGeometry(QRect(770, 30, 41, 41));
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
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        telech_employe->setIcon(icon3);
        telech_employe->setIconSize(QSize(30, 30));
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(370, 360, 731, 351));
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
        deconnexion_button->setGeometry(QRect(1170, 30, 141, 41));
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
        trie_button = new QPushButton(frame);
        trie_button->setObjectName("trie_button");
        trie_button->setGeometry(QRect(870, 20, 111, 61));
        trie_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-family: Arial, sans-serif;  /* Police \303\251l\303\251gante */\n"
"    font-size: 12px;                 /* Taille du texte */\n"
"    font-weight: bold;               /* Texte en gras */\n"
"    color: #4B4B4B;                  /* Couleur du texte */\n"
"    background-color: #E8E3DD;       /* Fond doux */\n"
"    padding: 8px 12px;               /* Espacement interne */\n"
"    border-radius: 5px;              /* Coins arrondis */\n"
"    text-align: center;              /* Centrer le texte */\n"
"    margin: 8px;                     /* Espacement externe */\n"
"    border: 2px solid #D1C8B9;       /* Bordure douce */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #D1C8B9;       /* Fond plus fonc\303\251 au survol */\n"
"    border: 2px solid #A89F92;       /* Bordure changeante */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    color: #A0A0A0;                  /* Couleur du texte d\303\251sactiv\303\251 */\n"
"    background-color: #F0F0F0;       /* Fond plus clair qua"
                        "nd d\303\251sactiv\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}\n"
""));
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1200, 650, 251, 281));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/image/logo (1).png")));
        label_10->setScaledContents(true);
        consulter_employe = new QPushButton(frame);
        consulter_employe->setObjectName("consulter_employe");
        consulter_employe->setGeometry(QRect(40, 30, 281, 41));
        consulter_employe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        consulter_employe->setIcon(icon4);
        consulter_employe->setIconSize(QSize(30, 30));
        gemploye->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gemploye);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1440, 22));
        gemploye->setMenuBar(menubar);
        statusbar = new QStatusBar(gemploye);
        statusbar->setObjectName("statusbar");
        gemploye->setStatusBar(statusbar);

        retranslateUi(gemploye);

        QMetaObject::connectSlotsByName(gemploye);
    } // setupUi

    void retranslateUi(QMainWindow *gemploye)
    {
        gemploye->setWindowTitle(QCoreApplication::translate("gemploye", "gemploye", nullptr));
        lineEdit_4->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableview_employe->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gemploye", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableview_employe->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gemploye", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableview_employe->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gemploye", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableview_employe->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gemploye", "D.naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableview_employe->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gemploye", "Mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableview_employe->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("gemploye", "Telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableview_employe->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("gemploye", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableview_employe->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("gemploye", "D.embauche", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableview_employe->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("gemploye", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableview_employe->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("gemploye", "Salaire", nullptr));
        label_2->setText(QCoreApplication::translate("gemploye", "Pr\303\251nom:", nullptr));
        label_4->setText(QCoreApplication::translate("gemploye", "Date d'embauche:", nullptr));
        ajouter_employe->setText(QCoreApplication::translate("gemploye", "Ajouter", nullptr));
        label_3->setText(QCoreApplication::translate("gemploye", "Adresse:", nullptr));
        label_5->setText(QCoreApplication::translate("gemploye", "Mail:", nullptr));
        label_6->setText(QCoreApplication::translate("gemploye", "Poste:", nullptr));
        label_7->setText(QCoreApplication::translate("gemploye", "Salaire:", nullptr));
        label_8->setText(QCoreApplication::translate("gemploye", "Num\303\251ro:", nullptr));
        label->setText(QCoreApplication::translate("gemploye", "Nom:", nullptr));
        label_11->setText(QCoreApplication::translate("gemploye", "Id:", nullptr));
        label_12->setText(QCoreApplication::translate("gemploye", "Date de naissance:", nullptr));
        annuler_employe->setText(QCoreApplication::translate("gemploye", "Annuler", nullptr));
        trie_employe->setItemText(0, QCoreApplication::translate("gemploye", "plus r\303\251c.", nullptr));
        trie_employe->setItemText(1, QCoreApplication::translate("gemploye", "plus anc.", nullptr));

        supprimer_employe->setText(QString());
        chercher_employe->setText(QString());
        modifier_employe->setText(QString());
        telech_employe->setText(QString());
        deconnexion_button->setText(QCoreApplication::translate("gemploye", "D\303\251connexion", nullptr));
        trie_button->setText(QCoreApplication::translate("gemploye", "Trier", nullptr));
        label_10->setText(QString());
        consulter_employe->setText(QCoreApplication::translate("gemploye", "      Consulter le menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gemploye: public Ui_gemploye {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEMPLOYE_H
