#include "musiclist.h"
#include <QMimeDatabase>
#include <QDebug>

MusicList::MusicList()
{

}

void MusicList::addMusicByUrl(const QUrl &url)
{
    // 获取文件的类型
    QMimeDatabase mimeDB;
    QMimeType mimeType = mimeDB.mimeTypeForFile(url.toLocalFile());
    QString mime = mimeType.name();

    if (mime == "audio/mepg" || mime == "audio/flac" || mime == "audio/wav") {
        musicVec.push_back(Music(url));
    }
}

void MusicList::addMusicByUrls(const QList<QUrl> &urls)
{
    for (auto &url : urls) {
        addMusicByUrl(url);
    }
}
