*g++*:QMAKE_CXXFLAGS += -std=c++11

QT += qml quick

macx {
INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib/
LIBS += -lboost_serialization
}

PROJECT_ROOT_DIR = ./
release: BUILD_DIR = $${PROJECT_ROOT_DIR}/build/release
debug:   BUILD_DIR = $${PROJECT_ROOT_DIR}/build/debug

OBJECTS_DIR = $${BUILD_DIR}/obj
MOC_DIR     = $${BUILD_DIR}/moc
DESTDIR     = $${BUILD_DIR}/bin
RCC_DIR     = $${BUILD_DIR}/rcc

macx {
HEADERS += \
    $$PWD/src/persistence/*.h

SOURCES += \
    $$PWD/src/persistence/*.cpp
}

HEADERS += \
    $$PWD/src/cabinet/*.h

SOURCES += \
    $$PWD/src/main.cpp \
    $$PWD/src/cabinet/*.cpp

RESOURCES += \
    icons.qrc

QML_FILES = \
    $$PWD/res/qml/main.qml \
    $$PWD/res/qml/ScreenManager.qml \
    $$PWD/res/qml/cabinet/*.qml

JS_FILES = \

DISTFILES += $$QML_FILES \
             $$JS_FILES
