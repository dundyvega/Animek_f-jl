#include "fileoperator.h"
#include <QDomDocument>
#include <QDebug>
#include "hummelobject.h"
#include <algorithm>



FileOperator::FileOperator()
{

}

void FileOperator::setFileName(QString fil)
{
    if (file != NULL) {
        delete file;
    }
    this->file = new QFile(fil);

    QString myFileName = "denera.hum";
    QFile myFile(myFileName);

    if (myFile.open(QIODevice::WriteOnly)) {
        QTextStream stream(&myFile);
        stream << fil << endl;

    }

    myFile.close();

}

void FileOperator::newFile(QString filek)
{
    if (file != NULL) {
        delete file;
    }



    QString myFileName = "denera.hum";
    QFile myFile(myFileName);

    if (myFile.open(QIODevice::WriteOnly)) {
        QTextStream stream(&myFile);
        stream << filek << endl;

    }

    myFile.close();


    this->file = new QFile(filek);

    QDomDocument dom("");
    dom.appendChild( dom.createProcessingInstruction("xml", "version='1.0' encoding='utf-8' standalone='no'") );



    QDomElement rootElement = dom.createElement("Animek");
    dom.appendChild(rootElement);
    QDomElement staff = dom.createElement("anime");
    rootElement.appendChild(staff);



    //id

    QDomElement animeID = dom.createElement("animeID");
    animeID.appendChild(dom.createTextNode("1"));

    staff.appendChild(animeID);

    //név

    QDomElement name = dom.createElement("animeNev");
    name.appendChild(dom.createTextNode("Empty"));

    staff.appendChild(name);

    //allapot

    QDomElement lastName = dom.createElement("nezem");
    lastName.appendChild(dom.createTextNode("1"));

    staff.appendChild(lastName);

    //reszek

    QDomElement nickName = dom.createElement("reszek");
    nickName.appendChild(dom.createTextNode("0"));

    staff.appendChild(nickName);

    //megjegyzes

    QDomElement megjegyzes = dom.createElement("megjegyzes");
    megjegyzes.appendChild(dom.createTextNode("---"));

    staff.appendChild(megjegyzes);

    //tartalom

    QDomElement tartalom = dom.createElement("tartalom");
    tartalom.appendChild(dom.createTextNode("---"));

    staff.appendChild(tartalom);

    qDebug() << dom.elementsByTagName("animeID").at(0).toElement().text() << "szöveg";

    //QTextStream stream (file);
    //stream << dom.toString();
    //file->close();
    //qDebug() << "write is done";



    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Failed to open");
        return;
    }

    QTextStream stream (file);
    stream << dom.toString();
    file->close();



}

QList<HummelObject*> FileOperator::animekXML(int allapot)
{

    file->open(QFile::ReadOnly | QFile::Text);
    QDomDocument dom;
    QString error;
    int line, column;
    qDebug() << "itt még jó ";

    if (!dom.setContent(file, &error, &line, &column))
    {
        qDebug() << "Error";
        exit(0);

    }



    QList<HummelObject*> animek;
    QDomNodeList nodes = dom.elementsByTagName("nezem");

    if (allapot != 100) {
        qDebug() << "itt is jó";
        for (int i = 0; i < nodes.count(); ++i)
        {

            QDomNode id = nodes.at(i);
            QString idS = id.toElement().text();
            if (idS.toInt() == allapot)
            {

                QDomNode parent = id.parentNode();

                int animeId = parent.toElement().elementsByTagName("animeID").at(0).toElement().text().toInt();
                QString animeReszek = parent.toElement().elementsByTagName("reszek").at(0).toElement().text();
                QString animeNev = parent.toElement().elementsByTagName("animeNev").at(0).toElement().text();
                QString megjegyzes = parent.toElement().elementsByTagName("megjegyzes").at(0).toElement().text();
                QString tartalom = parent.toElement().elementsByTagName("tartalom").at(0).toElement().text();
                HummelObject *anime = new HummelObject(animeId, animeReszek, allapot, animeNev, megjegyzes, tartalom);
                animek.append(anime);

            }
        }

    } else {

        for (int i = 0; i < nodes.count(); ++i)
        {


            QDomNode id = nodes.at(i);
            QString idS = id.toElement().text();

                QDomNode parent = id.parentNode();

                int animeId = parent.toElement().elementsByTagName("animeID").at(0).toElement().text().toInt();
                QString animeReszek = parent.toElement().elementsByTagName("reszek").at(0).toElement().text();
                QString animeNev = parent.toElement().elementsByTagName("animeNev").at(0).toElement().text();
                QString megjegyzes = parent.toElement().elementsByTagName("megjegyzes").at(0).toElement().text();
                QString tartalom = parent.toElement().elementsByTagName("tartalom").at(0).toElement().text();
                allapot = parent.toElement().elementsByTagName("nezem").at(0).toElement().text().toInt();
                HummelObject *anime = new HummelObject(animeId, animeReszek, allapot, animeNev, megjegyzes, tartalom);
                animek.append(anime);
                qDebug() << i << " " << animeNev;

        }

    }

    file->close();
   // std::sort(animek.begin(), animek.end());

    std::sort(animek.begin(), animek.end(), kisebb);



    return animek;

}

