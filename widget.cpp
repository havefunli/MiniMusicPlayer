#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
    initUi();
    initConnect();
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

// move window when move mouse
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        move(event->globalPosition().toPoint() - dragPosition);
    }
    // qDebug() << "Move mouse, dragPosition =" << dragPosition;
    QWidget::mouseMoveEvent(event);
}

// recorded pos when press mouse
void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // 鼠标的全局位置 - 窗口左上角的位置 = 鼠标在窗口的相对位置
        dragPosition = event->globalPosition().toPoint() - geometry().topLeft();
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

