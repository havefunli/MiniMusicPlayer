#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QWidget>

namespace Ui {
class SearchResult;
}

class SearchResult : public QWidget
{
    Q_OBJECT

public:
    explicit SearchResult(QWidget *parent = nullptr);
    ~SearchResult();

    void setKeyWords(const QString&);

private:
    Ui::SearchResult *ui;
    QString keyWords;
};

#endif // SEARCHRESULT_H
