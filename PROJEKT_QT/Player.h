#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Bullet.h"


class Player:public sf::Sprite
{
public:
    Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed,int numer_gracza);
    ~Player();

    //RUCH
    void UpdateB1(float DeltaTime);
    void UpdateB2(float DeltaTime);
    void Draw(sf::RenderWindow &window);

    //KOLIZJE
    void UpdateCollisionsB1(std::vector<sf::Sprite> &Blocks,  float &dt);
    void UpdateCollisionsB2(std::vector<sf::Sprite> &Blocks,  float &dt);


    bool isFiring=false;

    std::vector<Bullet> vecBullets;

private:

    float left_bound=0;
    float right_bound=1920;
    float top_bound=0;
    float bottom_bound=1080;

    int numer_gracza;

    sf::Sprite body1,body2;
    Animation animation;
    sf::Vector2f movement;

    unsigned int row;
    float speed;

    bool faceRight;
};

