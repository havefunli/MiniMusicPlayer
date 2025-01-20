#include "singeritem.h"
#include "ui_singeritem.h"

SingerItem::SingerItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingerItem)
{
    ui->setupUi(this);
}

SingerItem::~SingerItem()
{
    delete ui;
}
