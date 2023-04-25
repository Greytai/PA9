#pragma once

#include "libraries.hpp"
#include <SFML/Graphics.hpp>
#include "character.hpp"

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

private:
	sf::Texture texture;
};