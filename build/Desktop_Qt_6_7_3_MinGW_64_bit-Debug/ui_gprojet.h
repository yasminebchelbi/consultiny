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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
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
    QLineEdit *lineEdit_nom;
    QPushButton *ajouter_projet;
    QPushButton *annuler_projet;
    QPlainTextEdit *plainTextEdit_description;
    QLineEdit *lineEdit_cout;
    QLineEdit *lineEdit_adresse;
    QLineEdit *lineEdit_budget;
    QLineEdit *lineEdit_secteur;
    QLineEdit *recherche_projet;
    QComboBox *trier_projet;
    QLabel *label_13;
    QLabel *label_12;
    QPushButton *pushButton_7;
    QLabel *label_14;
    QTableView *tableView;
    QPushButton *supprimer_projet;
    QPushButton *update_projet;
    QPushButton *recherche_projet_2;
    QPushButton *telecharger_projet;
    QPushButton *trier_projet_2;
    QFrame *frame_stat;
    QPushButton *refresh_projet;
    QWidget *tab_2;
    QLabel *label_15;
    QFrame *frame_3;
    QLabel *label_16;
    QTextEdit *txtReponse;
    QLabel *image_projet;
    QPushButton *annuler_conseil_projet;
    QLineEdit *txtQuestion;
    QPushButton *btnEnvoyer;
    QFrame *frame_2;
    QLabel *label_28;
    QLineEdit *id_hist_projet;
    QPushButton *hist_projet;
    QLabel *label_21;
    QTextEdit *historique_projet;
    QPushButton *anuuler_hist;
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
        tabWidget->setGeometry(QRect(10, 10, 1011, 581));
        tabWidget->setStyleSheet(QString::fromUtf8("/* Style du QTabWidget */\n"
"QTabWidget::pane {\n"
"    border: 1px solid ;\n"
"    background-color:#DCDCDA;\n"
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
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 60, 321, 461));
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
        label_6->setGeometry(QRect(20, 210, 111, 20));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 140, 81, 20));
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 170, 91, 20));
        dateTimeEdit = new QDateTimeEdit(frame);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(120, 50, 181, 29));
        lineEdit_nom = new QLineEdit(frame);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(120, 20, 181, 28));
        ajouter_projet = new QPushButton(frame);
        ajouter_projet->setObjectName("ajouter_projet");
        ajouter_projet->setGeometry(QRect(30, 420, 83, 29));
        annuler_projet = new QPushButton(frame);
        annuler_projet->setObjectName("annuler_projet");
        annuler_projet->setGeometry(QRect(220, 420, 83, 29));
        plainTextEdit_description = new QPlainTextEdit(frame);
        plainTextEdit_description->setObjectName("plainTextEdit_description");
        plainTextEdit_description->setGeometry(QRect(20, 250, 281, 161));
        lineEdit_cout = new QLineEdit(frame);
        lineEdit_cout->setObjectName("lineEdit_cout");
        lineEdit_cout->setGeometry(QRect(120, 140, 181, 28));
        lineEdit_cout->setMaxLength(10);
        lineEdit_adresse = new QLineEdit(frame);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(120, 170, 181, 28));
        lineEdit_budget = new QLineEdit(frame);
        lineEdit_budget->setObjectName("lineEdit_budget");
        lineEdit_budget->setGeometry(QRect(120, 80, 181, 28));
        lineEdit_secteur = new QLineEdit(frame);
        lineEdit_secteur->setObjectName("lineEdit_secteur");
        lineEdit_secteur->setGeometry(QRect(120, 110, 181, 28));
        recherche_projet = new QLineEdit(tab);
        recherche_projet->setObjectName("recherche_projet");
        recherche_projet->setGeometry(QRect(240, 10, 171, 41));
        recherche_projet->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5; /* Fond clair et \303\251pur\303\251 */\n"
