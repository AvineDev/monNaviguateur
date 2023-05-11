
#include "fenprincipale.h"


//fenetre principale



FenPrincipale::FenPrincipale(QWidget *parent) :
    QMainWindow(parent)
{
    creerActions();
    creerMenus();
    creerBarresOutils();
    creerBarreEtat();


    //génération de la page d'acceuil

    onglets= new QTabWidget;
    onglets->addTab(creerOngletPageWeb(tr("http://localhost/tests/meeting/")),tr("(Nouvelle page)"));
    connect(onglets,SIGNAL(currentChanged(int)),this,SLOT(changementOnglet(int)));
    setCentralWidget(onglets);

    // Définition de quelques propriétés de la fenêtre
    setMinimumSize(500, 350);
    setWindowIcon(QIcon("C:/AvineDev/qt/zNavigo/favicon.ico"));
    setWindowTitle(tr("AvineNavigo"));

}


//Actions ,Menus

void FenPrincipale::creerActions()
{
    actionNouvelOnglet=new QAction(tr("&Nouvel onglet"),this);
    actionNouvelOnglet->setShortcut(tr("Ctrl+T"));
    connect(actionNouvelOnglet,SIGNAL(triggered()),this,SLOT(nouvelOnglet()));
    actionFermerOnglet=new QAction(tr("&Fermer l'onglet"),this);
    actionFermerOnglet->setShortcut(tr("Ctrl+W"));
    connect(actionFermerOnglet,SIGNAL(triggered()),this,SLOT(fermerOnglet()));
    actionQuitter=new QAction(tr("&Quitter"),this);
    actionQuitter->setShortcut(tr("Ctrl+Q"));
    connect(actionQuitter,SIGNAL(triggered()),qApp,SLOT(quit()));

    actionPrecedente=new QAction(QIcon("C:/AvineDev/qt/zNavigo/¨Previous.png"),tr("&Precedente"),this);
    actionPrecedente->setShortcut(QKeySequence::Back);
    connect(actionPrecedente,SIGNAL(triggered()),this,SLOT(precedente()));

    actionSuivante=new QAction(QIcon("C:/AvineDev/qt/zNavigo/Next.png"),tr("&Suivante"),this);
    actionSuivante->setShortcut(QKeySequence::Forward);
    connect(actionSuivante,SIGNAL(triggered()),this,SLOT(suivante()));

    actionStop=new QAction(QIcon("C:/AvineDev/qt/zNavigo/stop.png"),tr("S&top"),this);
    connect(actionStop,SIGNAL(triggered()),this,SLOT(stop()));
    actionActualiser=new QAction(QIcon("C:/AvineDev/qt/zNavigo/actualiser.jpg"),tr("&Actualiser"),this);
    actionActualiser->setShortcut(QKeySequence::Refresh);
    connect(actionActualiser,SIGNAL(triggered()),this,SLOT(actualiser()));
    actionAccueil= new QAction(QIcon("C:/AvineDev/qt/zNavigo/home.jpg"),tr("A&cceuil"),this);
    connect(actionAccueil,SIGNAL(triggered()),this,SLOT(acceuil()));
    actionGo=new QAction(QIcon("C:/AvineDev/qt/zNavigo/go.png"),tr("A&ller à"),this);
    connect(actionGo,SIGNAL(triggered()),this,SLOT(chargerPage()));
    actionAPropos=new QAction(tr("&A propos..."),this);
    connect(actionAPropos,SIGNAL(triggered()),this,SLOT(aPropos()));
    actionAProposQt=new QAction(tr("A propos de &Qt..."),this);
    connect(actionAProposQt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));


}

void FenPrincipale::creerMenus()
{
    QMenu *menuFichier=menuBar()->addMenu(tr("&Fichier"));
    menuFichier->addAction(actionNouvelOnglet);
    menuFichier->addAction(actionFermerOnglet);
    menuFichier->addSeparator();
    menuFichier->addAction(actionQuitter);

    QMenu *menuNaviguation=menuBar()->addMenu(tr("&Naviguation"));
    menuNaviguation->addAction(actionPrecedente);
    menuNaviguation->addAction(actionSuivante);
    menuNaviguation->addAction(actionStop);
    menuNaviguation->addAction(actionActualiser);
    menuNaviguation->addAction(actionAccueil);

    QMenu *menuAide=menuBar()->addMenu(tr("&?"));
    menuAide->addAction(actionAPropos);
    menuAide->addAction(actionAProposQt);



}

