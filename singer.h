#ifndef SINGER_H
#define SINGER_H

#include <QWidget>

namespace Ui {
class singer;
}

class singer : public QWidget
{
    Q_OBJECT

public:
    explicit singer(QWidget *parent = nullptr);
    ~singer();

private:
    int row = 0;
    int col = 0;   // 默认一个页最多 4 个歌手
    Ui::singer *ui;
};

#endif // SINGER_H
