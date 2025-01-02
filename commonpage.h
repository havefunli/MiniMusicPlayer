#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include <QMediaPlaylist>
#include "musiclist.h"

namespace Ui {
class CommonPage;
}

enum PageType
{
    LIKE_PAGE,      // 喜欢
    LOCAL_PAGE,     // 本地
    HISTORY_PAGE    // 历史播放
};

class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    ~CommonPage();

    // 设置文本和图片
    void setCommonPageUI(const QString&, const QString&);
    void setMusicListType(PageType);
    void addMusicToMusicPage(MusicList&);
    // 更新音乐到界面
    void reFresh(MusicList &musicList);
    // 更新音乐到播放列表
    void addMusicToPlaylist(MusicList&, QMediaPlaylist*);

signals:
    void upDateLikeMusic(const QString&, const bool);

private:
    Ui::CommonPage *ui;
    PageType type;
    QVector<QString> musicOfPage;
};

#endif // COMMONPAGE_H
