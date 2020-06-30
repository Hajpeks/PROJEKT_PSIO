#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Bullet.h"


class Player:public sf::Sprite
{
public:
    Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed,int numer_gracza);
    ~Player(){};

    //Return position
    void ResetBody(){
        if(numer_gracza==1){
        setPosition(100.0f,800.0f);
        }
        else
        setPosition(1700,20);
    }

    //RUCH
    void Update(float DeltaTime);
    void Drawing(sf::RenderWindow &window);

    //KOLIZJE
    void UpdateCollisions(std::vector<sf::Sprite> &Blocks,  float &dt);

//DO STRZAŁÓW
    void UpdateAttack(sf::Event &event)
    {
        if(numer_gracza==1){
        if(event.key.code==sf::Keyboard::LControl)
          {
           Bullet nowakula(bulletTexture,faceRight/*, body1.getGlobalBounds()*/ /*sf::FloatRect body*/);
           nowakula.SetPos(sf::Vector2f(getPosition().x+105,getPosition().y+77));//DO konsturkotra
           Bullets.emplace_back(nowakula);
        }

        }
        if(numer_gracza==2){
            if(event.key.code==sf::Keyboard::RControl){
                Bullet nowakula(bulletTexture,faceRight);
                nowakula.SetPos(sf::Vector2f(getPosition().x-10, getPosition().y+100));
                Bullets.emplace_back(nowakula);
            }

        }
    }

    void BulletCollision(std::vector<sf::Sprite> &bloczki);


    bool isFiring=false;
    std::vector<Bullet> Bullets;


private:

    float left_bound=0;
    float right_bound=1920;
    float top_bound=0;
    float bottom_bound=1080;

    int numer_gracza;

    sf::Texture bulletTexture;
    Animation animation;
    sf::Vector2f movement;

    unsigned int row;
    float speed;

    bool faceRight;
};

