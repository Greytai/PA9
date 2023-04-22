#include "menu.hpp"

#include <SFML/Graphics.hpp>

#include "char.hpp"

int main(void)
{
	Menu menu;

	menu.menuRunner();
    
    //Program will only continue once they have entered "Play" in menu.

    //Creates game window called "window"
    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Andy's Classroom");
   
    sf::Texture playermodel; //Creates a texture 
    playermodel.loadFromFile("Andy.png"); //Sets texture to sprite **CHANGE FILE LOCATION!!!!!
    sf::Sprite andy(playermodel); //Creates sprite, sets it to playermodel sprite
    andy.setScale(3.5, 3.5); //Changes Andy ize
    
    //CREATING CHARACTERS
    Char player;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            andy.move(0,-.75);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            andy.move(-.75, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            andy.move(0,.75);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            andy.move(.75, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            exit(0);
        }






        window.clear();
        window.draw(andy); //Creates Andy, played by user
        window.display();
    }

    //Exiting message in main console, not game console
    cout << "Thank you for playing!" << endl;


    return 0;
}