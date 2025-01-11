#include "upload.h"
#include "ui_upload.h"
#include <QDebug>


UpLoad::UpLoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpLoad),
    fileDialog(new QFileDialog(this))

{
    ui->setupUi(this);

    connect(ui->cancleBtn, &QPushButton::clicked, this, [=](){
        this->hide();
    });
    connect(ui->music, &QPushButton::clicked, this, &UpLoad::upLoadMusic);
    connect(ui->lrc, &QPushButton::clicked, this, &UpLoad::upLoadLrc);
    connect(ui->subBtn, &QPushButton::clicked, this, &UpLoad::onSubmitBtnClicked);
}

UpLoad::~UpLoad()
{
    delete ui;
}

void UpLoad::upLoadMusic()
{
    fileDialog->setWindowTitle("音乐文件");
    fileDialog->setDirectory("C:\\Users\acer\\Desktop\\Project\\MiniMusicPlayer\\musics");
    // 设置文件筛选
    QStringList fileName;
    fileName << "*.mp3" << "*.wav" << "*.flac";
    fileDialog->setNameFilters(fileName); // 使用文件名过滤器

    if (fileDialog->exec() == QFileDialog::Accepted) {
        musicFile = fileDialog->selectedUrls().front();
    }
}

void UpLoad::upLoadLrc()
{
    fileDialog->setWindowTitle("歌词文件");
    fileDialog->setDirectory("C:\\Users\acer\\Desktop\\Project\\MiniMusicPlayer\\musics");
    // 设置文件筛选
    QStringList fileName;
    fileName << "*.lrc";
    fileDialog->setNameFilters(fileName); // 使用文件名过滤器

    if (fileDialog->exec() == QFileDialog::Accepted) {
        lrcFile = fileDialog->selectedUrls().front();
    }
}

void UpLoad::onSubmitBtnClicked()
{
    if (musicFile.isEmpty() || lrcFile.isEmpty()) {
        QMessageBox::information(this, "上传出错啦", "请将两个指定的文件上传哦");
    }

    emit submitMusic(musicFile, lrcFile);

    // 清除便于下次上传
    musicFile.clear();
    lrcFile.clear();
}

