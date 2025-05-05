#include "access.h"
#include "gemploye.h"
#include "ui_gemploye.h"
#include <QDebug>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QDialogButtonBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTextStream>
#include <QAbstractButton>
#include <QPageSize>
#include <QMarginsF>
#include <QFontMetrics>
#include <QDateTime>
#include <QFont>
#include <QPen>
#include <QColor>
#include <QRegularExpression>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include "dialogtheme.h"
#include <QTimer>
#include "menu.h"

Gemploye::Gemploye(access *fenetreConnexion, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::gemploye),
    chartView(nullptr),
    fenetreConnexion(fenetreConnexion),
    fenetreMenu(nullptr)
{
    ui->setupUi(this);


    // Initialize database connection as before
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("novus");
    db.setPassword("dhia2005");

    if (!db.open()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Impossible de se connecter à la base de données: " + db.lastError().text());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }

    // Create table if it doesn't exist
    QSqlQuery query(db);
    query.exec("CREATE TABLE employes ("
               "ID_EMPLOYE VARCHAR2(20) PRIMARY KEY, "
               "NOM_EMPLOYE VARCHAR2(50), "
               "PRENOM_EMPLOYE VARCHAR2(50), "
               "DATE_NAISSANCE_EMPLOYE DATE, "
               "EMAIL_EMPLOYE VARCHAR2(100), "
               "TELEPHONE_EMPLOYE VARCHAR2(20), "
               "ADRESSE_EMPLOYE VARCHAR2(200), "
               "DATE_EMBAUCHE_EMPLOYE DATE, "
               "POSTE_EMPLOYE VARCHAR2(50), "
               "SALAIRE_EMPLOYE NUMBER(10,2))");

    // Sélection de toute la ligne
    ui->tableview_employe->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Désactiver l'édition directe par double-clic ou clic
    ui->tableview_employe->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Configuration du graphique
    chartView = new QChartView(new QChart(), this);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->statsLayout->addWidget(chartView);

    // Configuration du QComboBox pour les statistiques
    ui->statsTypeCombo->addItem("Répartition par poste", 0);
    ui->statsTypeCombo->addItem("Répartition par tranche d'âge", 1);
    ui->statsTypeCombo->addItem("Répartition par salaire", 2);

    // Style du ComboBox des statistiques
    ui->statsTypeCombo->setStyleSheet(
        "QComboBox {"
        "    background-color: white;"
        "    color: #263A69;"
        "    border: 2px solid #838DB1;"
        "    border-radius: 5px;"
        "    padding: 5px;"
        "    min-height: 25px;"
        "    min-width: 200px;"
        "}"
        "QComboBox:hover {"
        "    border-color: #263A69;"
        "}"
        "QComboBox::drop-down {"
        "    border: none;"
        "    width: 20px;"
        "}"
        "QComboBox::down-arrow {"
        "    image: url(:/icons/down_arrow.png);"
        "    width: 12px;"
        "    height: 12px;"
        "}"
        "QComboBox QAbstractItemView {"
        "    background-color: white;"
        "    color: #263A69;"
        "    selection-background-color: #263A69;"
        "    selection-color: white;"
        "}"
        );

    // Connecter le signal du combo box
    connect(ui->statsTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Gemploye::on_statsTypeCombo_currentIndexChanged);

    // Initialiser les données
    populateTable();
    updateStatistics();

    // Connexion du bouton de tri
    connect(ui->trie_button, &QPushButton::clicked, this, &Gemploye::on_trie_button_clicked);
}
/*Gemploye::Gemploye(Menu *menuExistant, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::gemploye),
    fenetreMenu(menuExistant)
{
    ui->setupUi(this);
}*/
Gemploye::~Gemploye() {
    db.close();
    delete ui;
}

void Gemploye::populateTable() {
    ui->tableview_employe->setRowCount(0);
    QSqlQuery query("SELECT * FROM employes");
    int row = 0;
    while (query.next()) {
        ui->tableview_employe->insertRow(row);
        for (int col = 0; col < 10; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setForeground(QColor(Qt::black)); // Définir la couleur du texte en noir
            ui->tableview_employe->setItem(row, col, item);
        }
        row++;
    }

    // Appliquer le style global pour s'assurer que les données non sélectionnées sont en noir
    ui->tableview_employe->setStyleSheet(
        "QTableView {"
        "    background-color: #EDECEA;" // Fond du tableau
        "    border: 2px solid #838DB1;" // Bordure subtile
        "    border-radius: 10px;" // Arrondi
        "    gridline-color: #DCDCDA;" // Couleur des lignes du tableau
        "    font-family: \"Segoe UI\", \"Arial\", sans-serif;" // Typographie moderne
        "    font-size: 14px;"
        "    selection-background-color: #838DB1;" // Couleur de sélection
        "    selection-color: white;" // Texte en blanc sur sélection
        "}"
        "QHeaderView::section {"
        "    background-color: #263A69;" // En-têtes foncés
        "    color: white;" // Texte blanc pour les en-têtes
        "    padding: 8px;"
        "    border: none;"
        "    font-weight: bold;"
        "    border-radius: 5px;"
        "}"
        "QTableView::item {"
        "    padding: 6px;"
        "    border-bottom: 1px solid #E8E3DD;" // Séparation entre les lignes
        "    color: black;" // Couleur du texte des données en noir
        "}"
        "QTableView::item:selected {"
        "    background-color: #838DB1;" // Fond des éléments sélectionnés
        "    color: white;" // Texte en blanc pour les éléments sélectionnés
        "}"
        );

    updateStatistics();
}

void Gemploye::clearFields() {
    ui->id_employe->clear();
    ui->nom_employe->clear();
    ui->prenom_employe->clear();
    ui->mail_employe->clear();
    ui->numero_employe->clear();
    ui->adresse_employe->clear();
    ui->poste_employe->clear();
    ui->salaire_employe->clear();
    ui->date_naissance_employe->setDate(QDate::currentDate());
    ui->date_embauche_employe->setDate(QDate::currentDate());
}

void Gemploye::on_ajouter_employe_clicked()
{
    // Validation des champs obligatoires
    QString idStr = ui->id_employe->text().trimmed();
    QString nom = ui->nom_employe->text().trimmed();
    QString prenom = ui->prenom_employe->text().trimmed();
    QDate naissance = ui->date_naissance_employe->date();
    QString email = ui->mail_employe->text().trimmed();
    QString phone = ui->numero_employe->text().trimmed();
    QString adresse = ui->adresse_employe->text().trimmed();
    QDate embauche = ui->date_embauche_employe->date();
    QString poste = ui->poste_employe->text().trimmed();
    QString salaireStr = ui->salaire_employe->text().trimmed();

    QRegularExpression emailRx(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    QRegularExpression nomRx("^[A-Za-zÀ-ÿ\\s]{1,30}$");
    QRegularExpression phoneRx("^[0-9]{8,15}$");

    // ID
    bool idOk = false;
    int id = idStr.toInt(&idOk);
    if (!idOk || id <= 0) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("ID employé doit être un entier positif non nul.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // NOM
    if (nom.isEmpty() || !nomRx.match(nom).hasMatch()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Nom : lettres et espaces (max 30).");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // PRENOM
    if (prenom.isEmpty() || !nomRx.match(prenom).hasMatch()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Prénom : lettres et espaces (max 30).");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // DATE NAISSANCE
    QDate now = QDate::currentDate();
    if (!naissance.isValid() || naissance.addYears(18) > now) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("L'employé doit avoir au moins 18 ans.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // EMAIL
    if (email.isEmpty() || !emailRx.match(email).hasMatch()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Email invalide.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // TELEPHONE
    if (phone.isEmpty() || !phoneRx.match(phone).hasMatch()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Téléphone : 8 à 15 chiffres.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // ADRESSE
    if (adresse.isEmpty() || adresse.length() > 100) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Adresse requise (max 100 caractères).");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // DATE EMBAUCHE
    if (!embauche.isValid() || embauche < naissance || embauche > now) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Date d'embauche invalide.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // POSTE
    if (poste.isEmpty() || !nomRx.match(poste).hasMatch()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Poste : lettres et espaces (max 30).");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // SALAIRE
    bool salaireOk = false;
    double salaire = salaireStr.toDouble(&salaireOk);
    if (!salaireOk || salaire <= 0) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Salaire : nombre positif obligatoire.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    // Toutes validations passées, on continue
    qDebug() << "All validations passed, proceeding with employee addition";

    // Convertir les dates au format Oracle
    QString dateNaissanceStr = naissance.toString("yyyy-MM-dd");
    QString dateEmbaucheStr = embauche.toString("yyyy-MM-dd");

    QSqlQuery query(db);
    query.prepare("INSERT INTO employes (ID_EMPLOYE, NOM_EMPLOYE, PRENOM_EMPLOYE, "
                  "DATE_NAISSANCE_EMPLOYE, EMAIL_EMPLOYE, TELEPHONE_EMPLOYE, "
                  "ADRESSE_EMPLOYE, DATE_EMBAUCHE_EMPLOYE, POSTE_EMPLOYE, SALAIRE_EMPLOYE) "
                  "VALUES (:id, :nom, :prenom, TO_DATE(:date_naissance, 'YYYY-MM-DD'), "
                  ":email, :telephone, :adresse, TO_DATE(:date_embauche, 'YYYY-MM-DD'), "
                  ":poste, :salaire)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date_naissance", dateNaissanceStr);
    query.bindValue(":email", email);
    query.bindValue(":telephone", phone);
    query.bindValue(":adresse", adresse);
    query.bindValue(":date_embauche", dateEmbaucheStr);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);

    if (query.exec()) {
        QMessageBox* box = new QMessageBox(QMessageBox::Information, "Succès", "L'employé a été ajouté avec succès.", QMessageBox::NoButton, this);
        box->setStyleSheet(dialogThemeStyle());
        box->show();
        QTimer::singleShot(1000, box, SLOT(close()));
        clearFields();
        populateTable();
        updateStatistics();
    } else {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Erreur");
        msgBox.setText("Erreur lors de l'ajout : " + query.lastError().text());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
    }
}

bool Gemploye::isValidEmail(const QString &email) {
    QRegularExpression emailRegex("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    return emailRegex.match(email).hasMatch();
}

bool Gemploye::isValidPhoneNumber(const QString &phone) {
    QRegularExpression phoneRegex("^[0-9]{8,}$");
    return phoneRegex.match(phone).hasMatch();
}

void Gemploye::on_annuler_employe_clicked() {
    clearFields();
}

void Gemploye::on_chercher_employe_clicked() {
    QString searchText = ui->lineEdit_4->text();
    ui->tableview_employe->setRowCount(0);
    QSqlQuery query;
    query.prepare("SELECT * FROM employes WHERE NOM_EMPLOYE LIKE :search OR PRENOM_EMPLOYE LIKE :search OR ID_EMPLOYE LIKE :search");
    query.bindValue(":search", "%" + searchText + "%");
    query.exec();

    int row = 0;
    while (query.next()) {
        ui->tableview_employe->insertRow(row);
        for (int col = 0; col < 10; col++) {
            ui->tableview_employe->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}

void Gemploye::on_supprimer_employe_clicked() {
    int row = ui->tableview_employe->currentRow();
    if (row >= 0) {
        QString id = ui->tableview_employe->item(row, 0)->text();
        QSqlQuery query;
        query.prepare("DELETE FROM employes WHERE ID_EMPLOYE = :id");
        query.bindValue(":id", id);
        if (query.exec()) {
            QMessageBox* box = new QMessageBox(QMessageBox::Information, "Succès", "Employé supprimé avec succès.", QMessageBox::NoButton, this);
            box->setStyleSheet(dialogThemeStyle());
            box->show();
            QTimer::singleShot(1000, box, SLOT(close()));
            populateTable();
        } else {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Erreur");
            msgBox.setText("Échec de la suppression : " + query.lastError().text());
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStyleSheet(dialogThemeStyle());
            QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Veuillez sélectionner un employé à supprimer.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
    }
}

void Gemploye::on_modifier_employe_clicked()
{
    QTableWidgetItem *idItem = ui->tableview_employe->item(ui->tableview_employe->currentRow(), 0);
    if (!idItem) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Attention");
        msgBox.setText("Veuillez sélectionner un employé à modifier.");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }

    QString id = idItem->text();

    // Empêcher plusieurs boîtes de dialogue de modification employé ouvertes en même temps
    static bool dialogOuvert = false;
    if (dialogOuvert) return;
    dialogOuvert = true;

    QDialog dialog(this);
    dialog.setWindowTitle("Modifier l'employé");
    dialog.setMinimumWidth(400);
    dialog.setStyleSheet(dialogThemeStyle());

    // Appliquer le style au dialogue
    QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setSpacing(10);
    formLayout->setContentsMargins(20, 20, 20, 20);

    // Widgets
    QLineEdit *idLineEdit = new QLineEdit(id, &dialog);
    idLineEdit->setReadOnly(true);
    idLineEdit->setCursor(Qt::ArrowCursor); // Curseur flèche, pas de curseur texte
    idLineEdit->setStyleSheet(idLineEdit->styleSheet() + "QLineEdit { background-color: #f0f0f0; color: #888; }" );

    QLineEdit *nomEdit = new QLineEdit(&dialog);
    QLineEdit *prenomEdit = new QLineEdit(&dialog);
    QDateEdit *naissanceEdit = new QDateEdit(&dialog);
    QLineEdit *emailEdit = new QLineEdit(&dialog);
    QLineEdit *telEdit = new QLineEdit(&dialog);
    QLineEdit *adresseEdit = new QLineEdit(&dialog);
    QDateEdit *embaucheEdit = new QDateEdit(&dialog);
    embaucheEdit->setEnabled(false);
    embaucheEdit->setStyleSheet(embaucheEdit->styleSheet() + "QDateEdit { background-color: #f0f0f0; }");
    QLineEdit *posteEdit = new QLineEdit(&dialog);
    QDoubleSpinBox *salaireEdit = new QDoubleSpinBox(&dialog);

    // Configuration des widgets
    naissanceEdit->setCalendarPopup(true);
    embaucheEdit->setCalendarPopup(true);
    salaireEdit->setRange(0, 1000000);
    salaireEdit->setDecimals(2);
    salaireEdit->setSuffix(" €");

    // Récupérer les données
    QSqlQuery query(db);
    query.prepare("SELECT * FROM employes WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        nomEdit->setText(query.value("NOM_EMPLOYE").toString());
        prenomEdit->setText(query.value("PRENOM_EMPLOYE").toString());
        emailEdit->setText(query.value("EMAIL_EMPLOYE").toString());
        telEdit->setText(query.value("TELEPHONE_EMPLOYE").toString());
        adresseEdit->setText(query.value("ADRESSE_EMPLOYE").toString());
        posteEdit->setText(query.value("POSTE_EMPLOYE").toString());
        salaireEdit->setValue(query.value("SALAIRE_EMPLOYE").toDouble());

        QString naissanceStr = query.value("DATE_NAISSANCE_EMPLOYE").toString();
        QString embaucheStr = query.value("DATE_EMBAUCHE_EMPLOYE").toString();

        QDate naissanceDate = QDate::fromString(naissanceStr, "yyyy-MM-dd");
        QDate embaucheDate = QDate::fromString(embaucheStr, "yyyy-MM-dd");

        if (naissanceDate.isValid())
            naissanceEdit->setDate(naissanceDate);
        if (embaucheDate.isValid())
            embaucheEdit->setDate(embaucheDate);
    }

    // Ajouter les champs au layout
    formLayout->addRow("ID Employé :", idLineEdit);
    formLayout->addRow("Nom:", nomEdit);
    formLayout->addRow("Prénom:", prenomEdit);
    formLayout->addRow("Date de naissance:", naissanceEdit);
    formLayout->addRow("Email:", emailEdit);
    formLayout->addRow("Téléphone:", telEdit);
    formLayout->addRow("Adresse:", adresseEdit);
    formLayout->addRow("Date d'embauche:", embaucheEdit);
    formLayout->addRow("Poste:", posteEdit);
    formLayout->addRow("Salaire:", salaireEdit);

    mainLayout->addLayout(formLayout);

    // Boutons
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal,
        &dialog
        );
    mainLayout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    int result = dialog.exec();
    dialogOuvert = false;
    if (result == QDialog::Accepted) {
        query.prepare("UPDATE employes SET "
                      "NOM_EMPLOYE = :nom, "
                      "PRENOM_EMPLOYE = :prenom, "
                      "DATE_NAISSANCE_EMPLOYE = TO_DATE(:naissance, 'YYYY-MM-DD'), "
                      "EMAIL_EMPLOYE = :email, "
                      "TELEPHONE_EMPLOYE = :tel, "
                      "ADRESSE_EMPLOYE = :adresse, "
                      "DATE_EMBAUCHE_EMPLOYE = TO_DATE(:embauche, 'YYYY-MM-DD'), "
                      "POSTE_EMPLOYE = :poste, "
                      "SALAIRE_EMPLOYE = :salaire "
                      "WHERE ID_EMPLOYE = :id");

        query.bindValue(":id", id);
        query.bindValue(":nom", nomEdit->text());
        query.bindValue(":prenom", prenomEdit->text());
        query.bindValue(":naissance", naissanceEdit->date().toString("yyyy-MM-dd"));
        query.bindValue(":email", emailEdit->text());
        query.bindValue(":tel", telEdit->text());
        query.bindValue(":adresse", adresseEdit->text());
        query.bindValue(":embauche", embaucheEdit->date().toString("yyyy-MM-dd"));
        query.bindValue(":poste", posteEdit->text());
        query.bindValue(":salaire", salaireEdit->value());

        if (query.exec()) {
            QMessageBox* box = new QMessageBox(QMessageBox::Information, "Succès", "L'employé a été modifié avec succès.", QMessageBox::NoButton, this);
            box->setStyleSheet(dialogThemeStyle());
            box->show();
            QTimer::singleShot(1000, box, SLOT(close()));
            populateTable();
            updateStatistics();
        } else {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Erreur");
            msgBox.setText("Erreur lors de la modification : " + query.lastError().text());
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStyleSheet(dialogThemeStyle());
            QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
            msgBox.exec();
        }
    }
}

void Gemploye::updatePieChart(int type) {
    if (!chartView) {
        return;
    }

    QPieSeries *series = new QPieSeries();
    QChart *chart = new QChart();

    // Couleurs vives comme dans l'image
    QList<QColor> colors;
    colors << QColor("#FF0000")    // Rouge pour Ingénieur
           << QColor("#00FF00")     // Vert pour Trésorier
           << QColor("#0000FF")     // Bleu pour RH
           << QColor("#FFFF00");    // Jaune pour Président

    QSqlQuery query(db);
    QString title;

    switch(type) {
    case 0:
        title = "Répartition par poste";
        query.exec("SELECT POSTE_EMPLOYE, COUNT(*) as nombre FROM employes GROUP BY POSTE_EMPLOYE");
        break;
    case 1:
        title = "Répartition par âge";
        query.exec("SELECT "
                   "CASE "
                   "  WHEN TRUNC(MONTHS_BETWEEN(SYSDATE, DATE_NAISSANCE_EMPLOYE)/12) < 25 THEN '18-25 ans' "
                   "  WHEN TRUNC(MONTHS_BETWEEN(SYSDATE, DATE_NAISSANCE_EMPLOYE)/12) < 35 THEN '26-35 ans' "
                   "  WHEN TRUNC(MONTHS_BETWEEN(SYSDATE, DATE_NAISSANCE_EMPLOYE)/12) < 45 THEN '36-45 ans' "
                   "  ELSE '45+ ans' "
                   "END as tranche_age, COUNT(*) as nombre "
                   "FROM employes "
                   "GROUP BY CASE "
                   "  WHEN TRUNC(MONTHS_BETWEEN(SYSDATE, DATE_NAISSANCE_EMPLOYE)/12) < 25 THEN '18-25 ans' "
                   "  WHEN TRUNC(MONTHS_BETWEEN(SYSDATE, DATE_NAISSANCE_EMPLOYE)/12) < 35 THEN '26-35 ans' "
                   "  WHEN TRUNC(MONTHS_BETWEEN(SYSDATE, DATE_NAISSANCE_EMPLOYE)/12) < 45 THEN '36-45 ans' "
                   "  ELSE '45+ ans' "
                   "END");
        break;
    case 2:
        title = "Répartition par salaire";
        query.exec("SELECT "
                   "CASE "
                   "  WHEN SALAIRE_EMPLOYE < 2000 THEN '< 2000 €' "
                   "  WHEN SALAIRE_EMPLOYE < 3000 THEN '2000-3000 €' "
                   "  WHEN SALAIRE_EMPLOYE < 4000 THEN '3000-4000 €' "
                   "  ELSE '4000+ €' "
                   "END as tranche_salaire, COUNT(*) as nombre "
                   "FROM employes "
                   "GROUP BY CASE "
                   "  WHEN SALAIRE_EMPLOYE < 2000 THEN '< 2000 €' "
                   "  WHEN SALAIRE_EMPLOYE < 3000 THEN '2000-3000 €' "
                   "  WHEN SALAIRE_EMPLOYE < 4000 THEN '3000-4000 €' "
                   "  ELSE '4000+ €' "
                   "END");
        break;
    }

    int total = 0;
    QMap<QString, int> data;
    int colorIndex = 0;

    while (query.next()) {
        QString category = query.value(0).toString();
        int count = query.value(1).toInt();
        data[category] = count;
        total += count;
    }

    QMapIterator<QString, int> it(data);
    QFont labelFont("Segoe UI", 9);

    while (it.hasNext()) {
        it.next();
        double percentage = (total > 0) ? (it.value() * 100.0 / total) : 0;

        QPieSlice *slice = series->append(it.key(), it.value());
        slice->setBrush(colors[colorIndex % colors.size()]);
        slice->setLabelVisible(true);
        slice->setLabelColor(Qt::white);
        slice->setLabelFont(labelFont);

        // Configuration des labels externes avec connecteurs
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setLabelArmLengthFactor(0.35); // Longueur du connecteur

        // Format détaillé pour le label
        QString detailedLabel;
        if (type == 0) { // Pour les postes
            detailedLabel = QString("%1 (%2%)")
                                .arg(it.key())
                                .arg(percentage, 0, 'f', 1);
        } else if (type == 1) { // Pour l'âge
            detailedLabel = QString("%1 (%2%)")
                                .arg(it.key())
                                .arg(percentage, 0, 'f', 1);
        } else { // Pour les salaires
            detailedLabel = QString("%1 (%2%)")
                                .arg(it.key())
                                .arg(percentage, 0, 'f', 1);
        }

        slice->setLabel(detailedLabel);

        // Explosion légère des segments pour meilleure visibilité
        slice->setExploded(true);
        slice->setExplodeDistanceFactor(0.1);

        colorIndex++;
    }

    chart->addSeries(series);
    chart->setTitle(title);
    chart->setTitleFont(QFont("Segoe UI", 12, QFont::Bold));
    chart->setTitleBrush(QBrush(Qt::white));

    // Configurer la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setLabelColor(Qt::white);
    chart->legend()->setFont(QFont("Segoe UI", 10));
    chart->legend()->setMarkerShape(QLegend::MarkerShapeCircle);

    // Style du graphique
    chart->setBackgroundBrush(QBrush(QColor("#263A69")));
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setBackgroundRoundness(0);

    // Appliquer le style au chartView
    if (chartView->chart()) {
        delete chartView->chart();
    }
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

void Gemploye::updateStatistics() {
    if (!db.isOpen()) {
        if (!db.open()) {
            QMessageBox msgBox(this);
            msgBox.setWindowTitle("Erreur");
            msgBox.setText("Impossible de se connecter à la base de données pour les statistiques.");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStyleSheet(dialogThemeStyle());
            QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
            msgBox.exec();
            return;
        }
    }

    if (!chartView) {
        chartView = new QChartView(new QChart(), this);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->statsLayout->addWidget(chartView);
    }

    updatePieChart(ui->statsTypeCombo->currentIndex());
}

void Gemploye::on_trie_button_clicked() {
    int index = ui->trie_employe->currentIndex();
    QString orderBy = (index == 0) ? "DESC" : "ASC"; // 0: plus récent, 1: plus ancien
    ui->tableview_employe->setRowCount(0);
    QSqlQuery query(db);
    query.prepare("SELECT * FROM employes ORDER BY DATE_EMBAUCHE_EMPLOYE " + orderBy);
    query.exec();
    int row = 0;
    while (query.next()) {
        ui->tableview_employe->insertRow(row);
        for (int col = 0; col < 10; col++) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setForeground(QColor(Qt::black));
            ui->tableview_employe->setItem(row, col, item);
        }
        row++;
    }
}

void Gemploye::on_telech_employe_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndexList selection = ui->tableview_employe->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Facture");
        msgBox.setText("Veuillez sélectionner un employé !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }

    // Récupérer l'index de la ligne sélectionnée
    int selectedRow = selection.first().row();
    QAbstractItemModel *model = ui->tableview_employe->model();

    // Récupérer les valeurs de l'employé sélectionné
    QString cin = model->data(model->index(selectedRow, 0)).toString();
    QString nom = model->data(model->index(selectedRow, 1)).toString();
    QString prenom = model->data(model->index(selectedRow, 2)).toString();
    QString date_naissance = model->data(model->index(selectedRow, 3)).toString();
    QString email = model->data(model->index(selectedRow, 4)).toString();
    QString telephone = model->data(model->index(selectedRow, 5)).toString();
    QString adresse = model->data(model->index(selectedRow, 6)).toString();
    QString date_embauche = model->data(model->index(selectedRow, 7)).toString();
    QString poste = model->data(model->index(selectedRow, 8)).toString();
    QString salaire = model->data(model->index(selectedRow, 9)).toString();

    // Génération du HTML pour la fiche employé
    QString html = "<html><head>"
                   "<style>"
                   "body { font-family: Arial, sans-serif; padding: 20px; }"
                   "h1 { text-align: center; color:#6f7dab; }"
                   "table { width: 100%; border-collapse: collapse; margin-top: 20px; }"
                   "th, td { padding: 10px; text-align: left; border: 1px solid black; }"
                   "th { background-color: #6f7dab; color: white; }"
                   "td { background-color: #f9f9f9; }"
                   ".footer { text-align: center; margin-top: 20px; font-style: italic; }"
                   ".logo { text-align: center; margin-bottom: 10px; }"
                   "</style></head><body>";
    html += "<h1>Fiche de l'Employé</h1>";
    html += "<div class='table-container'>";
    html += "<table>";
    html += "<tr><th>CIN</th><td>" + cin + "</td></tr>";
    html += "<tr><th>Nom</th><td>" + nom + "</td></tr>";
    html += "<tr><th>Prénom</th><td>" + prenom + "</td></tr>";
    html += "<tr><th>Date de naissance</th><td>" + date_naissance + "</td></tr>";
    html += "<tr><th>Email</th><td>" + email + "</td></tr>";
    html += "<tr><th>Téléphone</th><td>" + telephone + "</td></tr>";
    html += "<tr><th>Adresse</th><td>" + adresse + "</td></tr>";
    html += "<tr><th>Date d'embauche</th><td>" + date_embauche + "</td></tr>";
    html += "<tr><th>Poste</th><td>" + poste + "</td></tr>";
    html += "<tr><th>Salaire</th><td>" + salaire + "</td></tr>";
    html += "</table>";
    html += "</div>";
    html += "<div class='footer'>Document généré par le système de gestion des employés</div>";
    html += "<br><br><p style='text-align: right;'>Signature du Responsable</p>";
    html += "</body></html>";

    // Demander où enregistrer le PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer la Fiche", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return;
    }

    // Création du document PDF
    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    document.print(&printer);

    QMessageBox* box = new QMessageBox(QMessageBox::Information, "Fiche Employé", "La fiche de l'employé a été générée avec succès !");
    box->setStyleSheet(dialogThemeStyle());
    box->show();
    QTimer::singleShot(1000, box, SLOT(close()));
}

void Gemploye::on_statsTypeCombo_currentIndexChanged(int index) {
    updatePieChart(index);
}

void Gemploye::on_deconnexion_button_clicked()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Déconnexion");
    msgBox.setText("Voulez-vous vraiment vous déconnecter ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet(dialogThemeStyle()); // Applique le même thème
    int reply = msgBox.exec();
    if (reply == QMessageBox::Yes) {
        this->close();
        if (fenetreConnexion) fenetreConnexion->show();
    }
}

void Gemploye::on_consulter_employe_clicked()
{
    if (fenetreMenu) {
        fenetreMenu->show();
        fenetreMenu->raise();
        fenetreMenu->activateWindow();
        this->hide();
    }
}
