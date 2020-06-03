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

    void Update(float DeltaTime);
    void Draw(sf::RenderWindow &window);
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
};

