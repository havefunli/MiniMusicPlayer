/********************************************************************************
** Form generated from reading UI file 'commonpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONPAGE_H
#define UI_COMMONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommonPage
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *pageTitle;
    QWidget *musicPlayBox;
    QHBoxLayout *horizontalLayout;
    QLabel *musicImage;
    QWidget *playAll;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *playBtn;
    QSpacerItem *horizontalSpacer;
    QWidget *listLabelBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nameLabel;
    QLabel *singerName;
    QLabel *albumLabel;
    QListWidget *pageMusicList;

    void setupUi(QWidget *CommonPage)
    {
        if (CommonPage->objectName().isEmpty())
            CommonPage->setObjectName(QString::fromUtf8("CommonPage"));
        CommonPage->resize(800, 500);
        CommonPage->setMinimumSize(QSize(800, 500));
        verticalLayout = new QVBoxLayout(CommonPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pageTitle = new QLabel(CommonPage);
        pageTitle->setObjectName(QString::fromUtf8("pageTitle"));
        pageTitle->setMinimumSize(QSize(0, 30));
        pageTitle->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(pageTitle);

        musicPlayBox = new QWidget(CommonPage);
        musicPlayBox->setObjectName(QString::fromUtf8("musicPlayBox"));
        musicPlayBox->setMinimumSize(QSize(0, 150));
        musicPlayBox->setMaximumSize(QSize(16777215, 150));
        horizontalLayout = new QHBoxLayout(musicPlayBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        musicImage = new QLabel(musicPlayBox);
        musicImage->setObjectName(QString::fromUtf8("musicImage"));
        musicImage->setMinimumSize(QSize(150, 150));
        musicImage->setMaximumSize(QSize(150, 150));

        horizontalLayout->addWidget(musicImage);

        playAll = new QWidget(musicPlayBox);
        playAll->setObjectName(QString::fromUtf8("playAll"));
        playAll->setMinimumSize(QSize(140, 0));
        verticalLayout_2 = new QVBoxLayout(playAll);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 93, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);

        playBtn = new QPushButton(playAll);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        playBtn->setMinimumSize(QSize(100, 30));
        playBtn->setStyleSheet(QString::fromUtf8("#playBtn\n"
"{\n"
"	background-color: #e3e3e3;\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"#playBtn:hover\n"
"{\n"
"	background-color: #1ecd97;\n"
"}\n"
""));

        verticalLayout_2->addWidget(playBtn);


        horizontalLayout->addWidget(playAll);

        horizontalSpacer = new QSpacerItem(507, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(musicPlayBox);

        listLabelBox = new QWidget(CommonPage);
        listLabelBox->setObjectName(QString::fromUtf8("listLabelBox"));
        listLabelBox->setMinimumSize(QSize(0, 40));
        listLabelBox->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(listLabelBox);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(listLabelBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setMinimumSize(QSize(400, 0));
        nameLabel->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_2->addWidget(nameLabel);

        singerName = new QLabel(listLabelBox);
        singerName->setObjectName(QString::fromUtf8("singerName"));
        singerName->setMinimumSize(QSize(120, 0));
        singerName->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_2->addWidget(singerName);

        albumLabel = new QLabel(listLabelBox);
        albumLabel->setObjectName(QString::fromUtf8("albumLabel"));
        albumLabel->setMinimumSize(QSize(280, 0));
        albumLabel->setMaximumSize(QSize(280, 16777215));

        horizontalLayout_2->addWidget(albumLabel);


        verticalLayout->addWidget(listLabelBox);

        pageMusicList = new QListWidget(CommonPage);
        pageMusicList->setObjectName(QString::fromUtf8("pageMusicList"));

        verticalLayout->addWidget(pageMusicList);


        retranslateUi(CommonPage);

        QMetaObject::connectSlotsByName(CommonPage);
    } // setupUi

    void retranslateUi(QWidget *CommonPage)
    {
        CommonPage->setWindowTitle(QCoreApplication::translate("CommonPage", "Form", nullptr));
        pageTitle->setText(QCoreApplication::translate("CommonPage", "\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        musicImage->setText(QCoreApplication::translate("CommonPage", "\345\233\276\347\211\207", nullptr));
        playBtn->setText(QCoreApplication::translate("CommonPage", "\346\222\255\346\224\276\345\205\250\351\203\250", nullptr));
        nameLabel->setText(QCoreApplication::translate("CommonPage", "\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        singerName->setText(QCoreApplication::translate("CommonPage", "\346\255\214\346\211\213\345\220\215\347\247\260", nullptr));
        albumLabel->setText(QCoreApplication::translate("CommonPage", "\344\270\223\350\276\221\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommonPage: public Ui_CommonPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONPAGE_H
