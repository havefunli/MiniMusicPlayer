/********************************************************************************
** Form generated from reading UI file 'volumetool.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
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

    void setupUi(QWidget *VolumeTool)
    {
        if (VolumeTool->objectName().isEmpty())
            VolumeTool->setObjectName("VolumeTool");
        VolumeTool->resize(100, 350);
        volumeWidget = new QWidget(VolumeTool);
        volumeWidget->setObjectName("volumeWidget");
        volumeWidget->setGeometry(QRect(10, 10, 80, 300));
        volumeWidget->setMinimumSize(QSize(80, 300));
        volumeWidget->setMaximumSize(QSize(80, 300));
        silenceBtn = new QPushButton(volumeWidget);
        silenceBtn->setObjectName("silenceBtn");
        silenceBtn->setGeometry(QRect(0, 260, 80, 35));
        silenceBtn->setMinimumSize(QSize(80, 35));
        silenceBtn->setMaximumSize(QSize(80, 35));
        volumeRatio = new QLabel(volumeWidget);
        volumeRatio->setObjectName("volumeRatio");
        volumeRatio->setGeometry(QRect(0, 220, 80, 35));
        volumeRatio->setMinimumSize(QSize(80, 30));
        volumeRatio->setMaximumSize(QSize(80, 35));
        volumeRatio->setAlignment(Qt::AlignmentFlag::AlignCenter);
        volumeBox = new QWidget(volumeWidget);
        volumeBox->setObjectName("volumeBox");
        volumeBox->setGeometry(QRect(0, 0, 80, 220));
        volumeBox->setMaximumSize(QSize(16777215, 220));
        inLine = new QFrame(volumeBox);
        inLine->setObjectName("inLine");
        inLine->setGeometry(QRect(38, 25, 4, 180));
        inLine->setMinimumSize(QSize(4, 0));
        inLine->setMaximumSize(QSize(4, 16777215));
        inLine->setFrameShape(QFrame::Shape::StyledPanel);
        inLine->setFrameShadow(QFrame::Shadow::Raised);
        outLine = new QFrame(volumeBox);
        outLine->setObjectName("outLine");
        outLine->setGeometry(QRect(38, 25, 4, 180));
        outLine->setFrameShape(QFrame::Shape::StyledPanel);
        outLine->setFrameShadow(QFrame::Shadow::Raised);

        retranslateUi(VolumeTool);

        QMetaObject::connectSlotsByName(VolumeTool);
    } // setupUi

    void retranslateUi(QWidget *VolumeTool)
    {
        VolumeTool->setWindowTitle(QCoreApplication::translate("VolumeTool", "Form", nullptr));
        silenceBtn->setText(QCoreApplication::translate("VolumeTool", "PushButton", nullptr));
        volumeRatio->setText(QCoreApplication::translate("VolumeTool", "45%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolumeTool: public Ui_VolumeTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMETOOL_H
