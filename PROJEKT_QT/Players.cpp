#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Players.h"

Player::Player(sf::Texture *texture,sf::Vector2u imageCount,float switchTime)
{
    this->imageCount=imageCount;
    this->switchTime=switchTime;
    totalTime=0.0f;
    currentImage.x=0;

    uvRect.width=texture->getSize().x/float(imageCount.x);
    uvRect.height=texture->getSize().y/float(imageCount.y);
}
void Player::Update(int row,float DeltaTime)
{
    currentImage.y=row;
    totalTime+=DeltaTime;
    if(totalTime>=switchTime)
    {
        totalTime -=switchTime;
        currentImage.x++;
        if(currentImage.x>=imageCount.x)
        {
            currentImage.x=0;
        }
    }
    uvRect.left=currentImage.x*uvRect.width;
    uvRect.top=currentImage.y*uvRect.height;
}
