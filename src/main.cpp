#include <string>

#include "util/Sysout.h"

#include "language/Lexicographer.h"
#include "command/CmdLexicographer.h"

#include "Fuzzy.h"

// This is where the magic happens!
int main()
{
    // Set the display width to 80 chars long (for word-wrap)
    Sysout::setDisplayWidth(80);

    // Legendary string
    Sysout::println("Fuzzy Computing Machine");
    Sysout::println();

    // Add words
    Lexicographer::graph();

    // Add commands
    CmdLexicographer::graph();

    // I REALLY need a better name soon...
    Fuzzy::run();

    // Died quietly
    return 0;
}
