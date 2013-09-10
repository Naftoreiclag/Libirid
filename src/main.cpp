#include <string>
#include <sstream>
#include <vector>
#include <vector>
#include <map>

#include "util/SequencedMap.h"
#include "util/Sysout.h"
#include "util/Sysin.h"

#include "language/Grammar.h"

#include "Command.h"

SequencedMap<std::string, Command*> cmdByAlias;

bool alistatify(std::vector<std::string>* inputWords)
{
    // If we have no words
    if(inputWords->size() == 0)
    {
        // [Then obviously it cannot match anything]

        // Return unsuccessful
        return false;
    }

    // Loop through all commands
    for(unsigned int cait = 0; cait < cmdByAlias.size(); ++ cait)
    {
        // Info
        Sysout::print(" Testing for ");
        Sysout::println(cmdByAlias.first(cait));

        // Split the command's alias into a vector of individual words
        std::vector<std::string> cmdsWords;
        Sysin::splitWords(cmdByAlias.first(cait), &cmdsWords);

        // Check if we have enough input for it to be possible
        if(inputWords->size() < cmdsWords.size())
        {
            // [It cannot be this command]

            // Skip this one
            continue;
        }

        // Keeps track if the command comparison proves the input to start with the needed command
        bool commandMatches = true;

        // Get iterator for command words
        std::vector<std::string>::iterator commandWordFocus = cmdsWords.begin();

        // Iterate through the input words parallel
        std::vector<std::string>::iterator inputWordFocus = inputWords->begin();

        // Iterate through the command words
        while(commandWordFocus != cmdsWords.end())
        {
            // Check if this word is different
            if(*commandWordFocus != *inputWordFocus)
            {
                // [It is not]

                // The command therefore does not match
                commandMatches = false;

                // Stop checking, because it cannot possibly be it anymore
                break;
            }

            // Next
            ++ commandWordFocus;
            ++ inputWordFocus;
        }

        // If the command matches
        if(commandMatches)
        {
            // Loop through that command's sentence structures
            // To see if they fit.

            // Return successful
            return true;
        }
    }

    // [None of the commands matched]

    // Return unsuccessful
    return false;
}

int main()
{
    // Register commands
    Command* cmdEat = new Command();
    cmdByAlias.append("eat", cmdEat);

    // Legend
    Sysout::println("Fuzzy Computing Machine");

    // Running
    bool running = true;

    // Last input vector
    std::vector<std::string>* lastInput = new std::vector<std::string>();

    // While running, run!
    while(running)
    {
        Sysout::println("Enter something:");

        Sysout::print("FCM:\\>");
        Sysin::getWords(lastInput);
        Sysout::println();

        std::vector<std::string> vc(*lastInput);
        Sysout::print("The copy of the vector is: ");
        Sysout::println(vc);
        Sysout::println();

        Sysout::print("You entered:");
        Sysout::println(lastInput);

        Sysout::println("Trying to recognize command...");

        alistatify(lastInput);

        Sysout::println();
    }

    delete lastInput;

    // Died quietly
    return 0;
}
