/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <btform.h>
#include <commonpage.h>
#include <musicslider.h>
#include <recbox.h>

QT_BEGIN_NAMESPACE

class Ui_MusicPlayer
{
public:
    QVBoxLayout *verticalLayout_7;
    QWidget *background;
    QVBoxLayout *verticalLayout_2;
    QWidget *header;
    QHBoxLayout *horizontalLayout;
    QWidget *headLeft;
    QLabel *logo;
    QWidget *headRight;
    QHBoxLayout *horizontalLayout_2;
    QWidget *searchBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QWidget *settingBox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *skin;
    QPushButton *max;
    QPushButton *min;
    QPushButton *quit;
    QWidget *body;
    QHBoxLayout *horizontalLayout_5;
    QWidget *leftBody;
    QVBoxLayout *verticalLayout_3;
    QWidget *leftBox;
    QVBoxLayout *verticalLayout;
    QWidget *onlineMusic;
    QVBoxLayout *verticalLayout_4;
    QLabel *onlie;
    BtForm *recommend;
    BtForm *radio;
    BtForm *music;
    QWidget *myMusic;
    QVBoxLayout *verticalLayout_5;
    QLabel *onlie_2;
    BtForm *like;
    BtForm *local;
    BtForm *recent;
    QSpacerItem *verticalSpacer;
    QWidget *rightBody;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *stackedWidget;
    QWidget *recPage;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QLabel *recText;
    QLabel *recToday;
    RecBox *recMusicBox;
    QLabel *supplyText;
    RecBox *supplyBox;
    QWidget *radioPage;
    QLabel *label_2;
    QWidget *musicPage;
    QLabel *label_3;
    CommonPage *likePage;
    CommonPage *localPage;
    CommonPage *recentPage;
    MusicSlider *progressBar;
    QWidget *controlBox;
    QHBoxLayout *horizontalLayout_6;
    QWidget *play1;
    QGridLayout *gridLayout;
    QLabel *musicName;
    QLabel *picture;
    QLabel *singerName;
    QWidget *play2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *playMod;
    QPushButton *playUp;
    QPushButton *play;
    QPushButton *playDown;
    QPushButton *volume;
    QPushButton *addLocal;
    QWidget *play3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *placeHolder;
    QLabel *currentTime;
    QLabel *sep;
    QLabel *totalTime;
    QPushButton *volume_2;

    void setupUi(QWidget *MusicPlayer)
    {
        if (MusicPlayer->objectName().isEmpty())
            MusicPlayer->setObjectName(QString::fromUtf8("MusicPlayer"));
        MusicPlayer->resize(1046, 706);
        verticalLayout_7 = new QVBoxLayout(MusicPlayer);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        background = new QWidget(MusicPlayer);
        background->setObjectName(QString::fromUtf8("background"));
        background->setEnabled(true);
        background->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(background);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        header = new QWidget(background);
        header->setObjectName(QString::fromUtf8("header"));
        header->setMinimumSize(QSize(0, 80));
        header->setMaximumSize(QSize(16777215, 80));
        header->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(header);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        headLeft = new QWidget(header);
        headLeft->setObjectName(QString::fromUtf8("headLeft"));
        headLeft->setMinimumSize(QSize(150, 0));
        headLeft->setMaximumSize(QSize(150, 16777215));
        headLeft->setStyleSheet(QString::fromUtf8("#headLeft\n"
"{\n"
"	background-color: #f0f0f0;\n"
"}"));
        logo = new QLabel(headLeft);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(20, 20, 121, 31));
        logo->setStyleSheet(QString::fromUtf8("#logo\n"
"{\n"
"	background-image:url(\":/images/Logo.png\");\n"
"	background-repeat: no-repeat;\n"
"	background-position:center;	\n"
"}"));

        horizontalLayout->addWidget(headLeft);

