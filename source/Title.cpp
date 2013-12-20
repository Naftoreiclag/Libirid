/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Title.h"

#include <iostream>

void Title::printPrettyScreen(std::string centerifier, char solid)
{
    // Some space
    std::cout << std::endl;

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
        std::cout << centerifier;

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

    // Some space
    std::cout << std::endl;

    // Version number
    std::cout << centerifier << "Version 0.0.0.1   By Naftoreiclag" << std::endl;

    // Some space
    std::cout << std::endl;

    // Some more space
    std::cout << std::endl;

    // Display options
    std::cout << centerifier << "Select a number:" << std::endl;
    std::cout << std::endl;
    std::cout << centerifier << "1. Return to Game" << std::endl;
    std::cout << std::endl;
    std::cout << centerifier << "2. Player Creation" << std::endl;
    std::cout << centerifier << "3. Join Game" << std::endl;
    std::cout << centerifier << "4. Adjust Settings" << std::endl;
    std::cout << centerifier << "5. Exit Program" << std::endl;

    // Some space
    std::cout << std::endl;
}

void Title::run()
{
    // Print pretty prompt
    printPrettyScreen("  ", 219);

    int choice = 0;

    while(choice == 0)
    {
        // Print little triangle thing
        std::cout << "> ";

        // Extract line
        std::string line;
        std::getline(std::cin, line);

        if(line == "1")
        {
            choice = 1;
        }
    }
}
