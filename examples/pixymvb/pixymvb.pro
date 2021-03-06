QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    qpixymvbdriver.cpp

HEADERS += \
    qpixymvbdriver.h


unix:!macx|win32: LIBS += -L$$PWD/libMvb4Qt/ -lMvb4Qt

INCLUDEPATH += $$PWD/libMvb4Qt
DEPENDPATH += $$PWD/libMvb4Qt

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libMvb4Qt/Mvb4Qt.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/libMvb4Qt/libMvb4Qt.a


unix:!macx|win32: LIBS += -L$$PWD/libPixyMvb/ -lPixyMvb

INCLUDEPATH += $$PWD/libPixyMvb
DEPENDPATH += $$PWD/libPixyMvb

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libPixyMvb/PixyMvb.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/libPixyMvb/libPixyMvb.a
