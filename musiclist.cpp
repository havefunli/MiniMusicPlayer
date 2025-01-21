#include "musiclist.h"
#include <QMimeDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

MusicList::MusicList()
{}

size_t MusicList::size() const
{
    return musicVec.size();
}

void MusicList::addMusic(Music music)
{
    Music *musicPtr = findMUsicByQUrl(music.getMusicQUrl());
    if (musicPtr != nullptr) {
        // qDebug() << "曾经听过";
        music.setLike(musicPtr->getLike());
        remove(musicPtr);
    }
    musicVec.append(music);
}

void MusicList::addMusicByUrl(const QUrl &url)
{
    // 获取文件的类型
    QMimeDatabase mimeDB;
    QMimeType mimeType = mimeDB.mimeTypeForFile(url.toLocalFile());
    QString mime = mimeType.name();

    // 类型符合 && 不存在
    if ((mime == "audio/mpeg" || mime == "audio/flac" || mime == "audio/wav") && !isExists(url)) {
        qDebug() << url << ": " << mime;
        musicVec.push_back(Music(url));
    }
}

void MusicList::addMusicByUrls(const QList<QUrl> &urls)
{
    for (auto &url : urls) {
        addMusicByUrl(url);
    }
}

Music &MusicList::operator[](int index)
{
    return musicVec[index];
}

Music *MusicList::findMusicById(const QString &id)
{
    for (auto &music : musicVec) {
        if (music.getMusicId() == id) {
            return &music;
        }
    }
    return nullptr;
}

Music *MusicList::findMUsicByQUrl(const QUrl &url)
{
    for (auto &music : musicVec) {
        if (music.getMusicQUrl() == url) {
            return &music;
        }
    }
    return nullptr;
}

Music *MusicList::back()
{
    return &musicVec.back();
}

bool MusicList::isExists(const QUrl &url)
{
    return findMUsicByQUrl(url) != nullptr ? true : false;
}

void MusicList::remove(Music *musicPtr)
{
    for (int i = 0; i < musicVec.size(); i++) {
        if (&musicVec[i] == musicPtr) {
            musicVec.remove(i);
        }
    }
}

void MusicList::readFromDB()
{
    QSqlQuery query;
    query.prepare("select musicId, musicName, musicSinger, albumName, musicUrl, duration, isLike, isHistory, isLocal FROM Music");
    if (!query.exec()) {
        qDebug() << "数据读取出错：" << query.lastError().text();
    }

    while (query.next()) {
        Music music;
        music.setMusicId(query.value(0).toString());
        music.setMusicName(query.value(1).toString());
        music.setMusicSinger(query.value(2).toString());
        music.setMusicAlbum(query.value(3).toString());
        music.setMusicQUrl(query.value(4).toString());
        music.setMusicDuration(query.value(5).toLongLong());
        music.setLike(query.value(6).toBool());
        music.setHistory(query.value(7).toBool());
        music.setLocal(query.value(8).toBool());

        musicVec.push_back(music);
    }
}

void MusicList::writeToDB()
{
    for (int i = 0; i < musicVec.size(); i++) {
        musicVec[i].insertMusicToDB();
    }
}

