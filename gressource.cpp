#include "gressource.h"
#include "ui_gressource.h"
#include <QMessageBox>
#include <ressource.h>
#include <QRegularExpression>
#include <QSqlError>
#include <QSortFilterProxyModel>
#include <QRegularExpression>
#include <QPainter>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QCategoryAxis>
#include <QLineSeries>
#include <QSoundEffect>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>



Gressource::Gressource(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gressource)
    ,R()
{
    ui->setupUi(this);
    ui->tableView->setModel(R.afficher_ressource());
    connect(ui->lineEdit_nomressources, &QLineEdit::textChanged, this, &Gressource::verifierSaisie);
    connect(ui->quantite_ressource, &QLineEdit::textChanged, this, &Gressource::verifierSaisie);
    connect(ui->cout_ressource, &QLineEdit::textChanged, this, &Gressource::verifierSaisie);
    connect(ui->description_ressource, &QPlainTextEdit::textChanged, this, &Gressource::verifierSaisie);
    connect(ui->dateTimeEdit_ressource, &QDateTimeEdit::dateChanged, this, &Gressource::verifierSaisie);
    afficher_statistique_ressource();
    verifierRessourcesFaibles();

}

Gressource::~Gressource()
{
    delete ui;
}
void Gressource::verifierSaisie()
{
    QString nom_ressource = ui->lineEdit_nomressources->text().trimmed();
    QString quantite_text = ui->quantite_ressource->text();
    QString cout_text = ui->cout_ressource->text();
    QDate date_achat = ui->dateTimeEdit_ressource->date();
    QString type_ressource = ui->type_ressource->currentText();
    QString description = ui->description_ressource->toPlainText().trimmed();

    // Expression régulière pour vérifier que le nom ne contient pas de chiffres et a une longueur maximale de 20 caractères
    QRegularExpression regexNom("^[^0-9]{1,20}$");

    // Vérification du nom de la ressource
    if (nom_ressource.isEmpty() || !regexNom.match(nom_ressource).hasMatch()) {
        ui->lineEdit_nomressources->setStyleSheet("border: 2px solid red;");
        ui->lineEdit_nomressources->setToolTip("Le nom de la ressource doit contenir entre 1 et 20 caractères et ne pas inclure de chiffres.");
    } else {
        ui->lineEdit_nomressources->setStyleSheet("");
        ui->lineEdit_nomressources->setToolTip("");
    }

    // Vérification de la quantité (doit être un entier positif de 3 chiffres maximum)
    bool ok;
    int quantite_ressource = quantite_text.toInt(&ok);
    if (!ok || quantite_ressource <= 0 || quantite_text.length() > 3) {
        ui->quantite_ressource->setStyleSheet("border: 2px solid red;");
        ui->quantite_ressource->setToolTip("La quantité doit être un entier positif de 3 chiffres maximum.");
    } else {
        ui->quantite_ressource->setStyleSheet("");
        ui->quantite_ressource->setToolTip("");
    }

    // Vérification du coût (doit être un entier positif de 9 chiffres maximum)
    int cout_ressource = cout_text.toInt(&ok);
    if (!ok || cout_ressource < 0 || cout_text.length() > 9) {
        ui->cout_ressource->setStyleSheet("border: 2px solid red;");
        ui->cout_ressource->setToolTip("Le coût doit être un entier positif de 9 chiffres maximum.");
    } else {
        ui->cout_ressource->setStyleSheet("");
        ui->cout_ressource->setToolTip("");
    }

    // Vérification de la date d'achat (ne doit pas être dans le passé)
    if (date_achat > QDate::currentDate()) {
        ui->dateTimeEdit_ressource->setStyleSheet("border: 2px solid red;");

    } else {
        ui->dateTimeEdit_ressource->setStyleSheet("");
    }

    // Vérification du type de ressource (doit être sélectionné)
    if (type_ressource.isEmpty()) {
        ui->type_ressource->setStyleSheet("border: 2px solid red;");
    } else {
        ui->type_ressource->setStyleSheet("");
    }

    // Vérification de la description (ne doit pas être vide)
    if (description.isEmpty()) {
        ui->description_ressource->setStyleSheet("border: 2px solid red;");
    } else {
        ui->description_ressource->setStyleSheet("");
        ui->description_ressource->setToolTip("");
    }

    // Activation/désactivation du bouton en fonction de la validité des champs
    bool tousChampsValides = !nom_ressource.isEmpty() && regexNom.match(nom_ressource).hasMatch() &&
                             quantite_ressource > 0 && quantite_text.length() <= 3 &&
                             cout_ressource >= 0 && cout_text.length() <= 9 &&
                             date_achat >= QDate::currentDate() && !type_ressource.isEmpty() && !description.isEmpty();

    ui->ajouter_ressource->setEnabled(tousChampsValides);
}

