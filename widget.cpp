#include "widget.h"
#include "ui_widget.h"
#include <QMenu>
#include <QDebug>
#include <QList>
#include <QDir>
#include <QFileDialog>
#include <QJsonObject>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QCompleter>
#include <QAbstractItemView>
#include <QJsonDocument>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
    , player(new QMediaPlayer(this))
    , playList(new QMediaPlaylist(this))
    , isDrag(false)
    , trayIcon(new QSystemTrayIcon(this))
    , srv(new ServerConnection(this))
{
    ui->setupUi(this);
    initUi();
    initPageType();
    initSqlite();
    initMusicList();
    initPlayer();
    initConnect();

    // 显示到第一个界面
    ui->stackedWidget->setCurrentIndex(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initUi()
{
    // 设置系统图标
    setWindowIcon(QIcon(":/images/tubiao.png"));

    // 设置系统托盘
    trayIcon->setIcon(QIcon(":/images/trayicon.png"));
    trayIcon->setToolTip("MiniMusic");
    trayIcon->show();
    // 托盘系统菜单
    QMenu *trayMenu = new QMenu();
    trayMenu->addAction("显示", this, &QWidget::showNormal);
    trayMenu->addAction("退出", this, &Widget::onMusicQuit);
    trayIcon->setContextMenu(trayMenu);

    // remove frame
    this->setWindowFlag(Qt::FramelessWindowHint);
    // show shadow
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0, 0);
    shadow->setColor("black");
    shadow->setBlurRadius(10);
    setGraphicsEffect(shadow);

    // 设置图片和文本
    ui->recommend->initBtForm(":/images/rec.png", "推荐", 0);
    ui->radio->initBtForm(":/images/radio.png", "电台", 1);
    ui->music->initBtForm(":/images/music.png", "音乐馆", 2);
    ui->like->initBtForm(":/images/like.png", "我喜欢", 3);
    ui->local->initBtForm(":/images/local.png", "本地下载", 4);
    ui->recent->initBtForm(":/images/recent.png", "最近播放", 5);

    // 初始化推荐图片
    srand(time(NULL));
    ui->recMusicBox->initRecBoxUi(randomPiction(), 1);
    ui->supplyBox->initRecBoxUi(randomPiction(), 2);

    // 设置 CommonPage 的信息
    ui->likePage->setCommonPageUI("我喜欢", ":/images/ilikebg.png");
    ui->localPage->setCommonPageUI("本地音乐", ":/images/localbg.png");
    ui->recentPage->setCommonPageUI("最近播放", ":/images/recentbg.png");

    // 播放工具栏处理
    ui->play->setIcon(QIcon(":images/play_2.png"));
    ui->play->setIconSize(QSize(ui->play->width(), ui->play->height()));

    ui->playMod->setIcon(QIcon(":/images/list_play.png"));
    ui->playMod->setIconSize(QSize(ui->playMod->width(), ui->playMod->height()));

    // 设置声音调节弹窗
    vt = new VolumeTool(this);

    // 设置歌词窗口
    lrc = new LrcPage(this);
    lrc->setGeometry(9, 9, lrc->width(), lrc->height());
    lrc->hide();

    // 设置上传音乐窗口
    loadPage = new UpLoad(this);
    loadPage->setGeometry(292, 50, loadPage->width(), loadPage->height());
    loadPage->hide();

    // 上移动画对象
    lrcAnimation = new QPropertyAnimation(lrc, "geometry", this);
    lrcAnimation->setDuration(250);
    lrcAnimation->setStartValue(QRect(10, 10 + lrc->height(), lrc->width(), lrc->height()));
    lrcAnimation->setEndValue(QRect(10, 10, lrc->width(), lrc->height()));

    ui->todo->setPixmap(QPixmap(":/images/todo.png"));
    ui->todo->setScaledContents(true);

    // 调整 upload 图标
    ui->upLoad->setIcon(QIcon(":/images/upload_1.png"));
}

void Widget::initPageType()
{
    ui->likePage->setMusicListType(PageType::LIKE_PAGE);
    ui->localPage->setMusicListType(PageType::LOCAL_PAGE);
    ui->recentPage->setMusicListType(PageType::HISTORY_PAGE);
}

void Widget::initSqlite()
{
    // 1. 加载数据库驱动
    sqlite = QSqlDatabase::addDatabase("QSQLITE");
    // 2. 设置数据库名称
    sqlite.setDatabaseName("QQMusic.db");
    // 3. 打开
    if (!sqlite.open()) {
        QMessageBox::critical(this, "QQMusic", "数据库打开失败");
        return;
    }
    qDebug() << "数据库打开成功";

    // 4. 建音乐表
    QString sql = "CREATE TABLE IF NOT EXISTS Music(\
                    musicId PRIMARYKEY VARCHAR(50) UNIQUE, \
                    musicName VARCHAR(50), \
                    musicSinger VARCHAR(50), \
                    albumName VARCHAR(50), \
                    musicUrl VARCHAR(50) UNIQUE, \
                    duration BIGINT, \
                    isLike INTEGER, \
                    isHistory INTEGER, \
                    isLocal INTEGER)";
    QSqlQuery query;
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "QQMusic", "音乐数据初始化错误");
        qDebug() << "音乐数据初始化错误:" << query.lastError().text();
        return;
    }
    qDebug() << "创建表 / 读取表成功";
}

