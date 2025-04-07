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




//*************************************************************CONSTRUCTEUR+INITIALISATION***********************************************************
Evenements::Evenements()
    : ID_evenement(0),
    nom_evenement(""),
    date_debut_evenement(QDate::currentDate()),
    date_fin_evenement(QDate::currentDate()),
    nbr_participants_evenement(0),
    adresse_evenement(""),
    description_evenement(""),
    type_evenement("")
{
}

//****************************************************************constructeur paramétré***********************************************************
Evenements::Evenements(QString nom, QDate date_debut, QDate date_fin, int nbr_participants, QString adresse, QString description, QString type) {
    this->nom_evenement = nom;
    this->date_debut_evenement = date_debut;
    this->date_fin_evenement = date_fin;
    this->nbr_participants_evenement = nbr_participants;
    this->adresse_evenement = adresse;
    this->description_evenement = description;
    this->type_evenement = type;
}


//**********************************************************l'ajout*****************************************************************
bool Evenements::ajouter_evenements() {
    QSqlQuery query;


    query.prepare("INSERT INTO EVENEMENTS(NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT) "
                  "VALUES(:nom_evenement, :date_debut_evenement, :date_fin_evenement, :nbr_participants_evenement, :adresse_evenement, :description_evenement, :type_evenement)");

    query.bindValue(":nom_evenement", nom_evenement);
    query.bindValue(":date_debut_evenement", date_debut_evenement);
    query.bindValue(":date_fin_evenement", date_fin_evenement);
    query.bindValue(":nbr_participants_evenement", nbr_participants_evenement);
    query.bindValue(":adresse_evenement", adresse_evenement);
    query.bindValue(":description_evenement",  description_evenement);
    query.bindValue(":type_evenement", type_evenement);



    return query.exec();
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion:" << query.lastError().text();
    }
}
//*****************************l'affichage (sqltablemodel bich tnajem men ba3d ta3mel les modifications fel table menou lih)**************************

QSqlTableModel *Evenements::afficher_evenements() {
    qDebug() << "afficher_evenements() appelée";
    QSqlTableModel * model = new QSqlTableModel();

    model->setQuery("SELECT ID_EVENEMENT,NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT FROM evenements") ;

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date Début"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Fin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nombre des participants"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("type"));
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
bool Evenements::modifier_evenement(int id_evenement, QString nom_evenement, QDate date_debut_evenement, QDate date_fin_evenement, int nbr_participants_evenement, QString adresse_eevenement, QString description_evenement, QString type_evenement) {
    QSqlQuery query;
    query.prepare("UPDATE evenements SET nom_evenement = :nom_evenement, date_debut_evenement = :date_debut_evenement, date_fin_evenement = :date_fin_evenement, "
                  "nbr_participants_evenement = :nbr_participants_evenement, adresse_eevenement = :adresse_eevenement, description_evenement = :description_evenement, "
                  "type_evenement = :type_evenement WHERE id_evenement = :id_evenement");
    query.bindValue(":id_evenement", id_evenement);
    query.bindValue(":nom_evenement", nom_evenement);
    query.bindValue(":date_debut_evenement", date_debut_evenement);
    query.bindValue(":date_fin_evenement", date_fin_evenement);
    query.bindValue(":nbr_participants_evenement", nbr_participants_evenement);
    query.bindValue(":adresse_eevenement", adresse_eevenement);
    query.bindValue(":description_evenement", description_evenement);
    query.bindValue(":type_evenement", type_evenement);

    return query.exec();
}

//**********************************telecharger pdf*************************************************************************************************

void Evenements::telecharger_pdf_evenements()
{
    //

    // Demander à l'utilisateur où enregistrer le fichier
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Enregistrer PDF", "", "PDF Files (*.pdf)");

    if (fileName.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Aucun fichier sélectionné !");
        return;
    }

    // Créer un QPdfWriter
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);

    // Création du document HTML
    QTextDocument doc;
    QString content;

    // Ajouter un style CSS pour personnaliser le titre et le tableau
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

    // Style pour le tableau
    content.append("table { "
                   "width: 90%; "  // Largeur augmentée
                   "margin: 0 auto; "
                   "border-collapse: collapse; "
                   "font-family: 'Arial'; "
                   "font-size: 32px; "  // Augmenté de 24 à 32px
                   "}");

    // Style pour les en-têtes de tableau
    content.append("th { "
                   "background-color: #4CAF50; "
                   "color: white; "
                   "font-size: 36px; "  // Augmenté de 28 à 36px
                   "font-weight: bold; "
                   "padding: 15px;"  // Padding augmenté
                   "}");

    // Style pour les cellules du tableau
    content.append("td { "
                   "border: 2px solid #ddd; "  // Bordure épaissie
                   "padding: 20px; "  // Augmenté de 18 à 20px
                   "font-size: 32px; "  // Augmenté de 28 à 32px
                   "text-align: center; "
                   "}");

    content.append("</style>");

    // Ajouter le titre
    content.append("<p>LISTE DES ÉVÉNEMENTS</p>");  // Titre en majuscules pour plus de visibilité

    // Début du tableau
    content.append("<table>");
    content.append("<tr><th>ID</th><th>NOM</th><th>DATE DÉBUT</th><th>DATE FIN</th><th>LIEU</th><th>DESCRIPTION</th><th>PARTICIPANTS</th></tr>");

    // Exécuter la requête SQL
    QSqlQuery query("SELECT ID_EVENEMENT, NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT FROM evenements");

    while (query.next()) {
        content.append("<tr>");
        for (int i = 0; i < 7; ++i) {
            content.append("<td>" + query.value(i).toString() + "</td>");
        }
        content.append("</tr>");
    }

    content.append("</table>");

    // Définir le contenu HTML et générer le PDF
    doc.setHtml(content);
    doc.setPageSize(QSizeF(writer.width(), writer.height()));

    // Générer le PDF
    doc.print(&writer);

    QMessageBox::information(nullptr, "Succès", "Le fichier PDF a été généré avec succès !");
}



/********************************************************rechrche**********************************************************************************/
QSqlQueryModel* Evenements::recherche_evenements(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM evenements WHERE ID_EVENEMENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "La requête SQL a échoué !");
        delete model;  // Nettoyage mémoire
        return nullptr;
    }

    model->setQuery(std::move(query));
    return model;
}

/*******************************************************trier************************************************************************/
QSqlQueryModel* Evenements::trier_evenements(const QString& critere)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    // La requête de base pour récupérer tous les événements
    QString requete = "SELECT ID_EVENEMENT,NOM_EVENEMENT, DATE_DEBUT_EVENEMENT, DATE_FIN_EVENEMENT, NBR_PARTICIPANTS_EVENEMENT, ADRESSE_EEVENEMENT, DESCRIPTION_EVENEMENT, TYPE_EVENEMENT FROM evenements";

    // Ajouter la clause ORDER BY en fonction du critère
    if (critere == "id") {
        requete += " ORDER BY ID_EVENEMENT";  // Trier par ID
    } else if (critere == "date") {
        requete += " ORDER BY DATE_DEBUT_EVENEMENT";  // Trier par Date de début
    } else if (critere == "nombre participants") {
        requete += " ORDER BY NBR_PARTICIPANTS_EVENEMENT";  // Trier par Nombre de participants
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