void Gressource::on_ajouter_ressource_clicked()
{

    QString nom_ressource = ui->lineEdit_nomressources->text().trimmed();
    QDate date_achat = ui->dateTimeEdit_ressource->date();
    int quantite_ressource = ui->quantite_ressource->text().toInt();
    QString type_ressource = ui->type_ressource->currentText();
    QString description = ui->description_ressource->toPlainText().trimmed();
    int cout_ressource = ui->cout_ressource->text().toInt();
    if (budgetGlobal - cout_ressource < 50.0) {
        QMessageBox::warning(this, " Dépassement",
                             "Vous avez dépassé la limite de budget global !");
        return;
    }
    // Vérification des champs
    if (nom_ressource.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Le nom de la ressource ne peut pas être vide.");
        return;
    }

    if (quantite_ressource <= 0)
    {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre positif.");
        return;
    }

    if (cout_ressource < 0)
    {
        QMessageBox::warning(this, "Erreur", "Le coût ne peut pas être négatif.");
        return;
    }

    if (date_achat > QDate::currentDate())
    {
        QMessageBox::warning(this, "Erreur", "La date d'achat ne peut pas être dans le futur.");
        return;
    }

    if (type_ressource.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type de ressource.");
        return;
    }

    if (description.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une description.");
        return;
    }

    // Création et ajout de la ressource
    ressource R(nom_ressource, type_ressource, quantite_ressource, cout_ressource, date_achat, description);
    bool test = R.ajouter_ressource();

    if (test)
    {
        budgetGlobal -= cout_ressource;

        //  Mise à jour du label affichant le budget restant
        ui->labelbudget->setText(QString("Budget restant : %1 dt").arg(budgetGlobal, 0, 'f', 2));
        ui->tableView->setModel(R.afficher_ressource());
        afficher_statistique_ressource();

        QMessageBox::information(this, "Succès", "Ajout effectué !");
    }
    else
    {
        QMessageBox::critical(this, "Échec", "Ajout non effectué ! Vérifiez vos données.");
    }
}


void Gressource::on_delete_ressource_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    // Vérifier si une ligne est sélectionnée
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner une ligne à supprimer."));
        return;
    }

    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int id_ressource = index.sibling(index.row(), 0).data().toInt();


    // Demander confirmation avant la suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirmation de suppression"),
                                  tr("Voulez-vous vraiment supprimer ce ressource ?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Supprimer le ressource de la base de données
        ressource R;
        if (R.suprimer_ressource(id_ressource)) {
            // Mise à jour de la vue de la table
            ui->tableView->setModel(R.afficher_ressource());
            afficher_statistique_ressource();
            QMessageBox::information(this, tr("Succès"), tr("ressource supprimé avec succès."));
        } else {
            QMessageBox::critical(this, tr("Échec"), tr("Échec de la suppression du ressource."));
        }
    }
}



