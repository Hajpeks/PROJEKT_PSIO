#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Animation{

private:
   float totalTime;
   float switchTime;

    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

public:
    Animation(sf::Texture *player_animation,sf::Vector2u imageCount, float switchTime);


    void Update(int row,float DeltaTime,bool faceRight);

public:
    sf::IntRect uvRect;
};
