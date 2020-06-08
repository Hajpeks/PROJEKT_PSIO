#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("another.ttf"))
    {
        // handle error
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("ShootingGame Map1");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("ShootingGame Map2");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("ShootingGame Map3");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("EXIT");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

    selectedItemIndex =0;

}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}


void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
    }
}
//void Menu::loop(sf::RenderWindow &window)
//{
//    sf::Event event;
//    sf::Clock clock;
//    while (window.isOpen())
//    {
//        DeltaTime = clock.restart().asSeconds();
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed){
//            window.close();
//            }
//            if(event.type==sf::Event::KeyReleased){
//                if(event.key.code==sf::Keyboard::Numpad2)
//                {
//                    Menu::MoveDown();
//                }
//                if(event.key.code==sf::Keyboard::Numpad8)
//                {
//                    Menu::MoveUp();
//                }
//                if(event.key.code==sf::Keyboard::Escape)
//                {
//                    wybor=false;
//                }
//                if(event.key.code==sf::Keyboard::Enter)
//                {

//                    switch(Menu::GetPressedItem())
//                    {
//                    case 0:
//                        scena.numer_mapy=0;
//                        wybor=true;
//                        //window.clear();
//                        scena.draw(window);
//                    break;
//                    case 1:
//                        scena.numer_mapy=1;
//                        wybor=true;
//                        scena.draw(window);
//                    break;
//                    case 2:
//                        scena.numer_mapy=2;
//                        wybor=true;
//                        scena.draw(window);
//                    break;
//                    case 3:
//                        wybor=true;
//                        window.close();
//                    break;
//                    }
//                }

//            }

//         }


//        if(wybor==false){
//             window.clear(sf::Color(150,150,150));
//             Menu::draw(window);
//        }
//        if(scena.numer_mapy==0&&wybor!=false){
//           window.clear();
//           scena.draw(window);
//        }
//        else if(scena.numer_mapy==1&& wybor!=false){
//            window.clear();
//           scena.draw(window);
//        }
//        else if(scena.numer_mapy==2&&wybor!=false){
//           window.clear();
//           scena.draw(window);
//        }
////        soldier.UpdateB1(DeltaTime);
////        zombie.UpdateB2(DeltaTime);

////        window.clear();
////        zombie.Draw(window);
////        soldier.Draw(window);

//        window.display();
//    }
//}

