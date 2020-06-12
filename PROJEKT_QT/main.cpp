#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Scene.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME", sf::Style::Close | sf::Style::Titlebar);
    Scene scena;
    Menu menu(window.getSize().x,window.getSize().y);
    scena.loop(window,scena,menu);

 return 0;
  }