"    border: 2px solid #6f7dab; /* Bordure bleu-gris */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    color: #333; /* Couleur du texte */\n"
"    selection-background-color: #6f7dab; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #6f7dab; /* Changement de bordure au focus */\n"
"    background-color: white; /* Fond plus visible */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #999; /* Couleur du placeholder */\n"
"    font-style: italic;\n"
"}\n"
""));
        recherche_projet->setReadOnly(false);
        trier_projet = new QComboBox(tab);
        trier_projet->addItem(QString());
        trier_projet->addItem(QString());
        trier_projet->setObjectName("trier_projet");
        trier_projet->setGeometry(QRect(910, 20, 101, 28));
        trier_projet->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(850, 510, 191, 171));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/image.qrc/8025532-removebg-preview.png")));
        label_13->setScaledContents(true);
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(390, 370, 49, 16));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(20, 10, 201, 31));
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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(30, 30));
        label_14 = new QLabel(tab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(840, 410, 191, 131));
        label_14->setStyleSheet(QString::fromUtf8("QLabel#logoLabel {\n"
"    border: none;\n"
"    background: transparent;\n"
"}"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Users/HP/Downloads/8025532-removebg-preview.png")));
        label_14->setScaledContents(true);
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(340, 70, 661, 191));
        tableView->setStyleSheet(QString::fromUtf8("QTableView { \n"
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
"    color: black; /* Texte noir */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #838DB1; /* Fond des \303\251"
                        "l\303\251ments s\303\251lectionn\303\251s */\n"
"    color: black; /* Texte noir sur s\303\251lection */\n"
"}\n"
""));
        supprimer_projet = new QPushButton(tab);
        supprimer_projet->setObjectName("supprimer_projet");
        supprimer_projet->setGeometry(QRect(750, 10, 51, 41));
        supprimer_projet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        supprimer_projet->setIcon(icon1);
        supprimer_projet->setIconSize(QSize(30, 30));
        supprimer_projet->setCheckable(false);
        supprimer_projet->setChecked(false);
        update_projet = new QPushButton(tab);
        update_projet->setObjectName("update_projet");
        update_projet->setGeometry(QRect(630, 10, 51, 41));
        update_projet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/update4.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        update_projet->setIcon(icon2);
        update_projet->setIconSize(QSize(30, 30));
        update_projet->setCheckable(true);
        update_projet->setAutoDefault(false);
        update_projet->setFlat(false);
        recherche_projet_2 = new QPushButton(tab);
        recherche_projet_2->setObjectName("recherche_projet_2");
        recherche_projet_2->setGeometry(QRect(420, 10, 51, 41));
        recherche_projet_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"                stop:0 #6f7dab, stop:1 #5b6d96); /* D\303\251grad\303\251 bleu-gris */\n"
"    border: 2px solid #5b6d96;\n"
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
"                stop:0 #5b6d96, stop:1 #6f7dab); /* Inversion du d\303\251grad\303\251 */\n"
"    border: 2px solid #6f7dab;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #4a5a82; /* Couleur plus fonc\303\251e au clic */\n"
"    border: 2px solid #4a5a82;\n"
"}\n"
"QPushButton:icon {\n"
"    color: #4B4B4B; /* Couleur de l'ic\303\264ne */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D1C8B9; /* Fond pour \303\251tat d\303\251sactiv\303\251 */\n"
"    color: #A0A0A0; /* C"
                        "ouleur de texte pour d\303\251sactivation */\n"
"    border: 2px solid #A0A0A0; /* Bordure pour d\303\251sactivation */\n"
"}\n"
"\n"
"QPushButton:hover::icon {\n"
"    color: #FFFFFF; /* Changement de couleur de l'ic\303\264ne au survol */\n"
"}"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        recherche_projet_2->setIcon(icon3);
        recherche_projet_2->setIconSize(QSize(30, 30));
        telecharger_projet = new QPushButton(tab);
        telecharger_projet->setObjectName("telecharger_projet");
        telecharger_projet->setGeometry(QRect(690, 10, 51, 41));
        telecharger_projet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/enregistrer.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        telecharger_projet->setIcon(icon4);
        telecharger_projet->setIconSize(QSize(30, 30));
        trier_projet_2 = new QPushButton(tab);
        trier_projet_2->setObjectName("trier_projet_2");
        trier_projet_2->setGeometry(QRect(810, 10, 101, 51));
        trier_projet_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame_stat = new QFrame(tab);
        frame_stat->setObjectName("frame_stat");
        frame_stat->setGeometry(QRect(370, 290, 461, 211));
        frame_stat->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color:  #6f7dab; /* Couleur de fond fonc\303\251e */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"}\n"
""));
        frame_stat->setFrameShape(QFrame::Shape::StyledPanel);
        frame_stat->setFrameShadow(QFrame::Shadow::Raised);
        refresh_projet = new QPushButton(tab);
        refresh_projet->setObjectName("refresh_projet");
        refresh_projet->setGeometry(QRect(480, 10, 51, 41));
        refresh_projet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"QIcon{\n"
