#include "menu.hpp"
#include "libraries.hpp"
#include "game.hpp"
#include "test.hpp"
#include "highScore.hpp"

int main(void)
{
    //Random time generator
    srand((unsigned)time(NULL));

    Menu menu;
    string name;
    int score = 0;

    //Program will only continue once they have entered "Play" in menu.

    if (menu.getChoice() == 1) //When 1 is selected, will create game and run it.
    {
        Game game;
        score = game.gameRunner();
    }
    else if (menu.getChoice() == 4) //When 4 is selected, will create test cases and run them.
    {
        Test testcase;
    }

    //Get name for score
    name = menu.askName();

    highScore scoresList(name, score);

    scoresList.appRunner();

    return 0;
}