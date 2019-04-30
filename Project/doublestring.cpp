#include "doublestring.h"

DoubleString::DoubleString(QString writer, QString shower)
{
    this->shower = shower;
    this->writer = writer;
}

DoubleString::DoubleString()
{
    this->shower = "";
    this->writer = "";
}

QString DoubleString::getShower() const
{
    return shower;
}

void DoubleString::setShower(const QString &value)
{
    shower = value;
}

QString DoubleString::getWriter() const
{
    return writer;
}

void DoubleString::setWriter(const QString &value)
{
    writer = value;
}
