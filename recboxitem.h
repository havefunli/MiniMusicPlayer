#ifndef RECBOXITEM_H
#define RECBOXITEM_H

#include <QWidget>

namespace Ui {
class RecBoxItem;
}

class RecBoxItem : public QWidget
{
    Q_OBJECT

public:
    explicit RecBoxItem(QWidget *parent = nullptr);
    ~RecBoxItem();

    // 设置文本图片
    void setRecText(const QString&);
    void setRecImage(const QString&);

protected:
    void enterEvent(QEnterEvent *) override;
    void leaveEvent(QEvent *) override;

private:
    Ui::RecBoxItem *ui;
};

#endif // RECBOXITEM_H
