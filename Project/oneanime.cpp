#include "oneanime.h"

int OneAnime::getAnimeID() const
{
    return animeID;
}

void OneAnime::setAnimeID(int value)
{
    animeID = value;
}

QString OneAnime::getAnimeHossz() const
{
    return animeHossz;
}

void OneAnime::setAnimeHossz(const QString &value)
{
    animeHossz = value;
}

int OneAnime::getAnimeAllapot() const
{

    return animeAllapot;
}

void OneAnime::setAnimeAllapot(int value)
{
    animeAllapot = value;
}

QString OneAnime::getAnimeNev() const
{
    return animeNev;
}

void OneAnime::setAnimeNev(const QString &value)
{
    animeNev = value;
}

QString OneAnime::getAnimeMegjegyzes() const
{
    return animeMegjegyzes;
}

void OneAnime::setAnimeMegjegyzes(const QString &value)
{
    animeMegjegyzes = value;
}

QString OneAnime::getAnimeTartalom() const
{
    return animeTartalom;
}

void OneAnime::setAnimeTartalom(const QString &value)
{
    animeTartalom = value;
}

OneAnime::OneAnime()
{

}

OneAnime::OneAnime(int animeID, QString animeHossz, int animeAllapot, QString animeNev, QString animeMegjegyzes, QString animeTartalom)
{
    this->animeNev = animeNev;
    this->animeID = animeID;
    this->animeHossz = animeHossz;
    this->animeMegjegyzes = animeMegjegyzes;
    this->animeTartalom = animeTartalom;
}
