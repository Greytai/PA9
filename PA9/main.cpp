#include "menu.hpp"

#include <SFML/Graphics.hpp>
#include "player.hpp"

int main(void)
{
	Menu menu;

	menu.menuRunner();
    
    //Program will only continue once they have entered "Play" in menu.

    //Creates game window called "window"
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Andy's Classroom");
    window.setFramerateLimit(30);
   
    sf::Texture playermodel; //Creates a texture 
    playermodel.loadFromFile("Andy.png"); //Sets texture to sprite **CHANGE FILE LOCATION!!!!!

    sf::Texture defaultShot;
    defaultShot.loadFromFile("A+.png");

    Player andy; // Player inherits from Sprite
    andy.set_default(); // sets player stats to default values
    andy.setTexture(playermodel); // sets andy's texture to the png
    andy.Shot.setTexture(defaultShot); // sets sprite texture to default
    andy.Shots.push_back(andy.Shot); // puts a shot in the vector

    int shotTimer = 0; // timer that gets compared to andy's shotRate value to limit firerate

    //sf::Sprite andy(playermodel); //Creates sprite, sets it to playermodel sprite
    //andy.setScale(3.5, 3.5); //Changes Andy size
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            andy.move(0,-andy.get_moveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            andy.move(-andy.get_moveSpeed(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            andy.move(0, andy.get_moveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            andy.move(andy.get_moveSpeed(), 0);
        }

        // Shooting
        if (shotTimer < andy.Shot.get_shotRate()) 
        {
            // each frame, shotTimer increments by 1 this means that the shotRate value
            // is equal to the number of frames of cooldown it takes to fire again
            // the lower the shotRate, the faster andy shoots
            shotTimer++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shotTimer > andy.Shot.get_shotRate())
        {

            // this needs redoing
            andy.Shot.setPosition(andy.getPosition());
            andy.Shots.push_back(andy.Shot);

            shotTimer = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shotTimer > andy.Shot.get_shotRate())
        {


            shotTimer = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shotTimer > andy.Shot.get_shotRate())
        {


            shotTimer = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shotTimer > andy.Shot.get_shotRate())
        {


            shotTimer = 0;
        }

        // Misc.
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