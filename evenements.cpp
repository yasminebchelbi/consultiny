#include "evenements.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
#include <QPdfWriter>
#include <QVariant>
#include <QMap>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QFileInfo>
#include <QAbstractButton>
#include <QFontDatabase>
#include <QMap>
#include <QPair>
#include <QDate>
#include <QTextStream>
#include <QDebug>
#include "aihelper.h"

AIHelper ai;


//*************************************************************CONSTRUCTEUR+INITIALISATION***********************************************************
Evenements::Evenements()
    : ID_evenement(0),
    nom_evenement(""),
    date_debut_evenement(QDate::currentDate()),
    date_fin_evenement(QDate::currentDate()),
    nbr_participants_evenement(0),
    adresse_evenement(""),
    description_evenement(""),
    type_evenement(""),
    lieu_evenement("")
{
}

//****************************************************************constructeur paramétré***********************************************************
Evenements::Evenements(QString nom, QDate date_debut, QDate date_fin, int nbr_participants, QString adresse, QString description, QString type, QString lieu) {
    this->nom_evenement = nom;
    this->date_debut_evenement = date_debut;
    this->date_fin_evenement = date_fin;
    this->nbr_participants_evenement = nbr_participants;
    this->adresse_evenement = adresse;
    this->description_evenement = description;
    this->type_evenement = type;
    this->lieu_evenement = lieu;
}


//**********************************************************l'ajout*****************************************************************
bool Evenements::ajouter_evenements() {
    QSqlQuery query;


    query.prepare("INSERT INTO EVENEMENTS(NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT, LIEU_EVENEMENT) "
                  "VALUES(:nom_evenement, :date_debut_evenement, :date_fin_evenement, :nbr_participants_evenement, :adresse_evenement, :description_evenement, :type_evenement , :lieu_evenement)");

    query.bindValue(":nom_evenement", nom_evenement);
    query.bindValue(":date_debut_evenement", date_debut_evenement);
    query.bindValue(":date_fin_evenement", date_fin_evenement);
    query.bindValue(":nbr_participants_evenement", nbr_participants_evenement);
    query.bindValue(":adresse_evenement", adresse_evenement);
    query.bindValue(":description_evenement",  description_evenement);
    query.bindValue(":type_evenement", type_evenement);
    query.bindValue(":lieu_evenement", lieu_evenement);





    return query.exec();
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
    }
}
//*****************************l'affichage (sqltablemodel bich tnajem men ba3d ta3mel les modifications fel table menou lih)**************************

QSqlTableModel *Evenements::afficher_evenements() {
    qDebug() << "afficher_evenements() appelée";
    QSqlTableModel * model = new QSqlTableModel();

    model->setQuery("SELECT ID_EVENEMENT,NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT, LIEU_EVENEMENT FROM evenements") ;

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre des participants"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("lieu"));

    //return model;
    if (model->lastError().isValid()) {
        qDebug() << "Erreur de requête: " << model->lastError().text();
    } else {
        qDebug() << "Requête réussie!";
        qDebug() << "Nombre de lignes retournées: " << model->rowCount();
    }

return model;
}


//*****************************************la suppression*********************************************************************************************
bool Evenements::supprimer_evenements(int ID_EVENEMENT) {
    QSqlQuery query;
    QString res=QString::number(ID_EVENEMENT);
    query.prepare(("delete from evenements where ID_EVENEMENT= :ID_EVENEMENT"));
    query.bindValue(":ID_EVENEMENT",res);
    return query.exec();

}
/************************************la  modification**********************************************************************************************/
bool Evenements::modifier_evenement(int id_evenement, QString nom_evenement, QDate date_debut_evenement, QDate date_fin_evenement, int nbr_participants_evenement, QString adresse_eevenement, QString description_evenement, QString type_evenement ,QString lieu_evenement) {
    QSqlQuery query;
    query.prepare("UPDATE evenements SET nom_evenement = :nom_evenement, date_debut_evenement = :date_debut_evenement, date_fin_evenement = :date_fin_evenement, "
                  "nbr_participants_evenement = :nbr_participants_evenement, adresse_eevenement = :adresse_eevenement, description_evenement = :description_evenement, "
                  "type_evenement = :type_evenement , lieu_evenement = :lieu_evenement WHERE id_evenement = :id_evenement");
    query.bindValue(":id_evenement", id_evenement);
    query.bindValue(":nom_evenement", nom_evenement);
    query.bindValue(":date_debut_evenement", date_debut_evenement);
    query.bindValue(":date_fin_evenement", date_fin_evenement);
    query.bindValue(":nbr_participants_evenement", nbr_participants_evenement);
    query.bindValue(":adresse_eevenement", adresse_eevenement);
    query.bindValue(":description_evenement", description_evenement);
    query.bindValue(":type_evenement", type_evenement);
    query.bindValue(":lieu_evenement", lieu_evenement);


    return query.exec();
}

