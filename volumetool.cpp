#include "volumetool.h"
#include "ui_volumetool.h"

VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool)
{
    ui->setupUi(this);
}

VolumeTool::~VolumeTool()
{
    delete ui;
}
