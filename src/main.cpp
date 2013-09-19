#include <string>

#include "util/Sysout.h"

#include "language/Lexicographer.h"
#include "command/CmdLexicographer.h"

#include "Fuzzy.h"

#include "Asnd.h"
#include "AsndDog.h"

#include <vector>

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

typedef bool (*Funk)();

// This is where the magic happens!
int main()
{
    Funk potato;
    potato = &Asnd::say;

    //std::vector<(*funk)()> funkies;

    //funkies.push_back(funk);

    potato();


    // Initialize
    init();

    // I REALLY need a better name soon...
    Fuzzy::run();

    // Died quietly
    return 0;
}
