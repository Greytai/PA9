#include "menu.hpp"

#include <SFML/Graphics.hpp>
#include "libraries.hpp"
#include "andy.hpp"

int main(void)
{
	Menu menu;

	menu.menuRunner();
    
    //Program will only continue once they have entered "Play" in menu.

    //Creates game window called "window"
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Andy's Classroom");
    window.setFramerateLimit(30);

    // shot texture
    sf::Texture defaultShot;
    defaultShot.loadFromFile("A+.png");

    
    //andy.Shot.setTexture(defaultShot); // sets sprite texture to default
    //andy.Shots.push_back(andy.Shot); // puts a shot in the vector
    int shotTimer = 0; // timer that gets compared to andy's shotRate value to limit firerate

    //Test
    Andy andy;

    // hearts setup
    sf::Texture tHeartFull, tHeartEmpty;
    tHeartFull.loadFromFile("HeartFull.png");
    tHeartEmpty.loadFromFile("HeartEmpty.png");
    sf::Sprite HeartFull(tHeartFull);
    sf::Sprite HeartEmpty(tHeartEmpty);
    HeartFull.setScale(4, 4);
    HeartEmpty.setScale(4, 4);
    std::vector <sf::Sprite> MaxHeartFull;
    std::vector <sf::Sprite> MaxHeartEmpty;
    MaxHeartFull.push_back(HeartFull);
    MaxHeartFull.push_back(HeartFull);
    MaxHeartFull.push_back(HeartFull);
    MaxHeartEmpty.push_back(HeartEmpty);
    MaxHeartEmpty.push_back(HeartEmpty);
    MaxHeartEmpty.push_back(HeartEmpty);
    int curHearts = 0;
    int maxHearts = 0;
    int heartIterator = 0;

    //Game
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Moves Andy Up/North
        {
            andy.move(0, -andy.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Moves Andy Left/West
        {
            andy.move(-andy.getSpeed(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Moves Andy Down/South
        {
            andy.move(0, andy.getSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Moves Andy Right/East
        {
            andy.move(andy.getSpeed(), 0);
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

        // UI
        curHearts = andy.getHealth();
        maxHearts = andy.getMaxHealth();
        heartIterator = 0;
        while (heartIterator < curHearts)
        {
            MaxHeartFull[heartIterator].setPosition(15 + (55 * heartIterator), 15); // positions based off vector index
            window.draw(MaxHeartFull[heartIterator]);

            heartIterator++;
        }
        if (curHearts < maxHearts)
        {
            while ((heartIterator - curHearts) < (maxHearts - curHearts))
            {
                MaxHeartEmpty[heartIterator - curHearts].setPosition(15+ (55 * heartIterator), 15);
                window.draw(MaxHeartEmpty[heartIterator - curHearts]);

                heartIterator++;
            }

        }
        // Misc.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            exit(0);
        }



        window.draw(andy); //Creates Andy, character played by user
        window.display();
        window.clear();
    }

    //Exiting message in main console, not game console
    cout << "Thank you for playing!" << endl;


    return 0;
}