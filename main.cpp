#include<QApplication>
#include<QtWidgets>
#include<QLocale>
#include<QLibraryInfo>
#include"fenprincipale.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    //système de traductions

    QString locale=QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qt_")+locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&translator);
    //lancement de la fenetre
    FenPrincipale fenetre;
    fenetre.show();

    return app.exec();

}
