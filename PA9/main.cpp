#include "menu.hpp"
#include "libraries.hpp"
#include "game.hpp"
#include "test.hpp"

int main(void)
{
    //Random time generator
    srand((unsigned)time(NULL));

	Menu menu;

    //Program will only continue once they have entered "Play" in menu.

    if (menu.getChoice() == 1) //When 1 is selected, will create game and run it.
    {
        Game game;
        game.gameRunner();
    }
    else if (menu.getChoice() == 4) //When 4 is selected, will create test cases and run them.
    {
        Test testcase;
        
    }

    //Exiting message in main console, not game console
    cout << "Thank you for playing!" << endl;


    return 0;
}