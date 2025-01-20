#include "singerpage.h"
#include "singeritem.h"
#include "singeritem.h"
#include "ui_singerpage.h"
#include <QGridLayout>

#define MAXCOL 4

SingerPage::SingerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingerPage)
{
    ui->setupUi(this);
}

void SingerPage::initPage(QVector<Singer*> singerVec)
{
    singers = singerVec;

    // 创建一个网格布局管理器
    QGridLayout* gridLayout = new QGridLayout();

    int row = 0, col = 0;
    for (int i = 0; i < singers.size(); i++) {

        // 初始化一个 item 对象
        SingerItem *item = new SingerItem();
        item->setSingerName(singers[i]->getSingerName());
        item->setSingerImage(singers[i]->getSingerImage());

        // 加入到布局中
        gridLayout->addWidget(item, row, col);

        // 判断一行长度
        col += 1;
        if (col >= MAXCOL) {
            col = 0;
            row += 1;
        }
    }

    // 设置布局
    setLayout(gridLayout);
}


SingerPage::~SingerPage()
{
    delete ui;
}
