*g++*:QMAKE_CXXFLAGS += -std=c++11

QT += qml quick

PROJECT_ROOT_DIR = ./
release: BUILD_DIR = $${PROJECT_ROOT_DIR}/build/release
debug:   BUILD_DIR = $${PROJECT_ROOT_DIR}/build/debug

OBJECTS_DIR = $${BUILD_DIR}/obj
MOC_DIR     = $${BUILD_DIR}/moc
DESTDIR     = $${BUILD_DIR}/bin
RCC_DIR     = $${BUILD_DIR}/rcc

HEADERS += \

SOURCES += \
    $$PWD/src/main.cpp

RESOURCES += \

QML_FILES = \
    $$PWD/res/qml/main.qml \
    $$PWD/res/qml/ScreenManager.qml \
    $$PWD/res/qml/cabinet/*.qml

JS_FILES = \

DISTFILES += $$QML_FILES \
             $$JS_FILES \
    res/qml/cabinet/AuthorizationFailedForm.qml \
    res/qml/cabinet/CabinetForm.qml

FORMS += \
    res/qml/cabinet/form.ui
