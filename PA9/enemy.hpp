#pragma once

#include "libraries.hpp"
#include <SFML/Graphics.hpp>
#include "character.hpp"
#include <cstdlib>

/*
Aiden Gardner
Enemy class, inherits generic character class
*/
class Enemy : public Character
{
public:
	//Constructor
	Enemy() 
	{
		this->texture.loadFromFile("Student.png");
		this->setTexture(texture);

		this->setSize(5);
	};

	//Destructor
	~Enemy() {};

	//Setters

	//Getters


	//Randomly determines a location on the map for enemy to spawn in
	void randomLocation()
	{
		int Quadrant, randX, randY = 0;

		Quadrant = detQuad();

		randX = xGen(Quadrant);
		randY = yGen(Quadrant);

		this->setPosition(randX, randY);

	};

	//Randomly determines a number 1-4 for quadrant spawning locations.
	int detQuad() 
	{
		return (1 + rand()% 4);
	}

	//Randomly determines a number between 0-1500
	//Intended for X-Values only
	int xGen(int quad)
	{ // X maximum: ~1500
		int num = 0;

		//return (rand()%1500);

		switch (quad)
		{
		case 1: num = (rand()%1500);
			if (num < 750) { num + 750; }
			if (num > 1500) { num = (num - abs(num - 1500)); }
			break;
		case 2: num = (rand()%750);
			break;
		case 3: num = (rand() % 750);
			break;
		case 4: num = (rand() % 1500);
			if (num < 750) { num + 750; }
			if (num > 1500) { num = (num - abs(num - 1500)); }
			break;
		default: return 0;
		}

		return num;
	};

	int yGen(int quad)  //Y maximum: ~700
	{
		int num = 0;
		//return (rand() % 700);
		//250 middle
		switch (quad)
		{
		case 1: num = (rand() % 250);
			break;
		case 2: num = (rand() % 250);
			break;
		case 3: num = (rand() % 700);
			if (num < 250) { num + 250; }
			if (num > 700) { num = (num - abs(num - 700)); }
			break;
		case 4: num = (rand() % 700);
			if (num < 250) { num + 250; }
			if (num > 700) { num = (num - abs(num - 700)); }
			break;
		default: return 0;
		}

		return num;
	};



private:
	sf::Texture texture;
};