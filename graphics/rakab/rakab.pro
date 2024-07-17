QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    getplayersinfowindow.cpp \
    main.cpp \
    mainmenu.cpp \
    mapwindow.cpp \
    savedgamesmenu.cpp\
    card.cpp\
    player.cpp\
    purplecard.cpp\
    yelowcard.cpp\
    season.cpp\
    parchamdar.cpp\
    winter.cpp\
    spring.cpp\
    shahdokht.cpp\
    shirzan.cpp\
    rishsefid.cpp\
    yellow1.cpp\
    yellow2.cpp\
    yellow3.cpp\
    yellow4.cpp\
    yellow5.cpp\
    yellow6.cpp\
    yellow10.cpp\



HEADERS += \
    getplayersinfowindow.h \
    mainmenu.h \
    mapwindow.h \
    savedgamesmenu.h\
    card.h\
    player.h\
    purplecard.h\
    yelowcard.h\
    season.h\
    parchamdar.h\
    winter.h\
    spring.h\
    shahdokht.h\
    shirzan.h\
    rishsefid.h\
    yellow1.h\
    yellow2.h\
    yellow3.h\
    yellow4.h\
    yellow5.h\
    yellow6.h\
    yellow10.h\

FORMS += \
    getplayersinfowindow.ui \
    mainmenu.ui \
    mapwindow.ui \
    savedgamesmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
