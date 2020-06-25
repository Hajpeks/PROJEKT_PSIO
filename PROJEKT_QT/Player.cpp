#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

Player::Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed,int numer_gracza):
    animation(texture,imageCount,switchTime)
{
    if(!bulletTexture.loadFromFile("Tekstury/bullet.png")){throw("Can't do shit");}
    bulletTexture.setSrgb(true);

 if(numer_gracza==1){
 this->speed=speed;
 row=0;
 faceRight=true;
 //body1.setSize(sf::Vector2f(80,94));
 body1.setPosition(100.0f,800.0f);
 body1.setScale(1.3,1.3);
 body1.setTexture(*texture);
}
 else if(numer_gracza==2){
     this->speed=speed;
     row=0;
     faceRight=true;
    // body2.setSize(sf::Vector2f(80,92));
     body2.setPosition(1700,20);
     body2.setScale(1.3,1.3);
     body2.setTexture(*texture);
 }
}

Player::~Player()
{

}
void Player::UpdateB1(float DeltaTime)
{
   sf::Time czas;
    movement.x=0;
    movement.y=0;
    isFiring=false;

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
   //void Update attack
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
//      {
//       isFiring=true;
//      }

//      if(isFiring==true){
//       Bullet nowakula(bulletTexture);
//       nowakula.SetPos(sf::Vector2f(body1.getPosition().x+105,body1.getPosition().y+77));
//       vecBullets.emplace_back(nowakula);
//       isFiring=false;
//    }

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

    animation.Update(row,DeltaTime,faceRight);
    body1.setTextureRect(animation.uvRect);
    body1.move(movement);

}

void Player::UpdateB2(float DeltaTime)
{

    movement.x=0;
    movement.y=0;
    isFiring=false;
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
    else
    {
        faceRight=true;
    }
    animation.Update(row,DeltaTime,faceRight);
    body2.setTextureRect(animation.uvRect);
    body2.move(movement);

}

void Player::UpdateCollisionsB1(std::vector<sf::Sprite> &Blocks,float &dt){


    sf::FloatRect playerBounds = body1.getGlobalBounds();
    sf::FloatRect playerBoundsNext = body1.getGlobalBounds();
    playerBoundsNext.left = body1.getPosition().x + this->movement.x * dt;
    playerBoundsNext.top = body1.getPosition().y + this->movement.y * dt;

    // Kolizja z ekranem

    //PRZEJSCIE PRZEZ DOL
    if(playerBounds.top+playerBounds.height>1070)
    {
        body1.setPosition(playerBounds.left,0);
    }
    //PRZEJSCIE GORA
    if(playerBounds.top+playerBounds.height<80)
    {
        body1.setPosition(playerBounds.left,930);
    }
    //LEWA KRAWEDZ
    if(playerBounds.left<0)
    {
        movement.x=0;
        body1.setPosition(left_bound,playerBounds.top);//TUTAJ WROCIC
    }
    //PRAWA KRAWEDZ
    if(playerBounds.left+playerBounds.width>1920-1)
    {
        movement.x=0;
        body1.setPosition(right_bound-playerBounds.width,playerBounds.top);
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
                std::cout<<"KOLIZJA DOLNA"<<std::endl;
                this->movement.y = 0;
                body1.setPosition(playerBounds.left, BlocksBounds.top - playerBounds.height);
            }

            //Top Collision
            else if (playerBounds.top > BlocksBounds.top
                && playerBounds.top + playerBounds.height > BlocksBounds.top + BlocksBounds.height
                && playerBounds.left < BlocksBounds.left + BlocksBounds.width
                && playerBounds.left + playerBounds.width > BlocksBounds.left
                )
            {
                std::cout<<"Kolizja gorna"<<std::endl;
                this->movement.y = 0;
                body1.setPosition(playerBounds.left, BlocksBounds.top + BlocksBounds.height);
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
                body1.setPosition(BlocksBounds.left - playerBounds.width, playerBounds.top);
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
                body1.setPosition(BlocksBounds.left + BlocksBounds.width, playerBounds.top);
            }
        }


    }
}
void Player::UpdateCollisionsB2(std::vector<sf::Sprite> &Blocks,float &dt){

    //DLA EKRANU
    sf::FloatRect playerBounds = body2.getGlobalBounds();
    sf::FloatRect playerBoundsNext = body2.getGlobalBounds();
    playerBoundsNext.left = body2.getPosition().x + this->movement.x * dt;
    playerBoundsNext.top = body2.getPosition().y + this->movement.y * dt;

//    std::cout<< bounds.left<<" "<<bounds.width<<std::endl;
//    std::cout<<bounds.top<<" "<<bounds.height<<std::endl;


    if(playerBounds.top+playerBounds.height>1070)
    {
        body2.setPosition(playerBounds.left,0);
    }
    if(playerBounds.top+playerBounds.height<80)
    {
        body2.setPosition(playerBounds.left,930);
    }
    if(playerBounds.left<0)
    {
        movement.x=0;
        body2.setPosition(left_bound,playerBounds.top);
    }
    //PRAWA KOLIZJA
    if(playerBounds.left+playerBounds.width>1920-1)
    {
        movement.x=0;
        body2.setPosition(right_bound-playerBounds.width,playerBounds.top);
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
                std::cout<<"KOLIZJA DOLNA"<<std::endl;
                this->movement.y = 0;
                body2.setPosition(playerBounds.left, BlocksBounds.top - playerBounds.height);
            }

            //Top Collision
            else if (playerBounds.top > BlocksBounds.top
                && playerBounds.top + playerBounds.height > BlocksBounds.top + BlocksBounds.height
                && playerBounds.left < BlocksBounds.left + BlocksBounds.width
                && playerBounds.left + playerBounds.width > BlocksBounds.left
                )
            {
                std::cout<<"Kolizja gorna"<<std::endl;
                this->movement.y = 0;
                body2.setPosition(playerBounds.left, BlocksBounds.top + BlocksBounds.height);
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
                body2.setPosition(BlocksBounds.left - playerBounds.width, playerBounds.top);
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
                body2.setPosition(BlocksBounds.left + BlocksBounds.width, playerBounds.top);
            }
        }

    }
}
void Player::Draw(sf::RenderWindow &window)
{
    window.draw(body1);
    window.draw(body2);
    for(unsigned int i=0;i<vecBullets.size();i++)
    {
         vecBullets[i].draw(window);
         vecBullets[i].fire(3);
    }

}
