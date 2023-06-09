QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ./ressources

SOURCES += \
    attack.cpp \
    battleground.cpp \
    canevas.cpp \
    main.cpp \
    mainwindow.cpp \
    nooter.cpp \
    player.cpp \
    qstd.cpp \
    type.cpp \
    type_table.cpp

HEADERS += \
    attack.h \
    battleground.h \
    canevas.h \
    initParameterException.h \
    mainwindow.h \
    nooter.h \
    player.h \
    qstd.h \
    type.h \
    type_table.h \
    type_tuple.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
