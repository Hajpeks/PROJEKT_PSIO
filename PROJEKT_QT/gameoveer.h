#ifndef GAMEOVEER_H
#define GAMEOVEER_H
#include<SFML/Graphics.hpp>


class GameOveer:public sf::Sprite
{
public:
    GameOveer();

    void drawing(sf::RenderWindow &window);
private:
  sf::Texture GameOverTexture;
};

#endif // GAMEOVEER_H
