#include "connection.h" // Inclure la classe de connexion à la base de données
#include "gemploye.h"   // Inclure la classe de gestion des employés
#include "access.h"      // Inclure la classe de l'interface d'accès
#include "dialogtheme.h" // Inclure la classe de thème des boîtes de dialogue
#include <QApplication> // Inclure la classe QApplication
#include <QMessageBox>  // Inclure la classe QMessageBox pour les boîtes de dialogue

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Établir la connexion à la base de données
    Connection connection;
    bool isConnected = connection.createconnect();

    // Vérifier si la connexion à la base de données est réussie
    if (isConnected)
    {
        access *w = new access(); // Allouer dynamiquement la fenêtre d'accès
        w->show(); // Afficher la fenêtre d'accès
        // La fenêtre reste affichée tant que l'application tourne
    }
    else
    {
        QMessageBox msgBox(nullptr);
        msgBox.setWindowTitle(QObject::tr("Base de données non ouverte"));
        msgBox.setText(QObject::tr("Échec de la connexion.\nCliquez sur Annuler pour quitter."));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStyleSheet(dialogThemeStyle());
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();
        return -1; // Quitter l'application si la connexion échoue
    }

    return a.exec(); // Lancer l'application
}
