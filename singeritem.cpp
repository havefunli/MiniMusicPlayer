#include "singeritem.h"
#include "ui_singeritem.h"

SingerItem::SingerItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingerItem)
{
    ui->setupUi(this);
}

SingerItem::~SingerItem()
{
    delete ui;
}

void SingerItem::setSingerName(const QString &name)
{
    ui->singerName->setText(name);
}

void SingerItem::setSingerImage(const QByteArray &byteArr)
{
    // 设置图片
    QPixmap pixmap;
    pixmap.loadFromData(byteArr);
    ui->singerImage->setPixmap(pixmap);
    // 调整大小
    ui->singerImage->setScaledContents(true);
}
