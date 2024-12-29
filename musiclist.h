#ifndef MUSICLIST_H
#define MUSICLIST_H

#include <QUrl>
#include <QVector>
#include "music.h"

class MusicList
{
public:
    MusicList();

    void addMusicByUrl(const QUrl&);
    void addMusicByUrls(const QList<QUrl>&);

private:
    QVector<Music> musicVec;
};

#endif // MUSICLIST_H
