#ifndef UPLOAD_H
#define UPLOAD_H

#include <QWidget>

namespace Ui {
class UpLoad;
}

class UpLoad : public QWidget
{
    Q_OBJECT

public:
    explicit UpLoad(QWidget *parent = nullptr);
    ~UpLoad();

private:
    Ui::UpLoad *ui;
};

#endif // UPLOAD_H
