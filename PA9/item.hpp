# pragma once


#include "libraries.hpp"

class Item
{  
public:

	// setter
	void set_Name(string name)
	{
		this->Name = name;
	}
	void set_mod(double mod)
	{
		this->mod = mod;
	}
	void set_stat(string stat)
	{
		this->stat = stat;
	}

	// getter
	string get_Name()
	{
		return this->Name;
	}
	double get_mod()
	{
		return this->mod;
	}
	string get_stat()
	{
		return this->stat;
	}

private:
	string Name;
	double mod; // number by which the player's respective value is modified
	string stat; // the player stat the item modifies

};