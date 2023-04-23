#pragma once

#include "libraries.hpp"
#include "item.hpp"
#include "projectile.hpp"

class Player : public sf::Sprite
{
public:
	// default constructor
	Player() 
	{
		this->moveSpeed = -1;
		this->Size = -1;
		this->Health = -1;
		this->Shot = Projectile();
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

	void set_default()
	{
		this->set_moveSpeed(10);
		this->set_Size(3.5);
		this->set_Health(5);
		this->Shot.set_shotDamage(1);
		this->Shot.set_shotSize(1);
		this->Shot.set_shotSpeed(8);
		this->Shot.set_shotRate(5);
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

	// shot logic
	void set_ShotTexture(sf::Texture texture)
	{
		this->Shot.setTexture(texture);
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
	Projectile Shot;
};