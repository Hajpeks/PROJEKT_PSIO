#ifndef PLAYERS_H
#define PLAYERS_H
#endif // PLAYERS_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player: public sf::Sprite{

private:
    float velocity_y=0;
    float cage_width=0;
    float framerate=0;

    sf::IntRect begin_cage;
    sf::IntRect actual_cage;
    sf::IntRect end_cage;

    float time=0;

public:
    Player(sf::Texture &player_animation);

    void add_animation(float frame_rate,const int start_x, const int start_y,const int cage_numbers, const int width, const int height);

    void play_animation(float &dt);
};
