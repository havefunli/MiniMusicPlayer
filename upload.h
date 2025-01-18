#ifndef UPLOAD_H
#define UPLOAD_H

#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class UpLoad;
}

class UpLoad : public QWidget
{
    Q_OBJECT
public:

    struct UpLoadInfo
    {
        QString singerName;
        QString singerInfo;
        QUrl musicUrl;
        QUrl lrcUrl;
        QUrl imageUrl;
    };

public:
    explicit UpLoad(QWidget *parent = nullptr);
    ~UpLoad();

signals:
    void submitMusic(const UpLoadInfo);

private slots:
    void upLoadMusic();
    void upLoadLrc();
    void upLoadImage();
    void onSubmitBtnClicked();

private:
    Ui::UpLoad *ui;
    QUrl musicFile;
    QUrl lrcFile;
    QUrl imageFile;
    QFileDialog *fileDialog;
};

#endif // UPLOAD_H
