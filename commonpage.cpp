#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"

CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
}

CommonPage::~CommonPage()
{
    delete ui;
}

void CommonPage::setCommonPageUI(const QString &text, const QString &path)
{
    ui->pageTitle->setText(text);

    ui->musicImage->setPixmap(QPixmap(path));
    ui->musicImage->setScaledContents(true);

    // 将 ListBoxItem 对象放置到其中
    ListItemBox *itemBox = new ListItemBox(this);
    QListWidgetItem *item = new QListWidgetItem(ui->pageMusicList);
    item->setSizeHint(QSize(itemBox->width(), itemBox->height()));
    ui->pageMusicList->setItemWidget(item, itemBox);
}
