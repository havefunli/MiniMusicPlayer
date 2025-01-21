#include "listitembox.h"
#include "ui_listitembox.h"
#include <QDebug>

ListItemBox::ListItemBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListItemBox)
    , isLike(false)
{
    ui->setupUi(this);
}

ListItemBox::~ListItemBox()
{
    delete ui;
}

void ListItemBox::setMusicName(const QString &name)
{
    ui->nameLabel->setText(name);
}

void ListItemBox::setMusicSinger(const QString &singer)
{
    ui->singerName->setText(singer);
}

void ListItemBox::setMusicAlbum(const QString &album)
{
    ui->albumName->setText(album);
}

void ListItemBox::setLikeMusic(bool islike)
{
    this->isLike = islike;
    if (isLike) {
        ui->likeBtn->setIcon(QIcon(":/images/like_2.png"));
    } else {
        ui->likeBtn->setIcon(QIcon(":/images/like_3.png"));
    }
}

void ListItemBox::setMusic(const Music *music)
{
    setMusicName(music->getMusicName());
    setMusicAlbum(music->getMusicAlbum());
    setMusicSinger(music->getMusicSinger());
    setLikeMusic(music->getLike());
}

void ListItemBox::on_likeBtn_clicked()
{
    qDebug() << "喜欢按钮点击了，原来是 " << this->isLike;
    // this->isLike = !this->isLike; BUG
    this->isLike = isLike ? false : true;
    qDebug() << "现在是 " << this->isLike;
    setLikeMusic(isLike);

    // 通知 like 状态改变
    emit  likeStatusChanged(isLike);
}
