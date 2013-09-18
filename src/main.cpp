#include <string>

#include "util/Sysout.h"

#include "language/Lexicographer.h"
#include "command/CmdLexicographer.h"

#include "Fuzzy.h"

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

    // I REALLY need a better name soon...
    Fuzzy fuzzy;
    fuzzy.start();

    // Died quietly
    return 0;
}
