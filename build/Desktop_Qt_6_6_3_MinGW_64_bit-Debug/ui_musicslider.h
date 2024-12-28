/********************************************************************************
** Form generated from reading UI file 'musicslider.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSLIDER_H
#define UI_MUSICSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicSlider
{
public:
    QFrame *inLine;
    QFrame *outLine;

    void setupUi(QWidget *MusicSlider)
    {
        if (MusicSlider->objectName().isEmpty())
            MusicSlider->setObjectName("MusicSlider");
        MusicSlider->resize(820, 20);
        MusicSlider->setMinimumSize(QSize(820, 20));
        MusicSlider->setMaximumSize(QSize(820, 20));
        inLine = new QFrame(MusicSlider);
        inLine->setObjectName("inLine");
        inLine->setGeometry(QRect(0, 8, 850, 4));
        inLine->setMinimumSize(QSize(0, 4));
        inLine->setMaximumSize(QSize(850, 4));
        inLine->setStyleSheet(QString::fromUtf8("background-color:#ebeef5;"));
        inLine->setFrameShape(QFrame::Shape::StyledPanel);
        inLine->setFrameShadow(QFrame::Shadow::Raised);
        outLine = new QFrame(MusicSlider);
        outLine->setObjectName("outLine");
        outLine->setGeometry(QRect(0, 8, 400, 4));
        outLine->setMinimumSize(QSize(0, 4));
        outLine->setMaximumSize(QSize(850, 4));
        outLine->setStyleSheet(QString::fromUtf8("background-color: #1ecc94;"));
        outLine->setFrameShape(QFrame::Shape::StyledPanel);
        outLine->setFrameShadow(QFrame::Shadow::Raised);

        retranslateUi(MusicSlider);

        QMetaObject::connectSlotsByName(MusicSlider);
    } // setupUi

    void retranslateUi(QWidget *MusicSlider)
    {
        MusicSlider->setWindowTitle(QCoreApplication::translate("MusicSlider", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicSlider: public Ui_MusicSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICSLIDER_H
