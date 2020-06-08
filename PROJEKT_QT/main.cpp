#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Game_Objects.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME", sf::Style::Close | sf::Style::Titlebar);
    Scene scena;
    Menu menu(window.getSize().x,window.getSize().y);
    Game_Objects pls;
    pls.loop(window,scena,menu);

 return 0;
  }

