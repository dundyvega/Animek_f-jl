#include "hashmodel.h"

HashModel::HashModel(QObject *parent)
    : QAbstractListModel(parent)
{



}

QVariant HashModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int HashModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    return items.size();

    // FIXME: Implement me!
}

QVariant HashModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > items.size())
    {
        return QVariant();
    }

    HummelObject* entry = items[index.row()];

    if (role == 0)
    {
        return QVariant::fromValue(entry->getName());
    }

    return QVariant();

}

HashModel::~HashModel()
{
    clear();

}

void HashModel::clear()
{

    for (int i = 0; i < items.length(); ++i)
    {
        delete items.at(i);

    }

}


HummelObject* HashModel::roleName()
{

}
