#pragma once

#include "libraries.hpp"

class Projectile : public sf::Sprite
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
		this->setScale(this->get_shotSize(), this->get_shotSize());
	}
	void set_shotSpeed(double x)
	{
		this->shotSpeed = x;
	}
	void set_shotRate(int x)
	{
		this->shotRate = x;
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

private:
	double shotDamage;
	double shotSize;
	double shotSpeed; // how fast the projectile moves
	int shotRate; // how often the projectile can be fired | number of frames of cooldown it takes to fire again
				  // the lower the shotRate, the faster it shoots
};