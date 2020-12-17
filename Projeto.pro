TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cutellipsoid.cpp \
    cutsphere.cpp \
    putellipsoid.cpp \
    sculptor.cpp \
    cutbox.cpp \
    cutvoxel.cpp \
    putbox.cpp \
    putsphere.cpp \
    putvoxel.cpp \
    interpretador.cpp

HEADERS += \
    cutellipsoid.h \
    cutsphere.h \
    putellipsoid.h \
    sculptor.h \
    cutbox.h \
    cutvoxel.h \
    putbox.h \
    putsphere.h \
    putvoxel.h \
    interpretador.h \
    figurageometrica.h

