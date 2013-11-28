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

#include "expanse/Node.h"

//#define NULL (void *)0

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

    /*Node tramstation(NULL);
    tramstation.setName("Tram Station");
    Node tram(&tramstation);
    tram.setName("The tram");
    Node dylan(&tram);
    dylan.setName("Dylan");
    Node box(&dylan);
    box.setName("Box");
    Node donut(&box);
    donut.setName("Plain donut");
    Node jellyDonut(&box);
    jellyDonut.setName("Jelly donut");
    Node cafe(&tramstation);
    cafe.setName("Coffee shop");

    tramstation.printHeirachy(0);*/



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
