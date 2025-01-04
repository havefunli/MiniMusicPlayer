#include "musicslider.h"
#include "ui_musicslider.h"
#include <QMouseEvent>
#include <QDebug>

MusicSlider::MusicSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicSlider)
{
    ui->setupUi(this);
}

MusicSlider::~MusicSlider()
{
    delete ui;
}

void MusicSlider::setPos(float ratio)
{
    ui->outLine->setGeometry(ui->outLine->x(), ui->outLine->y(), this->width() * ratio, ui->outLine->height());
}

void MusicSlider::mousePressEvent(QMouseEvent *event)
{
    int width = event->pos().x();
    ui->outLine->setGeometry(ui->outLine->x(), ui->outLine->y(), width, ui->outLine->height());
}

void MusicSlider::mouseReleaseEvent(QMouseEvent *event)
{
    (void)event;
    emit setMusicSliderPosition(ui->outLine->width() / (float)this->width());
    qDebug() << "现在的位置，比例: " << event->pos().x() << " " << ui->outLine->width() / (float)this->width();
}

void MusicSlider::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton) {
        int width = event->pos().x();
        ui->outLine->setGeometry(ui->outLine->x(), ui->outLine->y(), width, ui->outLine->height());
    }
}
