#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

Player::Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed,int nr_gracza):
    animation(texture,imageCount,switchTime)
{
   if(!bulletTexture.loadFromFile("Tekstury/bullet.png")){throw("Can't do shit");}
   bulletTexture.setSrgb(true);

numer_gracza=nr_gracza;

 if(numer_gracza==1){
 this->speed=speed;
 row=0;
 this->setPosition(100.0f,800.0f);
 this->setScale(1.3,1.3);
 this->setTexture(*texture);
}
 else if(numer_gracza==2){
     this->speed=speed;
     row=0;
     this->setPosition(1700,20);
     this->setScale(1.3,1.3);
     this->setTexture(*texture);
 }
}

void Player::Update(float DeltaTime)
{
    movement.x=0;
    movement.y=0;


if(numer_gracza==1){

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
    else
    {
        faceRight=true;
    }

}
else if(numer_gracza==2){

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
        faceRight=true;
    }
    else if(movement.x<0.0f)
    {
        faceRight=false;
    }
    else
    {
        faceRight=false;
    }
}
    animation.Update(row,DeltaTime,faceRight);
    this->setTextureRect(animation.uvRect);
    this->move(movement);
}


void Player::UpdateCollisions(std::vector<sf::Sprite> &Blocks,float &dt){


    sf::FloatRect playerBounds = this->getGlobalBounds();
    sf::FloatRect playerBoundsNext = this->getGlobalBounds();
    playerBoundsNext.left = this->getPosition().x + this->movement.x * dt;
    playerBoundsNext.top = this->getPosition().y + this->movement.y * dt;

    // Kolizja z ekranem

    //PRZEJSCIE PRZEZ DOL
    if(playerBounds.top+playerBounds.height>1070)
    {
        setPosition(playerBounds.left,0);
    }
    //PRZEJSCIE GORA
    if(playerBounds.top+playerBounds.height<80)
    {
        setPosition(playerBounds.left,930);
    }
    //LEWA KRAWEDZ
    if(playerBounds.left<0)
    {
        movement.x=0;
        setPosition(left_bound,playerBounds.top);//TUTAJ WROCIC
    }
    //PRAWA KRAWEDZ
    if(playerBounds.left+playerBounds.width>1920-1)
    {
        movement.x=0;
        setPosition(right_bound-playerBounds.width,playerBounds.top);
    }
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
               // std::cout<<"KOLIZJA DOLNA"<<std::endl;
                this->movement.y = 0;
                setPosition(playerBounds.left, BlocksBounds.top - playerBounds.height);
            }

            //Top Collision
            else if (playerBounds.top > BlocksBounds.top
                && playerBounds.top + playerBounds.height > BlocksBounds.top + BlocksBounds.height
                && playerBounds.left < BlocksBounds.left + BlocksBounds.width
                && playerBounds.left + playerBounds.width > BlocksBounds.left
                )
            {
              //  std::cout<<"Kolizja gorna"<<std::endl;
                this->movement.y = 0;
                setPosition(playerBounds.left, BlocksBounds.top + BlocksBounds.height);
            }

            //Right collisin
            if (playerBounds.left < BlocksBounds.left
                && playerBounds.left + playerBounds.width < BlocksBounds.left + BlocksBounds.width
                && playerBounds.top < BlocksBounds.top + BlocksBounds.height
                && playerBounds.top + playerBounds.height > BlocksBounds.top
                )
            {
               //   std::cout<<"Kolizja prawa"<<std::endl;
                this->movement.x = 0;
                setPosition(BlocksBounds.left - playerBounds.width, playerBounds.top);
            }

            //Left Collision
            else if (playerBounds.left > BlocksBounds.left
                && playerBounds.left + playerBounds.width > BlocksBounds.left + BlocksBounds.width
                && playerBounds.top < BlocksBounds.top + BlocksBounds.height
                && playerBounds.top + playerBounds.height > BlocksBounds.top
                )
            {
              //    std::cout<<"Kolizja lewa"<<std::endl;
                this->movement.x = 0;
                setPosition(BlocksBounds.left + BlocksBounds.width, playerBounds.top);
            }
        }


   }
}

void Player::Drawing(sf::RenderWindow &window)
{
    window.draw(*this);
   // window.draw(body2);
    for(unsigned int i=0;i<vecBullets.size();i++)
    {
         vecBullets[i].drawing(window);
         vecBullets[i].fire();
    }

}
