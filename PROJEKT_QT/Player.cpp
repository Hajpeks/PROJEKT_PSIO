#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed):
    animation(texture,imageCount,switchTime)
{
 this->speed=speed;
 row=0;
 faceRight=true;
 body.setSize(sf::Vector2f(80,120));
 body.setPosition(500.0f,200.0f);
 body.setScale(3,3);
 body.setTexture(texture);

 //    sf::RectangleShape zombie(sf::Vector2f(80,120));
 //    zombie.setPosition(1000.0f,500.0f);
 //    zombie.setScale(3,3);
}
Player::~Player()
{

}
void Player::Update(float DeltaTime)
{
    sf::Vector2f movement(0.0f,0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -=speed*DeltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x +=speed*DeltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -=speed*DeltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y +=speed*DeltaTime;
    }
    if(movement.x>0.0f)
    {
        faceRight=true;
    }
    else
    {
        faceRight=false;
    }
    animation.Update(row,DeltaTime,faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}
void Player::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}