"color: white;\n"
"}"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::SystemReboot));
        refresh_projet->setIcon(icon5);
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
        frame_3->setGeometry(QRect(40, 40, 551, 361));
        frame_3->setStyleSheet(QString::fromUtf8("/* Style pour le QFrame avec fond fonc\303\251 et bords arrondis */\n"
"QFrame {\n"
"    background-color:  #6f7dab; /* Couleur de fond fonc\303\251e */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"}\n"
"\n"
"/* Style pour les QLabel */\n"
"QLabel {\n"
"    font-family: Arial, sans-serif;  /* Police \303\251l\303\251gante */\n"
"    font-size: 12px;                 /* Taille du texte */\n"
"    font-weight: bold;               /* Texte en gras */\n"
"    color: #4B4B4B;                  /* Couleur du texte */\n"
"    background-color: #E8E3DD;       /* Fond doux */\n"
"    padding: 10px 15px;              /* Espacement interne */\n"
"    border-radius: 8px;              /* Coins arrondis */\n"
"    text-align: center;              /* Centrer le texte */\n"
"    margin: 10px;                    /* Espacement externe */\n"
"    border: 2px solid #D1C8B9;       /* Bordure douce */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: #D1C8B9;       /* Fond plus fonc\303\251 au survol */\n"
"    border:"
                        " 2px solid #A89F92;       /* Bordure changeante */\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    color: #A0A0A0;                  /* Couleur du texte d\303\251sactiv\303\251 */\n"
"    background-color: #F0F0F0;       /* Fond plus clair quand d\303\251sactiv\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}\n"
""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_16 = new QLabel(frame_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(160, 10, 241, 61));
        txtReponse = new QTextEdit(frame_3);
        txtReponse->setObjectName("txtReponse");
        txtReponse->setGeometry(QRect(10, 170, 291, 121));
        txtReponse->setStyleSheet(QString::fromUtf8("#txtReponse {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}"));
        txtReponse->setReadOnly(true);
        image_projet = new QLabel(frame_3);
        image_projet->setObjectName("image_projet");
        image_projet->setGeometry(QRect(300, 160, 241, 141));
        image_projet->setSizeIncrement(QSize(300, 300));
        image_projet->setBaseSize(QSize(300, 300));
        annuler_conseil_projet = new QPushButton(frame_3);
        annuler_conseil_projet->setObjectName("annuler_conseil_projet");
        annuler_conseil_projet->setGeometry(QRect(120, 20, 41, 41));
        annuler_conseil_projet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 11pt \"Times New Roman\";\n"
"	\n"
"\n"
"    background-color: #E8E3DD;\n"
"    color: #6F7DAB;\n"
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
        annuler_conseil_projet->setIcon(icon5);
        txtQuestion = new QLineEdit(frame_3);
        txtQuestion->setObjectName("txtQuestion");
        txtQuestion->setGeometry(QRect(40, 100, 471, 51));
        txtQuestion->setStyleSheet(QString::fromUtf8("#txtQuestion {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}"));
        btnEnvoyer = new QPushButton(frame_3);
        btnEnvoyer->setObjectName("btnEnvoyer");
        btnEnvoyer->setGeometry(QRect(410, 110, 91, 31));
        btnEnvoyer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 11pt \"Times New Roman\";\n"
"	\n"
"\n"
"    background-color: #E8E3DD;\n"
"    color: #6F7DAB;\n"
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
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekForward));
        btnEnvoyer->setIcon(icon6);
        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(620, 40, 371, 361));
        frame_2->setStyleSheet(QString::fromUtf8("/* Style pour le QFrame avec fond fonc\303\251 et bords arrondis */\n"
"QFrame {\n"
"    background-color:  #6f7dab; /* Couleur de fond fonc\303\251e */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"}\n"
"\n"
"/* Style pour les QLabel */\n"
"QLabel {\n"
"    font-family: Arial, sans-serif;  /* Police \303\251l\303\251gante */\n"
"    font-size: 12px;                 /* Taille du texte */\n"
"    font-weight: bold;               /* Texte en gras */\n"
"    color: #4B4B4B;                  /* Couleur du texte */\n"
"    background-color: #E8E3DD;        /* Fond doux */\n"
"    padding: 10px 15px;              /* Espacement interne */\n"
"    border-radius: 8px;              /* Coins arrondis */\n"
"    text-align: center;              /* Centrer le texte */\n"
"    margin: 10px;                    /* Espacement externe */\n"
"    border: 2px solid #D1C8B9;       /* Bordure douce */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: #D1C8B9;       /* Fond plus fonc\303\251 au survol */\n"
"    border"
                        ": 2px solid #A89F92;       /* Bordure changeante */\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    color: #A0A0A0;                  /* Couleur du texte d\303\251sactiv\303\251 */\n"
"    background-color: #F0F0F0;       /* Fond plus clair quand d\303\251sactiv\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_28 = new QLabel(frame_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(70, 0, 211, 61));
        label_28->setStyleSheet(QString::fromUtf8(""));
        id_hist_projet = new QLineEdit(frame_2);
        id_hist_projet->setObjectName("id_hist_projet");
        id_hist_projet->setGeometry(QRect(190, 80, 131, 31));
        id_hist_projet->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Arial, sans-serif;  /* Police \303\251l\303\251gante */\n"
"    font-size: 8px;                 /* Taille du texte */\n"
"    font-weight: bold;               /* Texte en gras */\n"
"    color: #4B4B4B;                  /* Couleur du texte */\n"
"    background-color: #E8E3DD;       /* Fond doux */\n"
"    padding: 8px 10px;              /* Espacement interne */\n"
"    border-radius: 8px;              /* Coins arrondis */\n"
"    text-align: center;              /* Centrer le texte */\n"
"    margin: 10px;                    /* Espacement externe */\n"
"    border: 2px solid #D1C8B9;       /* Bordure douce */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: #D1C8B9;       /* Fond plus fonc\303\251 au survol */\n"
"    border: 2px solid #A89F92;       /* Bordure changeante */\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    color: #A0A0A0;                  /* Couleur du texte d\303\251sactiv\303\251 */\n"
"    background-color: #F0F0F0;       /* Fond plus clair quand d\303\251sacti"
                        "v\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}\n"
"QLineEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}"));
        hist_projet = new QPushButton(frame_2);
        hist_projet->setObjectName("hist_projet");
        hist_projet->setGeometry(QRect(230, 310, 131, 31));
        hist_projet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 11pt \"Times New Roman\";\n"