//**********************************telecharger pdf*************************************************************************************************

void Evenements::telecharger_pdf_evenement(int idEvenement)
{
    // Demander à l'utilisateur où enregistrer le fichier
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Enregistrer PDF", "", "PDF Files (*.pdf)");

    if (fileName.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Aucun fichier sélectionné !");
        return;
    }

    // Créer un QPdfWriter
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A6));
    writer.setResolution(300);

    QTextDocument doc;
    QString content;

    // Ajouter un style CSS pour personnaliser le titre, le tableau et l'image
    content.append("<style>");

    // Titre principal - taille augmentée à 54px
    content.append("p { "
                   "color: darkblue; "
                   "font-family: 'Arial'; "
                   "font-size: 50px ; "
                   "text-align: center; "
                   "font-weight: bold; "
                   "margin-bottom: 30px;"  // Marge augmentée
                   "}");

    // Style pour le tableau avec HTML amélioré
    content.append("table { "
                   "width: 80%; "
                   "center !important;"                   // Utiliser 80% de la largeur de la page pour le tableau
                   "margin: 0 auto; "  // Centre le tableau horizontalement
                   "border-collapse: collapse; "
                   "font-family: 'Arial'; "
                   "font-size: 32px; "  // Augmenter la taille du texte pour qu'il soit bien visible
                   "border: 2px solid #ddd; "  // Bordure générale du tableau
                   "}");

    // Style pour les cellules du tableau
    content.append("td, th { "
                   "border: 2px solid #ddd; "  // Bordure autour des cellules
                   "padding: 20px; "  // Augmenter l'espace autour du texte dans les cellules
                   "font-size: 30px; "  // Augmenter la taille du texte dans les cellules
                   "text-align: left; "  // Alignement du texte à gauche
                   "background-color: #f9f9f9;" // Couleur de fond des cellules
                   "}");

    // Style pour les en-têtes de tableau
    content.append("th { "
                   "background-color: #6f7dab; "  // Couleur d'arrière-plan des en-têtes
                   "color: white; "
                   "font-size: 36px; "  // Taille augmentée pour les en-têtes
                   "font-weight: bold; "
                   "padding: 20px;"  // Padding augmenté pour un meilleur espacement
                   "}");

    // Fermer la balise style
    content.append("</style>");

    // Ajouter le titre
    content.append("<p>Information de l'événement </p>");

    // Créer un tableau HTML avec 2 colonnes : label et valeur
    content.append("<table>");

    // Requête SQL pour récupérer l'événement sélectionné par son ID
    QSqlQuery query;
    query.prepare("SELECT ID_EVENEMENT, NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, lieu_evenement FROM evenements WHERE ID_EVENEMENT = :id");
    query.bindValue(":id", idEvenement);

    if (query.exec() && query.next()) {
        // Affichage des données dans le tableau avec les libellés à gauche
        content.append("<tr><th>ID :</th><td>" + query.value(0).toString() + "</td></tr>");  // ID_EVENEMENT
        content.append("<tr><th>Nom :</th><td>" + query.value(1).toString() + "</td></tr>");  // NOM_EVENEMENT
        content.append("<tr><th>Date Début :</th><td>" + query.value(2).toString() + "</td></tr>");  // DATE_DEBUT_EVENEMENT
        content.append("<tr><th>Date Fin :</th><td>" + query.value(3).toString() + "</td></tr>");  // DATE_FIN_EVENEMENT
        content.append("<tr><th>Adresse :</th><td>" + query.value(4).toString() + "</td></tr>");  // ADRESSE_EEVENEMENT
        content.append("<tr><th>Description :</th><td>" + query.value(5).toString() + "</td></tr>");  // DESCRIPTION_EVENEMENT
        content.append("<tr><th>Participants :</th><td>" + query.value(6).toString() + "</td></tr>");  // NBR_PARTICIPANTS_EVENEMENT
        content.append("<tr><th>Lieu :</th><td>" + query.value(7).toString() + "</td></tr>");  // lieu_evenement
    }

    content.append("</table>");

    // Ajouter l'image au bas du PDF
    content.append("<div style='text-align:center; margin-top:40px;'>");
    content.append("<img src='C:/Users/yasmi/OneDrive/Bureau/ProjetCpp/image.qrc/logo.png' alt='Image' style='width: 50%; height: auto;' />");
    content.append("</div>");

    // Appliquer le contenu HTML et imprimer le PDF
    doc.setHtml(content);
    doc.setPageSize(QSizeF(writer.width(), writer.height()));
    doc.print(&writer);

    QMessageBox::information(nullptr, "Succès", "Le fichier PDF a été généré avec succès !");
}