bool FileOperator::kisebb (HummelObject *v1,  HummelObject *v2)
{
    return v1->getName() < v2->getName();
}

QList<HummelObject*> FileOperator::keresAnimekXML(QString karakterlanc)
{
    file->open(QFile::ReadOnly | QFile::Text);
    QDomDocument dom;
    QString error;
    int line, column;
    qDebug() << "itt még jó ";

    if (!dom.setContent(file, &error, &line, &column))
    {
        qDebug() << "Error";
        exit(0);

    }



    QList<HummelObject*> animek;
    QDomNodeList nodes = dom.elementsByTagName("animeNev");


     for (int i = 0; i < nodes.length(); ++i)
     {
         QDomNode id = nodes.at(i);
         QString idS = id.toElement().text();

         if (idS.toLower().contains(karakterlanc.toLower()))
         {
             QDomNode parent = id.parentNode();

             int animeId = parent.toElement().elementsByTagName("animeID").at(0).toElement().text().toInt();
             QString animeReszek = parent.toElement().elementsByTagName("reszek").at(0).toElement().text();
             QString animeNev = parent.toElement().elementsByTagName("animeNev").at(0).toElement().text();
             QString megjegyzes = parent.toElement().elementsByTagName("megjegyzes").at(0).toElement().text();
             QString tartalom = parent.toElement().elementsByTagName("tartalom").at(0).toElement().text();
             int allapot = parent.toElement().elementsByTagName("nezem").at(0).toElement().text().toInt();
             HummelObject *anime = new HummelObject(animeId, animeReszek, allapot, animeNev, megjegyzes, tartalom);
             animek.append(anime);
             qDebug() << i << " " << animeNev;

         }


     }
     file->close();
    // std::sort(animek.begin(), animek.end());

     std::sort(animek.begin(), animek.end(), kisebb);



     return animek;


}

void FileOperator::modositAnimeXML(int index, QString nev, QString megjegyzes, QString reszek, int allapot)
{

     file->open(QIODevice::ReadWrite | QIODevice::Text);

    QDomDocument dom;
    QString error;
    int line, column;
    qDebug() << "itt még jó ";

    if (!dom.setContent(file, &error, &line, &column))
    {
        qDebug() << "Error";
        exit(0);

    }

    QDomNodeList nList = dom.elementsByTagName("animeID");
    bool b = true;

    for (int i = 0; i < nList.length() && b; ++i)
    {


        QDomElement id = nList.item(i).toElement();
        QString idS =id.text();


        if (idS.toInt() == index)
        {
            qDebug() << index;
            QDomElement parent = id.parentNode().toElement();

            parent.elementsByTagName("animeNev").at(0).firstChild().setNodeValue(nev);

            parent.elementsByTagName("nezem").at(0).firstChild().setNodeValue(QString::number(allapot));

            parent.elementsByTagName("megjegyzes").at(0).firstChild().setNodeValue(megjegyzes);

            parent.elementsByTagName("reszek").at(0).firstChild().setNodeValue(reszek);
            b = false;
        }
    }

    file->close();
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Failed to open");
        return;
    }

    QTextStream stream (file);
    stream << dom.toString();
    file->close();

}

bool FileOperator::isContentAnime()
{

}

void FileOperator::ujAnimeXML(QString animeNev)
{

    ujAnimeXML(0, 1, animeNev, "-----");


}

void FileOperator::ujAnimeXML(int reszek, int allapot, QString animeNevS, QString megjegyzesS)
{
    file->open(QIODevice::ReadWrite | QIODevice::Text);

    QDomDocument dom;
    QString error;
    int line, column;
    qDebug() << "itt még jó ";

    if (!dom.setContent(file, &error, &line, &column))
    {
        qDebug() << "Error";
        exit(0);

    }

    QDomElement rootElement = dom.documentElement();
    QDomElement staff = dom.createElement("anime");
    rootElement.appendChild(staff);

    QDomNodeList nList = dom.elementsByTagName("animeID");
    QDomNode elementes = nList.item(nList.length()-1);

    QString idS = elementes.toElement().text();
    int id = idS.toInt() + 1;

    //id

    QDomElement animeID = dom.createElement("animeID");
    animeID.appendChild(dom.createTextNode(QString::number(id)));

    staff.appendChild(animeID);

    //név

    QDomElement name = dom.createElement("animeNev");
    name.appendChild(dom.createTextNode(animeNevS));

    staff.appendChild(name);

    //allapot

    QDomElement lastName = dom.createElement("nezem");
    lastName.appendChild(dom.createTextNode(QString::number(allapot)));

    staff.appendChild(lastName);

    //reszek

    QDomElement nickName = dom.createElement("reszek");
    nickName.appendChild(dom.createTextNode(QString::number(reszek)));

    staff.appendChild(nickName);

    //megjegyzes

    QDomElement megjegyzes = dom.createElement("megjegyzes");
    megjegyzes.appendChild(dom.createTextNode(megjegyzesS));

    staff.appendChild(megjegyzes);

    //tartalom

    QDomElement tartalom = dom.createElement("tartalom");
    tartalom.appendChild(dom.createTextNode(megjegyzesS));

    staff.appendChild(tartalom);

    //QTextStream stream (file);
    //stream << dom.toString();
    //file->close();
    //qDebug() << "write is done";

    file->close();


    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug("Failed to open");
        return;
    }

    QTextStream stream (file);
    stream << dom.toString();
    file->close();




}

