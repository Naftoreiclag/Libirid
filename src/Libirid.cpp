/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid.h"

#include "util/Point3i.h"

#include "Game.h"

#ifdef DEBUG
#include "util/Sysout.h"
#endif // DEBUG

// The running game instance
Game* Libirid::runningGame;

void Libirid::run()
{

    // If we are in debug mode, then print that
    #ifdef DEBUG
    Sysout::println("Running in DEBUG mode!");
    Sysout::printDictionaryEntries();
    #endif

    //
    bool running = true;

    //
    while(running)
    {
        // Run a game
        runningGame = new Game();
        runningGame->load();
        runningGame->run();
        delete runningGame;
    }
}

int main()
{
    // Set the display width to 80 chars long (for word-wrap)
    Sysout::setDisplayWidth(80);

    // Legendary string HAS BEEN CHANGED!!! DUN DUN DUNNNNN
    Sysout::println("Libirid");
    Sysout::println();

    // Add words
    //Lexicographer::graph();

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

    Libirid::run();

    // Died quietly
    return 0;
}
