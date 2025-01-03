#ifndef VOLUMETOOL_H
#define VOLUMETOOL_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class VolumeTool;
}

class VolumeTool : public QWidget
{
    Q_OBJECT

public:
    explicit VolumeTool(QWidget *parent = nullptr);
    ~VolumeTool();

    bool eventFilter(QObject*, QEvent*);

    void calcVolume(); // 设置音量大小

signals:
    void setMusicMuted(bool); // 设置静音
    void setMusicVolume(int); // 设置音量

private slots:
    void on_silenceBtn_clicked();

private:
    Ui::VolumeTool *ui;
    bool isMuted;
    int volumeRatio;
};

#endif // VOLUMETOOL_H
