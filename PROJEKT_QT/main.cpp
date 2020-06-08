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

    sf::Texture Niebieskie;
    Niebieskie.setRepeated(true);
    if (!Niebieskie.loadFromFile("niebieskie_tlo.png")) { return -1; }

    sf::Texture Wooden_Backround;
    Wooden_Backround.setRepeated(true);
    if (!Wooden_Backround.loadFromFile("drewniane_tlo.png")) { return -1; }


    sf::Texture Red_Background;
    Red_Background.setRepeated(true);
    if (!Red_Background.loadFromFile("czerwone_tlo.png")) { return -1; }


    sf::Texture Cactus;
    Cactus.setSrgb(true);
    if (!Cactus.loadFromFile("cactus1.png")) { return -1; }

    sf::Texture Fence;
    Cactus.setSrgb(true);
    if (!Fence.loadFromFile("fence.png")) { return -1; }
//KONIEC TEKSTUR
    Menu menu(window.getSize().x, window.getSize().y);
    Scene scena(Cactus,Fence,Wooden_Backround,Niebieskie,Red_Background);

    Player player(&soldierTexture,sf::Vector2u(2,1),0.3,400.0f);

    Player Zombie(sf::Vector2u(2,1),0.3,400.0f,&zombieTexture);




    sf::Event sfEvent;
    sf::Clock clock;
    float DeltaTime;

    //Main gameplay loop
    while (window.isOpen()) {

//        menu.loop(window,scena);

       DeltaTime = clock.restart().asSeconds();

        while (window.pollEvent(sfEvent)) {
            if (sfEvent.type == sf::Event::Closed) {
                window.close();
            }
        }



        player.UpdateB1(DeltaTime);
        Zombie.UpdateB2(DeltaTime);



        window.clear();
        Zombie.Draw(window);
        player.Draw(window);
        window.display();
    }

 return 0;
    }


