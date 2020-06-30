#include "gameoveer.h"

GameOveer::GameOveer()
{
   //GAME OVER
        if(!GameOverTexture.loadFromFile("Tekstury/game_over.png")){throw("can't do shit");}
        this->setPosition(800,400);
        this->setScale(0.3,0.3);
        this->setTexture(GameOverTexture);
}
void GameOveer::drawing(sf::RenderWindow &window){
    window.draw(*this);
}