void FileOperator::makeContentAnime()
{

}

void FileOperator::torolAnimeXML(int animeID)
{


    file->open(QIODevice::ReadWrite | QIODevice::Text);

   QDomDocument dom;
   QString error;
   int line, column;
   qDebug() << "itt még jó ";

   if (!dom.setContent(file, &error, &line, &column))
   {
       qDebug() << "Error";
       exit(0);

   }

   QDomNodeList nList = dom.elementsByTagName("animeID");
   bool b = true;

   for (int i = 0; i < nList.length() && b; ++i)
   {


       QDomElement id = nList.item(i).toElement();
       QString idS =id.text();


       if (idS.toInt() == animeID)
       {

           QDomElement parent = id.parentNode().toElement();
           parent.parentNode().removeChild(parent);


           b = false;
       }
   }

   file->close();
   if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
   {
       qDebug("Failed to open");
       return;
   }

   QTextStream stream (file);
   stream << dom.toString();
   file->close();


}

bool FileOperator::configureCreated()
{
    QString myFileName = "denera.hum";
    QFile myFile(myFileName);

    if (myFile.open(QIODevice::ReadOnly)) {
       // QTextStream stream(&myFile);
        //stream << fil << endl;
        QString line = myFile.readLine();

        line.replace("\n", "");

        this->setFileName(line);
        myFile.close();

        qDebug() << line << "ez lesz";

    }

    myFile.close();

}

void FileOperator::setContainerFile(QFile file2)
{

}

void FileOperator::setTartalom(int index, QString text)
{

    file->open(QIODevice::ReadWrite | QIODevice::Text);

   QDomDocument dom;
   QString error;
   int line, column;
   qDebug() << "itt még jó ";

   if (!dom.setContent(file, &error, &line, &column))
   {
       qDebug() << "Error";
       exit(0);

   }

   QDomNodeList nList = dom.elementsByTagName("animeID");
   bool b = true;

   for (int i = 0; i < nList.length() && b; ++i)
   {


       QDomElement id = nList.item(i).toElement();
       QString idS =id.text();


       if (idS.toInt() == index)
       {
           qDebug() << index;
           QDomElement parent = id.parentNode().toElement();

           parent.elementsByTagName("tartalom").at(0).firstChild().setNodeValue(text);

           b = false;
       }
   }

   file->close();
   if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
   {
       qDebug("Failed to open");
       return;
   }

   QTextStream stream (file);
   stream << dom.toString();
   file->close();

}

QList<HummelObject*> FileOperator::keresAnimekTartalomXML(QString karakterLanc)
{
    file->open(QFile::ReadOnly | QFile::Text);
    QDomDocument dom;
    QString error;
    int line, column;
    qDebug() << "itt még jó ";

    if (!dom.setContent(file, &error, &line, &column))
    {
        qDebug() << "Error";
        exit(0);

    }



    QList<HummelObject*> animek;
    QDomNodeList nodes = dom.elementsByTagName("tartalom");


     for (int i = 0; i < nodes.length(); ++i)
     {
         QDomNode id = nodes.at(i);
         QString idS = id.toElement().text();

         if (idS.toLower().contains(karakterLanc.toLower()))
         {
             QDomNode parent = id.parentNode();

             int animeId = parent.toElement().elementsByTagName("animeID").at(0).toElement().text().toInt();
             QString animeReszek = parent.toElement().elementsByTagName("reszek").at(0).toElement().text();
             QString animeNev = parent.toElement().elementsByTagName("animeNev").at(0).toElement().text();
             QString megjegyzes = parent.toElement().elementsByTagName("megjegyzes").at(0).toElement().text();
             QString tartalom = parent.toElement().elementsByTagName("tartalom").at(0).toElement().text();
             int allapot = parent.toElement().elementsByTagName("nezem").at(0).toElement().text().toInt();
             HummelObject *anime = new HummelObject(animeId, animeReszek, allapot, animeNev, megjegyzes, tartalom);
             animek.append(anime);
             qDebug() << i << " " << animeNev;

         }


     }
     file->close();
    // std::sort(animek.begin(), animek.end());

     std::sort(animek.begin(), animek.end(), kisebb);



     return animek;


}
