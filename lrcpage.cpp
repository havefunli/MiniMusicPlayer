#include "lrcpage.h"
#include "ui_lrcpage.h"

LrcPage::LrcPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LrcPage)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    ui->hideBtn->setIcon(QIcon(":/images/xiala.png"));

    // 设置动画
    animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(250);
    animation->setStartValue(QRect(10, 10, width(), height()));
    animation->setEndValue(QRect(10, 10 + height(), width(), height()));

    // 下拉窗口动画
    connect(ui->hideBtn, &QPushButton::clicked, this, [=]() {
        animation->start();
    });
    // 下拉动作完成后隐藏窗口
    connect(animation, &QPropertyAnimation::finished, this, [=](){
       this->hide();
    });
}

LrcPage::~LrcPage()
{
    delete ui;
}
