#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H
#endif // Player.h
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
    Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed);
    ~Player();
    Player(sf::Vector2u imageCount, float switchTime,float speed,sf::Texture *texture1);

    void UpdateB1(float DeltaTime);
    void UpdateB2(float DeltaTime);
    void Draw(sf::RenderWindow &window);
private:
    sf::RectangleShape body1;
    sf::RectangleShape body2;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
};

