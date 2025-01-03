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

    // 开启事件捕获
    ui->volumeBox->installEventFilter(this);

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
            calcVolume();
        } else if (event->type() == QEvent::MouseButtonRelease) {
            // 鼠标释放
            emit setMusicVolume(volumeRatio);
        } else if (event->type() == QEvent::MouseMove) {
            // 鼠标移动
            calcVolume();
            emit setMusicVolume(volumeRatio);
        }
        return true;
    }

    return QObject::eventFilter(watched, event);
}

void VolumeTool::calcVolume()
{
    // 获取鼠标点击的 y 坐标(在控件内的)
    int height = ui->volumeBox->mapFromGlobal(QCursor().pos()).y();
    // height 的范围必须要在 [25, 205]
    height = height > 205 ? 205 : height;
    height = height < 25 ? 25 : height;
    // 设置 outline ui
    ui->outLine->setGeometry(ui->outLine->x(), height, ui->outLine->width(), 205 - height);
    // 设置 silderBtn 的位置
    ui->silderBtn->move(ui->silderBtn->x(), ui->outLine->y() - ui->silderBtn->height() / 2);
    // 设置音量大小
    volumeRatio = (int)(ui->outLine->height() / (float)180 * 100);
    // 设置音量显示
    ui->volumeRatio->setText(QString::number(volumeRatio) + "%");
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
