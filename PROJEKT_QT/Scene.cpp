#include "Scene.h"

Scene::Scene(sf::Texture &texture,sf::Texture &Block_Texture,sf::Texture &wooden,sf::Texture &blue,sf::Texture &red){

    this->genereteCactus(texture);
    this->generateBlocks(Block_Texture);
    this->generate_bacground(wooden,blue,red);
}
std::vector<sf::Sprite> Scene::genereteCactus(sf::Texture &texture)
{
    sf::Sprite cactus1;
    cactus1.setTexture(texture);
    cactus1.setPosition(400,200);
    cactus1.setScale(0.5,0.5);
    _cactus.emplace_back(cactus1);

    sf::Sprite cactus2;
    cactus2.setTexture(texture);
    cactus2.setPosition(1472,200);
    cactus2.setScale(0.5,0.5);
    _cactus.emplace_back(cactus2);

    sf::Sprite cactus3;
    cactus3.setTexture(texture);
    cactus3.setPosition(400,500);
    cactus3.setScale(0.5,0.5);
    _cactus.emplace_back(cactus3);

    sf::Sprite cactus4;
    cactus4.setTexture(texture);
    cactus4.setPosition(1472,500);
    cactus4.setScale(0.5,0.5);
    _cactus.emplace_back(cactus4);

    sf::Sprite cactus5;
    cactus5.setTexture(texture);
    cactus5.setPosition(400,800);
    cactus5.setScale(0.5,0.5);
    _cactus.emplace_back(cactus5);

    sf::Sprite cactus6;
    cactus6.setTexture(texture);
    cactus6.setPosition(1472,800);
    cactus6.setScale(0.5,0.5);
    _cactus.emplace_back(cactus6);

    return _cactus;
}
std::vector<sf::Sprite> Scene::generateBlocks(sf::Texture &block_Texture)
{
    sf::Sprite block1;
    block1.setTexture(block_Texture);
    block1.setPosition(930,350);
    block1.setScale(0.7,0.7);
    block1.setColor(sf::Color(200,100,100));
    _fences.emplace_back(block1);

    sf::Sprite block2;
    block2.setTexture(block_Texture);
    block2.setPosition(930,650);
    block2.setScale(0.7,0.7);
    block2.setColor(sf::Color(200,100,100));
    _fences.emplace_back(block2);

    sf::Sprite block3;
    block3.setTexture(block_Texture);
    block3.setPosition(930,50);
    block3.setScale(0.7,0.7);
    block3.setColor(sf::Color(200,100,100));
    _fences.emplace_back(block3);

    sf::Sprite block4;
    block4.setTexture(block_Texture);
    block4.setPosition(930,950);
    block4.setScale(0.7,0.7);
    block4.setColor(sf::Color(200,100,100));
    _fences.emplace_back(block4);

    return _fences;
}
std::vector<sf::Sprite> Scene::generate_bacground(sf::Texture &Wooden, sf::Texture &Blue, sf::Texture &Red)
{
    sf::Sprite Red_Background;
    Red_Background.setTexture(Red);
    Red_Background.setPosition(0,0);
    Red_Background.setTextureRect(sf::IntRect(0,0,1920,1080));
    _background_screens.emplace_back(Red_Background);

    sf::Sprite Blue_Background;
    Blue_Background.setTexture(Blue);
    Blue_Background.setPosition(0,0);
    Blue_Background.setTextureRect(sf::IntRect(0,0,1920,1080));
    _background_screens.emplace_back(Blue_Background);

    sf::Sprite wooden_background;
    wooden_background.setTexture(Wooden);
    wooden_background.setPosition(0,0);
    wooden_background.setTextureRect(sf::IntRect(0,0,1920,1080));
    _background_screens.emplace_back(wooden_background);


    return _background_screens;
}

void Scene::draw(sf::RenderWindow &window)
{
    //window.clear();
   // tla kolory;
    if(numer_mapy==0){
        window.draw(_background_screens[0]);
    }
    else if(numer_mapy==1){
            window.draw(_background_screens[1]);
    }
    else if(numer_mapy==2){
        window.draw(_background_screens[2]);
    }

    for(auto &el: _cactus)
    {
        window.draw(el);
    }
    for(auto &el2: _fences)
    {
        window.draw(el2);
    }

    window.display();
}
