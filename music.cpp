#include "music.h"
#include <QUuid>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <QCoreApplication>

Music::Music()
    : isLike(false)
    , isHistory(false)
{}

Music::Music(QUrl url)
    : isLike(false)
    , isHistory(false)
    , musicUrl(url)
{
    // 初始化一个 musicID
    musicID = QUuid::createUuid().toString();
    parseMediaMetaMusic();
}

void Music::setMusicName(const QString &name)
{
    musicName = name;
}

void Music::setMusicSinger(const QString &singer)
{
    musicSinger = singer;
}

void Music::setMusicAlbum(const QString &album)
{
    musicAlbum = album;
}

void Music::setMusicDuration(const qint64 &duration)
{
    this->duration = duration;
}

void Music::setLike(bool islike)
{
    isLike = islike;
}

void Music::setHistory(bool history)
{
    isHistory = history;
}

void Music::setMusicQUrl(const QUrl &url)
{
    musicUrl = url;
}

QString Music::getMusicId() const
{
    return musicID;
}

QString Music::getMusicName() const
{
    return musicName;
}

QString Music::getMusicSinger() const
{
    return musicSinger;
}

QString Music::getMusicAlbum() const
{
    return musicAlbum;
}

qint64 Music::getMusicDuration() const
{
    return duration;
}

bool Music::getLike() const
{
    return isLike;
}

bool Music::getHistory() const
{
    return isHistory;
}

QUrl Music::getMusicQUrl() const
{
    return musicUrl;
}

QString Music::getLrcFilePath() const
{
    QString filePath = musicUrl.toLocalFile();
    int dotIndex = filePath.lastIndexOf('.');
    if (dotIndex == -1) {
        return "文件格式错误";
    }
    filePath.replace(dotIndex + 1, filePath.size() - dotIndex - 1, QString("lrc"));
    return filePath;
}

void Music::parseMediaMetaMusic()
{
    // 1. 创建媒体播放对象
    QMediaPlayer player;

    // 2. 设置媒体源（音乐文件 URL）
    player.setMedia(musicUrl);

    // 3.等待数据加载
    while (!player.isMetaDataAvailable()) {
        QCoreApplication::processEvents();
    }

    // 4. 输出加载信息
    if (player.isMetaDataAvailable()){
        musicName = player.metaData("Title").toString();
        musicSinger = player.metaData("Author").toString();
        musicAlbum = player.metaData("AlbumTitle").toString();
        duration = player.metaData("duration").toLongLong();
        // qDebug() << musicName << " " << musicSinger << " " << musicAlbum << " " << duration;
    }

    // 5. 手动输入信息
    QString fileName = musicUrl.fileName();
    int index = fileName.indexOf('-');
    // 歌名为空
    if (musicName.isEmpty()) {
        if (index != -1) {
            musicName = fileName.mid(0, index).trimmed();
        } else {
            musicName = fileName.mid(0, fileName.indexOf('.')).trimmed();
        }
    }

    // 作者为空
    if(musicSinger.isEmpty()) {
        if (index != -1) {
            musicSinger = fileName.mid(index + 2, fileName.indexOf('.') - index - 2).trimmed();
        } else {
            musicSinger = "未知歌手";
        }
    }

    // 专辑为空
    if (musicAlbum.isEmpty()) {
        musicAlbum = "未知专辑";
    }
}

