/********************************************************************************
** Form generated from reading UI file 'listitembox.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTITEMBOX_H
#define UI_LISTITEMBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListItemBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *MusicName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *likeBtn;
    QLabel *nameLabel;
    QLabel *vip;
    QLabel *sq;
    QSpacerItem *horizontalSpacer;
    QWidget *musicSinger;
    QHBoxLayout *horizontalLayout_2;
    QLabel *singerName;
    QWidget *albumBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *albumName;

    void setupUi(QWidget *ListItemBox)
    {
        if (ListItemBox->objectName().isEmpty())
            ListItemBox->setObjectName("ListItemBox");
        ListItemBox->resize(800, 34);
        ListItemBox->setMinimumSize(QSize(800, 0));
        ListItemBox->setMaximumSize(QSize(800, 16777215));
        ListItemBox->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(ListItemBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        MusicName = new QWidget(ListItemBox);
        MusicName->setObjectName("MusicName");
        MusicName->setMinimumSize(QSize(400, 0));
        MusicName->setMaximumSize(QSize(400, 16777215));
        MusicName->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayout_4 = new QHBoxLayout(MusicName);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        likeBtn = new QLabel(MusicName);
        likeBtn->setObjectName("likeBtn");
        likeBtn->setMinimumSize(QSize(25, 25));
        likeBtn->setMaximumSize(QSize(25, 25));

        horizontalLayout_4->addWidget(likeBtn);

        nameLabel = new QLabel(MusicName);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout_4->addWidget(nameLabel);

        vip = new QLabel(MusicName);
        vip->setObjectName("vip");
        vip->setMinimumSize(QSize(30, 30));
        vip->setMaximumSize(QSize(30, 30));
        vip->setStyleSheet(QString::fromUtf8("border: 1px solid #1ecd96;\n"
"color: #1ecd96;\n"
"border-radius: 2px;"));

        horizontalLayout_4->addWidget(vip);

        sq = new QLabel(MusicName);
        sq->setObjectName("sq");
        sq->setMinimumSize(QSize(30, 30));
        sq->setMaximumSize(QSize(30, 30));
        sq->setStyleSheet(QString::fromUtf8("border: 1px solid #ff6600;\n"
"color: #ff6600;\n"
"border-radius: 2px;"));

        horizontalLayout_4->addWidget(sq);

        horizontalSpacer = new QSpacerItem(192, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        horizontalLayout->addWidget(MusicName);

        musicSinger = new QWidget(ListItemBox);
        musicSinger->setObjectName("musicSinger");
        musicSinger->setMinimumSize(QSize(150, 0));
        musicSinger->setMaximumSize(QSize(150, 16777215));
        musicSinger->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        horizontalLayout_2 = new QHBoxLayout(musicSinger);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        singerName = new QLabel(musicSinger);
        singerName->setObjectName("singerName");
        singerName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(singerName);


        horizontalLayout->addWidget(musicSinger);

        albumBox = new QWidget(ListItemBox);
        albumBox->setObjectName("albumBox");
        albumBox->setMinimumSize(QSize(250, 0));
        albumBox->setMaximumSize(QSize(250, 16777215));
        horizontalLayout_3 = new QHBoxLayout(albumBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        albumName = new QLabel(albumBox);
        albumName->setObjectName("albumName");

        horizontalLayout_3->addWidget(albumName);


        horizontalLayout->addWidget(albumBox);


        retranslateUi(ListItemBox);

        QMetaObject::connectSlotsByName(ListItemBox);
    } // setupUi

    void retranslateUi(QWidget *ListItemBox)
    {
        ListItemBox->setWindowTitle(QCoreApplication::translate("ListItemBox", "Form", nullptr));
        likeBtn->setText(QString());
        nameLabel->setText(QCoreApplication::translate("ListItemBox", "\346\210\221\346\230\257\344\270\200\351\246\226\346\255\214\347\232\204\345\220\215\345\255\227", nullptr));
        vip->setText(QCoreApplication::translate("ListItemBox", "VIP", nullptr));
        sq->setText(QCoreApplication::translate("ListItemBox", "SQ", nullptr));
        singerName->setText(QCoreApplication::translate("ListItemBox", "\346\235\216\346\235\203", nullptr));
        albumName->setText(QCoreApplication::translate("ListItemBox", "\346\235\216\346\235\203\347\232\204\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListItemBox: public Ui_ListItemBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTITEMBOX_H
