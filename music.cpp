#include "music.h"
#include <QUuid>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <QCoreApplication>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "serverconnection.h"

bool Music::isLocalPath(const QString &filePath)
{
    return filePath.contains("http://192.168.254.130:8888");
}

Music::Music()
    : isLike(false)
    , isHistory(false)
    , isLocal(true)
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

Music::Music(const QJsonObject &jsonObj)
{
    setLike(false);
    setLocal(false);
    setMusicId(jsonObj["uid"].toString());
    setMusicName(jsonObj["musicName"].toString());
    setMusicSinger(jsonObj["musicSinger"].toString());
    setMusicAlbum(jsonObj["musicAlbum"].toString());
    setMusicDuration(jsonObj["duration"].toString().toLongLong());
    setMusicQUrl(ServerConnection::musicFileUrlPrefix + jsonObj["musicFileName"].toString());
}

void Music::setMusicId(const QString &ID)
{
    musicID = ID;
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

void Music::setLocal(bool local)
{
    isLocal = local;
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

bool Music::getLocal() const
{
    return isLocal;
}

QUrl Music::getMusicQUrl() const
{
    return musicUrl;
}

QString Music::getLrcFilePath() const
{
    // 根据具体类型选择具体的转换方式
    QString filePath = musicUrl.toString();
    if (isLocal) {
        filePath = musicUrl.toLocalFile();
    }
    // 转换文件后缀
    int dotIndex = filePath.lastIndexOf('.');
    if (dotIndex == -1) {
        return "文件格式错误";
    }
    filePath.replace(dotIndex + 1, filePath.size() - dotIndex - 1, QString("lrc"));
    return filePath;
}

void Music::insertMusicToDB() const
{
    // 1. 检查当前音乐是否存在于数据库
    QSqlQuery query;
    query.prepare("SELECT EXISTS(SELECT 1 FROM Music WHERE musicId = :id)");
    query.bindValue(":id", musicID);
    if (!query.exec()) {
        qDebug() << "查询音乐出错：" << query.lastError().text();
        return;
    }

    if (query.next() && query.value(0).toBool()) {
        // 2. 如果存在只需要更新 isLike isHistory
        query.prepare("UPDATE Music SET isLike = :isLike, isHistory = :isHistory WHERE musicId = :musicId");
        query.bindValue(":isLike", isLike ? 1 : 0);
        query.bindValue(":isHistory", isHistory ? 1 : 0);
        query.bindValue(":musicId", musicID);
    } else {
        // 3. 如果不存在插入该音乐信息
        query.prepare("INSERT INTO Music \
                       (musicId, musicName, musicSinger, albumName, musicUrl, duration, isLike, isHistory, isLocal) \
                       VALUES(:musicId, :musicName, :musicSinger, :albumName, :musicUrl, :duration, :isLike, :isHistory, :isLocal)");
                      query.bindValue(":musicId", musicID);
        query.bindValue(":musicName", musicName);
        query.bindValue(":musicSinger", musicSinger);
        query.bindValue(":albumName", musicAlbum);
        query.bindValue(":musicUrl", musicUrl);
        query.bindValue(":duration", duration);
        query.bindValue(":isLike", isLike ? 1 : 0);
        query.bindValue(":isHistory", isHistory ? 1 : 0);
        query.bindValue(":isLocal", isLocal ? 1 : 0);
    }
    if (!query.exec()) {
        qDebug() << "保存音乐出错：" << query.lastError().text();
        return;
    }
    qDebug() << "成功保存音乐信息：" << musicName;
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
        duration = player.metaData("Duration").toLongLong();
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
            musicSinger = fileName.mid(index + 1, fileName.indexOf('.') - index - 1).trimmed();
        } else {
            musicSinger = "未知歌手";
        }
    }

    // 专辑为空
    if (musicAlbum.isEmpty()) {
        musicAlbum = "未知专辑";
    }

    isLocal = musicUrl.isLocalFile();
}

