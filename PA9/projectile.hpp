#pragma once

#include "libraries.hpp"

class Projectile
{
public:
	Projectile()
	{
		this->set_shotDamage(-1);
		this->set_shotSize(-1);
		this->set_shotSpeed(-1);
		this->set_shotRate(-1);
	}

	// setters
	void set_shotDamage(double x)
	{
		this->shotDamage = x;
	}
	void set_shotSize(double x)
	{
		this->shotSize = x;
		this->projectile.setRadius(this->get_shotSize());
	}
	void set_shotSpeed(double x)
	{
		this->shotSpeed = x;
	}
	void set_shotRate(int x)
	{
		this->shotRate = x;
	}
	void set_shotFillColor(sf::Color color)
	{
		this->projectile.setFillColor(color);
	}

	// getters
	virtual double get_shotDamage()
	{
		return this->shotDamage;
	}
	virtual double get_shotSize()
	{
		return this->shotSize;
	}
	virtual double get_shotSpeed()
	{
		return this->shotSpeed;
	}
	virtual int get_shotRate()
	{
		return this->shotRate;
	}

	// misc.
	sf::CircleShape projectile;
	std::vector <sf::CircleShape> projectilesUP;
	std::vector <sf::CircleShape> projectilesDOWN;
	std::vector <sf::CircleShape> projectilesLEFT;
	std::vector <sf::CircleShape> projectilesRIGHT;

private:
	double shotDamage;
	double shotSize;
	double shotSpeed; // how fast the projectile moves
	int shotRate; // how often the projectile can be fired | number of frames of cooldown it takes to fire again
				  // the lower the shotRate, the faster it shoots
};