#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

//#include "Animation.h"
#include "Player.h"

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


    //    sf::RectangleShape zombie(sf::Vector2f(80,120));
    //    zombie.setPosition(1000.0f,500.0f);
    //    zombie.setScale(3,3);


        sf::Texture soldierTexture;
        if (!soldierTexture.loadFromFile("soldier.png")) { return -1; }


//    sf::Texture zombieTexture;
//    if (!zombieTexture.loadFromFile("zombie.png")) { return -1; }
//    zombie.setTexture(&zombieTexture);


    Player player(&soldierTexture,sf::Vector2u(2,1),0.3,200.0f);

//    Player zombieAnimation(&zombieTexture,sf::Vector2u(2,1),0.3);


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



           player.Update(DeltaTime);
//         zombieAnimation.Update(0,DeltaTime);
//         zombie.setTextureRect(zombieAnimation.uvRect);

        window.clear();      
//      window.draw(zombie);
        player.Draw(window);
        window.display();
    }

 return 0;
    }


