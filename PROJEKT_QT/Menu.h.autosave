#pragma once
#include "Scene.h"
#include "SFML/Graphics.hpp"
//#include "Player.h"

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void loop(sf::RenderWindow &window,Scene &scena);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    bool wybor=false;
    float DeltaTime;
};
