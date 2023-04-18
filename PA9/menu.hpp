#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
Aiden Gardner
Text-based menu
*/
class Menu
{
public:
	//Constructor
	Menu() { this->choice = 0; };
	//Setter
	void setChoice(int num) { this->choice = num; };
	//Getter
	int getChoice() { return this->choice; };

	//display menu and options
	void displayMenu()
	{
		cout << "================" << endl;
		cout << "Andy's Classroom" << endl;
		cout << "================" << endl;

		cout << endl;

		cout << "Please enter one of the following options." << endl;

		cout << endl;

		cout << "1. Play" << endl;
		cout << "2. Exit" << endl;
	};

	//Gets user input
	int userChoice()
	{
		int n = 0;

		do {
			cin >> n;
		} while (n < 1 || n>2);

		return n;
	};

	//Full menu
	void menuRunner()
	{
		int choice = 0;

		this->displayMenu();

		this->setChoice(this->userChoice());

		switch (this->getChoice())
		{
		case 1: cout << "Game." << endl; //Start game function
			break;
		case 2: exit(0);
			break;
		default: cout << "Error." << endl;
		}
	};

private:
	int choice; //Player choice for menu
};
