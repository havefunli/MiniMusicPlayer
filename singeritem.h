#ifndef SINGERITEM_H
#define SINGERITEM_H

#include <QWidget>

namespace Ui {
class SingerItem;
}

class SingerItem : public QWidget
{
    Q_OBJECT

public:
    explicit SingerItem(QWidget *parent = nullptr);
    ~SingerItem();

private:
    Ui::SingerItem *ui;
};

#endif // SINGERITEM_H
