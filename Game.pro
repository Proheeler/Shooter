#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T13:10:44
#
#-------------------------------------------------

QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp \
    actor.cpp \
    bullet.cpp \
    enemies.cpp \
    score.cpp \
    game.cpp \
    health.cpp \
    Button.cpp

HEADERS  += \
    actor.h \
    bullet.h \
    enemies.h \
    score.h \
    game.h \
    health.h \
    Button.h

FORMS    += fg.ui

RESOURCES += \
    res.qrc
