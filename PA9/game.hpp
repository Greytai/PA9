#pragma once

#include <SFML/Graphics.hpp>
#include "libraries.hpp"
#include "Player.hpp"
#include "enemy.hpp"

class Game
{
public:
	//Constructor
	Game() {};

	//Destructor
	~Game() {};

	/*
	Aiden Gardner
    Runs game
	*/
	void gameRunner()
	{
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
        Player andy;
        Enemy enemy;

        enemy.randomLocation();

        andy.Shot.projectilesUP.push_back(andy.Shot.projectile);
        andy.Shot.projectilesDOWN.push_back(andy.Shot.projectile);
        andy.Shot.projectilesLEFT.push_back(andy.Shot.projectile);
        andy.Shot.projectilesRIGHT.push_back(andy.Shot.projectile);

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
            for (size_t iUP = 0; iUP < andy.Shot.projectilesUP.size(); iUP++)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shotTimer >= andy.Shot.get_shotRate())
                {
                    andy.Shot.projectile.setPosition(andy.getPosition());
                    andy.Shot.projectilesUP.push_back(andy.Shot.projectile);

                    shotTimer = 0;
                }
                andy.Shot.projectilesUP[iUP].move(0, -andy.Shot.get_shotSpeed());

                window.draw(andy.Shot.projectilesUP[iUP]);
            }
            for (size_t iLEFT = 0; iLEFT < andy.Shot.projectilesLEFT.size(); iLEFT++)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shotTimer >= andy.Shot.get_shotRate())
                {
                    andy.Shot.projectile.setPosition(andy.getPosition());
                    andy.Shot.projectilesLEFT.push_back(andy.Shot.projectile);

                    shotTimer = 0;
                }
                andy.Shot.projectilesLEFT[iLEFT].move(-andy.Shot.get_shotSpeed(), 0);

                window.draw(andy.Shot.projectilesLEFT[iLEFT]);
            }
            for (size_t iRIGHT = 0; iRIGHT < andy.Shot.projectilesRIGHT.size(); iRIGHT++)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shotTimer >= andy.Shot.get_shotRate())
                {
                    andy.Shot.projectile.setPosition(andy.getPosition());
                    andy.Shot.projectilesRIGHT.push_back(andy.Shot.projectile);

                    shotTimer = 0;
                }
                andy.Shot.projectilesRIGHT[iRIGHT].move(andy.Shot.get_shotSpeed(), 0);


                window.draw(andy.Shot.projectilesRIGHT[iRIGHT]);
            }
            for (size_t iDOWN = 0; iDOWN < andy.Shot.projectilesDOWN.size(); iDOWN++)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shotTimer >= andy.Shot.get_shotRate())
                {
                    andy.Shot.projectile.setPosition(andy.getPosition());
                    andy.Shot.projectilesDOWN.push_back(andy.Shot.projectile);

                    shotTimer = 0;
                }
                andy.Shot.projectilesDOWN[iDOWN].move(0, andy.Shot.get_shotSpeed());


                window.draw(andy.Shot.projectilesDOWN[iDOWN]);
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
                    MaxHeartEmpty[heartIterator - curHearts].setPosition(15 + (55 * heartIterator), 15);
                    window.draw(MaxHeartEmpty[heartIterator - curHearts]);

                    heartIterator++;
                }

            }
            // Misc.
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                exit(0);
            }


            window.draw(enemy);

            window.draw(andy); //Creates Andy, character played by user
            window.display();
            window.clear();
        }
	};

private:
};