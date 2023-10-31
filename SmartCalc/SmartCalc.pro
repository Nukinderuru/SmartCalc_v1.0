QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    calculate.c \
    check_input.c \
    credit.cpp \
    deposit.cpp \
    graphics.cpp \
    interface.cpp \
    main.cpp \
    mainwindow.cpp \
    parcer.c \
    plot.cpp \
    qcustomplot.cpp \
    replenishments.cpp \
    reverse_polish_notation.c \
    stack_functions.c \
    withdrawals.cpp

HEADERS += \
    button.h \
    credit.h \
    deposit.h \
    graphics.h \
    interface.h \
    mainwindow.h \
    plot.h \
    qcustomplot.h \
    replenishments.h \
    smart_calc.h \
    withdrawals.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
