#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Menu.h"
#include "Player.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME", sf::Style::Close | sf::Style::Titlebar);


    sf::Texture soldierTexture;
    if (!soldierTexture.loadFromFile("soldier.png")) { return -1; }

    sf::Texture zombieTexture;
    if (!zombieTexture.loadFromFile("zombie.png")) { return -1; }


    Player player(&soldierTexture,sf::Vector2u(2,1),0.3,400.0f);

    Player Zombie(sf::Vector2u(2,1),0.3,400.0f,&zombieTexture);


    sf::Event sfEvent;
    sf::Clock clock;
    float DeltaTime;

    //Main gameplay loop
    while (window.isOpen()) {

       DeltaTime = clock.restart().asSeconds();

        while (window.pollEvent(sfEvent)) {
            if (sfEvent.type == sf::Event::Closed) {
                window.close();
            }
        }



        player.UpdateB1(DeltaTime);
        Zombie.UpdateB2(DeltaTime);



        window.clear(sf::Color::Yellow);
        Zombie.Draw(window);
        player.Draw(window);
        window.display();
    }

 return 0;
    }


