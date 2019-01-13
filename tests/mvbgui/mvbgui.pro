#-------------------------------------------------
#
# Project created by QtCreator 2019-01-12T11:51:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mvbgui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    qmvbcardmanagerviewer.cpp \
    qmvbcardviewer.cpp \
    qmvbregisterviewer.cpp \
    qmvbportviewer.cpp \
    qporttablewidget.cpp

HEADERS += \
        qmvbcardmanagerviewer.h \
    qmvbcardviewer.h \
    qmvbregisterviewer.h \
    qmvbportviewer.h \
    qporttablewidget.h

FORMS +=

unix:!macx|win32: LIBS += -L$$PWD/libMvb4Qt/ -lMvb4Qt

# INCLUDEPATH += $$PWD/libMvb4Qt
INCLUDEPATH += $$PWD/../../src
DEPENDPATH += $$PWD/libMvb4Qt

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libMvb4Qt/Mvb4Qt.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/libMvb4Qt/libMvb4Qt.a

RESOURCES += \
    resources.qrc
