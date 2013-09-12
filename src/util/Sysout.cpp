#include "Sysout.h"

#include <iostream>
#include <string>
#include <unistd.h>

std::string Sysout::toFriendlyString(std::vector<std::string>* wordList)
{
    std::string returnVal = "[";

    if(wordList->size() == 0)
    {
        return returnVal + "]";
    }

    std::vector<std::string>::iterator it = wordList->begin();

    returnVal += *it;

    ++ it;

    while(it != wordList->end())
    {
        returnVal += ", " + *it;

        ++ it;
    }

    return returnVal + "]";
}

void Sysout::printSlow(std::string str)
{
    for(unsigned int index = 0; index < str.length(); ++ index)
    {
        // Print out one char
        std::cout << str.substr(index, 1);

        // Wait for some amount of time
        usleep(12500);

        //100000 = super slow
        // 50000 = slow
        // 25000 = medium
        // 12500 = fast
    }
}

void Sysout::print(std::string str)
{
    std::cout << str;
}

void Sysout::println(std::string str)
{
    std::cout << str << std::endl;
}

void Sysout::print(std::vector<std::string>* wordList)
{
    std::cout << toFriendlyString(wordList);
}

void Sysout::println(std::vector<std::string>* wordList)
{
    std::cout << toFriendlyString(wordList) << std::endl;
}

void Sysout::println()
{
    std::cout << std::endl;
}

Sysout::Sysout() {}
