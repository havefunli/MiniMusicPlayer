#ifndef LRCPAGE_H
#define LRCPAGE_H

#include <QWidget>
#include <functional>
#include <QPropertyAnimation>

using ParseFunc = std::function<void(QString)>;

struct LrcWordLine
{
    LrcWordLine() = default;

    LrcWordLine(qint64 lrcTime, QString lrcText)
        : lrcTime(lrcTime)
        , lrcText(lrcText)
    {}

    qint64 lrcTime;
    QString lrcText;
};

namespace Ui {
class LrcPage;
}

class LrcPage : public QWidget
{
    Q_OBJECT

public:
    explicit LrcPage(QWidget *parent = nullptr);
    ~LrcPage();

    void getLrcAndParse(const QString &, bool);
    bool parseOneLine(const QString &, LrcWordLine *);
    bool parseLrcFile(QString);

    void showLrcWordLine(qint64);  // 根据当前时间更新歌词界面
    int getLrcWordLineIndex(qint64);
    QString getLrcWordByIndex(int);

    void setMusicSinger(const QString &);
    void setMusicName(const QString &);

signals:
    void sendLrcRequest(const QUrl &, const ParseFunc);

private:
    Ui::LrcPage *ui;
    QVector<LrcWordLine*> lrcWordLines;
    QPropertyAnimation *animation;
};

#endif // LRCPAGE_H
