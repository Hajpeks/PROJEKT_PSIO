#include "Scene.h"

Scene::Scene(){
//Niebieskie tło
    Blue_Background.setRepeated(true);
    if (!Blue_Background.loadFromFile("Tekstury/niebieskie_tlo.png")) { throw("can't do shit"); }
//Drewniane tło
    Wooden_Backround.setRepeated(true);
    if (!Wooden_Backround.loadFromFile("Tekstury/drewniane_tlo.png")) { throw("cant do shit"); }
//Czerwone tło
    Red_Background.setRepeated(true);
    if (!Red_Background.loadFromFile("Tekstury/czerwone_tlo.png")) { throw("can't do shit"); }
//KAKTUSY
    Cactus.setSrgb(true);
    if (!Cactus.loadFromFile("Tekstury/cactus1.png")) { throw("can't do shit"); }
//PLOTKI
    Fence.setSrgb(true);
    if (!Fence.loadFromFile("Tekstury/fence.png")) {throw("can't do shit"); }
//Żolnierzyk
    if (!soldierTexture.loadFromFile("Tekstury/NewSoldier.png")) { throw("can't do shit"); }
    soldierTexture.setSrgb(true);
//Zombie
    if (!zombieTexture.loadFromFile("Tekstury/NewZombie.png")) { throw("can't do shit"); }
    zombieTexture.setSrgb(true);
//NABÓJ
//    if(!bulletTexture.loadFromFile("Tekstury/bullet.png")){throw("Can't do shit");}
//    bulletTexture.setSrgb(true);

    this->generateBlocks();
    this->generate_bacground(Wooden_Backround,Blue_Background,Red_Background);

}
void Scene::generateBlocks()
{

    sf::Sprite cactus1;
    cactus1.setTexture(Cactus);
    cactus1.setPosition(400,200);
    cactus1.setScale(0.5,0.5);
    _Blocks.emplace_back(cactus1);

    sf::Sprite cactus2;
    cactus2.setTexture(Cactus);
    cactus2.setPosition(1472,200);
    cactus2.setScale(0.5,0.5);
    _Blocks.emplace_back(cactus2);

    sf::Sprite cactus3;
    cactus3.setTexture(Cactus);
    cactus3.setPosition(400,500);
    cactus3.setScale(0.5,0.5);
    _Blocks.emplace_back(cactus3);

    sf::Sprite cactus4;
    cactus4.setTexture(Cactus);
    cactus4.setPosition(1472,500);
    cactus4.setScale(0.5,0.5);
    _Blocks.emplace_back(cactus4);

    sf::Sprite cactus5;
    cactus5.setTexture(Cactus);
    cactus5.setPosition(400,800);
    cactus5.setScale(0.5,0.5);
    _Blocks.emplace_back(cactus5);

    sf::Sprite cactus6;
    cactus6.setTexture(Cactus);
    cactus6.setPosition(1472,800);
    cactus6.setScale(0.5,0.5);
    _Blocks.emplace_back(cactus6);

    sf::Sprite fence1;
    fence1.setTexture(Fence);
    fence1.setPosition(930,350);
    fence1.setScale(0.7,0.7);
    fence1.setColor(sf::Color(200,100,100));
    _Blocks.emplace_back(fence1);

    sf::Sprite fence2;
    fence2.setTexture(Fence);
    fence2.setPosition(930,650);
    fence2.setScale(0.7,0.7);
    fence2.setColor(sf::Color(200,100,100));
    _Blocks.emplace_back(fence2);

    sf::Sprite fence3;
    fence3.setTexture(Fence);
    fence3.setPosition(930,50);
    fence3.setScale(0.7,0.7);
    fence3.setColor(sf::Color(200,100,100));
    _Blocks.emplace_back(fence3);


    sf::Sprite fence4;
    fence4.setTexture(Fence);
    fence4.setPosition(930,950);
    fence4.setScale(0.7,0.7);
    fence4.setColor(sf::Color(200,100,100));
    _Blocks.emplace_back(fence4);

}
void Scene::generate_bacground(sf::Texture &Wooden_Background, sf::Texture &Blue_Background, sf::Texture &Red_Background)
{
    sf::Sprite Red;
    Red.setTexture(Red_Background);
    Red.setPosition(0,0);
    Red.setTextureRect(sf::IntRect(0,0,1920,1080));
    _background_screens.emplace_back(Red);

    sf::Sprite Blue;
    Blue.setTexture(Blue_Background);
    Blue.setPosition(0,0);
    Blue.setTextureRect(sf::IntRect(0,0,1920,1080));
    _background_screens.emplace_back(Blue);

    sf::Sprite Wooden;
    Wooden.setTexture(Wooden_Background);
    Wooden.setPosition(0,0);
    Wooden.setTextureRect(sf::IntRect(0,0,1920,1080));
    _background_screens.emplace_back(Wooden);

}