"	\n"
"\n"
"    background-color: #E8E3DD;\n"
"    color: #6F7DAB;\n"
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/historique.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        hist_projet->setIcon(icon7);
        hist_projet->setIconSize(QSize(30, 30));
        label_21 = new QLabel(frame_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(40, 60, 141, 71));
        historique_projet = new QTextEdit(frame_2);
        historique_projet->setObjectName("historique_projet");
        historique_projet->setGeometry(QRect(20, 150, 331, 131));
        historique_projet->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Arial, sans-serif;  /* Police \303\251l\303\251gante */\n"
"    font-size: 8px;                 /* Taille du texte */\n"
"    font-weight: bold;               /* Texte en gras */\n"
"    color: #4B4B4B;                  /* Couleur du texte */\n"
"    background-color: #E8E3DD;       /* Fond doux */\n"
"    padding: 8px 10px;              /* Espacement interne */\n"
"    border-radius: 8px;              /* Coins arrondis */\n"
"    text-align: center;              /* Centrer le texte */\n"
"    margin: 10px;                    /* Espacement externe */\n"
"    border: 2px solid #D1C8B9;       /* Bordure douce */\n"
"}\n"
"\n"
"QLabel:hover {\n"
"    background-color: #D1C8B9;       /* Fond plus fonc\303\251 au survol */\n"
"    border: 2px solid #A89F92;       /* Bordure changeante */\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    color: #A0A0A0;                  /* Couleur du texte d\303\251sactiv\303\251 */\n"
"    background-color: #F0F0F0;       /* Fond plus clair quand d\303\251sacti"
                        "v\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}\n"
