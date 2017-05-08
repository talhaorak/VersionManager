#-------------------------------------------------
#
# Project created by QtCreator 2012-12-21T17:07:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VersionManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    generator.cpp \
    AboutDialog.cpp \
    buildactions.cpp \
    ibuildaction.cpp \
    tools.cpp \
    $$PWD/ProductInfo.cpp

HEADERS  += mainwidget.h \
    generator.h \
    AboutDialog.h \
    buildactions.h \
    ibuildaction.h \
    tools.h \
    version.h \
    $$PWD/ProductInfo.h

FORMS    += mainwidget.ui \
    AboutDialog.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    Usecase.txt

RC_FILE += \
    resource.rc
