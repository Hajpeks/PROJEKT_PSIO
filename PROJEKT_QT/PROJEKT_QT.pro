TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Animation.cpp \
        Items.cpp \
        Maps.cpp \
        Player.cpp \
        main.cpp
INCLUDEPATH += "C:/SFML/include"
LIBS += -L"C:/SFML/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}
DISTFILES += \
    budowa_gry.qmodel

HEADERS += \
    Animation.h \
    Items.h \
    Maps.h \
    Player.h
