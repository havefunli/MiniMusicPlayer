QT       += core gui
QT       += multimedia
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    btform.cpp \
    commonpage.cpp \
    listitembox.cpp \
    lrcpage.cpp \
    main.cpp \
    music.cpp \
    musiclist.cpp \
    musicslider.cpp \
    recbox.cpp \
    recboxitem.cpp \
    searchresult.cpp \
    serverconnection.cpp \
    singer.cpp \
    singerinfopage.cpp \
    singeritem.cpp \
    singerpage.cpp \
    upload.cpp \
    volumetool.cpp \
    widget.cpp

HEADERS += \
    btform.h \
    commonpage.h \
    listitembox.h \
    lrcpage.h \
    music.h \
    musiclist.h \
    musicslider.h \
    recbox.h \
    recboxitem.h \
    searchresult.h \
    serverconnection.h \
    singer.h \
    singerinfopage.h \
    singeritem.h \
    singerpage.h \
    upload.h \
    volumetool.h \
    widget.h

FORMS += \
    btform.ui \
    commonpage.ui \
    listitembox.ui \
    lrcpage.ui \
    musicslider.ui \
    recbox.ui \
    recboxitem.ui \
    searchresult.ui \
    singerinfopage.ui \
    singeritem.ui \
    singerpage.ui \
    upload.ui \
    volumetool.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
