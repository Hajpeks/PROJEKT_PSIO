#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "Player.h"

class Scene{

private:
//Wektory
std::vector<sf::Sprite> _background_screens;
std::vector<sf::Sprite> _Blocks;
//Tekstury
sf::Texture Wooden_Backround,Red_Background,Blue_Background,Cactus,Fence;
sf::Texture soldierTexture,zombieTexture;
sf::RectangleShape body1,body2;
//inne zmienne
int numer_mapy;
float DeltaTime;
bool wybor=false;

public:
  Scene();
  // std::vector<sf::Sprite> genereteCactus(sf::Texture &Cactus);
   void generateBlocks();
   void generate_bacground(sf::Texture &Wooden_Backgorund,sf::Texture &Blue_Backgorund,sf::Texture &Red_Background);

   void draw(sf::RenderWindow &window);
   void loop(sf::RenderWindow &window,Scene &scena,Menu &menu);









};
