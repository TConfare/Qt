TEMPLATE = app

QT += quick qml
SOURCES += main.cpp
RESOURCES += \
    localstorage.qrc \
    ../../shared/shared.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/localstorage/localstorage
INSTALLS += target
