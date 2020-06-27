TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Animation.cpp \
        Bullet.cpp \
        Menu.cpp \
        Player.cpp \
        Scene.cpp \
        main.cpp \
        Soldier.cpp
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
    Bullet.h \
    Menu.h \
    Player.h \
    Scene.h \
    Soldier.h
