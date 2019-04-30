#ifndef TEXTBROWSERANIMATED2_H
#define TEXTBROWSERANIMATED2_H

#include <QObject>
#include <QTextBrowser>
#include <QWidget>
#include <QMovie>
#include <QUrl>

class TextBrowserAnimated2 : public QTextBrowser
{
    Q_OBJECT

private:
    QHash<QMovie*, QUrl> urls;
public:
    explicit TextBrowserAnimated2(QWidget *parent = nullptr);
    ~TextBrowserAnimated2();
    void addAnimation(const QUrl& url, const QString filename);

    void adAll(QString datFile);

signals:

public slots:
     void animate();
};

#endif // TEXTBROWSERANIMATED2_H
