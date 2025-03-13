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
    QLineEdit *lineEdit_4;
    QLabel *label_10;
    QComboBox *comboBox_3;
    QLabel *label_13;
    QLabel *label_12;
    QFrame *frame_4;
    QLabel *label_3;
    QPushButton *pushButton_7;
    QLabel *label_14;
    QTableView *tableView;
    QPushButton *supprimer_projet;
    QPushButton *update_projet;
    QPushButton *pushButton_3;
    QPushButton *telecharger_projet;
    QWidget *tab_2;
    QLabel *label_15;
    QFrame *frame_3;
    QLabel *label_20;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_2;
    QLabel *label_16;
    QPushButton *pushButton_8;
    QFrame *frame_2;
    QLabel *label_28;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_5;
    QLabel *label_21;
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
        tabWidget->setGeometry(QRect(10, 10, 1011, 561));
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
        lineEdit_nom = new QLineEdit(frame);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(120, 20, 181, 28));
        ajouter_projet = new QPushButton(frame);
        ajouter_projet->setObjectName("ajouter_projet");
        ajouter_projet->setGeometry(QRect(80, 420, 83, 29));
        annuler_projet = new QPushButton(frame);
        annuler_projet->setObjectName("annuler_projet");
        annuler_projet->setGeometry(QRect(220, 420, 83, 29));
        plainTextEdit_description = new QPlainTextEdit(frame);
        plainTextEdit_description->setObjectName("plainTextEdit_description");
        plainTextEdit_description->setGeometry(QRect(120, 210, 181, 201));
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
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(340, 10, 171, 41));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"    border: 2px solid #2ecc71; /* Changement de bordure au focus */\n"
"    background-color: white; /* Fond plus visible */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #999; /* Couleur du placeholder */\n"
"    font-style: italic;\n"
"}\n"
""));
        lineEdit_4->setReadOnly(true);
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(820, 10, 91, 51));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-family: Arial, sans-serif;  /* Police \303\251l\303\251gante */\n"
"    font-size: 12px;                 /* Taille du texte */\n"
"    font-weight: bold;               /* Texte en gras */\n"
"    color: #4B4B4B;                  /* Couleur du texte */\n"
"    background-color: #E8E3DD;       /* Fond doux */\n"
"    padding: 8px 9px;              /* Espacement interne */\n"
"    border-radius: 5px;              /* Coins arrondis */\n"
"    text-align: center;              /* Centrer le texte */\n"
"    margin: 8px;                    /* Espacement externe */\n"
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
"    background-color: #F0F0F0;       /* Fond plus clair quand d\303\251sactiv"
                        "\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}\n"
