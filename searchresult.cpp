#include "listitembox.h"
#include "searchresult.h"
#include "ui_searchresult.h"

SearchResult::SearchResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchResult)
{
    ui->setupUi(this);

    ui->play->setIcon(QIcon(":/images/play3.png"));
    // 鼠标双击信号槽
    connect(ui->musicList, &QListWidget::doubleClicked, this, [=](const QModelIndex &index){

        for (auto &music : musicsPtr) {
            qDebug() << music->getMusicQUrl() ;
        }

        emit playMusicByIndex(this, index.row());
    });
}

SearchResult::~SearchResult()
{
    delete ui;
}

void SearchResult::setKeyWords(const QString &words)
{
    keyWords = words;
    ui->keywords->setText(keyWords);

    emit searchMusic(words);
}

void SearchResult::initSearchPage(QVector<Music*> &musics)
{
    // 刷新之前的搜索结果
    ui->musicList->clear();
    musicsPtr = musics;

    ui->hint->setText(QString("相关搜索如下, 找到 %1 首单曲").arg(musicsPtr.size(), 2, 10));
    if (musicsPtr.empty()) {
        return;
    }

    for (auto &music : musicsPtr) {
        if (music == nullptr) {
            continue;
        }

        ListItemBox *itemBox = new ListItemBox(this);
        // 设置详细信息
        itemBox->setMusic(music);

        QListWidgetItem *item = new QListWidgetItem(ui->musicList);
        item->setSizeHint(QSize(itemBox->width(), itemBox->height()));
        ui->musicList->setItemWidget(item, itemBox);

        // 拦截处理 like 状态改变的信号
        connect(itemBox, &ListItemBox::likeStatusChanged, this, [=](bool isLike){
            // 更新界面 and 音乐状态
            emit upDateLikeMusic(music->getMusicId(), isLike);
        });

    }
}

void SearchResult::addMusicToPlaylist(QMediaPlaylist *playList)
{
    playList->clear();
    for (auto &music : musicsPtr) {
        qDebug() << music->getMusicQUrl();
        playList->addMedia(music->getMusicQUrl());
    }
}

