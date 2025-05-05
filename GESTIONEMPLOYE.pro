QT += core gui sql printsupport charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += $$OUT_PWD $$PWD
CONFIG += c++17
QT += network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    access.cpp \
    connection.cpp \
    employe.cpp \
    gemploye.cpp \
    main.cpp \
    menu.cpp \
    oublie.cpp \
    changemdpdialog.cpp


HEADERS += \
    access.h \
    connection.h \
    dialogtheme.h \
    employe.h \
    gemploye.h \
    menu.h \
    oublie.h \
    changemdpdialog.h


FORMS += \
    access.ui \
    gemploye.ui \
    menu.ui \
    oublie.ui \
    changemdpdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Resources
RESOURCES += \
    images.qrc \
    img.qrc

DISTFILES += \
    image/logo (1).png
