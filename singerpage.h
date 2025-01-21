#ifndef SINGERPAGE_H
#define SINGERPAGE_H

#include <QWidget>
#include <QGridLayout>
#include "singer.h"

namespace Ui {
class SingerPage;
}

class SingerPage : public QWidget
{
    Q_OBJECT

public:
    explicit SingerPage(QWidget *parent = nullptr);
    ~SingerPage();

     // 初始化界面
     void initPage(QVector<Singer*> singerVec);
     // 清除之前的内容
     void cleanLayout();

signals:
     void singerClicked(const QString);

private:
    Ui::SingerPage *ui;
    QGridLayout *gridLayout;
};

#endif // SINGERPAGE_H
