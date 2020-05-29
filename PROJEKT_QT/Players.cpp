#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Players.h"

Player::Player(sf::Texture &animation_sheet)
{
    this->setTexture(animation_sheet);
}
void Player::add_animation(float frame_rate, const int start_x, const int start_y, const int cage_numbers, const int width, const int height)
{
    this->framerate=frame_rate;
    this->cage_width=width;

    this->begin_cage=sf::IntRect(start_x,start_y,width,height);

    this->actual_cage=this->begin_cage;

    this->end_cage=sf::IntRect(start_x+width,start_y,width*(cage_numbers-1),height);

    this->setTextureRect(begin_cage);
}
void Player::play_animation(float &dt)
{
    this->time+=dt;
    if(time>1/this->framerate)
    {
        time=0;

       if(actual_cage!=end_cage)
       {
           actual_cage.left+=this->cage_width;
       }
       else
       {
           this->end_cage=this->begin_cage;
       }
    }
    this->setTextureRect(this->actual_cage);
}
