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
		cout << "2. How to Play" << endl;
		cout << "3. Exit" << endl;
	};

	//Gets user input
	int userChoice()
	{
		int n = 0;

		do {
			cin >> n;
		} while (n < 1 || n>3);

		return n;
	};

	//Full menu
	void menuRunner()
	{
		do {

			system("cls");

			int choice = 0;

			this->displayMenu();

			this->setChoice(this->userChoice());

			switch (this->getChoice())
			{
			case 1: cout << "Playing Game..." << endl; //Start game function
				break;
			case 2: this->printHowToPlay();
				break;
			case 3: exit(0);
				break;
			default: cout << "Error." << endl;
			}
		} while (this->getChoice() == 2);


	};

	void printHowToPlay()
	{
		cout << "In Andy's Classroom, you are Andy." << endl;
		cout << "You are a professor who has been attacked by evil creatures while trying to help your students succeed." << endl;
		cout << "You decide to protect yourself, the students, and the world. Good luck." << endl;

		cout << "=========================" << endl;
		cout << "Controls:" << endl;
		cout << "W: Move Up" << endl;
		cout << "A: Move Left" << endl;
		cout << "S: Move Down" << endl;
		cout << "D: Move Right" << endl;
		cout << "ESC/Escape: Close Game" << endl;

		system("pause");
	};

private:
	int choice; //Player choice for menu
};
