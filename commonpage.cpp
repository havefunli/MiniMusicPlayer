#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"
#include <QDebug>

CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
    ui->pageMusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

CommonPage::~CommonPage()
{
    delete ui;
}

void CommonPage::setCommonPageUI(const QString &text, const QString &path)
{
    ui->pageTitle->setText(text);

    ui->musicImage->setPixmap(QPixmap(path));
    ui->musicImage->setScaledContents(true);
}

void CommonPage::setMusicListType(PageType type)
{
    this->type = type;
}

void CommonPage::addMusicToMusicPage(MusicList &musicList)
{
    // 清除原来数组存储 的内容，避免重复
    musicOfPage.clear();
    for (size_t i = 0; i < musicList.size(); i++) {
        Music music = musicList[i];

        switch(type)
        {
            case LIKE_PAGE:
                if (music.getLike()) {
                    musicOfPage.push_back(music.getMusicId());
                }
                break;
            case LOCAL_PAGE:
                musicOfPage.push_back(music.getMusicId());
                break;
            case HISTORY_PAGE:
                if (music.getHistory()) {
                    musicOfPage.push_back(music.getMusicId());
                }
            break;
        }
    }
}

void CommonPage::reFresh(MusicList &musicList)
{
     // 清除原来界面的内容
     ui->pageMusicList->clear();

     addMusicToMusicPage(musicList);

     for (auto &musicId : musicOfPage) {
         Music *music = musicList.findMusicById(musicId);
         if (music == nullptr) {
             qDebug() << "音乐不存在";
             continue;
         }

         // 显示到界面
         // 将 ListBoxItem 对象放置到其中
         ListItemBox *itemBox = new ListItemBox(this);
         // 设置字段
         itemBox->setMusicName(music->getMusicName());
         itemBox->setMusicSinger(music->getMusicSinger());
         itemBox->setMusicAlbum(music->getMusicAlbum());
         itemBox->setLikeMusic(music->getLike());

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

void CommonPage::addMusicToPlaylist(MusicList &musicList, QMediaPlaylist *playList)
{
    for (size_t i = 0; i < musicList.size(); i++) {
        Music music = musicList[i];

        switch(type)
        {
            case LIKE_PAGE:
                if (music.getLike()) {
                    playList->addMedia(music.getMusicQUrl());
                }
                break;
            case LOCAL_PAGE:
                playList->addMedia(music.getMusicQUrl());
                break;
            case HISTORY_PAGE:
                if (music.getHistory()) {
                    playList->addMedia(music.getMusicQUrl());
                }
            break;
        }
    }
}