void Widget::initMusicList()
{
    musicList.readFromDB();
    ui->likePage->reFresh(musicList);
    ui->recentPage->reFresh(musicList);
    ui->localPage->reFresh(musicList);
    qDebug() << "成功加载音乐数据";
}

void Widget::initConnect()
{
    // 界面切换处理信号
    connect(ui->recommend, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->radio, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->music, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->like, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->local, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->recent, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &Widget::searchClicked);
    connect(ui->music, &BtForm::btClick, this, &Widget::onBtFormClick);

    // 处理喜欢音乐的改变
    connect(ui->localPage, &CommonPage::upDateLikeMusic, this, &Widget::upDateLikeMusicAndPage);
    connect(ui->likePage, &CommonPage::upDateLikeMusic, this, &Widget::upDateLikeMusicAndPage);
    connect(ui->recentPage, &CommonPage::upDateLikeMusic, this, &Widget::upDateLikeMusicAndPage);
    connect(ui->searchPage, &SearchResult::upDateLikeMusic, this, &Widget::upDateLikeMusicAndPage);
    connect(ui->singerInfo, &SingerInfoPage::upDateLikeMusic, this, &Widget::upDateLikeMusicAndPage);

    // 点击显示 Lrc
    connect(ui->lrcWord, &QPushButton::clicked, this, &Widget::onLrcWordClicked);

    // 播放相关槽函数
    // 音乐状态的改变引起按钮的变化
    connect(player, &QMediaPlayer::stateChanged, this, &Widget::onMusicStateChanged);
    // 播放按钮
    connect(ui->play, &QPushButton::clicked, this, &Widget::onPlayMusic);
    // 上一首下一首
    connect(ui->playUp, &QPushButton::clicked, this, &Widget::onPlayUpClicked);
    connect(ui->playDown, &QPushButton::clicked, this, &Widget::onPlayDownClicked);
    // 播放模式
    connect(ui->playMod, &QPushButton::clicked, this, &Widget::onPlayBackModeClicked);
    // 播放全部
    connect(ui->likePage, &CommonPage::playAll, this, &Widget::onPlayAll);
    connect(ui->localPage, &CommonPage::playAll, this, &Widget::onPlayAll);
    connect(ui->recentPage, &CommonPage::playAll, this, &Widget::onPlayAll);
    connect(ui->searchPage, &SearchResult::playAll, this, &Widget::onPlayAllSearch);
    connect(ui->singerInfo, &SingerInfoPage::playAll, this, &Widget::onPlayAllSinger);
    // 双击处理
    connect(ui->likePage, &CommonPage::playMusicByIndex, this, &Widget::playMusicByIndex);
    connect(ui->localPage, &CommonPage::playMusicByIndex, this, &Widget::playMusicByIndex);
    connect(ui->recentPage, &CommonPage::playMusicByIndex, this, &Widget::playMusicByIndex);
    connect(ui->searchPage, &SearchResult::playMusicByIndex, this, &Widget::playOnlineMusicByIndex);
    connect(ui->singerInfo, &SingerInfoPage::playMusicByIndex, this, &Widget::playSingerMusicByIndex);
    // 记录历史播放
    connect(player, &QMediaPlayer::currentMediaChanged, this, &Widget::recordHistory);
    // 处理静音
    connect(vt, &VolumeTool::setMusicMuted, this, &Widget::setPlayerMuted);
    // 处理音量修改
    connect(vt, &VolumeTool::setMusicVolume, this, &Widget::setPlayerVolume);
    // 音乐切换
    connect(player, &QMediaPlayer::durationChanged, this, &Widget::onDurationChanged);
    // 播放进度改变
    connect(player, &QMediaPlayer::positionChanged, this, &Widget::onPositionChanged);
    // 进度条变化
    connect(ui->progressBar, &MusicSlider::setMusicSliderPosition, this, &Widget::onMusicSliderPosChanged);
    // 播放音乐切换
    connect(player, &QMediaPlayer::currentMediaChanged, this, &Widget::onMediaChanged);

    // 处理系统托盘点击事件
    connect(trayIcon, &QSystemTrayIcon::activated, this, [=](QSystemTrayIcon::ActivationReason reason){
        if (reason == QSystemTrayIcon::Trigger) {
            this->show();
        }
    });

    // 随机播放一个音乐
    connect(ui->recMusicBox, &RecBox::getRandomMusic, this, &Widget::getRandomMusicFromSrv);
    connect(ui->supplyBox, &RecBox::getRandomMusic, this, &Widget::getRandomMusicFromSrv);
    // 上传音乐到服务端
    connect(loadPage, &UpLoad::submitMusic, this, &Widget::onSubmitMusicToHost);
    // 获取歌词文件
    connect(lrc, &LrcPage::sendLrcRequest, this, &Widget::recvAndParseLrc);
    // 搜索音乐信息
    connect(ui->searchPage, &SearchResult::searchMusic, this, &Widget::onSearchMusic);

    // 人物图片就绪
    connect(srv, &ServerConnection::singerImageReady, this, [=](QVector<Singer*> singers){
        ui->singerPage->initPage(singers);
    });
    // 点击具体的歌手
    connect(ui->singerPage, &SingerPage::singerClicked, this, &Widget::onSingerClicked);
}

