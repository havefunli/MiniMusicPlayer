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
    // parseMediaMetaMusic();
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

void Music::parseMediaMetaMusic()
{
    // 1. 创建媒体播放对象
    QMediaPlayer player;

    // 2. 设置媒体源（音乐文件 URL）
    // player.;

    // 3.等待数据加载
    while (!player.isAvailable()) {
    }

    // 4. 输出加载信息   你QT是哪版本的 6 和老师的不一样
    // 用5.14的版本吧   QT6 把播放列表类移除了  你后续播放列表没有办法实现 那现在怎么回退版本呢？重新安装个5。14的
    if (player.isAvailable()){
        //musicName = player.metaData().value(QMediaMetaData::Duration).toString();
        // musicName = player.metaData("Duration").toString();
        qDebug() << musicName<<"xxx";
    }

    // 5. 开始播放以触发元数据加载
    player.play();
}

