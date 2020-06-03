#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Players.h"
#include <iostream>
#include <vector>


//class Game{
//    float DeltaTime=0.0f;
//    sf::Clock clock;
//    std::vector<sf::Sprite> players;
//    sf::RenderWindow window_;

//public:
//    Game(int W, int H): window_(sf::VideoMode(W,H),"SHOOT_Game")
//    {
//        sf::RenderWindow window(sf::VideoMode(800,600),"Shooting Game");
//       sf::RectangleShape player(sf::Vector2f(80,120));
//        player.setPosition(500,500);
//        sf::Texture playerTexture;
//        if (!playerTexture.loadFromFile("soldier.png")) {
//            std::cerr << "Could not load texture" << std::endl;
//             throw("Could not load texture");
//        }
//            Player animation(&playerTexture,sf::Vector2u(1,2),0.3f);
//            animation.Update(0,DeltaTime);
//            player.setTextureRect(animation.uvRect);

//       sf::RectangleShape prostokaty(sf::Vector2f(120,200));
//       prostokaty.setTextureRect(sf::IntRect(300,300,100,200));
//       prostokaty.setPosition(500.0, 400.0);
//        prostokaty.setFillColor(sf::Color::Red);
//       shapes.emplace_back(std::move(prostokaty));
//    }
//    void loop(){

//        while (window_.isOpen()) {
//            DeltaTime=clock.restart().asSeconds();
//            sf::Event event;
//            while (window_.pollEvent(event)) {
//                // "close requested" event: we close the window
//                if (event.type == sf::Event::Closed)
//                    window_.close();

//                this->draw_all();
//            }
//        }
//    }
//        void draw_all(){

//            window_.clear(sf::Color::Black);

//            // draw everything here...

//           for(auto &el :players)
//            {
//                window_.draw(el);
//            }
//            window_.draw(player)
//            // end the current frame
//            window_.display();
//        }
//};

int main() {

//    Game test(1920,1080);
//    test.loop();
//    test.draw_all();
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "lab9", sf::Style::Close | sf::Style::Titlebar);

    sf::RectangleShape player(sf::Vector2f(80,120));
    player.setPosition(500.0f,200.0f);
    player.setScale(3,3);

    sf::RectangleShape zombie(sf::Vector2f(80,120));
    zombie.setPosition(1000.0f,500.0f);
    zombie.setScale(3,3);


    //window.setVerticalSyncEnabled(true);
    sf::Event sfEvent;
    sf::Clock clock;
    float DeltaTime;

    sf::Texture soldierTexture;
    if (!soldierTexture.loadFromFile("soldier.png")) { return -1; }
    player.setTexture(&soldierTexture);

    sf::Texture zombieTexture;
    if (!zombieTexture.loadFromFile("zombie.png")) { return -1; }
    zombie.setTexture(&zombieTexture);


    Player soldierAnimation(&soldierTexture,sf::Vector2u(2,1),0.3);

    Player zombieAnimation(&zombieTexture,sf::Vector2u(2,1),0.3);



    //Main gameplay loop
    while (window.isOpen()) {

       DeltaTime = clock.restart().asSeconds();

        while (window.pollEvent(sfEvent)) {
            if (sfEvent.type == sf::Event::Closed) {
                window.close();
            }
        }


         soldierAnimation.Update(0,DeltaTime);
         player.setTextureRect(soldierAnimation.uvRect);

         zombieAnimation.Update(0,DeltaTime);
         zombie.setTextureRect(zombieAnimation.uvRect);

        window.clear();
        window.draw(player);
        window.draw(zombie);
        window.display();
    }

 return 0;
    }


