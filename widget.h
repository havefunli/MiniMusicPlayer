#ifndef WIDGET_H
#define WIDGET_H

#include "musiclist.h"
#include "commonpage.h"
#include "upload.h"
#include "lrcpage.h"
#include <QMouseEvent>
#include <QWidget>
#include <QDebug>
#include <volumetool.h>
#include <QJsonArray>
#include <QGraphicsDropShadowEffect>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QPropertyAnimation>
#include <QtSql/QSqlDatabase>
#include <QSystemTrayIcon>
#include <QNetworkReply>
#include <QNetworkAccessManager>

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

    void connectToHost();
    void initUi();
    void initPageType();
    void initSqlite();
    void initMusicLiset();
    void initConnect();
    void initPlayer();

private:
    void playAllMusicOfCommonPage(CommonPage*, int);
    void recordHistory(const QMediaContent&);

protected:
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);

private slots:
    void on_quit_clicked();
    // 切换界面
    // 将其他按键颜色清除
    void onBtFormClick(int);

    // 搜索界面切换
    void searchClicked();

    // 向服务器申请一个随机音乐
    void getRandomMusicFromSrv();

    // 推荐图片音频构造
    QJsonArray randomPiction();

    // 更新喜欢的音乐
    void upDateLikeMusicAndPage(const QString&, const bool);

    void on_volume_clicked();
    void on_addLocal_clicked();

    // Lrc 界面点击显示
    void onLrcWordClicked();

    // 播放相关槽函数
    void onPlayMusic(); // 播放状态
    void onPlayUpClicked();    // 上一首
    void onPlayDownClicked();  // 下一首
    void onPlayBackModeClicked(); // 播放模式
    void onPlayAll(PageType);    // 播放全部
    void onMusicStateChanged(QMediaPlayer::State);
    void playMusicByIndex(CommonPage*, int); // 点击播放全部，双击音乐

    void setPlayerMuted(bool); // 设置静音
    void setPlayerVolume(int); // 设置音量

    void onDurationChanged(qint64); // 播放音乐切换
    void onPositionChanged(qint64); // 播放进度变化

    void onMusicSliderPosChanged(float); // 进度条变化

    void onMediaChanged(const QMediaContent &); // 播放音乐切换

    void on_min_clicked();
    void on_max_clicked();
    void onMusicQuit();

    void on_upLoad_clicked();

    void onSubmitMusicToHost(const QUrl, const QUrl); // 上传音乐到服务端

private:
    Ui::MusicPlayer *ui;
    QPoint          dragPosition; // recored mouse pos
    VolumeTool      *vt;          // 声音弹窗
    LrcPage         *lrc;         // 歌词窗口
    MusicList       musicList;    // 管理的音乐
    QMediaPlayer    *player;      // 播放器
    QMediaPlaylist  *playList;    // 播放列表
    QSqlDatabase    sqlite;      // 保存音乐信息
    bool isDrag;  // 修复点击 BtForm 屏幕乱窜的Bug
    QPropertyAnimation *lrcAnimation; // 窗口上移动画
    QSystemTrayIcon *trayIcon;        // 系统托盘
    UpLoad *loadPage; // 上传界面
    QNetworkAccessManager *networkManager;
};
#endif // WIDGET_H