        headRight = new QWidget(header);
        headRight->setObjectName(QString::fromUtf8("headRight"));
        headRight->setStyleSheet(QString::fromUtf8("#headRight\n"
"{\n"
"	background-color: #f5f5f5;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(headRight);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        searchBox = new QWidget(headRight);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setMinimumSize(QSize(400, 0));
        searchBox->setMaximumSize(QSize(400, 16777215));
        searchBox->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(searchBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(8, -1, 8, -1);
        lineEdit = new QLineEdit(searchBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(16777215, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit\n"
"{\n"
"	background-color: #e3e3e3;\n"
"	border: none;\n"
"	border-radius: 15px;\n"
"	padding-left: 18;\n"
"}"));

        horizontalLayout_3->addWidget(lineEdit);


        horizontalLayout_2->addWidget(searchBox);

        settingBox = new QWidget(headRight);
        settingBox->setObjectName(QString::fromUtf8("settingBox"));
        settingBox->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:	none;\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #87CEFA;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(settingBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(354, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        skin = new QPushButton(settingBox);
        skin->setObjectName(QString::fromUtf8("skin"));
        skin->setMinimumSize(QSize(30, 30));
        skin->setMaximumSize(QSize(30, 30));
        skin->setStyleSheet(QString::fromUtf8("#skin\n"
"{\n"
"	background-image: url(\":/images/skin.png\");\n"
"}"));

        horizontalLayout_4->addWidget(skin);

        max = new QPushButton(settingBox);
        max->setObjectName(QString::fromUtf8("max"));
        max->setMinimumSize(QSize(30, 30));
        max->setMaximumSize(QSize(30, 30));
        max->setStyleSheet(QString::fromUtf8("#max\n"
"{\n"
"	background-image: url(\":/images/max.png\");\n"
"}"));

        horizontalLayout_4->addWidget(max);

        min = new QPushButton(settingBox);
        min->setObjectName(QString::fromUtf8("min"));
        min->setMinimumSize(QSize(30, 30));
        min->setMaximumSize(QSize(30, 30));
        min->setStyleSheet(QString::fromUtf8("#min\n"
"{\n"
"	background-image: url(\":/images/min.png\");\n"
"}"));

        horizontalLayout_4->addWidget(min);

        quit = new QPushButton(settingBox);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setMinimumSize(QSize(30, 30));
        quit->setMaximumSize(QSize(30, 30));
        quit->setStyleSheet(QString::fromUtf8("#quit\n"
"{\n"
"	background-image: url(\":/images/quit.png\");\n"
"}"));

        horizontalLayout_4->addWidget(quit);


        horizontalLayout_2->addWidget(settingBox);


        horizontalLayout->addWidget(headRight);


        verticalLayout_2->addWidget(header);

        body = new QWidget(background);
        body->setObjectName(QString::fromUtf8("body"));
        body->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_5 = new QHBoxLayout(body);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        leftBody = new QWidget(body);
        leftBody->setObjectName(QString::fromUtf8("leftBody"));
        leftBody->setMinimumSize(QSize(150, 608));
        leftBody->setMaximumSize(QSize(150, 608));
        leftBody->setStyleSheet(QString::fromUtf8("#leftBody\n"
"{\n"
"	background-color: #f0f0f0;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(leftBody);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        leftBox = new QWidget(leftBody);
        leftBox->setObjectName(QString::fromUtf8("leftBox"));
        leftBox->setMinimumSize(QSize(0, 400));
        leftBox->setMaximumSize(QSize(16777215, 400));
        leftBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(leftBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        onlineMusic = new QWidget(leftBox);
        onlineMusic->setObjectName(QString::fromUtf8("onlineMusic"));
        onlineMusic->setMinimumSize(QSize(0, 200));
        onlineMusic->setMaximumSize(QSize(16777215, 200));
        onlineMusic->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(onlineMusic);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 30);
        onlie = new QLabel(onlineMusic);
        onlie->setObjectName(QString::fromUtf8("onlie"));
        onlie->setMinimumSize(QSize(145, 0));
        onlie->setMaximumSize(QSize(145, 16777215));

        verticalLayout_4->addWidget(onlie);

        recommend = new BtForm(onlineMusic);
        recommend->setObjectName(QString::fromUtf8("recommend"));
        recommend->setMinimumSize(QSize(150, 0));
        recommend->setMaximumSize(QSize(150, 16777215));
        recommend->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(recommend);

        radio = new BtForm(onlineMusic);
        radio->setObjectName(QString::fromUtf8("radio"));
        radio->setMinimumSize(QSize(150, 0));
        radio->setMaximumSize(QSize(150, 16777215));
        radio->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(radio);

        music = new BtForm(onlineMusic);
        music->setObjectName(QString::fromUtf8("music"));
        music->setMinimumSize(QSize(150, 0));
        music->setMaximumSize(QSize(150, 16777215));
        music->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(music);


        verticalLayout->addWidget(onlineMusic);

        myMusic = new QWidget(leftBox);
        myMusic->setObjectName(QString::fromUtf8("myMusic"));
        myMusic->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(myMusic);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        onlie_2 = new QLabel(myMusic);
        onlie_2->setObjectName(QString::fromUtf8("onlie_2"));
        onlie_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(onlie_2);

        like = new BtForm(myMusic);
        like->setObjectName(QString::fromUtf8("like"));
        like->setMinimumSize(QSize(150, 0));
        like->setMaximumSize(QSize(150, 16777215));
        like->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(like);

        local = new BtForm(myMusic);
        local->setObjectName(QString::fromUtf8("local"));
        local->setMinimumSize(QSize(150, 0));
        local->setMaximumSize(QSize(150, 16777215));
        local->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(local);

        recent = new BtForm(myMusic);
        recent->setObjectName(QString::fromUtf8("recent"));
        recent->setMinimumSize(QSize(150, 0));
        recent->setMaximumSize(QSize(150, 16777215));
        recent->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(recent);


        verticalLayout->addWidget(myMusic);


        verticalLayout_3->addWidget(leftBox);

        verticalSpacer = new QSpacerItem(20, 605, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_5->addWidget(leftBody);

        rightBody = new QWidget(body);
        rightBody->setObjectName(QString::fromUtf8("rightBody"));
        rightBody->setMinimumSize(QSize(878, 608));
        rightBody->setMaximumSize(QSize(878, 608));
        rightBody->setStyleSheet(QString::fromUtf8("#rightBody\n"
"{\n"
"	background-color: #f5f5f5\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(rightBody);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 5, 0);
        stackedWidget = new QStackedWidget(rightBody);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        recPage = new QWidget();
        recPage->setObjectName(QString::fromUtf8("recPage"));
        scrollArea = new QScrollArea(recPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 871, 521));
        scrollArea->setMinimumSize(QSize(850, 518));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 869, 519));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        recText = new QLabel(scrollAreaWidgetContents);
        recText->setObjectName(QString::fromUtf8("recText"));
        recText->setMinimumSize(QSize(0, 50));
        recText->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(25);
        recText->setFont(font);

        verticalLayout_8->addWidget(recText);

        recToday = new QLabel(scrollAreaWidgetContents);
        recToday->setObjectName(QString::fromUtf8("recToday"));
        recToday->setMinimumSize(QSize(0, 30));
        recToday->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(20);
        recToday->setFont(font1);

        verticalLayout_8->addWidget(recToday);

        recMusicBox = new RecBox(scrollAreaWidgetContents);
        recMusicBox->setObjectName(QString::fromUtf8("recMusicBox"));

        verticalLayout_8->addWidget(recMusicBox);

        supplyText = new QLabel(scrollAreaWidgetContents);
        supplyText->setObjectName(QString::fromUtf8("supplyText"));
        supplyText->setMinimumSize(QSize(0, 30));
        supplyText->setMaximumSize(QSize(16777215, 30));
        QFont font2;
        font2.setPointSize(18);
        supplyText->setFont(font2);

        verticalLayout_8->addWidget(supplyText);

        supplyBox = new RecBox(scrollAreaWidgetContents);
        supplyBox->setObjectName(QString::fromUtf8("supplyBox"));

        verticalLayout_8->addWidget(supplyBox);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(recPage);
        radioPage = new QWidget();
        radioPage->setObjectName(QString::fromUtf8("radioPage"));
        label_2 = new QLabel(radioPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 110, 40, 12));
        stackedWidget->addWidget(radioPage);
        musicPage = new QWidget();
        musicPage->setObjectName(QString::fromUtf8("musicPage"));
        label_3 = new QLabel(musicPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 120, 40, 12));
        stackedWidget->addWidget(musicPage);
        likePage = new CommonPage();
        likePage->setObjectName(QString::fromUtf8("likePage"));
        stackedWidget->addWidget(likePage);
        localPage = new CommonPage();
        localPage->setObjectName(QString::fromUtf8("localPage"));
        stackedWidget->addWidget(localPage);
        recentPage = new CommonPage();
        recentPage->setObjectName(QString::fromUtf8("recentPage"));
        stackedWidget->addWidget(recentPage);

        verticalLayout_6->addWidget(stackedWidget);

        progressBar = new MusicSlider(rightBody);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(0, 30));
        progressBar->setMaximumSize(QSize(16777215, 30));
        progressBar->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(progressBar);

        controlBox = new QWidget(rightBody);
        controlBox->setObjectName(QString::fromUtf8("controlBox"));
        controlBox->setMinimumSize(QSize(0, 60));
        controlBox->setMaximumSize(QSize(16777215, 60));
        controlBox->setStyleSheet(QString::fromUtf8("QPushButton:hover\n"
"{\n"
"	background-color:#E3E3E3;\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(controlBox);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        play1 = new QWidget(controlBox);
        play1->setObjectName(QString::fromUtf8("play1"));
        play1->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(play1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        musicName = new QLabel(play1);
        musicName->setObjectName(QString::fromUtf8("musicName"));

        gridLayout->addWidget(musicName, 1, 1, 1, 1);

        picture = new QLabel(play1);
        picture->setObjectName(QString::fromUtf8("picture"));

        gridLayout->addWidget(picture, 0, 0, 2, 1);

        singerName = new QLabel(play1);
        singerName->setObjectName(QString::fromUtf8("singerName"));

        gridLayout->addWidget(singerName, 0, 1, 1, 1);


        horizontalLayout_6->addWidget(play1);

        play2 = new QWidget(controlBox);
        play2->setObjectName(QString::fromUtf8("play2"));
        play2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	background-repeat: no-repeat;\n"
"	background-position: center center;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #87CEFA;\n"
"}\n"
""));
        horizontalLayout_8 = new QHBoxLayout(play2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        playMod = new QPushButton(play2);
        playMod->setObjectName(QString::fromUtf8("playMod"));
        playMod->setMinimumSize(QSize(30, 30));
        playMod->setMaximumSize(QSize(30, 30));
        playMod->setStyleSheet(QString::fromUtf8("#playMod\n"
"{\n"
"	background-image: url(\":/images/shuffle_2.png\");\n"
"}"));

        horizontalLayout_8->addWidget(playMod);

        playUp = new QPushButton(play2);
        playUp->setObjectName(QString::fromUtf8("playUp"));
        playUp->setMinimumSize(QSize(30, 30));
        playUp->setMaximumSize(QSize(30, 30));
        playUp->setStyleSheet(QString::fromUtf8("#playUp\n"
"{\n"
"	background-image: url(\":/images/up.png\");\n"
"}"));

        horizontalLayout_8->addWidget(playUp);

        play = new QPushButton(play2);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMinimumSize(QSize(30, 30));
        play->setMaximumSize(QSize(30, 30));
        play->setStyleSheet(QString::fromUtf8("#play\n"
"{\n"
"	background-image: url(\":/images/play3.png\");\n"
"}"));

        horizontalLayout_8->addWidget(play);

        playDown = new QPushButton(play2);
        playDown->setObjectName(QString::fromUtf8("playDown"));
        playDown->setMinimumSize(QSize(30, 30));
        playDown->setMaximumSize(QSize(30, 30));
        playDown->setStyleSheet(QString::fromUtf8("#playDown\n"
"{\n"
"	background-image: url(\":/images/down.png\");\n"
"}"));

        horizontalLayout_8->addWidget(playDown);

        volume = new QPushButton(play2);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setMinimumSize(QSize(30, 30));
        volume->setMaximumSize(QSize(30, 30));
        volume->setStyleSheet(QString::fromUtf8("#volume\n"
"{\n"
"	background-image: url(\":/images/volumn.png\");\n"
"}"));

        horizontalLayout_8->addWidget(volume);

        addLocal = new QPushButton(play2);
        addLocal->setObjectName(QString::fromUtf8("addLocal"));
        addLocal->setMinimumSize(QSize(30, 30));
        addLocal->setMaximumSize(QSize(30, 30));
        addLocal->setStyleSheet(QString::fromUtf8("#addLocal\n"
"{\n"
"	background-image: url(\":/images/add.png\");\n"
"}"));

        horizontalLayout_8->addWidget(addLocal);


        horizontalLayout_6->addWidget(play2);

        play3 = new QWidget(controlBox);
        play3->setObjectName(QString::fromUtf8("play3"));
        play3->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_7 = new QHBoxLayout(play3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        placeHolder = new QLabel(play3);
        placeHolder->setObjectName(QString::fromUtf8("placeHolder"));
        placeHolder->setMinimumSize(QSize(200, 0));
        placeHolder->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_7->addWidget(placeHolder);

        currentTime = new QLabel(play3);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));

        horizontalLayout_7->addWidget(currentTime);

        sep = new QLabel(play3);
        sep->setObjectName(QString::fromUtf8("sep"));

        horizontalLayout_7->addWidget(sep);

        totalTime = new QLabel(play3);
        totalTime->setObjectName(QString::fromUtf8("totalTime"));

        horizontalLayout_7->addWidget(totalTime);

        volume_2 = new QPushButton(play3);
        volume_2->setObjectName(QString::fromUtf8("volume_2"));
        volume_2->setMinimumSize(QSize(30, 0));
        volume_2->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_7->addWidget(volume_2);


        horizontalLayout_6->addWidget(play3);


        verticalLayout_6->addWidget(controlBox);

        progressBar->raise();
        controlBox->raise();
        stackedWidget->raise();

        horizontalLayout_5->addWidget(rightBody);


        verticalLayout_2->addWidget(body);


        verticalLayout_7->addWidget(background);


        retranslateUi(MusicPlayer);

        QMetaObject::connectSlotsByName(MusicPlayer);
    } // setupUi

    void retranslateUi(QWidget *MusicPlayer)
    {
        MusicPlayer->setWindowTitle(QCoreApplication::translate("MusicPlayer", "Widget", nullptr));
        logo->setText(QString());
        skin->setText(QString());
        max->setText(QString());
        min->setText(QString());
        quit->setText(QString());
        onlie->setText(QCoreApplication::translate("MusicPlayer", "   \345\234\250\347\272\277\351\237\263\344\271\220", nullptr));
        onlie_2->setText(QCoreApplication::translate("MusicPlayer", "   \346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        recText->setText(QCoreApplication::translate("MusicPlayer", "\346\216\250\350\215\220", nullptr));
        recToday->setText(QCoreApplication::translate("MusicPlayer", "\344\273\212\346\227\245\344\270\272\344\275\240\346\216\250\350\215\220", nullptr));
        supplyText->setText(QCoreApplication::translate("MusicPlayer", "\344\275\240\347\232\204\351\237\263\344\271\220\350\241\245\347\273\231", nullptr));
        label_2->setText(QCoreApplication::translate("MusicPlayer", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MusicPlayer", "TextLabel", nullptr));
        musicName->setText(QCoreApplication::translate("MusicPlayer", "\346\255\214\345\220\215", nullptr));
        picture->setText(QCoreApplication::translate("MusicPlayer", "\345\233\276\347\211\207", nullptr));
        singerName->setText(QCoreApplication::translate("MusicPlayer", "\346\255\214\346\211\213", nullptr));
        playMod->setText(QString());
        playUp->setText(QString());
        play->setText(QString());
        playDown->setText(QString());
        volume->setText(QString());
        addLocal->setText(QString());
        placeHolder->setText(QString());
        currentTime->setText(QCoreApplication::translate("MusicPlayer", "00:40", nullptr));
        sep->setText(QCoreApplication::translate("MusicPlayer", "/", nullptr));
        totalTime->setText(QCoreApplication::translate("MusicPlayer", "04:20", nullptr));
        volume_2->setText(QCoreApplication::translate("MusicPlayer", "\350\257\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicPlayer: public Ui_MusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
