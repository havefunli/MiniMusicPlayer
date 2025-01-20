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
