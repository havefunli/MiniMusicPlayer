#ifndef SINGERPAGE_H
#define SINGERPAGE_H

#include <QWidget>
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

private:
    Ui::SingerPage *ui;
    QVector<Singer*> singers;
};

#endif // SINGERPAGE_H
