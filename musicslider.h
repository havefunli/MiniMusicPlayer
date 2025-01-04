#ifndef MUSICSLIDER_H
#define MUSICSLIDER_H

#include <QWidget>

namespace Ui {
class MusicSlider;
}

class MusicSlider : public QWidget
{
    Q_OBJECT

public:
    explicit MusicSlider(QWidget *parent = nullptr);
    ~MusicSlider();

    void setPos(float ratio);

protected:
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;

signals:
    void setMusicSliderPosition(float);

private:
    Ui::MusicSlider *ui;
};

#endif // MUSICSLIDER_H
