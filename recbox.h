#ifndef RECBOX_H
#define RECBOX_H

#include <QWidget>
#include <QJsonArray>

namespace Ui {
class RecBox;
}

class RecBox : public QWidget
{
    Q_OBJECT

public:
    explicit RecBox(QWidget *parent = nullptr);
    ~RecBox();
    void initRecBoxUi(QJsonArray, int);

private slots:
    void on_btUp_clicked();

    void on_btDown_clicked();

private:
    void createRecBoxItem();

signals:
    void getRandomMusic();

private:
    Ui::RecBox *ui;

    int row;
    int col;

    int currentIndex;
    int cnt;

    QJsonArray imageList;
};

#endif // RECBOX_H
