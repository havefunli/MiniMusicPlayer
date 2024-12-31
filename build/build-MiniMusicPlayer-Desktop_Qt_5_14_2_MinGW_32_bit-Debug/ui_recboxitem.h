/********************************************************************************
** Form generated from reading UI file 'recboxitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOXITEM_H
#define UI_RECBOXITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecBoxItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *imageBox;
    QLabel *recMusicImage;
    QPushButton *recMusicBtn;
    QLabel *recBoxItemText;

    void setupUi(QWidget *RecBoxItem)
    {
        if (RecBoxItem->objectName().isEmpty())
            RecBoxItem->setObjectName(QString::fromUtf8("RecBoxItem"));
        RecBoxItem->resize(154, 241);
        verticalLayout = new QVBoxLayout(RecBoxItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 6, 2, 5);
        imageBox = new QWidget(RecBoxItem);
        imageBox->setObjectName(QString::fromUtf8("imageBox"));
        imageBox->setMinimumSize(QSize(150, 200));
        imageBox->setMaximumSize(QSize(150, 200));
        imageBox->setStyleSheet(QString::fromUtf8(""));
        recMusicImage = new QLabel(imageBox);
        recMusicImage->setObjectName(QString::fromUtf8("recMusicImage"));
        recMusicImage->setGeometry(QRect(0, 0, 150, 150));
        recMusicImage->setMinimumSize(QSize(0, 150));
        recMusicImage->setMaximumSize(QSize(16777215, 150));
        recMusicBtn = new QPushButton(imageBox);
        recMusicBtn->setObjectName(QString::fromUtf8("recMusicBtn"));
        recMusicBtn->setGeometry(QRect(40, 60, 61, 61));
        recMusicBtn->setCursor(QCursor(Qt::PointingHandCursor));
        recMusicBtn->setStyleSheet(QString::fromUtf8("#recMusicBtn\n"
"{\n"
"	border: none;\n"
"}"));

        verticalLayout->addWidget(imageBox);

        recBoxItemText = new QLabel(RecBoxItem);
        recBoxItemText->setObjectName(QString::fromUtf8("recBoxItemText"));
        recBoxItemText->setMinimumSize(QSize(0, 30));
        recBoxItemText->setMaximumSize(QSize(16777215, 30));
        recBoxItemText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(recBoxItemText);


        retranslateUi(RecBoxItem);

        QMetaObject::connectSlotsByName(RecBoxItem);
    } // setupUi

    void retranslateUi(QWidget *RecBoxItem)
    {
        RecBoxItem->setWindowTitle(QCoreApplication::translate("RecBoxItem", "Form", nullptr));
        recMusicImage->setText(QString());
        recMusicBtn->setText(QString());
        recBoxItemText->setText(QCoreApplication::translate("RecBoxItem", "\346\216\250\350\215\220-001", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecBoxItem: public Ui_RecBoxItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOXITEM_H
