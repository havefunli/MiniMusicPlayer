#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>

namespace Ui {
class CommonPage;
}

class CommonPage : public QWidget
{
    Q_OBJECT

public:
    explicit CommonPage(QWidget *parent = nullptr);
    ~CommonPage();

    // 设置文本和图片
    void setCommonPageUI(const QString&, const QString&);

private:
    Ui::CommonPage *ui;
};

#endif // COMMONPAGE_H
