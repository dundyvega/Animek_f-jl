#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H
#include <QFile>
#include <QString>
#include <QList>
#include "hummelobject.h"


class FileOperator
{
private:

     QFile* file = NULL;
     QFile* container = NULL;

public:

    FileOperator();
    ~FileOperator()
    {
        delete file;
        delete container;
    }
     void setFileName(QString file);
     void newFile(QString filek);
     QList<HummelObject*> animekXML(int allapot);
     QList<HummelObject*> keresAnimekXML(QString karakterlanc);
     void modositAnimeXML(int index, QString nev, QString megjegyzes, QString reszek, int allapot);
     bool isContentAnime();
     void ujAnimeXML(QString animeNev);
     void ujAnimeXML(int reszek, int allapot, QString animeNevS, QString megjegyzesS);
     void makeContentAnime();
     void torolAnimeXML(int animeID);
     bool configureCreated();
     void setContainerFile(QFile file2);
     void setTartalom(int index, QString text);
     QList<HummelObject*> keresAnimekTartalomXML(QString karakterLanc);

     static bool kisebb( HummelObject *v1,  HummelObject *v2);

     bool isEmpty() {
         return file == NULL;
     }
};

#endif // FILEOPERATOR_H
