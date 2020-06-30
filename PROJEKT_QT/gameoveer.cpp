#include "gameoveer.h"

GameOveer::GameOveer()
{
   //GAME OVER
        if(!GameOverTexture.loadFromFile("Tekstury/game_over.png")){throw("can't do shit");}
        this->setPosition(1920/2,1080/2);
        this->setTexture(GameOverTexture);
}
void GameOveer::drawing(sf::RenderWindow &window){
    window.draw(*this);
}
