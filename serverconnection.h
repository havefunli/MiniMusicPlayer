#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include "music.h"
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
    void SendMusicToHost(const QUrl &, const QUrl &);
    // 接受一个随机线上音乐
    Music *getRandomMisc();

signals:

public:
    static const QUrl RandomMusicUrl;
    static const QUrl UpLoadMusicUrl;
    static const QString musicFileUrlPrefix;

private:
    QNetworkAccessManager *networkManager;
};

const QUrl ServerConnection::RandomMusicUrl("http://192.168.254.130:8888/getRandomMusic");
const QUrl ServerConnection::UpLoadMusicUrl("http://192.168.254.130:8888/uploadMusic");
const QString ServerConnection::musicFileUrlPrefix = "http://192.168.254.130:8888/Music/";

#endif // SERVERCONNECTION_H
