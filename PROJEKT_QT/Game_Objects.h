#include "iostream"
#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "Scene.h"
#include "Player.h"

class Game_Objects{

private:
    float DeltaTime;
    bool wybor=false;
    sf::Texture soldierTexture,zombieTexture;
public:
    Game_Objects();
    ~Game_Objects();
    void loop(sf::RenderWindow &window,Scene &scena,Menu &menu);

};
//Menu menu(window.getSize().x, window.getSize().y);
