#ifndef ONEANIME_H
#define ONEANIME_H
#include <QString>


class OneAnime
{
private:

    int animeID;
    QString animeHossz;
    int animeAllapot;
    QString animeNev;
    QString animeMegjegyzes;
    QString animeTartalom;

public:
    OneAnime();
    OneAnime(int animeID, QString animeHossz, int animeAllapot, QString animeNev, QString animeMegjegyzes, QString animeTartalom);
    int getAnimeID() const;
    void setAnimeID(int value);
    QString getAnimeHossz() const;
    void setAnimeHossz(const QString &value);
    int getAnimeAllapot() const;
    void setAnimeAllapot(int value);
    QString getAnimeNev() const;
    void setAnimeNev(const QString &value);
    QString getAnimeMegjegyzes() const;
    void setAnimeMegjegyzes(const QString &value);
    QString getAnimeTartalom() const;
    void setAnimeTartalom(const QString &value);
};

#endif // ONEANIME_H
