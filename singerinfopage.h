#ifndef SINGERINFOPAGE_H
#define SINGERINFOPAGE_H
#include "singer.h"
#include <QWidget>

namespace Ui {
class SingerInfoPage;
}

class SingerInfoPage : public QWidget
{
    Q_OBJECT

public:
    explicit SingerInfoPage(QWidget *parent = nullptr);
    ~SingerInfoPage();

    void setSingerName(const QString&);
    void setSingerImage(const QByteArray&);
    void setSingerIntroduce(const QString&);
    void setSingerMusic(const QVector<Music*>);

    QString getSingerName();

    void initPage(const Singer*);

private:
    Ui::SingerInfoPage *ui;
};

#endif // SINGERINFOPAGE_H
