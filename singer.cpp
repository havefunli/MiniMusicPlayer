#include "singer.h"
#include "ui_singer.h"

singer::singer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::singer)
{
    ui->setupUi(this);

    // for (int i = 0; )

}

singer::~singer()
{
    delete ui;
}