void Scene::draw(sf::RenderWindow &window)
{

    if(numer_mapy==0){
        window.draw(_background_screens[0]);
    }
    else if(numer_mapy==1){
            window.draw(_background_screens[1]);
    }
    else if(numer_mapy==2){
        window.draw(_background_screens[2]);
    }
    for(auto &el2: _Blocks)
    {
        window.draw(el2);
    }

}
void Scene::loop(sf::RenderWindow &window,Scene &scene,Menu &menu){
    //SOldier soldier(..);
    // zombie zombie(..);

        Player Soldier(&soldierTexture,sf::Vector2u(2,1),0.3,350.0f,1);
        Player Zombie(&zombieTexture,sf::Vector2u(2,1),0.3,350,2);


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

                  //DO MENU //

                    if(isMenu){
                    if(event.key.code==sf::Keyboard::Down)
                    {
                        menu.MoveDown();
                    }
                    if(event.key.code==sf::Keyboard::Up)
                    {
                        menu.MoveUp();
                    }}

               //KONIEC MENU  //

                    if(event.key.code==sf::Keyboard::Escape)
                    {
                        isMenu=true;
                        wybor=false;
                        Zombie.ResetBody();
                        Soldier.ResetBody();
                    }
                    if(event.key.code==sf::Keyboard::Enter)
                    {
                        isMenu=false;
                        switch(menu.GetPressedItem())
                        {
                        case 0:                       
                            scene.numer_mapy=0;
                            wybor=true;
                        break;
                        case 1:
                            scene.numer_mapy=1;
                            wybor=true;

                        break;
                        case 2:
                            scene.numer_mapy=2;
                            wybor=true;
                        break;
                        case 3:
                            wybor=true;
                            window.close();
                        break;
                        }
                    }
                         Soldier.UpdateAttack(event,1);
                         Zombie.UpdateAttack(event,2);

////                        if(event.key.code==sf::Keyboard::LControl){
////                            //Ten kod
//                        }
//}
                }

             }

            if(wybor==false){
                 window.clear(sf::Color(150,150,150));
                 menu.draw(window);
            }
            if(scene.numer_mapy==0&&wybor!=false){
               Soldier.UpdateB1(DeltaTime);
//               Soldier.UpdateAttack();
               Zombie.UpdateB2(DeltaTime);
               Soldier.UpdateCollisionsB1(_Blocks,DeltaTime);
               Zombie.UpdateCollisionsB2(_Blocks,DeltaTime);


               scene.draw(window);
               Soldier.Draw(window);
               Zombie.Draw(window);

            }
            else if(scene.numer_mapy==1&& wybor!=false){
                Soldier.UpdateB1(DeltaTime);
                Zombie.UpdateB2(DeltaTime);
                Soldier.UpdateCollisionsB1(_Blocks,DeltaTime);
                Zombie.UpdateCollisionsB2(_Blocks,DeltaTime);

                window.clear();
                scene.draw(window);
                Soldier.Draw(window);
                Zombie.Draw(window);
            }
            else if(scene.numer_mapy==2&&wybor!=false){
                Soldier.UpdateB1(DeltaTime);
                Zombie.UpdateB2(DeltaTime);
                Soldier.UpdateCollisionsB1(_Blocks,DeltaTime);
                Zombie.UpdateCollisionsB2(_Blocks,DeltaTime);

                window.clear();
                scene.draw(window);
                Soldier.Draw(window);
                Zombie.Draw(window);
            }
            window.display();
        }
}
