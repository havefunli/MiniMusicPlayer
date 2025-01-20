#include "serverconnection.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>

const QUrl ServerConnection::RandomMusicUrl("http://192.168.17.128:8888/getRandomMusic");
const QUrl ServerConnection::UpLoadMusicUrl("http://192.168.17.128:8888/uploadMusic");
const QString ServerConnection::musicFileUrlPrefix = "http://192.168.17.128:8888/Music/";
const QString ServerConnection::musicSearchPrefix = "http://192.168.17.128:8888/getMusicInfo/";

ServerConnection::ServerConnection(QObject *parent)
    : QObject(parent)
    , networkManager(new QNetworkAccessManager(this))
{}

void ServerConnection::SendMusicToHost(const UpLoad::UpLoadInfo info)
{
    // 将数据解析
    Music music(info.musicUrl);
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
    // 歌手介绍
    QHttpPart infoPart;
    infoPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"singerInfo\""));
    infoPart.setBody(info.singerInfo.toUtf8());
    multiPart->append(infoPart);
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

    // 添加歌曲和歌词和图片
    QFile *musicFile = new QFile(info.musicUrl.toLocalFile());
    QFile *lrcFile = new QFile(info.lrcUrl.toLocalFile());
    QFile *imageFile = new QFile(info.imageUrl.toLocalFile());
    if (!musicFile->open(QIODevice::ReadOnly) ||
            !lrcFile->open(QIODevice::ReadOnly) ||
            !imageFile->open(QIODevice::ReadOnly)) {
        QMessageBox::information(nullptr, "警告", "你的音乐相关文件不存在");
        delete multiPart; // 记得释放
        return;
    }

    // 管理文件生命周期
    musicFile->setParent(multiPart);
    lrcFile->setParent(multiPart);
    imageFile->setParent(multiPart);

    QString filePath = music.getMusicQUrl().toLocalFile();
    QString musicFileName = filePath.mid(filePath.lastIndexOf('/') + 1);
    QString lrcFileName = musicFileName.left(musicFileName.lastIndexOf('.')) + ".lrc";

    QString imageFilePath = info.imageUrl.toLocalFile();
    QString imageFileName = imageFilePath.mid(imageFilePath.lastIndexOf('/') + 1);

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
    // 图片
    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                        QVariant("form-data; name=\"image\"; filename = \"" + imageFileName + "\""));
    imagePart.setBodyDevice(imageFile);
    multiPart->append(imagePart);

    QNetworkReply *reply = networkManager->post(request, multiPart);
    multiPart->setParent(reply);

    qDebug() << "我已发送等待处理";

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
        reply->deleteLater();
    });
}

void ServerConnection::rcvLrcFromHost(const QUrl &url)
{
    QNetworkRequest requet(url);
    QNetworkReply *reply = networkManager->get(requet);
    connect(reply, &QNetworkReply::finished, this, [=](){
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (statusCode == 200) {
            qDebug() << "成功获取歌词文件";
            emit lrcReady(reply->readAll());
        } else {
            QMessageBox::warning(nullptr, "警告", "歌词获取失败");
        }
        reply->deleteLater();
    });
}

void ServerConnection::getRandomMusic()
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
            QJsonObject jsonObj = jsonDoc.object();
            // 构造一个 Music 对象
            Music music(jsonObj);
            music.setLocal(false);
            qDebug() << "随机获取的音乐是 " << music.getMusicName();
            emit randomMusicReady(music);
        } else {
            QMessageBox::warning(nullptr, "警告", "音乐获取失败");
        }
        reply->deleteLater();
    });
}

void ServerConnection::searchMusic(const QString &musicName)
{
    QUrl srcUrl = musicSearchPrefix + musicName;
    // 设置目标 url
    QNetworkRequest request(srcUrl);
    // 发起请求
    QNetworkReply *reply = networkManager->get(request);
    // 等待响应
    connect(reply, &QNetworkReply::finished, this, [=](){
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (statusCode == 200) {
            // 获取数据
            QVector<Music> musicVec;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
            // 搜索结果不为空
            if (jsonDoc.isArray()) {
                QJsonArray jsonArray = jsonDoc.array();
                // 遍历每一个音乐
                for (const auto &value : jsonArray) {
                    QJsonObject obj = value.toObject();
                    Music music(obj);
                    // 非本地的
                    music.setLocal(false);
                    musicVec.push_back(music);
                }
            }
            emit searchResultReady(musicVec);
        } else {
            QMessageBox::warning(nullptr, "警告", "音乐搜索失败");
        }

        reply->deleteLater();
    });
}

