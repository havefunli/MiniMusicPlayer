#ifndef WIDGET_H
#define WIDGET_H

#include "musiclist.h"
#include <QMouseEvent>
#include <QWidget>
#include <QDebug>
#include <volumetool.h>
#include <QJsonArray>
#include <QGraphicsDropShadowEffect>

#include <QMediaPlayer>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
namespace Ui {
class MusicPlayer;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initUi();
    void initConnect();
    void initPlayer();

protected:
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);

private slots:
    void on_quit_clicked();
    // 切换界面
    // 将其他按键颜色清除
    void onBtFormClick(int);
    // 推荐图片音频构造
    QJsonArray randomPiction();

    // 更新喜欢的音乐
    void upDateLikeMusicAndPage(const QString&, const bool);

    void on_volume_clicked();
    void on_addLocal_clicked();

    // 播放相关槽函数
    void onPlayMusic(); // 播放状态
    void onPlayUpClicked();    // 上一首
    void onPlayDownClicked();  // 下一首
    void onPlayBackModeClicked(); // 播放模式

private:
    Ui::MusicPlayer *ui;
    QPoint          dragPosition; // recored mouse pos
    VolumeTool      *vt;          // 声音弹窗
    MusicList       musicList;    // 管理的音乐
    QMediaPlayer    *player;      // 播放器
    QMediaPlaylist  *playList;    // 播放列表
};
#endif // WIDGET_H
