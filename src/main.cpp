#include <string>
#include <vector>
#include <map>

#include "util/Sysout.h"
#include "util/Sysin.h"

#include "language/Lexicographer.h"
#include "command/CmdLexicographer.h"

#include "Game.h"

// Initialization put in a handy auxiliary function!
void init()
{
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
    /* === Testing === */

    // Put something here, k?

    /* === Actual program === */

    // Initialize
    init();

    //
    Game game;

    game.start();

    // Died quietly
    return 0;
}
