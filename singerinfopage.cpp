#include "singerinfopage.h"
#include "listitembox.h"
#include "ui_singerinfopage.h"
#include <QDebug>

SingerInfoPage::SingerInfoPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingerInfoPage)
{
    ui->setupUi(this);

    // 鼠标双击信号槽
    connect(ui->pageMusicList, &QListWidget::doubleClicked, this, [=](const QModelIndex &index){
        emit playMusicByIndex(this, index.row());
    });
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

    // 保存播放使用
    this->musics = musics;

    for (auto &music : musics) {

        ListItemBox *itemBox = new ListItemBox();
        itemBox->setMusic(music);

        QListWidgetItem *item = new QListWidgetItem(ui->pageMusicList);
        item->setSizeHint(QSize(itemBox->width(), itemBox->height()));
        ui->pageMusicList->setItemWidget(item, itemBox);

        // 拦截处理 like 状态改变的信号
        connect(itemBox, &ListItemBox::likeStatusChanged, this, [=](bool isLike){
            // 更新界面 and 音乐状态
            emit upDateLikeMusic(music->getMusicId(), isLike);
        });
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

void SingerInfoPage::addMusicToPlaylist(QMediaPlaylist *playList)
{
    for (auto &music : musics) {
        if (music != nullptr) {
            playList->addMedia(music->getMusicQUrl());
        }
    }
}

void SingerInfoPage::on_playBtn_clicked()
{
    emit playAll();
}
