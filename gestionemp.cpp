#include "gestionemp.h"
#include "ui_gestionemp.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QPrinter>
#include "access.h"
#include "dialogtheme.h"
#include <QTimer>

gestionemp::gestionemp(access *fenetreConnexion, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gestionemp)
    , fenetreConnexion(fenetreConnexion)
{
    ui->setupUi(this);
    // Sélection de toute la ligne
    ui->tableview_employe->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Désactiver l'édition directe par double-clic ou clic
    ui->tableview_employe->setEditTriggers(QAbstractItemView::NoEditTriggers);
    populateTable(); // Affiche les employés dès l'ouverture
    connect(ui->trie_button, &QPushButton::clicked, this, &gestionemp::on_trie_button_clicked);
}

gestionemp::~gestionemp()
{
    delete ui;
}

void gestionemp::populateTable() {
    ui->tableview_employe->setRowCount(0);
    QSqlQuery query("SELECT * FROM EMPLOYES");
    if (!query.isActive()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Erreur SQL");
        msgBox.setText("La requête n'a pas pu s'exécuter !");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
        return;
    }
    int row = 0;
    bool auMoinsUn = false;
    while (query.next()) {
        ui->tableview_employe->insertRow(row);
        for (int col = 0; col < 10; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setForeground(Qt::black);
            ui->tableview_employe->setItem(row, col, item);
        }
        row++;
        auMoinsUn = true;
    }
    if (!auMoinsUn) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Aucun employé");
        msgBox.setText("Aucun employé trouvé dans la base de données.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
    }
}

void gestionemp::clearFields() {
    // Efface les champs de recherche ou d'ajout (à adapter selon l'UI)
    ui->lineEdit_4->clear();
}

void gestionemp::on_chercher_employe_clicked() {
    QString critere = ui->lineEdit_4->text();
    ui->tableview_employe->setRowCount(0);
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE NOM_EMPLOYE LIKE :critere OR PRENOM_EMPLOYE LIKE :critere");
    query.bindValue(":critere", "%" + critere + "%");
    query.exec();
    int row = 0;
    while (query.next()) {
        ui->tableview_employe->insertRow(row);
        for (int col = 0; col < 10; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setForeground(Qt::black);
            ui->tableview_employe->setItem(row, col, item);
        }
        row++;
    }
}

void gestionemp::on_telech_employe_clicked()
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

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Fiche Employé");
    msgBox.setText("La fiche de l'employé a été générée avec succès !");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStyleSheet(dialogThemeStyle());
    QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
    msgBox.exec();
}

void gestionemp::updatePieChart(int type) {
    // Exemple de stats: répartir les employés par poste
    QPieSeries *series = new QPieSeries();
    QSqlQuery query("SELECT POSTE_EMPLOYE, COUNT(*) FROM EMPLOYES GROUP BY POSTE_EMPLOYE");
    while (query.next()) {
        series->append(query.value(0).toString(), query.value(1).toInt());
    }
    if (!chartView) {
        chartView = new QChartView(new QChart(), this);
        ui->statsLayout->addWidget(chartView);
    }
    chartView->chart()->removeAllSeries();
    chartView->chart()->addSeries(series);
    chartView->chart()->setTitle("Répartition des employés par poste");
}

void gestionemp::updateStatistics() {
    updatePieChart(0);
}

void gestionemp::on_statsTypeCombo_currentIndexChanged(int index) {
    updatePieChart(index);
}

void gestionemp::on_deconnexion_button_clicked() {
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Déconnexion");
    msgBox.setText("Voulez-vous vraiment vous déconnecter ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet(dialogThemeStyle());
    int reply = msgBox.exec();
    if (reply == QMessageBox::Yes) {
        this->close();
        if (fenetreConnexion) fenetreConnexion->show();
    }
}

bool gestionemp::isValidEmail(const QString &email) {
    QRegularExpression re("^[\\w\\-.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
    return re.match(email).hasMatch();
}

bool gestionemp::isValidPhoneNumber(const QString &phone) {
    QRegularExpression re("^\\d{8,15}$");
    return re.match(phone).hasMatch();
}

void gestionemp::on_trie_button_clicked() {
    int index = ui->trie_employe->currentIndex();
    QString orderBy = (index == 0) ? "DESC" : "ASC"; // 0: plus récent, 1: plus ancien
    ui->tableview_employe->setRowCount(0);
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES ORDER BY DATE_EMBAUCHE_EMPLOYE " + orderBy);
    query.exec();
    int row = 0;
    bool auMoinsUn = false;
    while (query.next()) {
        ui->tableview_employe->insertRow(row);
        for (int col = 0; col < 10; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setForeground(Qt::black);
            ui->tableview_employe->setItem(row, col, item);
        }
        row++;
        auMoinsUn = true;
    }
    if (!auMoinsUn) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Aucun employé");
        msgBox.setText("Aucun employé trouvé dans la base de données.");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setStyleSheet(dialogThemeStyle());
        QTimer::singleShot(1000, &msgBox, [&msgBox]() { msgBox.close(); });
        msgBox.exec();
    }
}
