#ifndef BTFORM_H
#define BTFORM_H

#include <QWidget>
#include <QPropertyAnimation>

namespace Ui {
class BtForm;
}

class BtForm : public QWidget
{
    Q_OBJECT

public:
    explicit BtForm(QWidget *parent = nullptr);
    ~BtForm();

    // 设置 Icon 和 text
    void initBtForm(const QString&, const QString&, int);

    int getPageId();

    void clearBackground();

signals:
    void btClick(int);

private:
    // 当鼠标按下后修改颜色
    // 发出切换界面的信号
    void mousePressEvent(QMouseEvent*);

private:
    Ui::BtForm *ui;
    int pageId;

    QPropertyAnimation *line1Animal;
    QPropertyAnimation *line2Animal;
    QPropertyAnimation *line3Animal;
    QPropertyAnimation *line4Animal;
};

#endif // BTFORM_H
