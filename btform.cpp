#include "btform.h"
#include "ui_btform.h"
#include <QMouseEvent>

BtForm::BtForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BtForm)
{
    ui->setupUi(this);

    // line1 动画
    line1Animal = new QPropertyAnimation(ui->line1, "geometry", this);
    line1Animal->setDuration(1000);
    line1Animal->setKeyValueAt(0, QRect(0, 20, 2, 0));
    line1Animal->setKeyValueAt(0.5, QRect(0, 0, 2, 20));
    line1Animal->setKeyValueAt(1, QRect(0, 20, 2, 0));
    line1Animal->setLoopCount(-1);
    line1Animal->start();

    // line2 动画
    line2Animal = new QPropertyAnimation(ui->line2, "geometry", this);
    line2Animal->setDuration(1400);
    line2Animal->setKeyValueAt(0, QRect(7, 20, 2, 0));
    line2Animal->setKeyValueAt(0.5, QRect(7, 0, 2, 20));
    line2Animal->setKeyValueAt(1, QRect(7, 20, 2, 0));
    line2Animal->setLoopCount(-1);
    line2Animal->start();

    // line3 动画
    line3Animal = new QPropertyAnimation(ui->line3, "geometry", this);
    line3Animal->setDuration(1800);
    line3Animal->setKeyValueAt(0, QRect(14, 20, 2, 0));
    line3Animal->setKeyValueAt(0.5, QRect(14, 0, 2, 20));
    line3Animal->setKeyValueAt(1, QRect(14, 20, 2, 0));
    line3Animal->setLoopCount(-1);
    line3Animal->start();

    // line4 动画
    line4Animal = new QPropertyAnimation(ui->line4, "geometry", this);
    line4Animal->setDuration(2200);
    line4Animal->setKeyValueAt(0, QRect(20, 20, 2, 0));
    line4Animal->setKeyValueAt(0.5, QRect(20, 0, 2, 20));
    line4Animal->setKeyValueAt(1, QRect(20 , 20, 2, 0));
    line4Animal->setLoopCount(-1);
    line4Animal->start();
}

BtForm::~BtForm()
{
    delete ui;
}

void BtForm::initBtForm(const QString &btIcon, const QString &btText, int pageId)
{
    ui->btIcon->setPixmap(btIcon);
    ui->btText->setText(btText);
    this->pageId = pageId;
}

int BtForm::getPageId()
{
    return pageId;
}

void BtForm::clearBackground()
{
    ui->btStyle->setStyleSheet("#btStyle:hover{background-color:#f0f0f0;}");
}

void BtForm::mousePressEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton) {
        return;
    }
    // 1. 切换颜色
    ui->btStyle->setStyleSheet("#btStyle{background-color:rgb(30, 206, 154);border: none;border-radius: 12px;}");
    // 2. 切换界面
    emit btClick(this->pageId);
}
