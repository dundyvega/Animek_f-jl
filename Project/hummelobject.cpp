#include "hummelobject.h"



HummelObject::HummelObject(int ID, QString comment1, int  condition, QString  name, QString  comment2, QString  content, QWidget *parent):QStandardItem(name), ID(ID),
    comment1(comment1), condition(condition), name(name), comment2(comment2), content(content)

{

}

/*

, ID(ID),
    comment1(comment1), condition(condition), name(name), comment2(comment2), content(content)

*/


HummelObject::~HummelObject()
{

}
