#include "animatedtextbrowser.h"
#include <QDebug>



AnimatedTextBrowser::AnimatedTextBrowser(QWidget *parent)
{
    this->setOpenExternalLinks(true);
}

AnimatedTextBrowser::~AnimatedTextBrowser()
{
    QList<QMovie*>listMovies = urls.keys();
    for (QMovie *o : listMovies) {

        delete o;
    }

    urls.clear();
}

void AnimatedTextBrowser::addAnimation(const QUrl &url, const QString filename)
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

void AnimatedTextBrowser::animate()
{
    qDebug() << "harom";
    if (QMovie* movie = qobject_cast<QMovie*>(sender())) {

        document()->addResource(QTextDocument::ImageResource, urls.value(movie), movie->currentPixmap());

        setLineWrapColumnOrWidth(lineWrapColumnOrWidth());


    }

}
