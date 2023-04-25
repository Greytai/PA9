#pragma once

//Used for generic character class
#include "libraries.hpp"
#include <SFML/Graphics.hpp>

class Character : public sf::Sprite
{
public:
	//Default Constructor
	Character()
	{
		this->health = 3;
		this->speed = 0.75;
		this->size = 3.5;
	};

	//Destructor
	~Character() {};

	//Setters
	void setHealth(int health) { this->health = health; };
	void setSpeed(double newSpeed) { this->speed = newSpeed; };
	void setSize(double newSize) {
		this->size = newSize;
		this->setScale(this->getSize(), this->getSize());
	};

	//Getters
	int getHealth() { return this->health; };
	double getSpeed() { return this->speed; };
	double getSize() { return this->size; };

private:
	double speed;
	double size;
	int health;
};