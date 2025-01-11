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
    explicit UpLoad(QWidget *parent = nullptr);
    ~UpLoad();

signals:
    void submitMusic(const QUrl, const QUrl);

private slots:
    void upLoadMusic();
    void upLoadLrc();
    void onSubmitBtnClicked();

private:
    Ui::UpLoad *ui;
    QUrl musicFile;
    QUrl lrcFile;
    QFileDialog *fileDialog;
};

#endif // UPLOAD_H
