#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"

void Bullet::fire(int bulletSpeed){

    bullet.move(bulletSpeed,0);
}
void Bullet::draw(sf::RenderWindow &window){
    window.draw(bullet);
}

Bullet::Bullet(sf::Texture &teksturka){
    bullet.setScale(0.3,0.3);
    bullet.setTexture(teksturka);
    //setposition nie powinno byc?
}
void Bullet::SetPos(sf::Vector2f newpos){
    bullet.setPosition(newpos);
}

