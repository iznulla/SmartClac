QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.cc \
    ../model/calcplot.cc \
    ../model/calculate.cc \
    ../model/credit.cc \
    ../model/deposit.cc \
    ../model/parser.cc \
    ../model/validation.cc \
    creditwindow.cpp \
    debit.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../controller/controller.h \
    ../model/calcplot.h \
    ../model/calculate.h \
    ../model/credit.h \
    ../model/deposit.h \
    ../model/parser.h \
    ../model/validation.h \
    creditwindow.h \
    debit.h \
    mainwindow.h \
    qcustomplot.h


FORMS += \
    creditwindow.ui \
    debit.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
