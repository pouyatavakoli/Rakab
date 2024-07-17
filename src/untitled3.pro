QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    main.cpp \
    mainwindow.cpp \
    parchamdar.cpp \
    player.cpp \
    purplecard.cpp \
    rishsefid.cpp \
    season.cpp \
    shahdokht.cpp \
    shirzan.cpp \
    spring.cpp \
    winter.cpp \
    yellow1.cpp \
    yellow10.cpp \
    yellow2.cpp \
    yellow3.cpp \
    yellow4.cpp \
    yellow5.cpp \
    yellow6.cpp \
    yellowcard.cpp

HEADERS += \
    card.h \
    mainwindow.h \
    parchamdar.h \
    player.h \
    purplecard.h \
    rishsefid.h \
    season.h \
    shahdokht.h \
    shirzan.h \
    spring.h \
    winter.h \
    yellow1.h \
    yellow10.h \
    yellow2.h \
    yellow3.h \
    yellow4.h \
    yellow5.h \
    yellow6.h \
    yellowcard.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc
