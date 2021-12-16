################ DEFAULT SETTING ################

QT     += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS
# disables all the APIs deprecated before Qt 6.0.0
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    

################ FILE ORGANIZATION ################

# include
INCLUDEPATH += \
    ../include

# headers
HEADERS += \
    oglwindow.h \
    ../include/camera.h \
    ../include/oglclass.h \
    ../include/utility.h \

# sources
SOURCES += \
    main.cpp \
    oglwindow.cpp \
    ../src/camera.cpp \
    ../src/oglclass.cpp \

# ui file
FORMS = oglwindow.ui
# resources file
RESOURCES = res.qrc

################ BUILDING SETTING ################
TEMPLATE = app
TARGET   = oglDemo

CONFIG += debug

DESTDIR     = build/app
OBJECTS_DIR = build/tmp
UI_DIR      = build/gen
RCC_DIR     = build/gen
MOC_DIR     = build/gen



        