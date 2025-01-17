#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QUrl>
#include <QVector>
#include "music.h"

class MusicList
{
public:
    MusicList();

    size_t size() const;
    void addMusic(const Music &);
    void addMusicByUrl(const QUrl&);
    void addMusicByUrls(const QList<QUrl>&);

    Music &operator[](int);

    Music *findMusicById(const QString&);
    Music *findMUsicByQUrl(const QUrl&);

    Music *back();

    bool isExists(const QUrl&);

    void readFromDB();
    void writeToDB();

private:
    QVector<Music> musicVec;
};

#endif // MUSICLIST_H
