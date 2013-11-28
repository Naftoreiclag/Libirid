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

    //
    Node animals(NULL);
    animals.setName("animals");

        Node dog(&animals);
        dog.setName("dog");

            Node corgi(&dog);
            corgi.setName("corgi");

            Node retriever(&dog);
            retriever.setName("retriever");

        Node snake(&animals);
        snake.setName("snake");

            Node rattler(&snake);
            rattler.setName("rattler");

            Node kobra(&snake);
            kobra.setName("kobra");

        Node cat(&animals);
        cat.setName("cat");

            Node ragdoll(&cat);
            ragdoll.setName("ragdoll");

            Node aussie(&cat);
            aussie.setName("aussie");

            Node calico(&cat);
            calico.setName("calico");

    animals.printHeirachy(0);

    //aussie.setParent(&dog);
    //animals.printHeirachy(0);

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
