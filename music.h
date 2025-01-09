#ifndef MUSIC_H
#define MUSIC_H
#include <QUrl>

class Music
{
public:
    Music();
    Music(QUrl url);

    void setMusicId(const QString&);
    void setMusicName(const QString&);
    void setMusicSinger(const QString&);
    void setMusicAlbum(const QString&);
    void setMusicDuration(const qint64&);
    void setLike(bool);
    void setHistory(bool);
    void setLocal(bool);
    void setMusicQUrl(const QUrl&);

    QString getMusicId() const;
    QString getMusicName() const;
    QString getMusicSinger() const;
    QString getMusicAlbum() const;
    qint64 getMusicDuration() const;
    bool getLike() const;
    bool getHistory() const;
    bool getLocal() const;
    QUrl getMusicQUrl() const;

    QString getLrcFilePath() const;

    void insertMusicToDB() const;

private:
    void parseMediaMetaMusic();

private:
    // 音乐ID，标识一个歌曲的唯一性
    QString musicID;
    // 音乐名称
    QString musicName;
    // 音乐作者
    QString musicSinger;
    // 音乐专辑
    QString musicAlbum;
    // 持续时间
    qint64 duration;
    // 是否收藏
    bool isLike;
    // 是否历史播放
    bool isHistory;
    // 是否本地音乐
    bool isLocal;
    // 音乐 url
    QUrl musicUrl;
};

#endif // MUSIC_H
