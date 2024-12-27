#ifndef WIDGET_H
#define WIDGET_H

#include <QMouseEvent>
#include <QWidget>
#include <QDebug>
#include <QJsonArray>
#include <QGraphicsDropShadowEffect>

QT_BEGIN_NAMESPACE
namespace Ui {
class MusicPlayer;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void initUi();
    void initConnect();

protected:
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);

private slots:
    void on_quit_clicked();
    // 切换界面
    // 将其他按键颜色清除
    void onBtFormClick(int);
    // 推荐图片音频构造
    QJsonArray randomPiction();


private:
    Ui::MusicPlayer *ui;
    QPoint dragPosition; // recored mouse pos
};
#endif // WIDGET_H
