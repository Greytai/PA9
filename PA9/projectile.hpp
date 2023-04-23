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
	}
	void set_shotSpeed(double x)
	{
		this->shotSpeed = x;
	}
	void set_shotRate(double x)
	{
		this->shotRate = x;
	}

	// getters
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
	double get_shotRate()
	{
		return this->shotRate;
	}

private:
	double shotDamage;
	double shotSize;
	double shotSpeed; // how fast the projectile moves
	double shotRate; // how often the projectile can be fired
};