#include "musiclist.h"
#include <QMimeDatabase>
#include <QDebug>

MusicList::MusicList()
{

}

size_t MusicList::size() const
{
    return musicVec.size();
}

void MusicList::addMusicByUrl(const QUrl &url)
{
    // 获取文件的类型
    QMimeDatabase mimeDB;
    QMimeType mimeType = mimeDB.mimeTypeForFile(url.toLocalFile());
    QString mime = mimeType.name();

    if (mime == "audio/mpeg" || mime == "audio/flac" || mime == "audio/wav") {
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

