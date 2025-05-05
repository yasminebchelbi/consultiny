#include "oublie.h"
#include "ui_oublie.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSqlQuery>
#include <QSqlError>
#include <QProcess>
#include <QTextStream>
#include <QSslSocket>
#include "dialogtheme.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrlQuery>
#include <QUrl>
#include <QRegularExpression>
#include "changemdpdialog.h"
#include <QTimer>

oublie::oublie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::oublie),
    codeRecup(0)
{
    ui->setupUi(this);
    this->setStyleSheet(dialogThemeStyle());
    connect(ui->code_button, &QPushButton::clicked, this, &oublie::on_code_button_clicked);
}

oublie::~oublie()
{
    delete ui;
}

void oublie::on_code_button_clicked()
{
    telRecup = ui->num_recup->text().trimmed();
    if (telRecup.isEmpty()) {
        QMessageBox* box = new QMessageBox(QMessageBox::Warning, "Erreur", "Veuillez remplir le champ numéro de téléphone.", QMessageBox::NoButton, this);
        box->setStyleSheet(dialogThemeStyle());
        box->show();
        QTimer::singleShot(1000, box, SLOT(close()));
        return;
    }
    // Contrôle du format : doit être au format tunisien international +216XXXXXXXX
    QRegularExpression regex("^\\+216\\d{8}$");
    if (!regex.match(telRecup).hasMatch()) {
        QMessageBox* box = new QMessageBox(QMessageBox::Warning, "Erreur", "Le numéro doit être au format tunisien international, ex : +216XXXXXXXX", QMessageBox::NoButton, this);
        box->setStyleSheet(dialogThemeStyle());
        box->show();
        QTimer::singleShot(1000, box, SLOT(close()));
        return;
    }
    // Vérifier si le numéro existe dans la base
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM employes WHERE TELEPHONE_EMPLOYE = :tel");
    query.bindValue(":tel", telRecup);
    if (!query.exec() || !query.next() || query.value(0).toInt() == 0) {
        QMessageBox* box = new QMessageBox(QMessageBox::Warning, "Erreur", "Aucun compte associé à ce numéro de téléphone.", QMessageBox::NoButton, this);
        box->setStyleSheet(dialogThemeStyle());
        box->show();
        QTimer::singleShot(1000, box, SLOT(close()));
        return;
    }
    // Générer un code à 4 chiffres
    codeRecup = QRandomGenerator::global()->bounded(1000, 10000);
    envoyerSmsRecup(telRecup, codeRecup);
    ouvrirFenetreCode();
}

void oublie::envoyerSmsRecup(const QString &numero, int code) {
    // Paramètres Twilio
    QString accountSid = "ACde52fb068877124ce97c731be00ff6c6";
    QString authToken = "1d78e77c7fa8f0a06a316531c7eef333";
    QString fromNumber = "+19342055548";
    QString toNumber = numero; // doit être au format international, ex: +216XXXXXXXX

    QString message = QString("Votre code de récupération est : %1").arg(code);

    QNetworkAccessManager manager;
    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(accountSid));
    QNetworkRequest request(url);

    // Authentification HTTP Basic
    QByteArray auth = QString("%1:%2").arg(accountSid, authToken).toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + auth);

    QUrlQuery params;
    params.addQueryItem("To", toNumber);
    params.addQueryItem("From", fromNumber);
    params.addQueryItem("Body", message);

    QByteArray data = params.query(QUrl::FullyEncoded).toUtf8();
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QEventLoop loop;
    QNetworkReply *reply = manager.post(request, data);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QMessageBox msgBox(QMessageBox::Information, "SMS envoyé", "Un SMS de récupération a été envoyé à " + numero + ".");
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.exec();
    } else {
        QString details = "Échec de l'envoi du SMS : " + reply->errorString() +
            "\nCode HTTP : " + QString::number(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()) +
            "\nRéponse : " + reply->readAll();
        QMessageBox msgBox(QMessageBox::Critical, "Erreur SMS", details);
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.exec();
    }
    reply->deleteLater();
}

void oublie::ouvrirFenetreCode()
{
    // Empêcher plusieurs boîtes de dialogue de code de récupération ouvertes en même temps
    static bool dialogOuvert = false;
    if (dialogOuvert) return;
    dialogOuvert = true;
    QDialog codeDialog(this);
    codeDialog.setWindowTitle("Entrer le code de récupération");
    codeDialog.setStyleSheet(dialogThemeStyle());
    QVBoxLayout *layout = new QVBoxLayout(&codeDialog);
    QLabel *label = new QLabel("Veuillez entrer le code reçu par SMS :");
    QLineEdit *codeLineEdit = new QLineEdit();
    codeLineEdit->setPlaceholderText("Code à 4 chiffres");
    QPushButton *validerButton = new QPushButton("Valider");
    layout->addWidget(label);
    layout->addWidget(codeLineEdit);
    layout->addWidget(validerButton);
    QObject::connect(validerButton, &QPushButton::clicked, [&]() {
        if (codeLineEdit->text().toInt() == codeRecup) {
            ChangeMdpDialog dlg(telRecup, &codeDialog);
            dlg.exec();
            codeDialog.accept();
        } else {
            QMessageBox msgBox(QMessageBox::Warning, "Erreur", "Code incorrect.");
            msgBox.setStyleSheet(dialogThemeStyle());
            msgBox.exec();
        }
    });
    int result = codeDialog.exec();
    dialogOuvert = false;
    if (result == QDialog::Accepted) {
        // Fermeture automatique après succès
        this->close();
        QMessageBox msgBox(QMessageBox::Information, "Succès", "Code correct ! Vous pouvez maintenant réinitialiser votre mot de passe.");
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.exec();
    }
}
