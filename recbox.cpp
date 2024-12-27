#include "recbox.h"
#include "ui_recbox.h"
#include "recboxitem.h"
#include <QJsonObject>

RecBox::RecBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecBox)
    , row(1)
    , col(4)
{
    ui->setupUi(this);
}

RecBox::~RecBox()
{
    delete ui;
}

void RecBox::initRecBoxUi(QJsonArray data, int row)
{
    if (row == 2) {
        this->row = row;
        col = 8;
    } else {
        ui->listDown->hide();
    }
    imageList = data;

    currentIndex = 0;
    cnt = imageList.size() / col;

    // qDebug() << "size = " << imageList.size();
    // qDebug() << "cnt = " << cnt;

    // 创建 item
    createRecBoxItem();
}

void RecBox::createRecBoxItem()
{
    // 清除之前的元素
    QList<RecBoxItem*> recUpList = ui->listUp->findChildren<RecBoxItem*>();
    for (auto item : recUpList) {
        ui->recListUpHLayout->removeWidget(item);
        delete item;
    }
    QList<RecBoxItem*> recDownList = ui->listDown->findChildren<RecBoxItem*>();
    for (auto item : recDownList) {
        ui->recListDownHLayout->removeWidget(item);
        delete item;
    }

    // 创建 RecBoxItem 对象，添加到 RecBox
    int index = 0;
    for (int i = currentIndex * col; i < col + currentIndex * col; ++i) {

        RecBoxItem *item = new RecBoxItem();

        // 设置音乐图片和文本
        QJsonObject obj = imageList[i].toObject();
        item->setRecImage(obj.value("path").toString());
        item->setRecText(obj.value("text").toString());

        if (index >= col / 2 && 2 == row) {
            ui->recListDownHLayout->addWidget(item);
        } else {
            ui->recListUpHLayout->addWidget(item);
        }

        index++;
    }
}

void RecBox::on_btUp_clicked()
{
    // 计算当前索引
    currentIndex = (currentIndex - 1 + cnt) % cnt;

    createRecBoxItem();
}


void RecBox::on_btDown_clicked()
{
    // 计算当前索引
    currentIndex = (currentIndex + 1) % cnt;

    createRecBoxItem();
}

