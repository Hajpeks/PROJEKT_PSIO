#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"

class Scene{

private:

std::vector<sf::Sprite> _cactus;
std::vector<sf::Sprite> _fences;
std::vector<sf::Sprite> _background_screens;
sf::Texture Wooden_Backround,Red_Background,Blue_Background,Cactus,Fence;


public:
  Scene();
   std::vector<sf::Sprite> genereteCactus(sf::Texture &Cactus);
   std::vector<sf::Sprite> generateBlocks(sf::Texture &Fence);
   std::vector<sf::Sprite> generate_bacground(sf::Texture &Wooden_Backgorund,sf::Texture &Blue_Backgorund,sf::Texture &Red_Background);

   void draw(sf::RenderWindow &window);
public:
   int numer_mapy;
};
