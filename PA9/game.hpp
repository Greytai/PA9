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
	int gameRunner()
	{
        //Creates game window called "window"
        sf::RenderWindow window(sf::VideoMode(1920, 1080), "Andy's Classroom");
        window.setFramerateLimit(30);

        // shot texture
        sf::Texture defaultShot;
        defaultShot.loadFromFile("A+.png");

        // enemy texture
        sf::Texture enemyTexture;
        enemyTexture.loadFromFile("bug.png");

        // classroom texture
        sf::Texture classroomTexture;
        classroomTexture.loadFromFile("Classroom.jpg");
        sf::Sprite classroomSprite;
        classroomSprite.setTexture(classroomTexture);
        classroomSprite.setScale(2, 1.5);


        //andy.Shot.setTexture(defaultShot); // sets sprite texture to default
        //andy.Shots.push_back(andy.Shot); // puts a shot in the vector
        int shotTimer = 0; // timer that gets compared to andy's shotRate value to limit firerate

        //Test
        Player andy;

        Enemy enemy;
        enemy.setTexture(enemyTexture);

        std::vector <Enemy> enemies;
        enemies.push_back(Enemy(enemy));
        enemies[0].setPosition(-1000, -1000);
        enemies.push_back(Enemy(enemy));
        enemy.randomLocation();
        enemies.push_back(Enemy(enemy));

        int enemyIterator;
        int x, y;

        andy.Shot.projectilesUP.push_back(andy.Shot.projectile);
        andy.Shot.projectilesUP[0].setPosition(5000, 5000);
        andy.Shot.projectilesDOWN.push_back(andy.Shot.projectile);
        andy.Shot.projectilesDOWN[0].setPosition(5000, 5000);
        andy.Shot.projectilesLEFT.push_back(andy.Shot.projectile);
        andy.Shot.projectilesLEFT[0].setPosition(5000, 5000);
        andy.Shot.projectilesRIGHT.push_back(andy.Shot.projectile);
        andy.Shot.projectilesRIGHT[0].setPosition(5000, 5000);

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

        // invincibility frames
        sf::Clock iFramesClock; // will track time since last hit

        // Score and Time
        int intTime = 0, intScore = 0;
        string stringTime, stringScore;
        sf::Clock clock;
        sf::Time time;
        sf::Text curTimeText, scoreText, timeText, curScoreText;
        sf::Font font;
        
        font.loadFromFile("RobotoMono-Regular.ttf");
       
        curScoreText.setFont(font);
        curScoreText.setCharacterSize(40);
        curScoreText.setFillColor(sf::Color::White);
        curScoreText.setStyle(sf::Text::Bold);
        curScoreText.setPosition(175, 65);
       
        scoreText.setFont(font);
        scoreText.setCharacterSize(40);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setStyle(sf::Text::Bold);
        scoreText.setPosition(17, 65);
        scoreText.setString("Score:");

        curTimeText.setFont(font);
        curTimeText.setCharacterSize(40);
        curTimeText.setFillColor(sf::Color::White);
        curTimeText.setStyle(sf::Text::Bold);
        curTimeText.setPosition(175, 105);

        timeText.setFont(font);
        timeText.setCharacterSize(40);
        timeText.setFillColor(sf::Color::White);
        timeText.setStyle(sf::Text::Bold);
        timeText.setPosition(17, 105);
        timeText.setString("Time:");

        bool windowisOpen;


        // GAME STARTS HERE
        while (window.isOpen())
        {
            if (window.isOpen()) // test case 5
            {
                windowisOpen = true;
            }
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            window.draw(classroomSprite);

            // Movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && andy.getPosition().y > 175) //Moves Andy Up/North
            {
                andy.move(0, -andy.getSpeed());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && andy.getPosition().x > 0) //Moves Andy Left/West
            {
                andy.move(-andy.getSpeed(), 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && andy.getPosition().y < 890) //Moves Andy Down/South
            {
                andy.move(0, andy.getSpeed());
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && andy.getPosition().x < 1868) //Moves Andy Right/East
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

            // Enemy logic
            if ((rand() % 60) == 1) // rand spawn
            {
                enemy.randomLocation();
                enemies.push_back(Enemy(enemy));
            }
            
            enemyIterator = 0;
            
            while (enemyIterator < enemies.size()) // enemy movement
            {
                if (enemies[enemyIterator].getPosition().y < 175)
                {
                    // can't go up
                    y = rand() % 30;
                }
                else if (enemies[enemyIterator].getPosition().y > 890)
                {
                    // can't go down
                    y = -(rand() % 30);
                }

                if (enemies[enemyIterator].getPosition().x < 0)
                {
                    // can't go left
                    x = rand() % 30;
                }
                else if (enemies[enemyIterator].getPosition().x > 1868)
                {
                    // can't go right
                    x = -(rand() % 30);
                }

                if (enemyIterator != 0)
                {
                    enemies[enemyIterator].move(x, y);
                }
                enemyIterator++;
            }

            
            enemyIterator = 0;
            while (enemyIterator < enemies.size())
            {
                // andy gets hit
                if (andy.getGlobalBounds().intersects(enemies[enemyIterator].getGlobalBounds()) && iFramesClock.getElapsedTime().asSeconds() > 1.5) 
                {
                    if (andy.getHealth() > 1) // still alive after hit
                    {
                        andy.setHealth(andy.getHealth() - 1);
                    }
                    else if (andy.getHealth() == 1) // dead after hit
                    {
                        andy.setHealth(0);
                        andy.setIsAlive(false);
                    }
                    iFramesClock.restart(); // responsible for invincibility after being hit
                }

                // enemy gets shot
                for (size_t i = 0; i < andy.Shot.projectilesUP.size(); i++)
                {
                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (andy.Shot.projectilesUP[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
                        {
                          enemies.erase(enemies.begin() + k);
                          andy.Shot.projectilesUP.erase(andy.Shot.projectilesUP.begin() + i);
                          intScore += 2.5 * clock.getElapsedTime().asSeconds(); // score increases on kill

                          break;
                        }
                    }
                }
                for (size_t i = 0; i < andy.Shot.projectilesLEFT.size(); i++)
                {
                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (andy.Shot.projectilesLEFT[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
                        {
                            enemies.erase(enemies.begin() + k);
                            andy.Shot.projectilesLEFT.erase(andy.Shot.projectilesLEFT.begin() + i);
                            intScore += 2.5 * clock.getElapsedTime().asSeconds(); // score increases on kill

                            break;
                        }
                    }
                }
                for (size_t i = 0; i < andy.Shot.projectilesDOWN.size(); i++)
                {
                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (andy.Shot.projectilesDOWN[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
                        {
                            enemies.erase(enemies.begin() + k);
                            andy.Shot.projectilesDOWN.erase(andy.Shot.projectilesDOWN.begin() + i);
                            intScore += 2.5 * clock.getElapsedTime().asSeconds(); // score increases on kill

                            break;
                        }
                    }
                }
                for (size_t i = 0; i < andy.Shot.projectilesRIGHT.size(); i++)
                {
                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (andy.Shot.projectilesRIGHT[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
                        {
                            enemies.erase(enemies.begin() + k);
                            andy.Shot.projectilesRIGHT.erase(andy.Shot.projectilesRIGHT.begin() + i);
                            intScore += 2.5 * clock.getElapsedTime().asSeconds(); // score increases on kill

                            break;
                        }
                    }
                }

                // draw enemies
                window.draw(enemies[enemyIterator]);
                enemyIterator++;
            }
          

            // UI
                // Health
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

                // Timekeeping
            intTime = clock.getElapsedTime().asSeconds(); // starts from time to float to int
            stringTime = std::to_string(intTime); // sets value to string
            curTimeText.setString(stringTime); // prints as time

            window.draw(curTimeText);
            window.draw(timeText);

             // Scorekeeping
            stringScore = std::to_string(intScore);
            curScoreText.setString(stringScore);

            window.draw(curScoreText);
            window.draw(scoreText);

            // Gameover Procedure
            if (andy.getIsAlive() == false)
            {
                // GAME OVER
                return intScore;
            }

            // Misc.
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                exit(0);
            }

            window.draw(andy); //Creates Andy, character played by user
            window.display();
        }
	};

private:

};