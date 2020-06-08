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
 body1.setSize(sf::Vector2f(80,120));
 body1.setPosition(100.0f,800.0f);
 body1.setScale(1.5,1.5);
 body1.setTexture(texture);

}
Player::Player(sf::Vector2u imageCount,float switchTime,float speed,sf::Texture *texture1):
    animation(texture1,imageCount,switchTime)
{
     this->speed=speed;
     row=0;
     faceRight=true;
     body2.setSize(sf::Vector2f(80,120));
     body2.setPosition(1700,20);
     body2.setScale(1.5,1.5);
     body2.setTexture(texture1);
}
Player::~Player()
{

}
void Player::UpdateB1(float DeltaTime)
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
    else if(movement.x<0.0f)
    {
        faceRight=false;
    }
    animation.Update(row,DeltaTime,faceRight);
    body1.setTextureRect(animation.uvRect);
    body1.move(movement);
}

void Player::UpdateB2(float DeltaTime)
{
    sf::Vector2f movement(0.0f,0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        movement.x -=speed*DeltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        movement.x +=speed*DeltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        movement.y -=speed*DeltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        movement.y +=speed*DeltaTime;
    }
    if(movement.x>0.0f)
    {
        faceRight=false;
    }
    else if(movement.x<0.0f)
    {
        faceRight=true;
    }
    animation.Update(row,DeltaTime,faceRight);
    body2.setTextureRect(animation.uvRect);
    body2.move(movement);
}
void Player::Draw(sf::RenderWindow &window)
{
    window.clear();
    window.draw(body1);
    window.draw(body2);
}