void Widget::initPlayer()
{
    // 1. 设置播放模式
    playList->setPlaybackMode(QMediaPlaylist::Loop);
    // 2. 设置播放列表
    player->setPlaylist(playList);
    // 3. 设置初始音量
    player->setVolume(20);
}

void Widget::playAllMusicOfCommonPage(CommonPage *page, int index)
{
    // 清空 playlist 歌曲
    playList->clear();
    // 添加当前页音乐
    page->addMusicToPlaylist(musicList, playList);
    // 从 index 开始播放, 设置播放模式
    playList->setCurrentIndex(index);
    playList->setPlaybackMode(QMediaPlaylist::Loop);

    player->play();
}

void Widget::playAllMusicOfSearchPage(SearchResult *page, int index)
{
    // 清空 playlist 歌曲
    playList->clear();

    // qDebug() << "我要添加当前页音乐了哦";
    // 添加当前页音乐
    page->addMusicToPlaylist(playList);
    // 从 index 开始播放, 设置播放模式
    playList->setCurrentIndex(index);
    playList->setPlaybackMode(QMediaPlaylist::Loop);

    player->play();
}

void Widget::playAllMusicOfSingerPage(SingerInfoPage *page, int index)
{
    // 清空 playlist 歌曲
    playList->clear();

    // 添加当前页音乐
    page->addMusicToPlaylist(playList);
    // 从 index 开始播放, 设置播放模式
    playList->setCurrentIndex(index);
    playList->setPlaybackMode(QMediaPlaylist::Loop);

    player->play();
}

void Widget::recordHistory(const QMediaContent &content)
{
    if (content.isNull()) {
        return;
    }
    // 媒体内容中包含多个资源，需要我们处理
    // 重定向前，重定向后
    QUrl url = content.request().url();
    Music *music = musicList.findMUsicByQUrl(url);
    if (music) {
        music->setHistory(true);
        ui->recentPage->reFresh(musicList);
    } else {
        qDebug() << "Widget::recordHistory";
    }
}

// 移动窗口
// 点击按钮时如果存在移动动作，会移动窗口 BUG
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (isDrag && event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
    }
    // qDebug() << "Move mouse, dragPosition =" << dragPosition;
    QWidget::mouseMoveEvent(event);
}

