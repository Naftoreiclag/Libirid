#include <string>

#include "util/Sysout.h"

#include "language/Lexicographer.h"
#include "command/CmdLexicographer.h"

#include "Game.h"

// Initialization put in a handy auxiliary function!
void init()
{
    // Set the display width to 80 chars long
    Sysout::setDisplayWidth(80);

    // Legend
    Sysout::println("Fuzzy Computing Machine");
    Sysout::println();

    // Add words
    Lexicographer::graph();

    // Add commands
    CmdLexicographer::graph();
}

// This is where the magic happens!
int main()
{
    // Initialize
    init();

    // Put like, a main menu here or something

    // Instantiate a new game
    Game game;

    // Start it
    game.start();

    // Died quietly
    return 0;
}
