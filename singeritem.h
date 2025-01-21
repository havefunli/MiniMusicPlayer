#ifndef SINGERITEM_H
#define SINGERITEM_H

#include <QWidget>

namespace Ui {
class SingerItem;
}

class SingerItem : public QWidget
{
    Q_OBJECT

public:
    explicit SingerItem(QWidget *parent = nullptr);
    ~SingerItem();

    void setSingerName(const QString &);
    void setSingerImage(const QByteArray &);

private slots:
    void on_btn_clicked();

signals:
    void singerClicked(const QString);

private:
    Ui::SingerItem *ui;
};

#endif // SINGERITEM_H