/********************************************************rechrche**********************************************************************************/
QSqlQueryModel* Evenements::recherche_evenements_par_adresse(const QString& adresse)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Préparation de la requête pour rechercher par adresse
    query.prepare("SELECT * FROM evenements WHERE ADRESSE_EEVENEMENT = :adresse");
    query.bindValue(":adresse", adresse);

    // Exécution de la requête et vérification des erreurs
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "La requête SQL a échoué !");
        delete model;
        return nullptr;
    }

    // Affectation des résultats à l'objet model
    model->setQuery(std::move(query));
    return model;
}


/*******************************************************trier************************************************************************/
QSqlQueryModel* Evenements::trier_evenements(const QString& critere)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString requete = "SELECT ID_EVENEMENT,NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT, lieu_evenement FROM evenements";

    if (critere == "id") {
        requete += " ORDER BY ID_EVENEMENT";

    } else if (critere == "nombre participants") {
        requete += " ORDER BY NBR_PARTICIPANTS_EVENEMENT";
    }

    // Appliquer la requête au modèle

    model->setQuery(requete);

    // Vérifier les erreurs de la requête
    if (model->lastError().isValid()) {
        qDebug() << "Erreur de requête: " << model->lastError().text();
    }

    return model;
}
/***********************************************************************************************************/

QMap<QString, int> Evenements::stat_evenements()
{
    QMap<QString, int> stats;
    QSqlQuery query;

    query.prepare("SELECT TYPE_EVENEMENT, COUNT(*) FROM evenements GROUP BY TYPE_EVENEMENT");

    if (query.exec()) {
        while (query.next()) {
            QString type = query.value(0).toString();
            int count = query.value(1).toInt();
            stats[type] = count;
            qDebug() << "Type:" << type << "- Count:" << count;
        }
    } else {
        qDebug() << "Erreur lors de la récupération des statistiques :" << query.lastError().text();
    }

    return stats;
}

