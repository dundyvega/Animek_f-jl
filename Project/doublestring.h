#ifndef DOUBLESTRING_H
#define DOUBLESTRING_H
#include <QString>


class DoubleString
{

private:
    QString writer;
    QString shower;


public:
    DoubleString(QString writer, QString shower);
    DoubleString();

    QString getWriter() const;
    void setWriter(const QString &value);
    QString getShower() const;
    void setShower(const QString &value);
};

#endif // DOUBLESTRING_H
