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
// 获取什么呀  歌曲信息 好的我演示一下   你这个只是八歌曲加载进来了  并没有通过代码获取歌曲的作者 之类的信息  是这样的 使用 Music 构造函数还获取
