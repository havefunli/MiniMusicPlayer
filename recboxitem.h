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
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;

private slots:
    void on_recMusicBtn_clicked();

signals:
    void clicked();

private:
    Ui::RecBoxItem *ui;
};

#endif // RECBOXITEM_H
