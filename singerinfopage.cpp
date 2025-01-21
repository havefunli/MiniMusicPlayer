#include "singerinfopage.h"
#include "listitembox.h"
#include "ui_singerinfopage.h"
#include <QDebug>

SingerInfoPage::SingerInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingerInfoPage)
{
    ui->setupUi(this);
}

SingerInfoPage::~SingerInfoPage()
{
    delete ui;
}

void SingerInfoPage::setSingerName(const QString &singerName)
{
    ui->name->setText(singerName);
}

void SingerInfoPage::setSingerImage(const QByteArray &byteArr)
{
    // 设置图片
    QPixmap pixmap;
    pixmap.loadFromData(byteArr);
    ui->singerImage->setPixmap(pixmap);
    // 调整大小
    ui->singerImage->setScaledContents(true);
}

void SingerInfoPage::setSingerIntroduce(const QString &intruduce)
{
    ui->info->setText(intruduce);
}

void SingerInfoPage::setSingerMusic(const QVector<Music *> musics)
{
    // 清除之前的内容
    ui->pageMusicList->clear();

    for (auto &music : musics) {

        ListItemBox *itemBox = new ListItemBox();
        itemBox->setMusic(music);

        QListWidgetItem *item = new QListWidgetItem(ui->pageMusicList);
        item->setSizeHint(QSize(itemBox->width(), itemBox->height()));
        ui->pageMusicList->setItemWidget(item, itemBox);
    }
}

QString SingerInfoPage::getSingerName()
{
    return ui->name->text();
}

void SingerInfoPage::initPage(const Singer *singer)
{
    setSingerName(singer->getSingerName());
    setSingerImage(singer->getSingerImage());
    setSingerIntroduce(singer->getSingerInfo());
    setSingerMusic(singer->getSingerMusic());
}
