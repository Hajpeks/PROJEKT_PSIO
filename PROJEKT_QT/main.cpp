#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Menu.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME", sf::Style::Close | sf::Style::Titlebar);
//WGRANIE TEKSTUR
    sf::Texture soldierTexture;
    if (!soldierTexture.loadFromFile("soldier.png")) { return -1; }

    sf::Texture zombieTexture;
    if (!zombieTexture.loadFromFile("zombie.png")) { return -1; }

//KONIEC TEKSTUR
    Menu menu(window.getSize().x, window.getSize().y);

    Scene scena;

    Player Soldier(&soldierTexture,sf::Vector2u(2,1),0.3,400.0f);

    Player Zombie(sf::Vector2u(2,1),0.3,400.0f,&zombieTexture);


    menu.loop(window,scena);

 return 0;
  }


