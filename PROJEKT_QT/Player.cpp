#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

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
    movement.x=0;
    movement.y=0;

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
    movement.x=0;
    movement.y=0;
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
void Player::UpdateColisions(std::vector<sf::Sprite> &Blocks,float &dt){

    sf::FloatRect playerBounds = this->getGlobalBounds();
    sf::FloatRect playerBoundsNext = this->getGlobalBounds();
    playerBoundsNext.left = this->getPosition().x + this->movement.x * dt;
    playerBoundsNext.top = this->getPosition().y + this->movement.y * dt;

    for (auto& block : Blocks) {

        sf::FloatRect BlocksBounds = block.getGlobalBounds();
        if (BlocksBounds.intersects(playerBoundsNext)) {

            //Bottom collision
            if (playerBounds.top < BlocksBounds.top
                && playerBounds.top + playerBounds.height < BlocksBounds.top + BlocksBounds.height
                && playerBounds.left < BlocksBounds.left + BlocksBounds.width
                && playerBounds.left + playerBounds.width > BlocksBounds.left
                )
            {
                std::cout<<"KOLIZJA"<<std::endl;
                this->movement.y = 0;
                this->setPosition(playerBounds.left, BlocksBounds.top - playerBounds.height);

            }

            //Top Collision
            else if (playerBounds.top > BlocksBounds.top
                && playerBounds.top + playerBounds.height > BlocksBounds.top + BlocksBounds.height
                && playerBounds.left < BlocksBounds.left + BlocksBounds.width
                && playerBounds.left + playerBounds.width > BlocksBounds.left
                )
            {
                std::cout<<"Kolizja górna"<<std::endl;
                this->movement.y = 0;
                this->setPosition(playerBounds.left, BlocksBounds.top + BlocksBounds.height);
            }

            //Right collisin
            if (playerBounds.left < BlocksBounds.left
                && playerBounds.left + playerBounds.width < BlocksBounds.left + BlocksBounds.width
                && playerBounds.top < BlocksBounds.top + BlocksBounds.height
                && playerBounds.top + playerBounds.height > BlocksBounds.top
                )
            {
                  std::cout<<"Kolizja prawa"<<std::endl;
                this->movement.x = 0;
                this->setPosition(BlocksBounds.left - playerBounds.width, playerBounds.top);
            }

            //Left Collision
            else if (playerBounds.left > BlocksBounds.left
                && playerBounds.left + playerBounds.width > BlocksBounds.left + BlocksBounds.width
                && playerBounds.top < BlocksBounds.top + BlocksBounds.height
                && playerBounds.top + playerBounds.height > BlocksBounds.top
                )
            {
                  std::cout<<"Kolizja lewa"<<std::endl;
                this->movement.x = 0;
                this->setPosition(BlocksBounds.left + BlocksBounds.width, playerBounds.top);
            }
        }


    }
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(body1);
    window.draw(body2);

}
