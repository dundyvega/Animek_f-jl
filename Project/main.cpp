#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
     translator.load("deneraHummel_hu_HU", QCoreApplication::applicationDirPath());
     a.installTranslator(&translator);


    MainWindow w;
    //w.setGeometry(0, 0, 900, 900);
    //w.setSizeIncrement(500, 600);

    QScreen *screen = QGuiApplication::primaryScreen();
    w.setGeometry(screen->geometry());


    w.show();


    return a.exec();
}
