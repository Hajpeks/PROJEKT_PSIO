#include "Scene.h"

Scene::Scene(){

    Blue_Background.setRepeated(true);
    if (!Blue_Background.loadFromFile("niebieskie_tlo.png")) { throw("can't do shit"); }

    Wooden_Backround.setRepeated(true);
    if (!Wooden_Backround.loadFromFile("drewniane_tlo.png")) { throw("cant do shit"); }


    Red_Background.setRepeated(true);
    if (!Red_Background.loadFromFile("czerwone_tlo.png")) { throw("can't do shit"); }

    Cactus.setSrgb(true);
    if (!Cactus.loadFromFile("cactus1.png")) { throw("can't do shit"); }

    Fence.setSrgb(true);
    if (!Fence.loadFromFile("fence.png")) {throw("can't do shit"); }

    std::vector<sf::Sprite> _Blocks=generateBlocks();
    this->generateBlocks();
    this->generate_bacground(Wooden_Backround,Blue_Background,Red_Background);

}
std::vector<sf::Sprite> Scene::generateBlocks()
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
    return _Blocks;
}
std::vector<sf::Sprite> Scene::generate_bacground(sf::Texture &Wooden_Background, sf::Texture &Blue_Background, sf::Texture &Red_Background)
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


    return _background_screens;
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
