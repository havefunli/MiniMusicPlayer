#ifndef SINGERINFOPAGE_H
#define SINGERINFOPAGE_H
#include "singer.h"
#include <QWidget>
#include <QMediaPlaylist>

namespace Ui {
class SingerInfoPage;
}

class SingerInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit SingerInfoPage(QWidget *parent = nullptr);
    ~SingerInfoPage();

    void setSingerName(const QString&);
    void setSingerImage(const QByteArray&);
    void setSingerIntroduce(const QString&);
    void setSingerMusic(const QVector<Music*>);
    QString getSingerName();

    void initPage(const Singer*);

    void addMusicToPlaylist(QMediaPlaylist*);

signals:
    void upDateLikeMusic(const QString&, const bool);
    void playMusicByIndex(SingerInfoPage*, int);
    void playAll();

private slots:
    void on_playBtn_clicked();

private:
    Ui::SingerInfoPage *ui;
    QVector<Music*> musics;
};

#endif // SINGERINFOPAGE_H
