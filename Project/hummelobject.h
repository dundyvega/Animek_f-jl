#ifndef HUMMELOBJECT_H
#define HUMMELOBJECT_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QAction>
#include <QStandardItem>

class HummelObject:public QStandardItem
{


private:

    int ID;

    QString comment1;

    int condition;

    QString name;


    QString comment2;

    QString content;


public:

    //HummelObject(QWidget *parent = nullptr);
    HummelObject(int ID, QString comment1, int condition, QString name, QString comment2, QString content, QWidget *parent = nullptr);
    virtual ~HummelObject();


    //setter, getter functions

    void setId(int ID) {this->ID = ID;}
    int getId() {return ID;}

    void setComment1(QString comment1) {this->comment1 = comment1;}
    QString getComment1() {return comment1;}

    void setCondition (int condition) { this->condition = condition;}
    int getCondition() {return condition;}

    void setName(QString name) {this->name = name;}
    QString getName() {return name;}

    void setComment2(QString comment2) {this->comment2 = comment2;}
    QString getComment2() {return comment2;}

    void setContent(QString content) {this->content = content;}
    QString getContent() {return content;}


    //toString

    QString toString() { return name;}

     bool operator <(HummelObject& other) const
     {
            name < other.getName();
     }








signals:

public slots:



};

#endif // HUMMELOBJECT_H
