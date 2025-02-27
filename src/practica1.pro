QT       += core gui
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += core5compat
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./windows/DeleteWindow.cpp \
    ./windows/GraphWindow.cpp \
    ./windows/MainMenu.cpp \
    ./windows/InputWindow.cpp \
    ./windows/InsulatorsWindow.cpp \
    ./windows/SemiconductorsWindow.cpp \
    ./windows/ConductorsWindow.cpp \
    ./windows/TableView.cpp \
    main.cpp \


HEADERS += \
    ./windows/DeleteWindow.h \
    ./windows/GraphWindow.h \
    ./windows/MainMenu.h \
    ./windows/InputWindow.h \
    ./windows/InsulatorsWindow.h \
    ./windows/SemiconductorsWindow.h \
    ./windows/ConductorsWindow.h \
    ./windows/TableView.h \
    .Ellements.h \



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
