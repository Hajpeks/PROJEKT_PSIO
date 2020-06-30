#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"
#include "Player.h"
#include "gameoveer.h"

class Scene{

private:
//Wektory
std::vector<sf::Sprite> _background_screens;
std::vector<sf::Sprite> _Blocks;
//Tekstury
sf::Texture Wooden_Backround,Red_Background,Blue_Background,Cactus,Fence;
sf::Texture soldierTexture,zombieTexture;


//inne zmienne
int numer_mapy;

int hp_Zombie=3;
int hp_Soldier=3;

float DeltaTime;

bool wybor=false;
bool isMenu=true;

public:
  Scene();
  // std::vector<sf::Sprite> genereteCactus(sf::Texture &Cactus);
   void generateBlocks();
   void generate_bacground(sf::Texture &Wooden_Backgorund,sf::Texture &Blue_Backgorund,sf::Texture &Red_Background);

   //PlayerCollision
   void player_collision(std::vector<Bullet> &bullets,Player &player,int &punkty_zycia);

   void reset_hp();
   //Managing
   void drawing(sf::RenderWindow &window);
   void loop(sf::RenderWindow &window,Scene &scena,Menu &menu);









};
