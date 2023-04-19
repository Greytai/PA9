#pragma once

#include "libraries.hpp"
#include "item.hpp"

class Player
{
public:
	Player() // default constructor
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
		this->Size = x;
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

private:
	double moveSpeed;
	double Size;
	double Health;
	double shotDamage;
	double shotSize;
	double shotSpeed;
};