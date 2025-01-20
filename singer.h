#ifndef SINGER_H
#define SINGER_H

#include <QWidget>
#include "music.h"

namespace Ui {
class Singer;
}

class Singer : public QWidget
{
    Q_OBJECT

public:
    explicit Singer(QWidget *parent = nullptr);
    ~Singer();

    QString getSingerName() const;
    void setSingerName(const QString &value);

    QString getSingerInfo() const;
    void setSingerInfo(const QString &value);

    QByteArray getSingerImage() const;
    void setSingerImage(const QByteArray &value);

private:
    Ui::Singer *ui;
    QString singerName;
    QString singerInfo;
    QByteArray singerImage;
    QVector<Music*> musics;
};

#endif // SINGER_H
