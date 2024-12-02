QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appmanager.cpp \
    datapage.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    measurementpoint.cpp \
    menupage.cpp \
    profile.cpp \
    profilepage.cpp \
    radotechdevice.cpp \
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> d456991 (basic structure implmented)
    scan.cpp \
    scanner.cpp \
    scanpage.cpp \
    switchprofilepage.cpp
=======
    scanpage.cpp
>>>>>>> 36ca08a (working mid-integration of on/off skin toggle and scan page ui)
=======
    scanpage.cpp \
    switchprofilepage.cpp
>>>>>>> ef311ba (added switchprofilepage)

HEADERS += \
    AppManager.h \
    datapage.h \
    defs.h \
    global.h \
    mainwindow.h \
    measurementpoint.h \
    menupage.h \
    profile.h \
    profilepage.h \
    radotechdevice.h \
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> d456991 (basic structure implmented)
    scan.h \
    scanner.h \
    scanpage.h \
    switchprofilepage.h
=======
    scanpage.h
>>>>>>> 36ca08a (working mid-integration of on/off skin toggle and scan page ui)
=======
    scanpage.h \
    switchprofilepage.h
>>>>>>> ef311ba (added switchprofilepage)

FORMS += \
    datapage.ui \
    mainwindow.ui \
    menupage.ui \
    profilepage.ui \
    scanpage.ui \
    switchprofilepage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
