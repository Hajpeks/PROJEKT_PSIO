#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include"Scene.h"

class Player:public sf::Sprite
{
public:
    Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed);
    ~Player();
    Player(sf::Vector2u imageCount, float switchTime,float speed,sf::Texture *texture1);

    void UpdateB1(float DeltaTime);
    void UpdateB2(float DeltaTime);
    void Draw(sf::RenderWindow &window);

    void UpdateColisions(std::vector<sf::Sprite> &Blocks,  float &dt);


private:
    sf::RectangleShape body1;
    sf::RectangleShape body2;
    Animation animation;
    sf::Vector2f movement;
    unsigned int row;
    float speed;
    bool faceRight;
};

