QT       += core gui
QT       +=sql
QT       +=charts
QT       += printsupport
QT       += core network
QT       += core gui network
QT       += network
QT       += core gui  serialport






greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    gprojet.cpp \
    projets.cpp

HEADERS += \
    arduino.h \
    connection.h \
    gprojet.h \
    projets.h

FORMS += \
    gprojet.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    ../../image/1-removebg-preview (1).png \
    ../../image/1-removebg-preview (1).png \
    ../../image/2-removebg-preview (1).png \
    ../../image/2-removebg-preview (1).png \
    ../../image/3-removebg-preview (1).png \
    ../../image/3-removebg-preview (1).png \
    ../../image/4-removebg-preview (1).png \
    ../../image/4-removebg-preview (1).png