// 记录鼠标的位置
void Widget::mousePressEvent(QMouseEvent *event)
{
    isDrag = true;
    if (event->button() == Qt::LeftButton)
    {
        // 鼠标的全局位置 - 窗口左上角的位置 = 鼠标在窗口的相对位置
        dragPosition = event->globalPos() - geometry().topLeft();
    }
    // qDebug() << "Press mouse, dragPosition =" << dragPosition;
    QWidget::mousePressEvent(event);
}

// 最小化窗口
void Widget::on_quit_clicked()
{
    this->hide();
}

void Widget::onBtFormClick(int pageId)
{
    isDrag = false;
    ui->stackedWidget->setCurrentIndex(pageId);
    // 清除其他按钮颜色
    QList<BtForm*> bts = this->findChildren<BtForm*>();
    for (auto& bt : bts) {
        if (bt->getPageId() != pageId) {
            bt->clearBackground();
        }
    }

    // 某些页面的指定处理
    if (pageId == 1) {
        QMessageBox::information(nullptr, "信息", "抱歉，该功能程序猿还在开发中");
    } else if (pageId == 2) {
        srv->getSingerNameAndInfo();
        connect(srv, &ServerConnection::singerNameReady, this, [=](QVector<Singer*> singers){
            // qDebug() << "数据返回成功，初始化界面";
            this->singers.addSingers(singers);
            srv->getSingerImage(singers);
        });
    }
}

void Widget::searchClicked()
{
    // 切换到该页 / 传入关键词
    ui->stackedWidget->setCurrentIndex(6);
    ui->searchPage->setKeyWords(ui->lineEdit->text());
    // 去除搜索框的词
    ui->lineEdit->clear();
}

void Widget::getRandomMusicFromSrv()
{
    srv->getRandomMusic();
    // 音乐就绪
    connect(srv, &ServerConnection::randomMusicReady, this, [=](const Music music){
        // 加入到音乐管理数组(自动查重)
        musicList.addMusic(music);
        this->playList->clear();
        playList->addMedia(music.getMusicQUrl());
        player->play();
    });
}

QJsonArray Widget::randomPiction()
{
    // 获取文件名
    QVector<QString> vecImageName;
    foreach (const QString& imageName, QDir(":/images/rec").entryList()) {
        vecImageName << imageName;
    }
    // 打乱顺序
    std::random_shuffle(vecImageName.begin(), vecImageName.end());

    QJsonArray  objArray;
    for (int i = 0; i < vecImageName.size(); i++) {
        QJsonObject obj;
        obj.insert("path", ":/images/rec/" + vecImageName[i]);

        QString text = QString("推荐-%1").arg(i, 3, 10, QChar('0'));
        obj.insert("text", text);

        objArray.push_back(obj);
    }
    return objArray;
}

void Widget::upDateLikeMusicAndPage(const QString &musicID, const bool isLike)
{
    Music *music = musicList.findMusicById(musicID);
    if (music == nullptr) {
        return;
    }
    music->setLike(isLike);
    ui->likePage->reFresh(musicList);
    ui->recentPage->reFresh(musicList);
    ui->localPage->reFresh(musicList);
}

void Widget::on_volume_clicked()
{
    // 1. 获取全局坐标
    QPoint gPoint = ui->volume->mapToGlobal(QPoint(0, 0));
    // 2. 计算音量控件位置
    QPoint volPoint = gPoint - QPoint(vt->width() / 3, vt->height());
    // 3. 设置位置
    vt->move(volPoint);
    vt->show();
}


void Widget::on_addLocal_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);

    // 设置标题
    fileDialog->setWindowTitle("添加本地音乐");
    // 设置默认目录
    fileDialog->setDirectory("C:\\Users\acer\\Desktop\\Project\\MiniMusicPlayer\\musics");
    // 可选择多个文件
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    // 获取选取的文件
    if (fileDialog->exec() == QFileDialog::Accepted) {
        QList<QUrl> fileUrls = fileDialog->selectedUrls();
        // 将选中的文件内容解析为 Music 对象，交由 musicList 管理
        musicList.addMusicByUrls(fileUrls);
        // 将窗口切换为本地下载
        ui->stackedWidget->setCurrentIndex(4);
        // 刷新音乐显示
        ui->localPage->reFresh(musicList);
        // 将本地音乐添加到播放列表z
        ui->localPage->addMusicToPlaylist(musicList, playList);
    }
}

void Widget::onLrcWordClicked()
{
    lrc->show();
    lrcAnimation->start();
}


