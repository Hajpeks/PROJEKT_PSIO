#ifndef BULLET_H
#define BULLET_H
#endif // BULLET_H
#include <SFML/Graphics.hpp>
//#include "Player.h"

class Bullet{

public:
    Bullet(sf::Texture &tekturka,bool &Shotright);

    void draw(sf::RenderWindow &window);
    void SetPos(sf::Vector2f newpos);

    void fire();

private:
    float bulletspeed=3.0f;
    sf::Sprite bullet;
};
