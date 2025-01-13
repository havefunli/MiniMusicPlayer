#include "lrcpage.h"
#include "ui_lrcpage.h"
#include "serverconnection.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

LrcPage::LrcPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LrcPage)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    ui->hideBtn->setIcon(QIcon(":/images/xiala.png"));

    // 设置动画
    animation = new QPropertyAnimation(this, "geometry", this);
    animation->setDuration(250);
    animation->setStartValue(QRect(10, 10, width(), height()));
    animation->setEndValue(QRect(10, 10 + height(), width(), height()));

    // 下拉窗口动画
    connect(ui->hideBtn, &QPushButton::clicked, this, [=]() {
        animation->start();
    });
    // 下拉动作完成后隐藏窗口
    connect(animation, &QPropertyAnimation::finished, this, [=](){
       this->hide();
    });
}

LrcPage::~LrcPage()
{
    delete ui;
}

void LrcPage::getLrcAndParse(const QString &filePath, bool isLocal)
{
    qDebug() << "lrcFilePath: " << filePath;

    // lrc 文件不一定在本地
    // 本地文件
    if (isLocal) {
        // 打开文件
        QFile file;
        file.setFileName(filePath);
        file.open(QIODevice::ReadOnly);
        if (!file.isOpen()) {
            qDebug() << "打开本地歌词文件失败";
            return;
        }
        parseLrcFile(file.readAll());
        file.close();
        return;
    } else {
        // 远程获取文件
        qDebug() << "远程获取歌词文件";
        emit sendLrcRequest(QUrl(filePath), std::bind(&LrcPage::parseLrcFile, this, std::placeholders::_1));
    }
}


bool LrcPage::parseOneLine(const QString &line, LrcWordLine *lrcLine)
{
    // [00:25.28]说话的方式简单点
    int start = 1, end = 0;
    end = line.indexOf(']');
    if (end == -1) {
        return false;
    }
    // 解析歌词
    QString words = line.mid(end + 1);
    lrcLine->lrcText = words.trimmed();

    // 解析时间
    qint64 duration = 0;
    // 解析分
    end = line.indexOf(':', start);
    duration += (line.mid(start, end - start).toInt() * 60 * 1000);
    // 解析秒
    start = end + 1;
    end = line.indexOf('.', start);
    duration += (line.mid(start, end - start).toInt() * 1000);
    // 解析毫秒
    start = end + 1;
    end = line.indexOf('.', start);
    duration += (line.mid(start, end - start).toInt());
    lrcLine->lrcTime = duration;

    return true;
}

bool LrcPage::parseLrcFile(QString fileContent)
{
    QTextStream stream(&fileContent);

    // 清除上一个音乐的信息
    lrcWordLines.clear();

    while (!stream.atEnd()) {
        QString line = stream.readLine();
        // 解析单行数据：
        LrcWordLine *lrcLine = new LrcWordLine();
        if (parseOneLine(line, lrcLine)) {
            lrcWordLines.push_back(lrcLine);
            // qDebug() << lrcLine->lrcTime << " " << lrcLine->lrcText;
        }
    }
    return true;
}

void LrcPage::showLrcWordLine(qint64 time)
{
    // 1. 根据当前时间获取歌词在数组的索引
    int index = getLrcWordLineIndex(time);
    if (-1 == index) {
        ui->line_1->setText("");
        ui->line_2->setText("");
        ui->line_3->setText("");
        ui->lineCenter->setText("抱歉，当前音乐暂无歌词 QAQ");
        ui->line_5->setText("");
        ui->line_6->setText("");
        ui->line_7->setText("");
    }
    // 2. 获取前后三行
    ui->line_1->setText(getLrcWordByIndex(index - 3));
    ui->line_2->setText(getLrcWordByIndex(index - 2));
    ui->line_3->setText(getLrcWordByIndex(index - 1));
    ui->lineCenter->setText(getLrcWordByIndex(index));
    ui->line_5->setText(getLrcWordByIndex(index + 1));
    ui->line_6->setText(getLrcWordByIndex(index + 2));
    ui->line_7->setText(getLrcWordByIndex(index + 3));
}

int LrcPage::getLrcWordLineIndex(qint64 time)
{
    if (lrcWordLines.isEmpty()) {
        return -1;
    }

    // 最开始的情况，特殊处理
    if (time <= lrcWordLines[0]->lrcTime) {
        return 0;
    }
    // 中间状态
    for (int i = 1; i < lrcWordLines.size(); i++) {
        if (time < lrcWordLines[i]->lrcTime) {
            return i - 1;
        }
    }
    // 最后的状态
    return lrcWordLines.size() - 1;
}

QString LrcPage::getLrcWordByIndex(int index)
{
    if (index < 0 || index >= lrcWordLines.size()) {
        return "";
    }
    return lrcWordLines[index]->lrcText;
}

void LrcPage::setMusicSinger(const QString &singer)
{
    ui->musicSinger->setText(singer);
}

void LrcPage::setMusicName(const QString &name)
{
    ui->musicName->setText(name);
}

