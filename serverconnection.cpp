#include "serverconnection.h"
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>

ServerConnection::ServerConnection(QObject *parent)
    : QObject(parent)
    , networkManager(new QNetworkAccessManager(this))
{}

void ServerConnection::SendMusicToHost(const QUrl &musicUrl, const QUrl &lrcUrl)
{
    // 将数据解析
    Music music(musicUrl);
    // 设置目标 Url
    QNetworkRequest request(UpLoadMusicUrl);
    // 创建表单对象
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    // 添加文本字段
    // Quid
    QHttpPart uidPart;
    uidPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"uid\""));
    uidPart.setBody(music.getMusicId().toUtf8());
    multiPart->append(uidPart);
    // 名字
    QHttpPart namePart;
    namePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"musicName\""));
    namePart.setBody(music.getMusicName().toUtf8());
    multiPart->append(namePart);
    // 歌手
    QHttpPart singerPart;
    singerPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"musicSinger\""));
    singerPart.setBody(music.getMusicSinger().toUtf8());
    multiPart->append(singerPart);
    // 专辑名
    QHttpPart albumPart;
    albumPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"musicAlbum\""));
    albumPart.setBody(music.getMusicAlbum().toUtf8());
    multiPart->append(albumPart);
    // 时长
    QHttpPart durationPart;
    durationPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"musicDuration\""));
    durationPart.setBody(QString::number(music.getMusicDuration()).toUtf8());
    multiPart->append(durationPart);

    // 添加歌曲和歌词
    QFile *musicFile = new QFile(musicUrl.toLocalFile());
    QFile *lrcFile = new QFile(lrcUrl.toLocalFile());
    if (!musicFile->open(QIODevice::ReadOnly) || !lrcFile->open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "警告", "你的音乐相关文件不存在");
        delete multiPart; // 记得释放
        return;
    }

    // 管理文件生命周期
    musicFile->setParent(multiPart);
    lrcFile->setParent(multiPart);

    QString filePath = music.getMusicQUrl().toLocalFile();
    QString musicFileName = filePath.mid(filePath.lastIndexOf('/') + 1);
    QString lrcFileName = musicFileName.left(musicFileName.lastIndexOf('.')) + ".lrc";

    // 歌曲
    QHttpPart musicPart;
    musicPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("audio/mp3"));
    musicPart.setHeader(QNetworkRequest::ContentDispositionHeader,
                        QVariant("form-data; name=\"music\"; filename=\"" + musicFileName + "\""));
    musicPart.setBodyDevice(musicFile);
    multiPart->append(musicPart);
    // 歌词
    QHttpPart lrcPart;
    lrcPart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain"));
    lrcPart.setHeader(QNetworkRequest::ContentDispositionHeader,
                      QVariant("form-data; name=\"lrc\"; filename = \"" + lrcFileName + "\""));
    lrcPart.setBodyDevice(lrcFile);
    multiPart->append(lrcPart);

    QNetworkReply *reply = networkManager->post(request, multiPart);
    multiPart->setParent(reply);

    // 处理回复
    connect(reply, &QNetworkReply::finished, this, [reply]() {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (statusCode == 200) {
            QMessageBox::information(nullptr, "信息", reply->readAll());
        } else {
            QString msg = reply->readAll();
            msg = msg.isEmpty() ? reply->errorString() : msg;
            QMessageBox::information(nullptr, "警告", msg);
        }
    });
}

Music *ServerConnection::getRandomMisc()
{
    // 设置目标 Url
    QNetworkRequest request(RandomMusicUrl);
    // 发起请求
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, [reply, this](){
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (statusCode == 200) {
            // 获取音乐信息
            QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
            // 构造一个 Music 对象
            Music music;
            music.setLocal(false);
            music.setMusicId(jsonDoc["uid"].toString());
            music.setMusicName(jsonDoc["musicName"].toString());
            music.setMusicSinger(jsonDoc["musicSinger"].toString());
            music.setMusicAlbum(jsonDoc["musicAlbum"].toString());
            music.setMusicDuration(jsonDoc["duration"].toString().toLongLong());
            music.setMusicQUrl(musicFileUrlPrefix + jsonDoc["musicFileName"].toString());
        } else {
            QMessageBox::warning(nullptr, "警告", "音乐获取失败");
        }
    });
}

QUrl ServerConnection::getRandomMusicUrl() const
{
    return RandomMusicUrl;
}
