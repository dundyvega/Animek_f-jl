#ifndef ANIMATEDTEXTBROWSER_H
#define ANIMATEDTEXTBROWSER_H

#include <QTextBrowser>
#include <QTextEdit>
#include <QMovie>
#include <QUrl>
#include <QWidget>
#include <QObject>


class AnimatedTextBrowser : public QTextBrowser
{



private:
    QHash<QMovie*, QUrl> urls;


public:
    AnimatedTextBrowser(QWidget* parent = 0);
    ~AnimatedTextBrowser();

    void addAnimation(const QUrl& url, const QString filename);

public slots:
    void animate();

};

#endif // ANIMATEDTEXTBROWSER_H
