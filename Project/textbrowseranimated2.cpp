#include "textbrowseranimated2.h"
#include <QDebug>
#include "dialogtextedit.h"
#include <QFile>

TextBrowserAnimated2::TextBrowserAnimated2(QWidget *parent) : QTextBrowser(parent)
{
    this->setOpenExternalLinks(true);
}


TextBrowserAnimated2::~TextBrowserAnimated2()
{
    QList<QMovie*>listMovies = urls.keys();
    for (QMovie *o : listMovies) {

        delete o;
    }

    urls.clear();
}

void TextBrowserAnimated2::addAnimation(const QUrl &url, const QString filename)
{
    QList<QUrl> listUrls = urls.values();

    if (!listUrls.contains(url)) {
        QMovie *movie = new QMovie(this);
        movie->setFileName(filename);
        movie->setCacheMode(QMovie::CacheAll);
        urls.insert(movie, url);
        qDebug() << "egy";
        connect (movie, SIGNAL(frameChanged(int)), this, SLOT(animate()));
        movie->start();
        qDebug() << "kettő";
    }

}

void TextBrowserAnimated2::adAll(QString datFile)
{

    QString data;
    QFile file(datFile);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"filenot opened"<<endl;
        //QMessageBox::information(0,"error",file.errorString());
    }
    else
    {
        qDebug()<<"file opened"<<endl;

        QString line = file.readLine();

        while (!file.atEnd())
        {
            QStringList fields = line.split("#");
            DoubleString obj(fields.at(1), fields.at(2));
            addAnimation("smiles/" + fields.at(0), "smiles/" + fields.at(0));
            //qDebug() << fields.at(1);
            line = file.readLine();

        }


    }

    file.close();


}

void TextBrowserAnimated2::animate()
{
    qDebug() << "harom";
    if (QMovie* movie = qobject_cast<QMovie*>(sender())) {

        document()->addResource(QTextDocument::ImageResource, urls.value(movie), movie->currentPixmap());

        setLineWrapColumnOrWidth(lineWrapColumnOrWidth());


    }

}
