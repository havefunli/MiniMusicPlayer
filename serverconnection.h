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
    void getRandomMusic();

signals:
    // 随机音乐就绪了
    void randomMusicReady(const Music);


public:
    static const QUrl RandomMusicUrl;
    static const QUrl UpLoadMusicUrl;
    static const QString musicFileUrlPrefix;

private:
    QNetworkAccessManager *networkManager;
};

#endif // SERVERCONNECTION_H
