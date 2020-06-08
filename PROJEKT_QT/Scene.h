#include "SFML/Graphics.hpp"
#include <iostream>

class Scene{

private:

std::vector<sf::Sprite> _cactus;
std::vector<sf::Sprite> _fences;
std::vector<sf::Sprite> _background_screens;

public:
  Scene(sf::Texture &texture,sf::Texture &Block_Texture,sf::Texture &wooden,sf::Texture &blue,sf::Texture &red);

   std::vector<sf::Sprite> genereteCactus(sf::Texture &texture);
   std::vector<sf::Sprite> generateBlocks(sf::Texture &block_Texture);
   std::vector<sf::Sprite> generate_bacground(sf::Texture &Wooden,sf::Texture &Blue,sf::Texture &Red);

   void draw(sf::RenderWindow &window);
public:
   int numer_mapy;
};
