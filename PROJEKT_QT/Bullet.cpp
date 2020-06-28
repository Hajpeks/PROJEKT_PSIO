#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Bullet.h"

void Bullet::fire(){

    this->move(bulletspeed,0);
}
void Bullet::drawing(sf::RenderWindow &window){
    window.draw(*this);
}

Bullet::Bullet(sf::Texture &teksturka,bool &Shotright /*sf::FloatRect body*/){
    if(Shotright==false){
        bulletspeed=(-std::abs(bulletspeed));
    }
    ///...setposition(body.x,....)
    this->setScale(0.3,0.3);
    this->setTexture(teksturka);
}
void Bullet::SetPos(sf::Vector2f newpos){
    this->setPosition(newpos);
}

void Bullet::bulletCollision(sf::Sprite &body/*, float &dt*/){

  // std::vector<Bullet> vecBullets;
    sf::FloatRect bodybound=body.getGlobalBounds();
    sf::FloatRect bulletBound=this->getGlobalBounds();
    if(bulletBound.intersects(bodybound)){
        std::cout<<"strzal w kolano"<<std::endl;
//    for (auto& bullet : vecBullets) {

//        sf::FloatRect bulletBounds = bullet.getGlobalBounds();
//        if (bulletBounds.intersects(bodybound)) {

//            std::cout<<"STRZAL W KOLANO"<<std::endl;
//            }
//    }

}
}

