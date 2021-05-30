#-------------------------------------------------
#
# Project created by QtCreator 2019-04-21T04:01:41
#
#-------------------------------------------------

QT       += core gui
QT       += core gui xml



TRANSLATIONS = deneraHummel_hu_HU.ts deneraHumel_en_EN.ts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
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
        mainwindow.cpp \
    myactions.cpp \
    hummelobject.cpp \
    hashmodel.cpp \
    contentdialog.cpp \
    dialogtextedit.cpp \
    textnode.cpp \
    doublestring.cpp \
    fileoperator.cpp \
    oneanime.cpp \
    aboutdialog.cpp \
    animatedtextbrowser.cpp \
    textbrowseranimated2.cpp

HEADERS += \
        mainwindow.h \
    myactions.h \
    hummelobject.h \
    hashmodel.h \
    contentdialog.h \
    dialogtextedit.h \
    textnode.h \
    doublestring.h \
    fileoperator.h \
    oneanime.h \
    aboutdialog.h \
    animatedtextbrowser.h \
    textbrowseranimated2.h

FORMS += \
        mainwindow.ui \
    contentdialog.ui \
    dialogtextedit.ui \
    aboutdialog.ui

RESOURCES += \
    myresource.qrc

 ICON = favicon.ico
