/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Title.h"

#include <iostream>

void Title::run()
{
    //
    std::cout << std::endl << std::endl;

    // Solid char
    char solid = 219;

    // The logo
    std::string logo[9] =
    {
        "100000000100000000000000000000001",
        "100000000100000000000000000000001",
        "100000100100000010000000001000001",
        "100000000100000000000000000000001",
        "100011100111001110010110111000111",
        "100000100100100010011000001001001",
        "100000100100100010010000001001001",
        "100000100100100010010000001001001",
        "111100100111000010010000001000111"
    };

    // For every line
    for(int i = 0; i < 9; ++ i)
    {
        // Some space
        std::cout << "                      ";

        // For every char
        for(int j = 0; j < 33; ++ j)
        {
            // If its one
            if(logo[i].at(j) == '1')
            {
                // Print solid
                std::cout << solid;
            }

            // If its zero
            else
            {
                // Print blank
                std::cout << ' ';
            }
        }

        // Make space for next line
        std::cout << std::endl;
    }
}
