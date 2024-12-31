/********************************************************************************
** Form generated from reading UI file 'volumetool.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMETOOL_H
#define UI_VOLUMETOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeTool
{
public:
    QWidget *volumeWidget;
    QPushButton *silenceBtn;
    QLabel *volumeRatio;
    QWidget *volumeBox;
    QFrame *inLine;
    QFrame *outLine;
    QPushButton *silderBtn;

    void setupUi(QWidget *VolumeTool)
    {
        if (VolumeTool->objectName().isEmpty())
            VolumeTool->setObjectName(QString::fromUtf8("VolumeTool"));
        VolumeTool->resize(100, 350);
        volumeWidget = new QWidget(VolumeTool);
        volumeWidget->setObjectName(QString::fromUtf8("volumeWidget"));
        volumeWidget->setGeometry(QRect(10, 10, 80, 300));
        volumeWidget->setMinimumSize(QSize(80, 300));
        volumeWidget->setMaximumSize(QSize(80, 300));
        volumeWidget->setStyleSheet(QString::fromUtf8("#volumeWidget\n"
"{\n"
"	background-color: #F0F0F0;\n"
"	border-radius:5px;\n"
"}"));
        silenceBtn = new QPushButton(volumeWidget);
        silenceBtn->setObjectName(QString::fromUtf8("silenceBtn"));
        silenceBtn->setGeometry(QRect(0, 260, 80, 35));
        silenceBtn->setMinimumSize(QSize(80, 35));
        silenceBtn->setMaximumSize(QSize(80, 35));
        silenceBtn->setStyleSheet(QString::fromUtf8("#silenceBtn\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"#silenceBtn:hover\n"
"{\n"
"	background-color:#e0e0e0;\n"
"}\n"
"\n"
""));
        volumeRatio = new QLabel(volumeWidget);
        volumeRatio->setObjectName(QString::fromUtf8("volumeRatio"));
        volumeRatio->setGeometry(QRect(0, 220, 80, 35));
        volumeRatio->setMinimumSize(QSize(80, 30));
        volumeRatio->setMaximumSize(QSize(80, 35));
        volumeRatio->setAlignment(Qt::AlignCenter);
        volumeBox = new QWidget(volumeWidget);
        volumeBox->setObjectName(QString::fromUtf8("volumeBox"));
        volumeBox->setGeometry(QRect(0, 0, 80, 220));
        volumeBox->setMaximumSize(QSize(16777215, 220));
        inLine = new QFrame(volumeBox);
        inLine->setObjectName(QString::fromUtf8("inLine"));
        inLine->setGeometry(QRect(38, 25, 4, 180));
        inLine->setMinimumSize(QSize(4, 0));
        inLine->setMaximumSize(QSize(4, 16777215));
        inLine->setStyleSheet(QString::fromUtf8("background-color: #ececec;"));
        inLine->setFrameShape(QFrame::NoFrame);
        outLine = new QFrame(volumeBox);
        outLine->setObjectName(QString::fromUtf8("outLine"));
        outLine->setGeometry(QRect(38, 25, 4, 180));
        outLine->setStyleSheet(QString::fromUtf8("background-color:#1ecc94;"));
        outLine->setFrameShape(QFrame::NoFrame);
        silderBtn = new QPushButton(volumeBox);
        silderBtn->setObjectName(QString::fromUtf8("silderBtn"));
        silderBtn->setGeometry(QRect(33, 18, 14, 14));
        silderBtn->setStyleSheet(QString::fromUtf8("border-radius:7px;\n"
"background-color:#1ecc94;"));

        retranslateUi(VolumeTool);

        QMetaObject::connectSlotsByName(VolumeTool);
    } // setupUi

    void retranslateUi(QWidget *VolumeTool)
    {
        VolumeTool->setWindowTitle(QCoreApplication::translate("VolumeTool", "Form", nullptr));
        silenceBtn->setText(QCoreApplication::translate("VolumeTool", "\351\235\231\351\237\263", nullptr));
        volumeRatio->setText(QCoreApplication::translate("VolumeTool", "45%", nullptr));
        silderBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VolumeTool: public Ui_VolumeTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMETOOL_H
