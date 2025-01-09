#include "searchresult.h"
#include "ui_searchresult.h"

SearchResult::SearchResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchResult)
{
    ui->setupUi(this);

    ui->play->setIcon(QIcon(":/images/play3.png"));
}

SearchResult::~SearchResult()
{
    delete ui;
}

void SearchResult::setKeyWords(const QString &words)
{
    keyWords = words;
    ui->keywords->setText(keyWords);
}
