#include <string>
#include <vector>
#include <map>

#include "util/SequencedMap.h"
#include "util/Sysout.h"
#include "util/Sysin.h"
#include "util/SentenceStateBuilder.h"

#include "language/Grammar.h"
#include "language/Dictionary.h"
#include "language/Lexicographer.h"

#include "command/CmdDictionary.h"
#include "command/CmdLexicographer.h"

#include "command/Command.h"
#include "command/CommandEat.h"
#include "command/CommandDance.h"

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
    CmdDictionary::cmdByAlias->append("eat", new CommandEat());
    CmdDictionary::cmdByAlias->append("dance", new CommandDance());
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
