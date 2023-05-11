#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H
#include<QtGui>
#include<QtWebKit>
#include<QtWidgets>
#include<QtWebKitWidgets/QtWebKitWidgets>

#include <QMainWindow>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
public:
    explicit FenPrincipale(QWidget *parent = 0);

private:
    void creerActions();
    void creerMenus();
    void creerBarresOutils();
    void creerBarreEtat();
    QWidget *creerOngletPageWeb(QString url=" ");
    QWebView *pageActuelle();

signals:

private slots:
    void precedente();
    void suivante();
    void stop();
    void actualiser();
    void acceuil();
    void aPropos();
    void nouvelOnglet();
    void fermerOnglet();
    void changementOnglet(int index);
    void chargerPage();
    void changementTitre(const QString & titreComplet);
    void changementUrl(const QUrl & url);
    void chargementDebut();
    void chargementEnCours(int pourcentage);
    void chargementTermine(bool ok);






private:
    QTabWidget *onglets;
    QAction *actionNouvelOnglet;
    QAction *actionFermerOnglet;
    QAction *actionQuitter;
    QAction *actionAPropos;
    QAction *actionAProposQt;
    QAction *actionPrecedente;
    QAction *actionSuivante;
    QAction *actionStop;
    QAction *actionActualiser;
    QAction *actionAccueil;
    QAction *actionGo;
    QLineEdit *champAdresse;
    QProgressBar *progression;

};

#endif // FENPRINCIPALE_H
