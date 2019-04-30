#ifndef MYACTIONS_H
#define MYACTIONS_H

#include <QAction>

class MyActions : public QAction
{
    Q_OBJECT
private:
    int num = 0;
    QString name = "";


public:
    explicit MyActions(QObject *parent = nullptr);
    MyActions(QObject *parent, QString s, int i);
    int getNum();
signals:
    void menuChanged(int i);


public slots:
    //void clicked(int number);
   void clicked(bool checked);
};

#endif // MYACTIONS_H
