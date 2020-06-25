#ifndef BULLET_H
#define BULLET_H
#endif // BULLET_H
#include <SFML/Graphics.hpp>
//#include "Player.h"

class Bullet{

public:
    Bullet(sf::Texture &tekturka);

    void draw(sf::RenderWindow &window);
    void SetPos(sf::Vector2f newpos);

    void fire(int bulletSpeed);

private:

    sf::Sprite bullet;
};