void Gressource::on_update_ressource_clicked()
{
    // Vérifier si une ligne est sélectionnée
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez sélectionner une ligne à modifier."));
        return;
    }

    // Récupérer l'index de la ligne sélectionnée
    int row = selectedIndexes.first().row();

    // Récupérer l'ID du ressource (qui doit être stocké dans la première colonne)
    int id_ressource = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();

    // Récupérer les valeurs modifiées directement depuis la table
    QString nom_ressource = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QString type_ressource = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString();
    int quantite_ressource = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toInt();
    int  cout_ressource = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toInt();
    QDate date_achat = ui->tableView->model()->data(ui->tableView->model()->index(row, 5)).toDate();
    QString description = ui->tableView->model()->data(ui->tableView->model()->index(row, 6)).toString();


    // Vérification des champs obligatoires
    if (nom_ressource.isEmpty() || type_ressource.isEmpty() || description.isEmpty() ) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez remplir tous les champs avant de mettre à jour."));
        return;
    }

    // Confirmation de la mise à jour
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirmation"),
                                  tr("Voulez-vous enregistrer les modifications ?"),
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Mettre à jour la base de données
        ressource R;
        if (R.update_ressource(id_ressource ,nom_ressource, type_ressource, quantite_ressource, cout_ressource, date_achat, description)) {
            QMessageBox::information(this, tr("Succès"), tr("ressource mis à jour avec succès."));
        } else {
            QMessageBox::critical(this, tr("Erreur"), tr("Échec de la mise à jour du ressource."));
        }

        // Rafraîchir l'affichage des données dans la table
        ui->tableView->setModel(R.afficher_ressource());
        afficher_statistique_ressource();
    }
}


void Gressource::on_tri_ressource_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("RESSOURCES");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("cout"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("description"));



    if (ui->tri_2_ressource->currentText() == "Quantité") {
        model->setSort(3, Qt::AscendingOrder);
    }

    model->select();

    if (model->lastError().isValid()) {
        qDebug() << "Erreur dans la requête SQL: " << model->lastError().text();
        QMessageBox::warning(this, tr("Erreur SQL"), tr("Une erreur est survenue lors de l'exécution de la requête."));
        ui->tableView->setModel(nullptr);
    } else {
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(5, true);
    }
}


void Gressource::on_recherche_ressource_clicked()

    {
        QString statut = ui->recherche_ressource_2->text(); // Récupérer le statut entré par l'utilisateur

        if (statut.isEmpty()) {
            QMessageBox::warning(this, "Recherche", "Veuillez entrer un statut !");
            return;
        }

        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(R.afficher_ressource());

        proxyModel->setFilterKeyColumn(R.afficher_ressource()->fieldIndex("statut"));
        proxyModel->setFilterFixedString(statut);

        ui->tableView->setModel(proxyModel);
    }


    void Gressource::on_telecharger_ressource_clicked()
    {
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
        if (fileName.isEmpty())
            return;

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        printer.setPageMargins(QMarginsF(15, 15, 15, 15));

        QPainter painter;
        if (!painter.begin(&printer)) {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier PDF.");
            return;
        }

        int y = 100;
        const int rowHeight = 30;
        const int colWidth = 80;

        QFont font;
        font.setPointSize(10);
        painter.setFont(font);

        // Titres des colonnes
        for (int col = 0; col < ui->tableView->model()->columnCount() ; ++col) {
            QString header = ui->tableView->model()->headerData(col, Qt::Horizontal).toString();
            painter.drawText(col * colWidth, y, colWidth, rowHeight, Qt::AlignLeft, header);
        }

        y += rowHeight;


        for (int row = 0; row < ui->tableView->model()->rowCount() ; ++row) {
            for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
                QModelIndex index = ui->tableView->model()->index(row, col);
                QString data = index.data().toString();
                painter.drawText(col * colWidth, y, colWidth, rowHeight, Qt::AlignLeft, data);
            }
            y += rowHeight;


            if (y > printer.height() - 100) {
                printer.newPage();
                y = 100;
            }
        }

        painter.end();
        QMessageBox::information(this, "Succès", "Liste exportée en PDF avec succès !");
    }

    void Gressource::verifierRessourcesFaibles()
    {
        QSqlQuery query;
        QString message;

        if (query.exec("SELECT id_ressource, nom_ressource, quantite_ressource FROM RESSOURCES WHERE quantite_ressource < 5")) {
            while (query.next()) {
                int id = query.value(0).toInt();
                QString nom = query.value(1).toString();
                int quantite = query.value(2).toInt();

                message += " ID: " + QString::number(id) +
                           " | Nom: " + nom +
                           " | Quantité: " + QString::number(quantite) + "\n";
            }

            if (!message.isEmpty()) {

                QSoundEffect *sound = new QSoundEffect(this);
                sound->setSource(QUrl::fromLocalFile("C:/Users/dhiab/Downloads/songsong.wav")); // ou "qrc:/sons/alert.wav" si via .qrc
                sound->setVolume(1.0); // entre 0.0 et 1.0
                sound->play();


                QMessageBox *alertBox = new QMessageBox(this);
                alertBox->setIcon(QMessageBox::Warning);
                alertBox->setWindowTitle("Alerte Ressources");
                alertBox->setText(" Ressources avec quantité faible :");
                alertBox->setInformativeText(message);
                alertBox->setStandardButtons(QMessageBox::Ok);
                alertBox->setStyleSheet(R"(
    QMessageBox {
        background-color: #fff5f5;
        border: 2px solid #e74c3c;
        border-radius: 10px;
        font-family: 'Segoe UI';
        font-size: 14px;
    }
    QLabel {
        color: #c0392b;
        font-weight: bold;
    }
    QPushButton {
        background-color: #e74c3c;
        color: white;
        border: none;
        padding: 6px 12px;
        border-radius: 5px;
        min-width: 80px;
    }
    QPushButton:hover {
        background-color: #c0392b;
    }
)");
                alertBox->show();
            } else {
                qDebug() << "Aucune ressource faible.";
            }
        } else {
            QMessageBox::critical(this, "Erreur SQL", "Erreur lors de la récupération des données.");
            qDebug() << query.lastError().text();
        }
    }



