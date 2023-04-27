#pragma once

#include "libraries.hpp"
#include <SFML/Graphics.hpp>
#include "character.hpp"
#include "projectile.hpp"

/*
Aiden Gardner
Class for playable character, inherits character class
Creates graphics in the constuctor, cleans up main.
*/
class Player : public Character
{
public:
	//Constructor
	Player() : Character() 
	{ 
	this->maxHealth = 3;
	this->Shot = Projectile();

	this->set_default();

	//Visuals
	this->texture.loadFromFile("Andy.png");
	this->setTexture(texture);
	};

	//Deconstructor
	~Player() {};

	//Setter
	void setMaxHealth(int newMaxHealth) { this->maxHealth = newMaxHealth; };

	//Getter
	int getMaxHealth() { return (this->maxHealth); };

	//Unique
	Projectile Shot;

	//Gets values to default/standard values
	void set_default()
	{
		// player
		this->setSpeed(10);
		this->setSize(3.5);
		this->setHealth(3);
		this->setMaxHealth(3);
		this->setPosition(960, 540);

		// test case 3
		if (this->getSpeed() == 10 && this->getSize() == 3.5 && this->getHealth() == 3 && this->getMaxHealth() == 3)
		{
			this->isDefault = true;
		}

		// player shot
		this->Shot.set_shotFillColor(sf::Color::Red);
		this->Shot.set_shotDamage(1);
		this->Shot.set_shotSize(5);
		this->Shot.set_shotSpeed(30);
		this->Shot.set_shotRate(10);

		// test case 4
		if (this->Shot.get_shotDamage() == 1 && this->Shot.get_shotSize() == 5 && this->Shot.get_shotSpeed() == 30 && this->Shot.get_shotRate() == 10)
		{
			this->isShotDefault = true;
		}
	}

private:
	//Max Health
	int maxHealth;
	bool isDefault;
	bool isShotDefault;

	//Visuals
	sf::Texture texture;
};