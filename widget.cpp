#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QList>
#include <QDir>
#include <QFileDialog>
#include <QJsonObject>

#include "music.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
    initUi();
    initConnect();

    // TEST
    QUrl url = QUrl::fromLocalFile("C:/Users/acer/Desktop/Project/MiniMusicPlayer/musics/2002年的第一场雪 - 刀郎.mp3");
    Music music(url);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initUi()
{
    // remove frame
    this->setWindowFlag(Qt::FramelessWindowHint);
    // show shadow
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0, 0);
    shadow->setColor("black");
    shadow->setBlurRadius(20);
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

    // 设置声音调节弹窗
    vt = new VolumeTool(this);
}

void Widget::initConnect()
{
    connect(ui->recommend, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->radio, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->music, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->like, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->local, &BtForm::btClick, this, &Widget::onBtFormClick);
    connect(ui->recent, &BtForm::btClick, this, &Widget::onBtFormClick);
}

// 移动窗口
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
    }
    // qDebug() << "Move mouse, dragPosition =" << dragPosition;
    QWidget::mouseMoveEvent(event);
}

// 记录鼠标的位置
void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // 鼠标的全局位置 - 窗口左上角的位置 = 鼠标在窗口的相对位置
        dragPosition = event->globalPos() - geometry().topLeft();
    }
    // qDebug() << "Press mouse, dragPosition =" << dragPosition;
    QWidget::mousePressEvent(event);
}

// close window
void Widget::on_quit_clicked()
{
    this->close();
}

void Widget::onBtFormClick(int pageId)
{
    ui->stackedWidget->setCurrentIndex(pageId);
    // 清除其他按钮颜色
    QList<BtForm*> bts = this->findChildren<BtForm*>();
    for (auto& bt : bts) {
        if (bt->getPageId() != pageId) {
            bt->clearBackground();
        }
    }
    qDebug() << "turn to pageId = " << pageId;
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
    fileDialog->setDirectory(QDir::currentPath());
    // 可选择多个路径
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    // 获取选取的文件
    if (fileDialog->exec() == QFileDialog::Accepted) {
        QList<QUrl> fileUrls = fileDialog->selectedUrls();
        musicList.addMusicByUrls(fileUrls);
    }
}

