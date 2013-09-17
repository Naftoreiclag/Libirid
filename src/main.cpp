#include <string>

#include "util/Sysout.h"

#include "language/Lexicographer.h"
#include "command/CmdLexicographer.h"

#include "Game.h"

// Initialization put in a handy auxiliary function!
void init()
{
    //
    Sysout::setDisplayWidth(80);

    Sysout::println(Sysout::wordWrappify("Foo foo foo. Bar barfoo, bar quux foo. Foobar barfoo quux quux foobar. Bar'foo quux; bar foo quux quux. Foo foo foo. Bar barfoo, bar quux foo. Foobar barfoo quux quux foobar. Bar'foo quux; bar foo quux quux. Foo foo foo. Bar barfoo, bar quux foo. Foobar barfoo quux quux foobar. Bar'foo quux; bar foo quux quux."));

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

    // Reminds me of JME
    Game game;
    game.start();

    // Died quietly
    return 0;
}
