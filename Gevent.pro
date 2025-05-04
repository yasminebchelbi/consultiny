QT       += core gui
QT       += charts
QT       +=sql
QT       += printsupport
QT       += charts
QT       +=core gui network
QT       += core gui network sql printsupport charts
QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aihelper.cpp \
    arduino.cpp \
    connection.cpp \
    evenements.cpp \
    main.cpp \
    gevent.cpp

HEADERS += \
    aihelper.h \
    arduino.h \
    connection.h \
    evenements.h \
    gevent.h

FORMS += \
    gevent.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagesEvents.qrc

DISTFILES += \
    ../../../../../../../../Downloads/1-removebg-preview (1).png \
    ../../../../../../../../Downloads/1-removebg-preview (1).png \
    ../../../../../../../../Downloads/2-removebg-preview (1).png \
    ../../../../../../../../Downloads/2-removebg-preview (1).png \
    ../../../../../../../../Downloads/2-removebg-preview.png \
    ../../../../../../../../Downloads/3-removebg-preview (1).png \
    ../../../../../../../../Downloads/3-removebg-preview (1).png \
    ../../../../../../../../Downloads/4-removebg-preview (1).png \
    ../../../../../../../../Downloads/4-removebg-preview (1).png \
    ../../../../../../../../Downloads/5-removebg-preview (1).png \
    ../../../../../../../../Downloads/5-removebg-preview (1).png \
    ../../../../../../../../Downloads/6-removebg-preview (1).png \
    ../../../../../../../../Downloads/6-removebg-preview (1).png \
    ../../../../../../../../Downloads/6-removebg-preview (1).png \
    image.qrc/1-removebg-preview (1).png \
    image.qrc/1-removebg-preview (1).png \
    image.qrc/2-removebg-preview (1).png \
    image.qrc/3-removebg-preview (1).png \
    image.qrc/4-removebg-preview (1).png \
    image.qrc/5-removebg-preview (1).png \
    image.qrc/6-removebg-preview (1).png \
    image.qrc/meteo.png
