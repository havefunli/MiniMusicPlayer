/********************************************************************************
** Form generated from reading UI file 'recbox.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOX_H
#define UI_RECBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftPage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btUp;
    QWidget *musicContent;
    QVBoxLayout *verticalLayout;
    QWidget *listUp;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *recListUpHLayout;
    QWidget *listDown;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *recListDownHLayout;
    QWidget *rightPage;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btDown;

    void setupUi(QWidget *RecBox)
    {
        if (RecBox->objectName().isEmpty())
            RecBox->setObjectName(QString::fromUtf8("RecBox"));
        RecBox->resize(685, 400);
        horizontalLayout = new QHBoxLayout(RecBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftPage = new QWidget(RecBox);
        leftPage->setObjectName(QString::fromUtf8("leftPage"));
        leftPage->setMinimumSize(QSize(30, 0));
        leftPage->setMaximumSize(QSize(30, 16777215));
        leftPage->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(leftPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btUp = new QPushButton(leftPage);
        btUp->setObjectName(QString::fromUtf8("btUp"));
        btUp->setMinimumSize(QSize(0, 220));
        btUp->setStyleSheet(QString::fromUtf8("#btUp\n"
"{\n"
"	border: none;\n"
"	background-image: url(:/images/up_page.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #1ECD97;\n"
"}"));

        horizontalLayout_2->addWidget(btUp);


        horizontalLayout->addWidget(leftPage);

        musicContent = new QWidget(RecBox);
        musicContent->setObjectName(QString::fromUtf8("musicContent"));
        musicContent->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(musicContent);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listUp = new QWidget(musicContent);
        listUp->setObjectName(QString::fromUtf8("listUp"));
        listUp->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_6 = new QHBoxLayout(listUp);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        recListUpHLayout = new QHBoxLayout();
        recListUpHLayout->setObjectName(QString::fromUtf8("recListUpHLayout"));

        horizontalLayout_6->addLayout(recListUpHLayout);


        verticalLayout->addWidget(listUp);

        listDown = new QWidget(musicContent);
        listDown->setObjectName(QString::fromUtf8("listDown"));
        listDown->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_7 = new QHBoxLayout(listDown);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        recListDownHLayout = new QHBoxLayout();
        recListDownHLayout->setSpacing(0);
        recListDownHLayout->setObjectName(QString::fromUtf8("recListDownHLayout"));

        horizontalLayout_7->addLayout(recListDownHLayout);


        verticalLayout->addWidget(listDown);


        horizontalLayout->addWidget(musicContent);

        rightPage = new QWidget(RecBox);
        rightPage->setObjectName(QString::fromUtf8("rightPage"));
        rightPage->setMinimumSize(QSize(30, 0));
        rightPage->setMaximumSize(QSize(30, 16777215));
        rightPage->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(rightPage);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btDown = new QPushButton(rightPage);
        btDown->setObjectName(QString::fromUtf8("btDown"));
        btDown->setMinimumSize(QSize(0, 220));
        btDown->setStyleSheet(QString::fromUtf8("#btDown\n"
"{\n"
"	border: none;\n"
"	background-image: url(:/images/down_page.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position:center center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #1ECD97;\n"
"}"));

        horizontalLayout_3->addWidget(btDown);


        horizontalLayout->addWidget(rightPage);


        retranslateUi(RecBox);

        QMetaObject::connectSlotsByName(RecBox);
    } // setupUi

    void retranslateUi(QWidget *RecBox)
    {
        RecBox->setWindowTitle(QCoreApplication::translate("RecBox", "Form", nullptr));
        btUp->setText(QString());
        btDown->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecBox: public Ui_RecBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOX_H
