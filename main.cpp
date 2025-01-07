#include "widget.h"

#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>

void isRunning()
{
    QSharedMemory *sharedMemory = new QSharedMemory("Music");
    if (sharedMemory->attach()) {
        QMessageBox::information(nullptr, "提示", "该程序正在运行......");
        exit(0);
    }
    sharedMemory->create(1);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 判断该程序是否已经运行
    isRunning();

    Widget w;
    w.show();
    return a.exec();
}
