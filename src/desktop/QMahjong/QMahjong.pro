*g++*:QMAKE_CXXFLAGS += -std=c++11

QT += qml quick core

PROJECT_ROOT_DIR = ./
release: BUILD_DIR = $${PROJECT_ROOT_DIR}/build/release
debug:   BUILD_DIR = $${PROJECT_ROOT_DIR}/build/debug

OBJECTS_DIR = $${BUILD_DIR}/obj
MOC_DIR     = $${BUILD_DIR}/moc
DESTDIR     = $${BUILD_DIR}/bin
RCC_DIR     = $${BUILD_DIR}/rcc

HEADERS += \
    $$PWD/src/cabinet/*.h \
    $$PWD/src/cabinet/admin/*.h \
    $$PWD/src/persistence/*.h

SOURCES += \
    $$PWD/src/main.cpp \
    $$PWD/src/cabinet/*.cpp \
    $$PWD/src/cabinet/admin/*.cpp \
    $$PWD/src/persistence/*.cpp

RESOURCES += \
    icons.qrc

QML_FILES = \
    $$PWD/res/qml/main.qml \
    $$PWD/res/qml/ScreenManager.qml \
    $$PWD/res/qml/FSMEvent.qml \
    $$PWD/res/qml/ColorScheme.qml \
    $$PWD/res/qml/NumericConstants.qml \
    $$PWD/res/qml/controls/*.qml \
    $$PWD/res/qml/controls/tableview/*.qml \
    $$PWD/res/qml/controls/listview/*.qml \
    $$PWD/res/qml/cabinet/*.qml \
    $$PWD/res/qml/cabinet/admin/*.qml \

JS_FILES = \

DISTFILES += $$QML_FILES \
             $$JS_FILES
