#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Bullet.h"


class Player:public sf::Sprite
{
public:
    Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed,int numer_gracza);
    ~Player();

    //Return position
    void ResetBody(){
        body1.setPosition(100.0f,800.0f);
         body2.setPosition(1700,20);
    }

    //RUCH
    void UpdateB1(float DeltaTime);
    void UpdateB2(float DeltaTime);
    void Draw(sf::RenderWindow &window);

    //KOLIZJE
    void UpdateCollisionsB1(std::vector<sf::Sprite> &Blocks,  float &dt);
    void UpdateCollisionsB2(std::vector<sf::Sprite> &Blocks,  float &dt);

//DO STRZAŁÓW
    void UpdateAttack(sf::Event &event)
    {
        if(event.key.code==sf::Keyboard::LControl)
          {
           Bullet nowakula(bulletTexture);
           nowakula.SetPos(sf::Vector2f(body1.getPosition().x+105,body1.getPosition().y+77));
           vecBullets.emplace_back(nowakula);
        }
    }
    bool isFiring=false;
    std::vector<Bullet> vecBullets;
    float timer=1.0f;

private:

    float left_bound=0;
    float right_bound=1920;
    float top_bound=0;
    float bottom_bound=1080;

    int numer_gracza;

    sf::Sprite body1,body2;
    sf::Texture bulletTexture;
    Animation animation;
    sf::Vector2f movement;

    unsigned int row;
    float speed;

    bool faceRight;
};

