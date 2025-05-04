/********************************************************************************
** Form generated from reading UI file 'gressource.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRESSOURCE_H
#define UI_GRESSOURCE_H

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

class Ui_Gressource
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
    QDateTimeEdit *dateTimeEdit_ressource;
    QLineEdit *lineEdit_nomressources;
    QComboBox *type_ressource;
    QPushButton *ajouter_ressource;
    QPushButton *pushButton_2;
    QPlainTextEdit *description_ressource;
    QLineEdit *cout_ressource;
    QLineEdit *quantite_ressource;
    QLineEdit *recherche_ressource_2;
    QComboBox *tri_2_ressource;
    QLabel *label_13;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QFrame *frame_stat;
    QLabel *label_9;
    QPushButton *recherche_ressource;
    QPushButton *update_ressource;
    QPushButton *telecharger_ressource;
    QPushButton *delete_ressource;
    QTableView *tableView;
    QPushButton *tri_ressource;
    QLabel *labelbudget;
    QWidget *tab_2;
    QLabel *label_15;
    QFrame *frame_2;
    QPushButton *preduction_ressource;
    QTextEdit *rsult_preduction;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gressource)
    {
        if (Gressource->objectName().isEmpty())
            Gressource->setObjectName("Gressource");
        Gressource->resize(1292, 618);
        centralwidget = new QWidget(Gressource);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1541, 991));
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
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        frame = new QFrame(tab);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 60, 371, 511));
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
"\n"
"\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 63, 20));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 131, 21));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 90, 81, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 120, 91, 21));
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 180, 121, 20));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 150, 81, 20));
        dateTimeEdit_ressource = new QDateTimeEdit(frame);
        dateTimeEdit_ressource->setObjectName("dateTimeEdit_ressource");
        dateTimeEdit_ressource->setGeometry(QRect(160, 60, 181, 29));
        lineEdit_nomressources = new QLineEdit(frame);
        lineEdit_nomressources->setObjectName("lineEdit_nomressources");
        lineEdit_nomressources->setGeometry(QRect(160, 30, 181, 28));
        type_ressource = new QComboBox(frame);
        type_ressource->addItem(QString());
        type_ressource->addItem(QString());
        type_ressource->setObjectName("type_ressource");
        type_ressource->setGeometry(QRect(160, 90, 181, 28));
        ajouter_ressource = new QPushButton(frame);
        ajouter_ressource->setObjectName("ajouter_ressource");
        ajouter_ressource->setGeometry(QRect(80, 410, 83, 29));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 410, 83, 29));
        description_ressource = new QPlainTextEdit(frame);
        description_ressource->setObjectName("description_ressource");
        description_ressource->setGeometry(QRect(160, 180, 191, 191));
        cout_ressource = new QLineEdit(frame);
        cout_ressource->setObjectName("cout_ressource");
        cout_ressource->setGeometry(QRect(160, 150, 181, 28));
        cout_ressource->setMaxLength(9);
        quantite_ressource = new QLineEdit(frame);
        quantite_ressource->setObjectName("quantite_ressource");
        quantite_ressource->setGeometry(QRect(160, 120, 181, 28));
        quantite_ressource->setMaxLength(3);
        recherche_ressource_2 = new QLineEdit(tab);
        recherche_ressource_2->setObjectName("recherche_ressource_2");
        recherche_ressource_2->setGeometry(QRect(410, 17, 271, 41));
        recherche_ressource_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"}"));
        tri_2_ressource = new QComboBox(tab);
        tri_2_ressource->addItem(QString());
        tri_2_ressource->addItem(QString());
        tri_2_ressource->setObjectName("tri_2_ressource");
        tri_2_ressource->setGeometry(QRect(1090, 20, 121, 41));
        tri_2_ressource->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"}"));
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(850, 510, 191, 171));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/image.qrc/8025532-removebg-preview.png")));
        label_13->setScaledContents(true);
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1100, 390, 181, 181));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Users/dhiab/Downloads/8025532-removebg-preview.png")));
        label_3->setScaledContents(true);
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(90, 10, 261, 29));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(111, 125, 171);\n"
"font: 700 11pt \"Times New Roman\";"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        pushButton_4->setIcon(icon);
        frame_stat = new QFrame(tab);
        frame_stat->setObjectName("frame_stat");
        frame_stat->setGeometry(QRect(430, 350, 541, 181));
        frame_stat->setStyleSheet(QString::fromUtf8("/* Style pour le QFrame avec fond fonc\303\251 et bords arrondis */\n"
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
        frame_stat->setFrameShape(QFrame::Shape::StyledPanel);
        frame_stat->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(frame_stat);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 10, 321, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Times New Roman\";"));
        recherche_ressource = new QPushButton(tab);
        recherche_ressource->setObjectName("recherche_ressource");
        recherche_ressource->setGeometry(QRect(700, 20, 61, 41));
        recherche_ressource->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        recherche_ressource->setIcon(icon1);
        recherche_ressource->setIconSize(QSize(30, 30));
        update_ressource = new QPushButton(tab);
        update_ressource->setObjectName("update_ressource");
        update_ressource->setGeometry(QRect(770, 20, 51, 41));
        update_ressource->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/update.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        update_ressource->setIcon(icon2);
        update_ressource->setIconSize(QSize(30, 30));
        telecharger_ressource = new QPushButton(tab);
        telecharger_ressource->setObjectName("telecharger_ressource");
        telecharger_ressource->setGeometry(QRect(830, 20, 51, 41));
        telecharger_ressource->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/telech.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        telecharger_ressource->setIcon(icon3);
        telecharger_ressource->setIconSize(QSize(30, 30));
        delete_ressource = new QPushButton(tab);
        delete_ressource->setObjectName("delete_ressource");
        delete_ressource->setGeometry(QRect(890, 20, 51, 41));
        delete_ressource->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        delete_ressource->setIcon(icon4);
        delete_ressource->setIconSize(QSize(30, 30));
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(415, 81, 751, 261));
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
        tri_ressource = new QPushButton(tab);
        tri_ressource->setObjectName("tri_ressource");
        tri_ressource->setGeometry(QRect(970, 18, 101, 51));
        tri_ressource->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QPushButton:hover {\n"
"    background-color: #D1C8B9;       /* Fond plus fonc\303\251 au survol */\n"
"    border: 2px solid #A89F92;       /* Bordure changeante */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    color: #A0A0A0;                  /* Couleur du texte d\303\251sactiv\303\251 */\n"
"    background-color: #F0F0F0;       /* Fond plus clair quand "
                        "d\303\251sactiv\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}"));
        labelbudget = new QLabel(tab);
        labelbudget->setObjectName("labelbudget");
        labelbudget->setGeometry(QRect(972, 350, 311, 91));
        labelbudget->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"    border: 2px solid #A89F92;       /* Bordure changeante */\n"
