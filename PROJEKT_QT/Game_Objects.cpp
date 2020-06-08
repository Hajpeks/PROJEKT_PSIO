#include "Game_Objects.h"
#include "iostream"



Game_Objects::Game_Objects(){


    if (!soldierTexture.loadFromFile("soldier.png")) { throw("can't do shit"); }
    soldierTexture.setSrgb(true);
    if (!zombieTexture.loadFromFile("zombie.png")) { throw("can't do shit"); }
    zombieTexture.setSrgb(true);
//    Player Soldier(&soldierTexture,sf::Vector2u(2,1),0.3,400.0f);
//    Player Zombie(sf::Vector2u(2,1),0.3,400.0f,&zombieTexture);

}
Game_Objects::~Game_Objects(){};

void Game_Objects::loop(sf::RenderWindow &window,Scene &scene,Menu &menu){

        Player Soldier(&soldierTexture,sf::Vector2u(2,1),0.3,400.0f);
        Player Zombie(sf::Vector2u(2,1),0.3,400.0f,&zombieTexture);
        sf::Event event;
        sf::Clock clock;
        while (window.isOpen())
        {
            DeltaTime = clock.restart().asSeconds();
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                window.close();
                }
                if(event.type==sf::Event::KeyReleased){
                    if(event.key.code==sf::Keyboard::Numpad2)
                    {
                        menu.MoveDown();
                    }
                    if(event.key.code==sf::Keyboard::Numpad8)
                    {
                        menu.MoveUp();
                    }
                    if(event.key.code==sf::Keyboard::Escape)
                    {
                        wybor=false;
                    }
                    if(event.key.code==sf::Keyboard::Enter)
                    {

                        switch(menu.GetPressedItem())
                        {
                        case 0:
                            scene.numer_mapy=0;
                            wybor=true;
                            //window.clear();
                            Soldier.Draw(window);
                            Zombie.Draw(window);
                            scene.draw(window);

                        break;
                        case 1:
                            scene.numer_mapy=1;
                            wybor=true;
                            scene.draw(window);
                        break;
                        case 2:
                            scene.numer_mapy=2;
                            wybor=true;
                            scene.draw(window);
                        break;
                        case 3:
                            wybor=true;
                            window.close();
                        break;
                        }
                    }

                }

             }


            if(wybor==false){
                 window.clear(sf::Color(150,150,150));
                 menu.draw(window);
            }
            if(scene.numer_mapy==0&&wybor!=false){
               window.clear();
               scene.draw(window);
               Soldier.UpdateB1(DeltaTime);
               Zombie.UpdateB2(DeltaTime);
               Soldier.Draw(window);
               Zombie.Draw(window);
            }
            else if(scene.numer_mapy==1&& wybor!=false){
                window.clear();
               scene.draw(window);
            }
            else if(scene.numer_mapy==2&&wybor!=false){
               window.clear();
               scene.draw(window);
            }
    //        soldier.UpdateB1(DeltaTime);
    //        zombie.UpdateB2(DeltaTime);

    //        window.clear();
    //      zombie.Draw(window);
    //        soldier.Draw(window);

            window.display();
        }
}


