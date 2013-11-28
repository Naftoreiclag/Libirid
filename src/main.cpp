/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include <string>

#include "util/Sysout.h"

#include "language/Lexicographer.h"
#include "command/CmdLexicographer.h"
#include "world/item/ItmLexicographer.h"

#include "Libirid.h"

// This is where the magic happens!
int main()
{
    // Set the display width to 80 chars long (for word-wrap)
    Sysout::setDisplayWidth(80);

    // Legendary string HAS BEEN CHANGED!!! DUN DUN DUNNNNN
    Sysout::println("Libirid");
    Sysout::println();

    // Add words
    Lexicographer::graph();

/*
    // Add commands
    CmdLexicographer::graph();

    // Add items
    ItmLexicographer::graph();
*/
    // I REALLY need a better name soon...
    Libirid::run();

    // Died quietly
    return 0;
}
