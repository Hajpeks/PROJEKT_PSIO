#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"


class Player:public sf::Sprite
{
public:
    Player(sf::Texture *texture,sf::Vector2u imageCount, float switchTime,float speed,int numer_gracza);//int numer gracza
    //if numer gracza=1 to wykonuje to i tamto else to inny gracz
    ~Player();

    void UpdateB1(float DeltaTime);
    void UpdateB2(float DeltaTime);
    void Draw(sf::RenderWindow &window);

    void UpdateCollisionsB1(std::vector<sf::Sprite> &Blocks,  float &dt);

    void UpdateCollisionsB2(std::vector<sf::Sprite> &Blocks,  float &dt);



private:



    int numer_gracza;

    sf::Sprite body1,body2;
    Animation animation;
    sf::Vector2f movement;

    unsigned int row;
    float speed;

    bool faceRight;
};