// 播放和暂停
// 切换音乐播放状态和音乐图标
void Widget::onPlayMusic()
{
    if (QMediaPlayer::PlayingState == player->state()) {
        player->pause();
        ui->play->setIcon(QIcon(":/images/play3.png"));
    } else if(QMediaPlayer::PausedState == player->state()) {
        player->play();
        ui->play->setIcon(QIcon(":/images/play_on.png"));
    } else if(QMediaPlayer::StoppedState == player->state()) {
        player->play();
        ui->play->setIcon(QIcon(":/images/play_on.png"));
    } else {
        qDebug() << player->errorString();
        ui->play->setIcon(QIcon(":/images/play3.png"));
    }
    ui->play->setIconSize(QSize(ui->play->width(), ui->play->height()));
}

void Widget:: onPlayUpClicked()
{
    playList->previous();
}

void Widget::onPlayDownClicked()
{
    playList->next();
}

void Widget::onPlayBackModeClicked()
{
    // 循环 随机 单曲 三者循环
    if (playList->playbackMode() == QMediaPlaylist::Loop) {
        playList->setPlaybackMode(QMediaPlaylist::Random);
        ui->playMod->setIcon(QIcon(":/images/shuffle_2.png"));
    } else if (playList->playbackMode() == QMediaPlaylist::Random) {
        playList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        ui->playMod->setIcon(QIcon(":/images/single_play.png"));
    } else if (playList->playbackMode() == QMediaPlaylist::CurrentItemOnce) {
        playList->setPlaybackMode(QMediaPlaylist::Loop);
        ui->playMod->setIcon(QIcon(":/images/list_play.png"));
    } else {
        qDebug() << "Mode error";
    }
}

void Widget::onPlayAll(PageType pageType)
{
    CommonPage *page = nullptr;
    // 判断是哪一个界面
    switch(pageType) {
        case PageType::LIKE_PAGE:
            page = ui->likePage;
            break;
        case PageType::LOCAL_PAGE:
            page = ui->localPage;
            break;
        case PageType::HISTORY_PAGE:
            page = ui->recentPage;
            break;
        default:
            qDebug() << "页面不支持";
    }
    playAllMusicOfCommonPage(page, 0);
}

void Widget::onMusicStateChanged(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::State::PlayingState) {
        ui->play->setIcon(QIcon(":/images/play_on.png"));
    } else if (state == QMediaPlayer::State::PausedState
               || state == QMediaPlayer::State::StoppedState) {
        ui->play->setIcon(QIcon(":/images/play3.png"));
    }
    ui->play->setIconSize(QSize(ui->play->width(), ui->play->height()));
}

void Widget::playMusicByIndex(CommonPage *page, int index)
{
    playAllMusicOfCommonPage(page, index);
}

void Widget::playOnlineMusicByIndex(SearchResult *page, int index)
{
    // qDebug() << "playOnlineMusicByIndex";
    playAllMusicOfSearchPage(page, index);
}

void Widget::playSingerMusicByIndex(SingerInfoPage *page, int index)
{
    playAllMusicOfSingerPage(page, index);
}

void Widget::setPlayerMuted(bool isMuted)
{
    player->setMuted(isMuted);
}

void Widget::setPlayerVolume(int volume)
{
    player->setVolume(volume);
}

void Widget::onDurationChanged(qint64 duration)
{
    // 获取分秒
    int min = duration / 1000 / 60;
    int sec = duration / 1000 % 60;
    // 更新界面
    ui->totalTime->setText(QString("%1:%2").arg(min, 2, 10, QChar('0'))
                           .arg(sec, 2, 10, QChar('0')));
}

void Widget::onPositionChanged(qint64 duration)
{
    // 获取分秒
    int min = duration / 1000 / 60;
    int sec = duration / 1000 % 60;
    // 更新界面
    ui->currentTime->setText(QString("%1:%2").arg(min, 2, 10, QChar('0'))
                             .arg(sec, 2, 10, QChar('0')));
    // 更新进度条的位置
    ui->progressBar->setPos(duration / (float)player->duration());
    // 更新歌词
    lrc->showLrcWordLine(duration);
}

void Widget::onMusicSliderPosChanged(float ratio)
{
    // 获取当前进度
    qint64 pos = player->duration() * ratio;
    // 设置播放位置
    player->setPosition(pos);
}

