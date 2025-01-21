#include "singerpage.h"
#include "singeritem.h"
#include "singeritem.h"
#include "ui_singerpage.h"
#include <QDebug>

#define MAXCOL 4

SingerPage::SingerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingerPage),
    gridLayout(new QGridLayout())
{
    ui->setupUi(this);
    setLayout(gridLayout);
}

void SingerPage::initPage(QVector<Singer*> singers)
{
    // 去除之前的内容
    cleanLayout();

    int row = 0, col = 0;
    qDebug() << "singer.size() = " << singers.size();
    for (int i = 0; i < singers.size(); i++) {

        // 初始化一个 item 对象
        SingerItem *item = new SingerItem(this);
        item->setSingerName(singers[i]->getSingerName());
        item->setSingerImage(singers[i]->getSingerImage());

        item->setFixedSize(item->width(), item->height());

        // 加入到布局中，并且左上对齐
        gridLayout->addWidget(item, row, col, Qt::AlignLeft | Qt::AlignTop);

        // 判断一行长度
        col += 1;
        if (col >= MAXCOL) {
            col = 0;
            row += 1;
        }

        // 绑定对应槽函数
        connect(item, &SingerItem::singerClicked, this, &SingerPage::singerClicked);
    }
}

void SingerPage::cleanLayout()
{
    QList<SingerItem*> list = findChildren<SingerItem*>();
    for (auto &item : list) {
        gridLayout->removeWidget(item);
        item->deleteLater();
    }
}


SingerPage::~SingerPage()
{
    delete ui;
}
