#ifndef HASHMODEL_H
#define HASHMODEL_H


#include <QAbstractListModel>

#include <QList>

#include "hummelobject.h"

class HashModel : public QAbstractListModel
{

     Q_OBJECT
public:



    enum eMLERoleTypes
    {
        MLERT_MSG = Qt::UserRole,
        MLERT_COLOR
    };
   explicit HashModel(QObject *parent = nullptr);

    ~HashModel();

    void clear();

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

   HummelObject* roleName();

   HummelObject* getElement(int i)
   {
       if (!items.isEmpty()) {

        return items.at(i);
       } else {
           return NULL;
       }
   }

   void addElement(HummelObject* item)
   {
       items.append(item);
   }


   void deleteHummel(HummelObject *item)
   {
       if (!items.isEmpty()) {

        items.removeOne(item);
        delete item;
        item = nullptr;

       }
   }

   int length() {
       return items.length();
   }

   int hasElement(int id) {

       int index = -1;
       for (int i = 0; i < items.length() && index == -1; ++i) {

           if (items.at(i)->getId() == id) {
               index = i;
           }

       }

       return index;
   }




private:
    QList<HummelObject*> items;



};

#endif // HASHMODEL_H
