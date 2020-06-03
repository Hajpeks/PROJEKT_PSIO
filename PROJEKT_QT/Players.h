#ifndef PLAYERS_H
#define PLAYERS_H
#endif // PLAYERS_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player: public sf::Sprite{

private:
   float totalTime;
   float switchTime;

    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

public:
    Player(sf::Texture *player_animation,sf::Vector2u imageCount, float switchTime);
   // ~Player();

    void Update(int row,float DeltaTime);

public:
    sf::IntRect uvRect;
};