void Widget::onMediaChanged(const QMediaContent &content)
{
    Music *music = nullptr;
    QString musicName = "未知音乐";
    QString musicSinger = "未知歌手";

    // 获取音乐信息
    if (!content.isNull()) {
        // 不止一个返回
        QUrl url = content.request().url();
        music = musicList.findMUsicByQUrl(url);
        if (music != nullptr) {
            // 改变音乐状态
            music->setHistory(true);
            musicName = music->getMusicName();
            musicSinger = music->getMusicSinger();
        }
    }

    // 设置播放栏文本
    ui->musicName->setText(musicName);
    ui->singerName->setText(musicSinger);
    // 设置 lrc 界面文本
    lrc->setMusicName(musicName);
    lrc->setMusicSinger(musicSinger);

    // 获取封面图 / 异步加载
    connect(player, &QMediaPlayer::metaDataAvailableChanged, this, [=](){
        QVariant coverImage = player->metaData("ThumbnailImage");
        if (coverImage.isValid()) {
            QImage image = coverImage.value<QImage>();
            ui->picture->setPixmap(QPixmap::fromImage(image));
        } else {
            // qDebug() << content.request().url() << " 封面图片不存在";
            QString path = ":/images/rec/001.png";
            ui->picture->setPixmap(QPixmap(path));
        }
        ui->picture->setScaledContents(true);
    });

    // 获取 lrc 歌词
    if (music != nullptr) {
        QString lrcPath = music->getLrcFilePath();
        lrc->getLrcAndParse(lrcPath, music->getLocal());
    }
}


void Widget::on_min_clicked()
{
    showMinimized();
}

void Widget::on_max_clicked()
{
    QMessageBox::information(this, "QQMusic", "该功能程序猿正在修补BUG……");
}

// 退出程序
// 还需要保存音乐信息
// 断开数据库连接
void Widget::onMusicQuit()
{
    musicList.writeToDB();

    sqlite.close();
    qDebug() << "成功断开数据库连接";

    this->close();
}

void Widget::on_upLoad_clicked()
{
    loadPage->show();
}

void Widget::onSubmitMusicToHost(const UpLoad::UpLoadInfo info)
{
    srv->SendMusicToHost(info);
}

void Widget::recvAndParseLrc(const QUrl &url, const ParseFunc task)
{
    srv->rcvLrcFromHost(url);
    connect(srv, &ServerConnection::lrcReady, this, [=](QString content){
        task(content);
    });
}

void Widget::onSearchMusic(const QString &musicName)
{
    srv->searchMusic(musicName);
    connect(srv, &ServerConnection::searchResultReady, this, &Widget::onSearchReady);
}

void Widget::onSearchReady(QVector<Music> musicVec)
{
    QVector<Music*> musics;
    for (auto &music : musicVec) {
        // 自动查重更新
        musicList.addMusic(music);
        musics.append(musicList.findMUsicByQUrl(music.getMusicQUrl()));
    }
    ui->searchPage->initSearchPage(musics);
}

void Widget::onPlayAllSearch()
{
    playAllMusicOfSearchPage(ui->searchPage, 0);
}

void Widget::onPlayAllSinger()
{
    playAllMusicOfSingerPage(ui->singerInfo, 0);
}

void Widget::onSingerClicked(const QString singerName)
{
    Singer *target_singer = singers.findSinger(singerName);

    if (target_singer == nullptr) {
        QMessageBox::warning(nullptr, "出错", "歌手信息不存在");
        return;
    }

    // 先预先设置该界面时是属于哪一个歌手，方便后续获取
    ui->singerInfo->setSingerName(singerName);
    // 获取该歌手的音乐
    srv->getSingerMusic(target_singer->getSingerName());
    connect(srv, &ServerConnection::singerMusicReady, this, &Widget::onSingerMusicReady);
}

void Widget::onSingerMusicReady(QVector<Music> musics)
{
    Singer *target_singer = singers.findSinger(ui->singerInfo->getSingerName());
    if (target_singer == nullptr) {
        QMessageBox::warning(nullptr, "错误", "你的歌手信息不存在");
        return;
    }

    qDebug() << "歌手：" << target_singer->getSingerName() << ", 一共有歌曲：" << musics.size();
    for (auto &music : musics) {
        musicList.addMusic(music);
        target_singer->addMusic(musicList.findMUsicByQUrl(music.getMusicQUrl()));
    }

    ui->singerInfo->initPage(target_singer);
    ui->stackedWidget->setCurrentIndex(7);
}