//****************************************************************************flyer
//v0.1
/*void Evenements::generateFlyerForEvent(int eventId, QWidget* parent)
{
    // 1. Récupérer les données de l'événement
    QSqlQuery query;
    query.prepare("SELECT nom_evenement, description_evenement, date_debut_evenement, adresse_eevenement FROM evenements WHERE id_evenement = ?");
    query.addBindValue(eventId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(parent, "Erreur", "Impossible de récupérer les données de l'événement");
        return;
    }

    QString titre = query.value(0).toString();
    QString description = query.value(1).toString();
    QDate date = query.value(2).toDate();
    QString lieu = query.value(3).toString();
    QString descLower = description.toLower();

    // 2. Définir les mots-clés pour chaque thème
    QMap<QString, QStringList> themeKeywords = {
        { "technologie", {"technologie", "innovation", "numérique", "robot", "ia", "intelligence artificielle", "machine learning", "informatique"} },
        { "santé", {"santé", "bien-être", "médical", "médecine", "soins", "hôpital", "docteur"} },
        { "art", {"art", "peinture", "sculpture", "musique", "exposition", "créatif", "dessin"} },
        { "éducation", {"éducation", "école", "enseignement", "apprentissage", "pédagogie", "étudiants", "cours"} }
    };

    // 3. Détection du thème basé sur les mots-clés
    QString detectedTheme;
    for (auto it = themeKeywords.begin(); it != themeKeywords.end(); ++it) {
        for (const QString& keyword : it.value()) {
            if (descLower.contains(keyword)) {
                detectedTheme = it.key();
                break;
            }
        }
        if (!detectedTheme.isEmpty())
            break;
    }

    // 4. Appliquer les styles en fonction du thème détecté
    QString fontName = "Times New Roman";
    QColor textColor = QColor("#3A7D44");
    QString bgPath = ":/image.qrc/default_bg.png";
    QString imagePath = ":/image.qrc/default.png";

    if (detectedTheme == "technologie") {
        fontName = "AVENGEANCE HEROIC AVENGER AT";
        textColor = QColor("#004080");
        bgPath = ":/image.qrc/tech_bg.png";
        imagePath = ":/image.qrc/technologie.png";
    } else if (detectedTheme == "santé") {
        fontName = "Sakitu Baelah Clean";
        textColor = QColor("#2e7d32");
        bgPath = ":/image.qrc/sante_bg.png";
        imagePath = ":/image.qrc/sante.png";
    } else if (detectedTheme == "art") {
        fontName = "Beachfly Free Trial";
        textColor = QColor("#880e4f");
        bgPath = ":/image.qrc/art_bg.png";
        imagePath = ":/image.qrc/art.png";
    } else if (detectedTheme == "éducation") {
        fontName = "Jackal Holiday";
        textColor = QColor("#6a1b9a");
        bgPath = ":/image.qrc/edu_bg.png";
        imagePath = ":/image.qrc/ecole.png";
    }

    // 5. Choisir un nom de fichier pour le PDF
    QString fileName = QFileDialog::getSaveFileName(parent, "Enregistrer le flyer", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    // 6. Configurer le printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A6));
    printer.setFullPage(true);
    printer.setResolution(125);

    // 7. Démarrer le painter
    QPainter painter(&printer);
    QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

    // 8. Dessiner le background
    QImage bgImage(bgPath);
    painter.drawImage(pageRect, bgImage);

    // 9. Créer le contenu HTML
    QString html = QString(R"(
        <html>
        <head>
            <meta charset='UTF-8'>
            <style>
                body {
                    font-family: '%1';
                    color: %2;
                    margin: 0;
                    padding: 40px;
                    font-size: 24px;
                    text-align: center;
                }
                .header {
                    text-align: center;
                    font-size: 38px;
                    font-weight: bold;
                    margin-bottom: 20px;
                    padding: 10px;
                }
                .meta {

                    padding: 10px;
                    margin-bottom: 20px;
                }
                .image {
                    text-align: center;
                    margin-bottom: 20px;
                }
                .description {
                    text-align: justify;
                    line-height: 1.5;
                    background-color: rgba(255,255,255,0.6);
                    padding: 15px;
                }
                .footer {
                    text-align: right;
                    margin-top: 30px;
                }
            </style>
        </head>
        <body>
            <div class='header'>%3</div>
            <div class='meta'>📅 %4<br>📍 %5</div>
            <div class='image'><img src='%6' width='300'></div>
            <div class='description'>📝 %7</div>
            <div class='footer'><img src=':/image.qrc/logo.png' width='100'></div>
        </body>
        </html>
    )")
                       .arg(fontName)
                       .arg(textColor.name())
                       .arg(titre)
                       .arg(date.toString("dddd dd MMMM yyyy"))
                       .arg(lieu)
                       .arg(imagePath)
                       .arg(description);

    // 10. Préparer le document
    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(pageRect.size());

    // 11. Dessiner le document
    doc.drawContents(&painter, QRectF(QPointF(0, 0), pageRect.size()));
    painter.end();

    QMessageBox::information(parent, "Succès", "Le flyer a été généré avec succès !");
}*/
//v0.0
/*
void Evenements::generateFlyerForEvent(int eventId, QWidget* parent)
{
    // 1. Récupérer les données de l'événement selon votre structure
    QSqlQuery query;
    query.prepare("SELECT NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, "
                  "NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, "
                  "TYPE_EVENEMENT, LIEU_EVENEMENT FROM evenements WHERE id_evenement = ?");
    query.addBindValue(eventId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(parent, "Erreur", "Impossible de récupérer les données de l'événement");
        return;
    }

    QString titre = query.value(0).toString();
    QDate dateDebut = query.value(1).toDate();
    QDate dateFin = query.value(2).toDate();
    int participants = query.value(3).toInt();
    QString adresse = query.value(4).toString();
    QString description = query.value(5).toString();
    QString type = query.value(6).toString();
    QString lieu = query.value(7).toString();

    QString descLower = description.toLower();
    QString titreLower = titre.toLower();
    QString typeLower = type.toLower();

    // 2. Définir les mots-clés pour chaque thème avec un système de pondération
    struct ThemeData {
        QStringList keywords;
        QMap<QString, int> keywordWeights;
        QString defaultFont;
        QColor textColor;
        QString bgPath;
        QString imagePath;
    };

    QMap<QString, ThemeData> themes = {
        { "technologie", {
                            {"technologie", "innovation", "numérique", "robot", "ia", "intelligence artificielle",
                             "machine learning", "informatique", "code", "programmation", "blockchain", "réseau",
                             "cybersécurité", "données", "cloud", "iot", "électronique"},
                            {{"ia", 3}, {"intelligence artificielle", 3}, {"robot", 3}, {"innovation", 2}, {"blockchain", 2}},
                            "AVENGEANCE HEROIC AVENGER AT",
                            QColor("#004080"),
                            ":/image.qrc/tech_bg.png",
                            ":/image.qrc/technologie.png"
                        }},
        { "santé", {
                      {"santé", "bien-être", "médical", "médecine", "soins", "hôpital", "docteur",
                       "infirmier", "santé mentale", "thérapie", "nutrition", "fitness", "yoga",
                       "méditation", "vaccin", "pharmacie"},
                      {{"santé mentale", 3}, {"thérapie", 2}, {"bien-être", 2}},
                      "Sakitu Baelah Clean",
                      QColor("#2e7d32"),
                      ":/image.qrc/sante_bg.png",
                      ":/image.qrc/sante.png"
                  }},
        { "art", {
                    {"art", "peinture", "sculpture", "musique", "exposition", "créatif", "dessin",
                     "photographie", "théâtre", "danse", "performance", "vernissage", "galerie",
                     "concert", "festival", "culturel"},
                    {{"exposition", 3}, {"vernissage", 3}, {"concert", 2}},
                    "Beachfly Free Trial",
                    QColor("#880e4f"),
                    ":/image.qrc/art_bg.png",
                    ":/image.qrc/art.png"
                }},
        { "éducation", {
                          {"éducation", "école", "enseignement", "apprentissage", "pédagogie", "étudiants",
                           "cours", "formation", "université", "conférence", "séminaire", "workshop",
                           "atelier", "apprendre", "diplôme", "professeur"},
                          {{"conférence", 3}, {"workshop", 3}, {"séminaire", 2}},
                          "Jackal Holiday",
                          QColor("#6a1b9a"),
                          ":/image.qrc/edu_bg.png",
                          ":/image.qrc/ecole.png"
                      }}
    };

    // 3. Détection intelligente du thème avec pondération
    QMap<QString, int> themeScores;

    // Vérifier d'abord le TYPE_EVENEMENT
    if (!type.isEmpty()) {
        for (const QString& theme : themes.keys()) {
            if (typeLower.contains(theme, Qt::CaseInsensitive)) {
                themeScores[theme] += 5; // Bonus important pour correspondance type
            }
        }
    }

    // Analyser le titre et la description
    for (auto it = themes.begin(); it != themes.end(); ++it) {
        const ThemeData& themeData = it.value();

        // Vérifier dans le titre (donne plus de poids)
        for (const QString& keyword : themeData.keywords) {
            if (titreLower.contains(keyword)) {
                themeScores[it.key()] += themeData.keywordWeights.value(keyword, 1) * 2;
            }
        }

        // Vérifier dans la description
        for (const QString& keyword : themeData.keywords) {
            if (descLower.contains(keyword)) {
                themeScores[it.key()] += themeData.keywordWeights.value(keyword, 1);
            }
        }
    }

    // Trouver le thème avec le score le plus élevé
    QString detectedTheme = "default";
    int maxScore = 0;
    for (auto it = themeScores.begin(); it != themeScores.end(); ++it) {
        if (it.value() > maxScore) {
            maxScore = it.value();
            detectedTheme = it.key();
        }
    }

    // 4. Appliquer les styles en fonction du thème détecté
    ThemeData selectedTheme = themes.value(detectedTheme, ThemeData{
                                                              {}, {}, "Arial", Qt::black, ":/image.qrc/default_bg.png", ":/image.qrc/default.png"
                                                          });

    // 5. Préparer les données pour le flyer
    QString dateText;
    if (dateDebut == dateFin) {
        dateText = dateDebut.toString("dddd d MMMM yyyy").toLower();
        dateText[0] = dateText[0].toUpper();
    } else {
        QString debut = dateDebut.toString("d MMM");
        QString fin = dateFin.toString("d MMM yyyy");
        dateText = QString("Du %1 au %2").arg(debut, fin);
    }

    QString participantsText = (participants > 0) ?
                                   QString("👥 Nombre de participants: %1").arg(participants) : "";

    // 6. Choisir un nom de fichier pour le PDF
    QString defaultName = QString("Flyer_%1_%2").arg(titre.replace(" ", "_"), QDate::currentDate().toString("yyyyMMdd"));
    QString fileName = QFileDialog::getSaveFileName(
        parent,
        "Enregistrer le flyer",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + defaultName + ".pdf",
        "PDF Files (*.pdf)"
        );
    if (fileName.isEmpty()) return;

    // 7. Configurer le printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A5));
    printer.setPageOrientation(QPageLayout::Portrait);
    printer.setFullPage(true);
    printer.setResolution(150);
    printer.setColorMode(QPrinter::Color);

    // 8. Démarrer le painter
    QPainter painter(&printer);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

    // 9. Dessiner le background
    QImage bgImage(selectedTheme.bgPath);
    if (!bgImage.isNull()) {
        painter.setOpacity(0.9);
        painter.drawImage(pageRect, bgImage.scaled(pageRect.size().toSize(), Qt::KeepAspectRatioByExpanding));
        painter.setOpacity(1.0);
    }

    // 10. Créer le contenu HTML
    QString html = QString(R"(
        <html>
        <head>
            <meta charset='UTF-8'>
            <style>
                body {
                    font-family: '%1';
                    color: %2;
                    margin: 0;
                    padding: 40px;
                    font-size: 24px;
                    background-color: rgba(255,255,255,0.7);
                }
                .header {
                    text-align: center;
                    font-size: 42px;
                    font-weight: bold;
                    margin-bottom: 15px;
                    padding: 15px;
                    border-radius: 10px;
                    background: linear-gradient(90deg, rgba(255,255,255,0.8) 0%, rgba(255,255,255,0.9) 50%, rgba(255,255,255,0.8) 100%);
                    text-shadow: 1px 1px 2px rgba(0,0,0,0.1);
                }
                .meta-container {
                    display: flex;
                    flex-wrap: wrap;
                    justify-content: space-between;
                    margin-bottom: 20px;
                    gap: 10px;
                }
                .meta {
                    background-color: rgba(255,255,255,0.85);
                    padding: 12px;
                    border-radius: 8px;
                    flex: 1;
                    min-width: 40%;
                    box-shadow: 0 2px 5px rgba(0,0,0,0.1);
                }
                .image-container {
                    text-align: center;
                    margin: 20px 0;
                    background-color: rgba(255,255,255,0.8);
                    padding: 15px;
                    border-radius: 8px;
                }
                .description {
                    text-align: justify;
                    line-height: 1.6;
                    background-color: rgba(255,255,255,0.85);
                    padding: 20px;
                    border-radius: 8px;
                    margin-bottom: 20px;
                    box-shadow: 0 2px 5px rgba(0,0,0,0.1);
                }
                .footer {
                    text-align: center;
                    margin-top: 20px;
                    font-size: 18px;
                }
                .participants {
                    font-style: italic;
                    background-color: rgba(255,255,255,0.9);
                    padding: 5px 10px;
                    border-radius: 15px;
                    display: inline-block;
                    margin-top: 10px;
                }
            </style>
        </head>
        <body>
            <div class='header'>%3</div>

            <div class='meta-container'>
                <div class='meta'>📅 %4</div>
                <div class='meta'>📍 %5</div>
                <div class='meta'>🏛️ %6</div>
                %7
            </div>

            <div class='image-container'>
                <img src='%8' width='280'>
            </div>

            <div class='description'>%9</div>

            %10

            <div class='footer'>
                <img src=':/image.qrc/logo.png' width='120'><br>
                Pour plus d'informations, contactez-nous
            </div>
        </body>
        </html>
    )")
                       .arg(selectedTheme.defaultFont)
                       .arg(selectedTheme.textColor.name())
                       .arg(titre)
                       .arg(dateText)
                       .arg(adresse)
                       .arg(lieu)
                       .arg(participants > 0 ? "<div class='meta'>" + participantsText + "</div>" : "")
                       .arg(selectedTheme.imagePath)
                       .arg(description)
                       .arg(participants > 0 ? "<div class='participants'>" + participantsText + "</div>" : "");

    // 11. Préparer et dessiner le document
    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(pageRect.size());

    painter.fillRect(pageRect, QColor(255, 255, 255, 180));
    doc.drawContents(&painter, pageRect);
    painter.end();


    QMessageBox::information(parent, "Succès", QString("Le flyer pour '%1' a été généré avec succès!").arg(titre));
}
*/
//version api ai
/*void Evenements::generateFlyerForEvent(int eventId, QWidget* parent)
{
    // 1. Récupérer les données de l'événement
    QSqlQuery query;
    query.prepare("SELECT nom_evenement, description_evenement, date_debut_evenement, adresse_eevenement FROM evenements WHERE id_evenement = ?");
    query.addBindValue(eventId);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(parent, "Erreur", "Impossible de récupérer les données de l'événement");
        return;
    }

    QString titre = query.value(0).toString();
    QString description = query.value(1).toString();
    QDate date = query.value(2).toDate();
    QString lieu = query.value(3).toString();

    // 2. Appeler l'IA pour détecter le thème et améliorer la description
    AIHelper ai;
    QString detectedTheme = ai.detectThemeFromAI(description);
    QString descriptionAmelioree = ai.enhanceDescriptionWithAI(description);

    // 3. Appliquer les styles en fonction du thème détecté
    QString fontName = "Times New Roman";
    QColor textColor = QColor("#3A7D44");
    QString bgPath = ":/image.qrc/default_bg.png";
    QString imagePath = ":/image.qrc/default.png";

    if (detectedTheme == "technologie") {
        fontName = "AVENGEANCE HEROIC AVENGER AT";
        textColor = QColor("#004080");
        bgPath = ":/image.qrc/tech_bg.png";
        imagePath = ":/image.qrc/technologie.png";
    } else if (detectedTheme == "santé") {
        fontName = "Sakitu Baelah Clean";
        textColor = QColor("#2e7d32");
        bgPath = ":/image.qrc/sante_bg.png";
        imagePath = ":/image.qrc/sante.png";
    } else if (detectedTheme == "art") {
        fontName = "Beachfly Free Trial";
        textColor = QColor("#880e4f");
        bgPath = ":/image.qrc/art_bg.png";
        imagePath = ":/image.qrc/art.png";
    } else if (detectedTheme == "éducation") {
        fontName = "Jackal Holiday";
        textColor = QColor("#6a1b9a");
        bgPath = ":/image.qrc/edu_bg.png";
        imagePath = ":/image.qrc/ecole.png";
    }

    // 4. Choisir un nom de fichier pour le PDF
    QString fileName = QFileDialog::getSaveFileName(parent, "Enregistrer le flyer", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    // 5. Configurer l'imprimante
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A6));
    printer.setFullPage(true);
    printer.setResolution(125);

    // 6. Démarrer le painter
    QPainter painter(&printer);
    QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

    // 7. Dessiner le background
    QImage bgImage(bgPath);
    painter.drawImage(pageRect, bgImage);

    // 8. Générer le HTML
    QString html = QString(R"(
        <html>
        <head>
            <meta charset='UTF-8'>
            <style>
                body {
                    font-family: '%1';
                    color: %2;
                    margin: 0;
                    padding: 40px;
                    font-size: 24px;
                    text-align: center;
                }
                .header {
                    text-align: center;
                    font-size: 38px;
                    font-weight: bold;
                    margin-bottom: 20px;
                    padding: 10px;
                }
                .meta {
                    padding: 10px;
                    margin-bottom: 20px;
                }
                .image {
                    text-align: center;
                    margin-bottom: 20px;
                }
                .description {
                    text-align: justify;
                    line-height: 1.5;
                    background-color: rgba(255,255,255,0.6);
                    padding: 15px;
                }
                .footer {
                    text-align: right;
                    margin-top: 30px;
                }
            </style>
        </head>
        <body>
            <div class='header'>%3</div>
            <div class='meta'>📅 %4<br>📍 %5</div>
            <div class='image'><img src='%6' width='300'></div>
            <div class='description'>📝 %7</div>
            <div class='footer'><img src=':/image.qrc/logo.png' width='100'></div>
        </body>
        </html>
    )")
                       .arg(fontName)
                       .arg(textColor.name())
                       .arg(titre)
                       .arg(date.toString("dddd dd MMMM yyyy"))
                       .arg(lieu)
                       .arg(imagePath)
                       .arg(descriptionAmelioree);

    // 9. Préparer et dessiner le document
    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(pageRect.size());
    doc.drawContents(&painter, QRectF(QPointF(0, 0), pageRect.size()));
    painter.end();

    QMessageBox::information(parent, "Succès", "Le flyer a été généré avec succès !");
}*/
//version 0.1 plus revisite
QImage Evenements::generateFlyerForEvent(int eventId)
{
    QSqlQuery query;
    query.prepare("SELECT nom_evenement, description_evenement, date_debut_evenement, adresse_eevenement FROM evenements WHERE id_evenement = ?");
    query.addBindValue(eventId);

    if (!query.exec() || !query.next()) {
        return QImage();
    }

    QString titre = query.value(0).toString();
    QString description = query.value(1).toString();
    QDate date = query.value(2).toDate();
    QString lieu = query.value(3).toString();
    QString descLower = description.toLower();

    // 2. Thèmes et mots-clés
    QMap<QString, QStringList> themeKeywords = {
        { "technologie", {"technologie", "innovation", "numérique", "robot", "ia", "intelligence artificielle", "informatique"} },
        { "santé", {"santé", "bien-être", "médical", "médecine", "soins"} },
        { "art", {"art", "peinture", "sculpture", "musique", "créatif"} },
        { "éducation", {"éducation", "école", "apprentissage", "pédagogie"} },
        { "softskills", {"communication", "leadership", "softskills", "esprit d'équipe", "créativité", "empathie"} }
    };

    // 3. Détection de thème
    QString detectedTheme = "default";
    for (auto it = themeKeywords.begin(); it != themeKeywords.end(); ++it) {
        for (const QString& keyword : it.value()) {
            if (descLower.contains(keyword)) {
                detectedTheme = it.key();
                break;
            }
        }
        if (detectedTheme != "default") break;
    }

    QMap<QString, QStringList> themeBackgrounds = {
        { "technologie", {":/image.qrc/tech_bg1.png", ":/image.qrc/tech_bg2.png", ":/image.qrc/tech_bg.png"} },
        { "santé",       {":/image.qrc/sante_bg1.png", ":/image.qrc/sante_bg2.png",":/image.qrc/sante_bg.png"} },
        { "art",         {":/image.qrc/art_bg1.png", ":/image.qrc/art_bg2.png", ":/image.qrc/art_bg.png"} },
        { "éducation",   {":/image.qrc/edu_bg1.png", ":/image.qrc/edu_bg2.png", ":/image.qrc/edu_bg.png"} },
        { "softskills",  {":/image.qrc/softSkills_bg.png", ":/image.qrc/softSkills_bg1.png", ":/image.qrc/softSkills_bg2.png"} },
        { "default",     {":/image.qrc/default_bg.png",":/image.qrc/default_bg1.png", ":/image.qrc/default_bg2.png"} }
    };

    QMap<QString, QStringList> themeFonts = {
        { "technologie", {"Orbitron", "Roboto Mono","Orbitron-Regular", "Gloomie Saturday"} },
        { "santé", {"Open Sans", "Lato","Beachfly Free Trial"} },
        { "art", {"Pacifico", "Dancing Script","moria","Bassunpersonaluse","Drawliner"} },
        { "éducation", {"Schoolbell", "Comic Sans MS","Jackal Holiday"} },
        { "softskills", {"Verdana", "Segoe UI", "varsity_regular"} },
        { "default", {"Arial","AVENGEANCE HEROIC AVENGER AT", "Sakitu Baelah Clean"} }
    };

    QMap<QString, QStringList> themeColors = {
        { "technologie", {"#003366", "#0055AA", "#007FFF"} },
        { "santé", {"#2e7d32", "#66bb6a", "#a5d6a7"} },
        { "art", {"#880e4f", "#c2185b", "#f06292"} },
        { "éducation", {"#6a1b9a", "#8e24aa", "#ba68c8"} },
        { "softskills", {"#ff9800", "#ffa726", "#ffcc80"} },
        { "default", {"#444444"} }
    };
    QMap<QString, QStringList> themeImages = {
        { "technologie", {":/image.qrc/technologie.png", ":/image.qrc/technologie1.png", ":/image.qrc/technologie2.png"} },
        { "santé",       {":/image.qrc/sante.png", ":/image.qrc/sante1.png", ":/image.qrc/sante2.png"} },
        { "art",         {":/image.qrc/art.png", ":/image.qrc/art1.png", ":/image.qrc/art2.png"} },
        { "éducation",   {":/image.qrc/ecole.png", ":/image.qrc/ecole1.png", ":/image.qrc/ecole2.png"} },
        { "softskills",  {":/image.qrc/softSkills1.png", ":/image.qrc/softSkills.png", ":/image.qrc/softSkills2.png"} },
        { "default",     {":/image.qrc/default.png", ":/image.qrc/default1.png", ":/image.qrc/default2.png"} }
    };

    // 5. Choix aléatoire des styles
    srand(QDateTime::currentSecsSinceEpoch() % 100000);

    auto pickRandom = [](const QStringList& list) -> QString {
        return list[rand() % list.size()];
    };

    QString fontName = pickRandom(themeFonts[detectedTheme]);
    QColor textColor(pickRandom(themeColors[detectedTheme]));
    QString bgPath = pickRandom(themeBackgrounds[detectedTheme]);
    QString imagePath = pickRandom(themeImages[detectedTheme]);

    QSize flyerSize(600, 850);
    QImage flyer(flyerSize, QImage::Format_ARGB32);
    flyer.fill(Qt::white);

    QPainter painter(&flyer);
    painter.setRenderHint(QPainter::Antialiasing);

    // 7. Background
    QImage bgImage(bgPath);
    painter.drawImage(QRect(QPoint(0, 0), flyerSize), bgImage);

    //rq : date en francais
    QLocale localeFr(QLocale::French, QLocale::France);
    QString dateStr = localeFr.toString(date, "dddd dd MMMM yyyy");


    QString html = QString(R"(
        <html>
        <head>
            <meta charset='UTF-8'>
            <style>
                body {
                    font-family: '%1', sans-serif;
                    color: %2;
                    margin: 0;
                    padding: 30px;
                    font-size: 20px;
                    text-align: center;
                }
                .header {
                    font-size: 32px;
                    font-weight: bold;
                    margin: 20px 0;
                    padding: 70px;
                    border-radius: 5px;
                }
                .meta {
                    margin: 20px 0;
                    padding: 10px;
                    border-radius: 5px;
                }
                .image {
                    margin: 20px auto;
                    max-width: 260px;
                }
                .description {
                    text-align: justify;
                    line-height: 1.4;
                    padding: 15px;
                    border-radius: 5px;
                }
                .footer {
                    margin-top: 30px;
                }
            </style>
        </head>
        <body>
            <div class='header'>%3</div>
            <div class='meta'>📅 %4<br>📍 %5</div>
            <div class='image'><img src='%6' width='260'></div>
            <div class='description'>📝 %7</div>
            <div class='footer'><img src=':/image.qrc/logo.png' width='80'></div>
        </body>
        </html>
    )")
                       .arg(fontName)
                       .arg(textColor.name())
                       .arg(titre)
                       .arg(dateStr)
                       .arg(lieu)
                       .arg(imagePath)
                       .arg(description);

    // 9. Document HTML → image
    QTextDocument doc;
    doc.setHtml(html);
    doc.setTextWidth(flyerSize.width() - 40);

    // Dessiner le document centré verticalement
    QRectF textRect(20, 20, flyerSize.width() - 40, flyerSize.height() - 40);
    doc.setPageSize(textRect.size());
    doc.drawContents(&painter, textRect);

    painter.end();

    return flyer;
}




