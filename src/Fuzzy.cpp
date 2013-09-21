#include "Fuzzy.h"

#include "util/Sysout.h"
#include "util/Point3i.h"

#include "Game.h"

// Debug mode boolean
bool Fuzzy::debugMode;

// The running game instance
Game* Fuzzy::runningGame;

void Fuzzy::run()
{
    // Debug mode check
    #ifdef DEBUG
    debugMode = true;
    #else
    debugMode = false;
    #endif

    // If we are in debug mode, then print that
    if(inDebug())
    {
        Sysout::println("Running in DEBUG mode!");
    }

    //
    bool running = true;

    while(running)
    {
        // Title screen
        // InputResult ir = Title::show();
        // switch(ir) ...

        // Run a game
        runningGame = new Game();
        runningGame->run();
        delete runningGame;
    }
}

bool Fuzzy::inDebug()
{
    return debugMode;
}
