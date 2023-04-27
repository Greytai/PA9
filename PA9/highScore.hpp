#pragma once

#include "libraries.hpp"
#include <iostream>
#include <fstream>
using std::fstream;

class highScore
{
public:
	highScore(string name, int score) 
	{
		this->file.open("scores.txt");
		this->name = name;
		this->score = score;
	};

	//Deconstructor, closes file
	~highScore() { this->file.close(); };

	//Setter
	void setName(string name) { this->name = name; };
	void setScore(int score) { this->score = score; };

	//Getter
	string getName() { return this->name; };
	int getScore() { return this->score; };

	//Adds to txt document
	void addScore(string name, int score)
	{
		this->file << name << score << endl;
	};

	//Prints last score onto screen
	void printThisScore()
	{
		cout << this->getName() << this->getScore() << endl;
	};

	//Print all Scores onto screen, scores will not be in order from highest to lowest
	void printScores()
	{
		string tempStr;

		system("cls");

		cout << "===============" << endl;
		cout << "Current  Scores" << endl;
		cout << "===============" << endl;

		while(!this->file.eof())
		{
		this->file >> tempStr;

		cout << tempStr << endl;

		}
	};

	void appRunner()
	{
		int i = 0;

		cout << "What would you like to do?" << endl;

		cout << "1. Save and Enter score." << endl;
		cout << "2. Print all scores." << endl;
		cout << "3. Exit Game or Play Again. " << endl;

		
		do{
			cin >> i;
			cout << "Enter: ";
			switch (i)
			{
			case 1: this->addScore(this->getName(), this->getScore()); //Adds score to scores.txt
				break;
			case 2: this->printScores();//Prints doc onto screen
				break;
			case 3: cout << "3" << endl;
				break;
			default: cout << "Error." << endl;
			}
		}while (i!=3);

		system("cls");

	};

private:
	fstream file;
	string name;
	int score;
};