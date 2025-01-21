#include "singer.h"
#include "ui_singer.h"

Singer::Singer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Singer)
{
    ui->setupUi(this);
}

Singer::~Singer()
{
    delete ui;
}

QString Singer::getSingerName() const
{
    return singerName;
}

void Singer::setSingerName(const QString &value)
{
    singerName = value;
}

QString Singer::getSingerInfo() const
{
    return singerInfo;
}

void Singer::setSingerInfo(const QString &value)
{
    singerInfo = value;
}

QByteArray Singer::getSingerImage() const
{
    return singerImage;
}

void Singer::setSingerImage(const QByteArray &value)
{
    singerImage = value;
}

QVector<Music *> Singer::getSingerMusic() const
{
    return musics;
}

void Singer::addMusic(Music *music)
{
    if (!IsExists(music)){
        musics.append(music);
    }
}

bool Singer::IsExists(Music *target_music)
{
    for (auto &music : musics) {
        if (music == target_music) {
            return true;
        }
    }
    return false;
}

void SingerList::addSinger(Singer *singer)
{
    singers.append(singer);
}

void SingerList::addSingers(QVector<Singer *> singers)
{
    for (auto &singer : singers) {
        addSinger(singer);
    }
}

Singer *SingerList::findSinger(const QString &singerName)
{
    for (auto &singer : singers) {
        if (singer->getSingerName() == singerName) {
            return singer;
        }
    }
    return nullptr;
}
