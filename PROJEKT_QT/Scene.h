#include "SFML/Graphics.hpp"
#include <iostream>
#include "Collider.h"

class Scene{

private:

std::vector<sf::Sprite> _background_screens;
sf::Texture Wooden_Backround,Red_Background,Blue_Background,Cactus,Fence;
sf::Texture soldierTexture,zombieTexture;
sf::RectangleShape body1,body2;



public:
  Scene();
  // std::vector<sf::Sprite> genereteCactus(sf::Texture &Cactus);
   std::vector<sf::Sprite> generateBlocks();
   std::vector<sf::Sprite> generate_bacground(sf::Texture &Wooden_Backgorund,sf::Texture &Blue_Backgorund,sf::Texture &Red_Background);

   void draw(sf::RenderWindow &window);

public: //powinny byc private ale tutak klopoty
   std::vector<sf::Sprite> _Blocks;
    int numer_mapy;






};
