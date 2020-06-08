TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Animation.cpp \
        Game_Objects.cpp \
        Menu.cpp \
        Player.cpp \
        Scene.cpp \
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
    Game_Objects.h \
    Menu.h \
    Player.h \
    Scene.h