void FenPrincipale::creerBarresOutils()
{
    champAdresse=new QLineEdit;
    connect(champAdresse,SIGNAL(returnPressed()),this,SLOT(chargerPage()));
    QToolBar *toolBarNaviguation=addToolBar(tr("Naviguation"));
    toolBarNaviguation->addAction(actionPrecedente);
    toolBarNaviguation->addAction(actionSuivante);
    toolBarNaviguation->addAction(actionStop);
    toolBarNaviguation->addAction(actionActualiser);
    toolBarNaviguation->addAction(actionAccueil);
    toolBarNaviguation->addWidget(champAdresse);
    toolBarNaviguation->addAction(actionGo);


}
void FenPrincipale::creerBarreEtat()
{
    progression=new QProgressBar(this);
    progression->setVisible( false);
    progression->setMaximumHeight(14);
    statusBar()->addWidget(progression,1);

}
//slots personnalisés
void FenPrincipale::precedente()
{
    pageActuelle()->back();
}
void FenPrincipale::suivante()
{
    pageActuelle()->forward();
}

void FenPrincipale::acceuil()
{
    pageActuelle()->load(QUrl(tr("http://www.dineavadji.eu5.org")));
}
void FenPrincipale::stop()
{
    pageActuelle()->stop();
}
void FenPrincipale::actualiser()
{
    pageActuelle()->reload();
}
void FenPrincipale::aPropos()
{
    QMessageBox::information(this,tr("A propos"),tr("zNavigo est projet réalisé pour illuster un cours QT"));

}

void FenPrincipale::nouvelOnglet()
{
    int indexNouvelOnglet=onglets->addTab(creerOngletPageWeb(),tr("Nouvelle Page"));
    onglets->setCurrentIndex(indexNouvelOnglet);
    champAdresse->setText("");
    champAdresse->setFocus(Qt::OtherFocusReason);


}

void FenPrincipale::fermerOnglet()
{
    if(onglets->count()>1)
    {
        onglets->removeTab(onglets->currentIndex());
    }
    else
    {
        QMessageBox::critical(this,tr("Erreur"),tr("Il faut au moins un onglet ouvert"));
    }
}
void FenPrincipale::chargerPage()
{
    QString url = champAdresse->text();
    // On rajoute le "http://" s'il n'est pas déjà dans l'adresse
    if (url.left(7) != "http://")
    {
        url = "http://" + url;
        champAdresse->setText(url);
    }
    pageActuelle()->load(QUrl(url));
}

void FenPrincipale::changementOnglet(int index)
{
changementTitre(pageActuelle()->title());
changementUrl(pageActuelle()->url());
}
void FenPrincipale::changementTitre(const QString & titreComplet)
{
    QString titreCourt=titreComplet;
    if(titreComplet.size()>40)
    {
        titreCourt=titreComplet.left(40)+"...";
    }
    setWindowTitle(titreCourt+"-"+ tr("zNavigo"));
    onglets->setTabText(onglets->currentIndex(),titreCourt);
}
void FenPrincipale::changementUrl(const QUrl & url)
{
    if(url.toString()!=tr("C:/AvineDev/qt/zNavigo/html/page_blache.html"))
    {
        champAdresse->setText(url.toString());
    }
}
void FenPrincipale::chargementDebut()
{
    progression->setVisible(true);
}
void FenPrincipale::chargementEnCours(int pourcentage)
{
    progression->setValue(pourcentage);
}

void FenPrincipale::chargementTermine(bool ok)
{
    progression->setVisible(false);
    statusBar()->showMessage(tr("Prêt"),2000);
}

//en complément

QWidget *FenPrincipale::creerOngletPageWeb(QString url)
{
    QWidget *pageOnglet=new QWidget;
    QWebView *pageWeb=new QWebView;
    QVBoxLayout *layout=new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(pageWeb);
    pageOnglet->setLayout(layout);

    if(url.isEmpty())
    {
        pageWeb->load(QUrl(tr("html/page_blache.html")));
    }
    else
    {
        if(url.left(7)!="http://")
        {
            url="http://"+url;
        }
        pageWeb->load(QUrl(url));
    }
    // Gestion des signaux envoyés par la page web
    connect(pageWeb,SIGNAL(titleChanged(QString)),this,SLOT(changementTitre(QString)));
    connect(pageWeb,SIGNAL(urlChanged(QUrl)),this,SLOT(changementUrl(QUrl)));
    connect(pageWeb,SIGNAL(loadStarted()),this,SLOT(chargementDebut()));
    connect(pageWeb,SIGNAL(loadProgress(int)),this,SLOT(chargementEnCours(int)));
    connect(pageWeb,SIGNAL(loadFinished(bool)),this,SLOT(chargementTermine(bool)));

    return pageOnglet;
}

QWebView *FenPrincipale::pageActuelle()
{
return onglets->currentWidget()->findChild<QWebView *>();
}


