#include "myactions.h"
#include <QDebug>

MyActions::MyActions(QObject *parent) : QAction(parent)
{

}


 MyActions::MyActions(QObject *parent, QString s, int i):QAction(s, parent)
 {
     num = i;
     name = s;
 }

 int MyActions::getNum()
 {
     return num;

 }

 void MyActions::clicked(bool checked = false) {
     qDebug() << num;
     emit(menuChanged(num));
 }