void Gressource::afficher_statistique_ressource()
{
    // Mettre à jour le modèle de la table si nécessaire
    ui->tableView->setModel(R.afficher_ressource());

    // Actualiser les données du graphique
    QPieSeries *series = new QPieSeries();

    QSqlQuery query;
    query.prepare("SELECT type_ressource, COUNT(*) FROM RESSOURCES GROUP BY type_ressource");

    if (query.exec()) {
        while (query.next()) {
            QString type = query.value(0).toString();
            int count = query.value(1).toInt();
            series->append(type, count);
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des ressources par type");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Nettoyage du contenu précédent dans frame_stat
    QLayout *oldLayout = ui->frame_stat->layout();
    if (oldLayout != nullptr) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // Ajout du nouveau graphique
    QVBoxLayout *layout = new QVBoxLayout(ui->frame_stat);
    layout->addWidget(chartView);
    ui->frame_stat->setLayout(layout);
}


void Gressource::on_preduction_ressource_clicked()
{
    QSqlQuery query;
    QString resultat;
    double coutTotal = 0.0;

    // Supposons que ta table s'appelle "ressources"
    query.exec("SELECT nom_ressource, quantite_ressource, cout_ressource FROM ressources");

    while (query.next()) {
        QString nom = query.value(0).toString();
        int quantite = query.value(1).toInt();
        double cout = query.value(2).toDouble()/quantite;

        if (quantite < 5) {
            int manque = 5 - quantite;
            double coutPrevu = manque * cout;
            coutTotal += coutPrevu;

            resultat += QString("Ressource: %1\n").arg(nom);
            resultat += QString("  Quantité actuelle: %1\n").arg(quantite);
            resultat += QString("  Manque: %1\n").arg(manque);
            resultat += QString("  Coût prévisionnel: %1 dt\n\n").arg(coutPrevu, 0, 'f', 2);
        }
    }

    resultat += QString("💰 Coût total prévisionnel: %1 dt").arg(coutTotal, 0, 'f', 2);

    // Affichage dans un QTextEdit
    ui->rsult_preduction->setText(resultat);

}
