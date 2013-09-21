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

    Point3i one(1, 2, 3);
    Point3i two(4, 5, 6);
    Point3i three;

    three = one + two;
    Sysout::println(Sysout::toFriendlyString(three));

    three = one - two;
    Sysout::println(Sysout::toFriendlyString(three));

    three = one * two;
    Sysout::println(Sysout::toFriendlyString(three));

    if(three == one * two)
    {
        Sysout::println("equal");
    }

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
