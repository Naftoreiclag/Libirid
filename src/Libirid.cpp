#include "Libirid.h"

#include "util/Point3i.h"

#include "Game.h"

#ifdef DEBUG
#include "util/Sysout.h"
#endif // DEBUG

// Debug mode boolean
bool Libirid::debugMode;

// The running game instance
Game* Libirid::runningGame;

void Libirid::run()
{
    // Debug mode check
    #ifdef DEBUG
    debugMode = true;
    #else
    debugMode = false;
    #endif

    // If we are in debug mode, then print that
    #ifdef DEBUG
    Sysout::println("Running in DEBUG mode!");
    Sysout::printDictionaryEntries();
    #endif

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

bool Libirid::inDebug()
{
    return debugMode;
}
