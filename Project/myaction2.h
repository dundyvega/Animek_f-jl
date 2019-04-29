#ifndef MYACTION2_H
#define MYACTION2_H

#include <QObject>

class MyAction2 : public QObject
{
    Q_OBJECT
public:
    explicit MyAction2(QObject *parent = nullptr);

signals:
    void clickOnMenu(MyAction myAction);

public slots:
};

#endif // MYACTION2_H
