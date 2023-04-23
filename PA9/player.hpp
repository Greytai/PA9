#pragma once

#include "libraries.hpp"
#include "item.hpp"

class Player : public sf::Sprite
{
public:
	// default constructor
	Player() 
	{
		this->moveSpeed = -1;
		this->Size = -1;
		this->Health = -1;
		this->shotDamage = -1;
		this->shotSize = -1;
		this->shotSpeed = -1;
	}

	// setters
	void set_moveSpeed(double x)
	{
		this->moveSpeed = x;
	}
	void set_Size(double x)
	{
		this->Size = x; // stores value
		this->setScale(this->get_Size(), this->get_Size()); // sets value to real scale
	}
	void set_Health(double x)
	{
		this->Health = x;
	}
	void set_shotDamage(double x)
	{
		this->shotDamage = x;
	}
	void set_shotSize(double x)
	{
		this->shotSize = x;
	}
	void set_shotSpeed(double x)
	{
		this->shotSpeed = x;
	}
	void set_shotRate(double x)
	{
		this->shotRate = x;
	}
	void set_shotSprite(sf::Texture sprite)
	{
		this->shotSprite.setTexture(sprite);
	}

	void set_default()
	{
		this->set_moveSpeed(10);
		this->set_Size(3.5);
		this->set_Health(5);
		this->set_shotDamage(1);
		this->set_shotSize(1);
		this->set_shotSpeed(8);
		this->set_shotRate(5);
	}



	// getters
	double get_moveSpeed()
	{
		return this->moveSpeed;
	}
	double get_Size()
	{
		return this->Size;
	}
	double get_Health()
	{
		return this->Health;
	}
	double get_shotDamage()
	{
		return this->shotDamage;
	}
	double get_shotSize()
	{
		return this->shotSize;
	}
	double get_shotSpeed()
	{
		return this->shotSpeed;
	}
	sf::Sprite get_shotSprite()
	{
		return this->shotSprite;
	}

	// item logic
	void applyItem(Item item)
	{
		// this is probably an ass way of doing this... maybe enum? How to avoid if/else?
		if (item.get_stat() == "moveSpeed")
		{

		}
		else if (item.get_stat() == "Size")
		{

		}
	}

private:
	double moveSpeed;
	double Size;
	double Health;
	double shotDamage;
	double shotSize;
	double shotSpeed; // how fast the projectile moves
	double shotRate; // how often the projectile can be fired
	sf::Sprite shotSprite;
};