"}\n"
"\n"
"QLabel:disabled {\n"
"    color: #A0A0A0;                  /* Couleur du texte d\303\251sactiv\303\251 */\n"
"    background-color: #F0F0F0;       /* Fond plus clair quand d\303\251sac"
                        "tiv\303\251 */\n"
"    border: 2px solid #A0A0A0;       /* Bordure d\303\251sactiv\303\251e */\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_15 = new QLabel(tab_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(880, 420, 181, 91));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/Users/HP/Downloads/8025532-removebg-preview.png")));
        label_15->setScaledContents(true);
        frame_2 = new QFrame(tab_2);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(300, 100, 591, 321));
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
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        preduction_ressource = new QPushButton(frame_2);
        preduction_ressource->setObjectName("preduction_ressource");
        preduction_ressource->setGeometry(QRect(10, 250, 91, 51));
        preduction_ressource->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}"));
        rsult_preduction = new QTextEdit(frame_2);
        rsult_preduction->setObjectName("rsult_preduction");
        rsult_preduction->setGeometry(QRect(130, 100, 431, 191));
        rsult_preduction->setStyleSheet(QString::fromUtf8("#rsult_preduction {\n"
"    font-family: \"Poppins\", \"Arial\", sans-serif;\n"
"    font-size: 14px;\n"
"    background-color: #E8E3DD;\n"
"    border: 1px solid #838db1;\n"
"    border-radius: 5px;\n"
"    padding: 4px;\n"
"    color: #263A69;\n"
"}"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(140, 10, 311, 81));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"}"));
        tabWidget->addTab(tab_2, QString());
        Gressource->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gressource);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1292, 25));
        Gressource->setMenuBar(menubar);
        statusbar = new QStatusBar(Gressource);
        statusbar->setObjectName("statusbar");
        Gressource->setStatusBar(statusbar);

        retranslateUi(Gressource);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Gressource);
    } // setupUi

    void retranslateUi(QMainWindow *Gressource)
    {
        Gressource->setWindowTitle(QCoreApplication::translate("Gressource", "Gressource", nullptr));
        label->setText(QCoreApplication::translate("Gressource", "Nom", nullptr));
        label_2->setText(QCoreApplication::translate("Gressource", "Date d'achat", nullptr));
        label_4->setText(QCoreApplication::translate("Gressource", "Type", nullptr));
        label_5->setText(QCoreApplication::translate("Gressource", "Quantit\303\251", nullptr));
        label_6->setText(QCoreApplication::translate("Gressource", "Description", nullptr));
        label_8->setText(QCoreApplication::translate("Gressource", "Co\303\273t", nullptr));
        type_ressource->setItemText(0, QCoreApplication::translate("Gressource", "Mat\303\251riel", nullptr));
        type_ressource->setItemText(1, QCoreApplication::translate("Gressource", "Logiciel", nullptr));

        ajouter_ressource->setText(QCoreApplication::translate("Gressource", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Gressource", "Annuler", nullptr));
        recherche_ressource_2->setText(QCoreApplication::translate("Gressource", "               Recherche par type", nullptr));
        tri_2_ressource->setItemText(0, QCoreApplication::translate("Gressource", "Quantit\303\251", nullptr));
        tri_2_ressource->setItemText(1, QCoreApplication::translate("Gressource", "nom", nullptr));

        label_13->setText(QString());
        label_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Gressource", "Consulter le menu", nullptr));
        label_9->setText(QCoreApplication::translate("Gressource", "Nombres des ressources par type", nullptr));
        recherche_ressource->setText(QString());
        update_ressource->setText(QString());
        telecharger_ressource->setText(QString());
        delete_ressource->setText(QString());
        tri_ressource->setText(QCoreApplication::translate("Gressource", "Trier par :", nullptr));
        labelbudget->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Gressource", "Gestion des ressources", nullptr));
        label_15->setText(QString());
        preduction_ressource->setText(QCoreApplication::translate("Gressource", "Prevoir", nullptr));
        label_7->setText(QCoreApplication::translate("Gressource", "                 Les predictions des couts", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Gressource", "Gestion des m\303\251tiers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gressource: public Ui_Gressource {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRESSOURCE_H
