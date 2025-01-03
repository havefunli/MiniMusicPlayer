#include "volumetool.h"
#include "ui_volumetool.h"
#include <QGraphicsDropShadowEffect>

VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool)
    , isMuted(false)
    , volumeRatio(20)
{
    ui->setupUi(this);
    // 设置为弹出窗口
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    // 设置透明背景
    setAttribute(Qt::WA_TranslucentBackground);
    // 设置窗口阴影 BUG
     QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
     shadowEffect->setColor("#646464");
     shadowEffect->setBlurRadius(10);
     shadowEffect->setOffset(0, 0);
     setGraphicsEffect(shadowEffect);

    // 设置图标
    ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    // 默认音量
    ui->volumeRatio->setText("20%");
    // 设置音量槽
    QRect old = ui->outLine->geometry();
    ui->outLine->setGeometry(old.x(), old.height() - 36 + 25, old.width(), 36);
    // 设置音量按钮
    ui->silderBtn->move(ui->silderBtn->x(), ui->outLine->y() - ui->silderBtn->height() / 2);
}

VolumeTool::~VolumeTool()
{
    delete ui;
}

bool VolumeTool::eventFilter(QObject *watched, QEvent *event)
{
    if (ui->volumeBox == watched) {
        if (event->type() == QEvent::MouseButtonPress) {
            // 鼠标按下
        } else if (event->type() == QEvent::MouseButtonRelease) {
            // 鼠标释放
        } else if (event->type() == QEvent::MouseMove) {
            // 鼠标移动
        }
        return true;
    }

    return QObject::eventFilter(watched, event);
}

void VolumeTool::calcVolume()
{
    // 设置音量大小
    // 设置界面显示
}


void VolumeTool::on_silenceBtn_clicked()
{
    isMuted = !isMuted;
    if (isMuted) {
        ui->silenceBtn->setIcon(QIcon(":/images/silent.png"));
    } else {
        ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    }
    emit setMusicMuted(isMuted);
}
