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
class Andy : public Character
{
public:
	//Constructor
	Andy() : Character() 
	{ 
	this->maxHealth = 3;
	this->Shot = Projectile();

	this->set_default();

	//Visuals
	this->texture.loadFromFile("Andy.png");
	this->setTexture(texture);
	};

	//Deconstructor
	~Andy() {};

	//Setter
	void setMaxHealth(int newMaxHealth) { this->maxHealth = newMaxHealth; };
	
	//Getter
	int getMaxHealth() { return (this->maxHealth); };

	//Unique
	std::vector <Projectile> Shots;
	Projectile Shot;

	//Gets values to default/standard values
	void set_default()
	{
		this->setSpeed(10);
		this->setSize(3.5);
		this->setHealth(3);
		this->setMaxHealth(3);
		this->Shot.set_shotDamage(1);
		this->Shot.set_shotSize(1);
		this->Shot.set_shotSpeed(8);
		this->Shot.set_shotRate(1);
	}

private:
	//Max Health
	int maxHealth;

	//Visuals
	sf::Texture texture;
};