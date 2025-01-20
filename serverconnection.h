#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H
#include "upload.h"
#include "music.h"
#include "singer.h"
#include <QObject>
#include <QHttpPart>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class ServerConnection : public QObject
{
    Q_OBJECT
public:
    explicit ServerConnection(QObject *parent = nullptr);

    // 发送一个音乐文件
    void SendMusicToHost(const UpLoad::UpLoadInfo);
    // 接受 lrc 文件
    void rcvLrcFromHost(const QUrl &);
    // 接受一个随机线上音乐
    void getRandomMusic();
    // 获取歌手名字
    void getSingerName();
    // 获取歌手图片
    void getSingerImage(QVector<Singer*>);
    // 搜索音乐
    void searchMusic(const QString &);

signals:
    // 随机音乐就绪了
    void randomMusicReady(const Music);
    // 歌词就绪
    void lrcReady(QString);
    // 搜索结果就绪了
    void searchResultReady(QVector<Music>);
    // 歌手名字就绪
    void singerNameReady(QVector<Singer*>);
    // 图片数据就绪
    void singerImageReady(QVector<Singer*>);


public:
    static const QUrl RandomMusicUrl;
    static const QUrl UpLoadMusicUrl;
    static const QUrl SingerNameUrl;
    static const QString SingerImageUrl;
    static const QString musicFileUrlPrefix;
    static const QString musicSearchPrefix;
private:
    QNetworkAccessManager *networkManager;
};

#endif // SERVERCONNECTION_H
