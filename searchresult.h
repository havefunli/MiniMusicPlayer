#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <musiclist.h>
#include <QWidget>
#include <QMediaPlaylist>

namespace Ui {
class SearchResult;
}

class SearchResult : public QWidget
{
    Q_OBJECT

public:
    explicit SearchResult(QWidget *parent = nullptr);
    ~SearchResult();

    void setKeyWords(const QString&); // 设置搜索词；发起搜索请求
    void initSearchPage(QVector<Music*>&); // 初始化搜索页面
    void addMusicToPlaylist(QMediaPlaylist*);

signals:
    void searchMusic(const QString &);
    void playMusicByIndex(SearchResult*, int);

private:
    Ui::SearchResult *ui;
    QString keyWords;
    QVector<Music*> musicsPtr;
};

#endif // SEARCHRESULT_H
