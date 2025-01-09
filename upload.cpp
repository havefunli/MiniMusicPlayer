#include "upload.h"
#include "ui_upload.h"

UpLoad::UpLoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpLoad)
{
    ui->setupUi(this);
}

UpLoad::~UpLoad()
{
    delete ui;
}
