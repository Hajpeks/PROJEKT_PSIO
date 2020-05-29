#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class Game{
    std::vector<sf::RectangleShape> shapes;
    sf::RenderWindow window_;
public:
    Game(int W, int H): window_(sf::VideoMode(W,H),"SHOOT_Game")
    {
        sf::RenderWindow window(sf::VideoMode(800,600),"Shooting Game");

        sf::RectangleShape prostokaty(sf::Vector2f(120,200));
        prostokaty.setTextureRect(sf::IntRect(300,300,100,200));
        prostokaty.setPosition(500.0, 400.0);
        prostokaty.setFillColor(sf::Color::Red);
        shapes.emplace_back(std::move(prostokaty));
    }
    void loop(){

        while (window_.isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window_.pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window_.close();

                this->draw_all();
            }
        }
    }
        void draw_all(){

            window_.clear(sf::Color::Black);

            // draw everything here...

            for(auto &el :shapes)
            {
                window_.draw(el);
            }

            // end the current frame
            window_.display();
        }
};

int main() {

  Game test(1920,1080);
 // test.loop();
  test.draw_all();

 return 0;
    }


