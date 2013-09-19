#include "Fuzzy.h"

#include "util/Sysout.h"

#include "Game.h"

bool Fuzzy::debugMode;

Game* Fuzzy::runningGame;

void Fuzzy::run()
{
    // Debug mode check
    #ifdef DEBUG
    debugMode = true;
    #else
    debugMode = false;
    #endif

    // Put like, a main menu here or something

    // If we are in debug mode, then print that
    if(inDebug())
    {
        Sysout::println("Running in DEBUG mode!");
    }

    // Run a game
    runningGame = new Game();
    runningGame->run();
    delete runningGame;
}

bool Fuzzy::inDebug()
{
    return debugMode;
}