""));
        comboBox_3 = new QComboBox(tab);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(910, 20, 101, 28));
        comboBox_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        frame_4 = new QFrame(tab);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(350, 270, 491, 241));
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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(30, 30));
        label_14 = new QLabel(tab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(830, 410, 191, 131));
        label_14->setStyleSheet(QString::fromUtf8("QLabel#logoLabel {\n"
"    border: none;\n"
"    background: transparent;\n"
"}"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/Users/HP/Downloads/8025532-removebg-preview.png")));
        label_14->setScaledContents(true);
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(340, 70, 661, 191));
        tableView->setStyleSheet(QString::fromUtf8("/* Style global du tableau QTableView */\n"
"QTableView {  \n"
"    background-color: #EDECEA; /* Fond doux du tableau */\n"
"    border: 2px solid #838DB1; /* Bordure subtile mais visible */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    gridline-color: #2B0101; /* Lignes de grille en couleur sombre */\n"
"    font-family: \"Segoe UI\", \"Arial\", sans-serif; /* Police moderne et professionnelle */\n"
"    font-size: 14px; /* Taille de police standard */\n"
"    selection-background-color: #838DB1; /* Couleur de fond lors de la s\303\251lection */\n"
"    selection-color: white; /* Texte en blanc lors de la s\303\251lection */\n"
"    alternate-background-color: #F5F5F5; /* Fond alternatif pour les lignes paires (lignes de table) */\n"
"}\n"
"\n"
"/* Style des sections de l'en-t\303\252te */\n"
"QHeaderView::section {\n"
"    background-color: #263A69; /* Fond sombre pour les en-t\303\252tes */\n"
"    color: white; /* Texte blanc pour les en-t\303\252tes */\n"
"    padding: 8px; /* Un peu d'espace"
                        " autour du texte */\n"
"    border: none; /* Suppression des bordures internes */\n"
"    font-weight: bold; /* Texte en gras pour un meilleur contraste */\n"
"    border-radius: 5px; /* Coins arrondis pour les en-t\303\252tes */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
"\n"
"/* Style des \303\251l\303\251ments dans le tableau (cellules) */\n"
"QTableView::item {\n"
"    padding: 6px; /* Espacement interne dans les cellules */\n"
"    border-bottom: 1px solid #E8E3DD; /* L\303\251g\303\250re s\303\251paration entre les lignes */\n"
"    color: black; /* Texte noir dans les cellules */\n"
"    background-color: transparent; /* Fond transparent pour une meilleure lisibilit\303\251 */\n"
"}\n"
"\n"
"/* Style des \303\251l\303\251ments s\303\251lectionn\303\251s dans le tableau */\n"
"QTableView::item:selected {\n"
"    background-color: #838DB1; /* Fond de s\303\251lection pour les \303\251l\303\251ments */\n"
"    color: white; /* Texte en blanc lorsqu'une cellule est s\303\251lectionn\303\251"
                        "e */\n"
"}\n"
"\n"
"/* Effet de survol pour les \303\251l\303\251ments du tableau */\n"
"QTableView::item:hover {\n"
"    background-color: #D0D8E4; /* Fond plus clair lors du survol */\n"
"    cursor: pointer; /* Curseur pointeur lors du survol */\n"
"}\n"
"\n"
"/* Style pour les lignes altern\303\251es du tableau */\n"
"QTableView::item:alternate {\n"
"    background-color: #F7F7F7; /* Fond plus clair pour les lignes impaires */\n"
"}\n"
"\n"
"/* Focus sur les en-t\303\252tes au survol */\n"
"QHeaderView::section:hover {\n"
"    background-color: #1C2D4B; /* Sombre mais plus visible au survol */\n"
"    cursor: pointer; /* Curseur pointeur sur l'en-t\303\252te */\n"
"}\n"
""));
        supprimer_projet = new QPushButton(tab);
        supprimer_projet->setObjectName("supprimer_projet");
        supprimer_projet->setGeometry(QRect(760, 10, 61, 41));
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
        update_projet->setGeometry(QRect(620, 10, 61, 41));
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
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(520, 10, 51, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_3->setIcon(icon3);
        pushButton_3->setIconSize(QSize(30, 30));
        telecharger_projet = new QPushButton(tab);
        telecharger_projet->setObjectName("telecharger_projet");
        telecharger_projet->setGeometry(QRect(690, 10, 61, 41));
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
        frame_3->setGeometry(QRect(40, 40, 481, 361));
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
        label_20 = new QLabel(frame_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(30, 60, 141, 71));
        lineEdit_8 = new QLineEdit(frame_3);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(20, 140, 431, 171));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        lineEdit_2 = new QLineEdit(frame_3);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(180, 80, 131, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_16 = new QLabel(frame_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(100, 0, 241, 61));
        pushButton_8 = new QPushButton(frame_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(350, 320, 111, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(560, 40, 371, 361));
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
        lineEdit_9 = new QLineEdit(frame_2);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(190, 80, 131, 31));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        lineEdit_15 = new QLineEdit(frame_2);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(30, 140, 321, 131));
        lineEdit_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(230, 310, 131, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/historique.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon5);
        pushButton_5->setIconSize(QSize(30, 30));
        label_21 = new QLabel(frame_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(40, 60, 141, 71));
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
        lineEdit_4->setText(QCoreApplication::translate("Gprojet", "Recherche par status", nullptr));
        label_10->setText(QCoreApplication::translate("Gprojet", "Trier par", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Gprojet", "Nom", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Gprojet", "Date D\303\251but", nullptr));

        label_13->setText(QString());
        label_12->setText(QString());
        label_3->setText(QCoreApplication::translate("Gprojet", "Nombre des projets mensuelle:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Gprojet", "      Consulter le menu", nullptr));
        label_14->setText(QString());
        supprimer_projet->setText(QString());
        update_projet->setText(QString());
        pushButton_3->setText(QString());
        telecharger_projet->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Gprojet", "Gestion des projets", nullptr));
        label_15->setText(QString());
        label_20->setText(QCoreApplication::translate("Gprojet", "Id_projet:", nullptr));
        label_16->setText(QCoreApplication::translate("Gprojet", "Des conseils g\303\251n\303\251r\303\251s avec l'IA", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Gprojet", "G\303\251n\303\251rer ", nullptr));
        label_28->setText(QCoreApplication::translate("Gprojet", "       Historique du projet           ", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Gprojet", "    Historique", nullptr));
        label_21->setText(QCoreApplication::translate("Gprojet", "Id_projet:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Gprojet", "Gestion des m\303\251tiers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gprojet: public Ui_Gprojet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPROJET_H
