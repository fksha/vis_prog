QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RESOURCES += icons.qrc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addrecipedialog.cpp \
    main.cpp \
    mainwindow.cpp \
    profiledialog.cpp \
    recipeviewdialog.cpp \
    searchdialog.cpp \
    user.cpp

HEADERS += \
    addrecipedialog.h \
    mainwindow.h \
    profiledialog.h \
    recipeviewdialog.h \
    searchdialog.h \
    user.h

FORMS += \
    addrecipedialog.ui \
    mainwindow.ui \
    profiledialog.ui \
    recipeviewdialog.ui \
    searchdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
