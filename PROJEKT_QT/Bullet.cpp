#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"

void Bullet::fire(int speed){

    bullet.move(speed,0);
}
void Bullet::draw(sf::RenderWindow &window){
    window.draw(bullet);
}

Bullet::Bullet(sf::Vector2f size){
    bullet.setScale(size);
    //setposition nie powinno byc?
}
void Bullet::SetPos(sf::Vector2f newpos){
    bullet.setPosition(newpos);
}

