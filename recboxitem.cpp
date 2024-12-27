#include "recboxitem.h"
#include "ui_recboxitem.h"
#include <QPropertyAnimation>

RecBoxItem::RecBoxItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecBoxItem)
{
    ui->setupUi(this);
}

RecBoxItem::~RecBoxItem()
{
    delete ui;
}

void RecBoxItem::setRecText(const QString &text)
{
    ui->recBoxItemText->setText(text);
}

void RecBoxItem::setRecImage(const QString &path)
{
    ui->recMusicImage->setPixmap(QPixmap(path));
    ui->recMusicImage->setScaledContents(true);
}

void RecBoxItem::enterEvent(QEnterEvent *event)
{
    // qDebug() << "你的鼠标进入了";
    // 动画效果
    QPropertyAnimation *animal = new QPropertyAnimation(ui->imageBox, "geometry");
    animal->setDuration(100);
    animal->setStartValue(QRect(ui->imageBox->x(), 6, ui->imageBox->width(), ui->imageBox->height()));
    animal->setEndValue(QRect(ui->imageBox->x(), 0, ui->imageBox->width(), ui->imageBox->height()));
    animal->start();

    // 释放动画对象
    connect(animal, &QPropertyAnimation::finished, this, [=](){
        delete animal;
    });
}

void RecBoxItem::leaveEvent(QEvent *event)
{
    // qDebug() << "你的鼠标离开了";
    // 动画效果
    QPropertyAnimation *animal = new QPropertyAnimation(ui->imageBox, "geometry");
    animal->setDuration(100);
    animal->setStartValue(QRect(ui->imageBox->x(), 0, ui->imageBox->width(), ui->imageBox->height()));
    animal->setEndValue(QRect(ui->imageBox->x(), 6, ui->imageBox->width(), ui->imageBox->height()));
    animal->start();

    // 释放动画对象
    connect(animal, &QPropertyAnimation::finished, this, [=](){
        delete animal;
    });
}

