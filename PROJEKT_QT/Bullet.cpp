#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"

void Bullet::fire(){

    bullet.move(bulletspeed,0);
}
void Bullet::draw(sf::RenderWindow &window){
    window.draw(bullet);
}

Bullet::Bullet(sf::Texture &teksturka,bool &Shotright /*sf::FloatRect body*/){
    if(Shotright==false){
        bulletspeed=(-std::abs(bulletspeed));
    }
    ///...setposition(body.x,....)
    bullet.setScale(0.3,0.3);
    bullet.setTexture(teksturka);
}
void Bullet::SetPos(sf::Vector2f newpos){
    bullet.setPosition(newpos);
}