"QTextEdit {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}"));
        historique_projet->setReadOnly(true);
        anuuler_hist = new QPushButton(frame_2);
        anuuler_hist->setObjectName("anuuler_hist");
        anuuler_hist->setGeometry(QRect(30, 310, 121, 31));
        anuuler_hist->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 11pt \"Times New Roman\";\n"
"	\n"
"\n"
"    background-color: #E8E3DD;\n"
"    color: #6F7DAB;\n"
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
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        anuuler_hist->setIcon(icon8);
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

        tabWidget->setCurrentIndex(1);
        update_projet->setDefault(false);


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
        ajouter_projet->setText(QCoreApplication::translate("Gprojet", "Ajouter", nullptr));
        annuler_projet->setText(QCoreApplication::translate("Gprojet", "Annuler", nullptr));
        recherche_projet->setText(QCoreApplication::translate("Gprojet", "Recherche par status", nullptr));
        trier_projet->setItemText(0, QCoreApplication::translate("Gprojet", "Nom", nullptr));
        trier_projet->setItemText(1, QCoreApplication::translate("Gprojet", "Date D\303\251but", nullptr));

        label_13->setText(QString());
        label_12->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("Gprojet", "      Consulter le menu", nullptr));
        label_14->setText(QString());
        supprimer_projet->setText(QString());
        update_projet->setText(QString());
        recherche_projet_2->setText(QString());
        telecharger_projet->setText(QString());
        trier_projet_2->setText(QCoreApplication::translate("Gprojet", "Trier par ", nullptr));
        refresh_projet->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Gprojet", "Gestion des projets", nullptr));
        label_15->setText(QString());
        label_16->setText(QCoreApplication::translate("Gprojet", "               Consutiny Bot", nullptr));
        txtReponse->setHtml(QCoreApplication::translate("Gprojet", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Poppins','Arial','sans-serif'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        image_projet->setText(QCoreApplication::translate("Gprojet", "         G\303\251n\303\251ration des images", nullptr));
        annuler_conseil_projet->setText(QString());
        txtQuestion->setText(QCoreApplication::translate("Gprojet", "Pose ta question \360\237\230\212  ", nullptr));
        btnEnvoyer->setText(QCoreApplication::translate("Gprojet", "G\303\251n\303\251rer", nullptr));
        label_28->setText(QCoreApplication::translate("Gprojet", "       Historique du projet           ", nullptr));
        hist_projet->setText(QCoreApplication::translate("Gprojet", "    Historique", nullptr));
        label_21->setText(QCoreApplication::translate("Gprojet", "Id_projet:", nullptr));
        anuuler_hist->setText(QCoreApplication::translate("Gprojet", "    Annuler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Gprojet", "Gestion des m\303\251tiers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gprojet: public Ui_Gprojet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPROJET_H
