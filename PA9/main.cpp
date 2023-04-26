#include "menu.hpp"
#include "libraries.hpp"
#include "game.hpp"

int main(void)
{
    //Random time generator
    srand((unsigned)time(NULL));

	Menu menu;

    //Program will only continue once they have entered "Play" in menu.

    if (menu.getChoice() == 1)
    {
        Game game;
        game.gameRunner();
    }
    else if (menu.getChoice() == 4)
    {

    }

    //Exiting message in main console, not game console
    cout << "Thank you for playing!" << endl;


    return 0;
}