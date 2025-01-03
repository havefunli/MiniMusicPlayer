#include "musicslider.h"
#include "ui_musicslider.h"

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

void MusicSlider::mousePressEvent(QMouseEvent *)
{

}

void MusicSlider::mouseReleaseEvent(QMouseEvent *)
{

}

void MusicSlider::mouseMoveEvent(QMouseEvent *)
{

}
