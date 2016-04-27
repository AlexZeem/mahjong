*g++*:QMAKE_CXXFLAGS += -std=c++11

QT += qml quick core

macx{
INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib/
LIBS += -lboost_serialization
}

#win32 {
#INCLUDEPATH += C:/"Program Files"/boost/boost_1_60_0
#LIBS += -LC:/"Program Files"/boost/boost_1_60_0/stage/lib/
#LIBS += -lboost_serialization-mgw49-mt-1_60 -lws2_32
#}

PROJECT_ROOT_DIR = ./
release: BUILD_DIR = $${PROJECT_ROOT_DIR}/build/release
debug:   BUILD_DIR = $${PROJECT_ROOT_DIR}/build/debug

OBJECTS_DIR = $${BUILD_DIR}/obj
MOC_DIR     = $${BUILD_DIR}/moc
DESTDIR     = $${BUILD_DIR}/bin
RCC_DIR     = $${BUILD_DIR}/rcc

HEADERS += \
    $$PWD/src/cabinet/*.h \
    $$PWD/src/persistence/*.h

SOURCES += \
    $$PWD/src/main.cpp \
    $$PWD/src/cabinet/*.cpp \
    $$PWD/src/persistence/*.cpp

RESOURCES += \
    icons.qrc

QML_FILES = \
    $$PWD/res/qml/main.qml \
    $$PWD/res/qml/ScreenManager.qml \
    $$PWD/res/qml/FSMEvent.qml \
    $$PWD/res/qml/cabinet/*.qml

JS_FILES = \

DISTFILES += $$QML_FILES \
             $$JS_FILES
