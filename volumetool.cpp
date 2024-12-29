#include "volumetool.h"
#include "ui_volumetool.h"
#include <QGraphicsDropShadowEffect>

VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool)
{
    ui->setupUi(this);
    // 设置为弹出窗口
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    // 设置透明背景
    setAttribute(Qt::WA_TranslucentBackground);
    // 设置窗口阴影 BUG
    // QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    // shadowEffect->setColor("#646464");
    // shadowEffect->setBlurRadius(10);
    // shadowEffect->setOffset(0, 0);
    // setGraphicsEffect(shadowEffect);

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

