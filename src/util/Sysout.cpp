#include "Sysout.h"

#include <iostream>
#include <string>
#include <unistd.h>

#include "../language/Dictionary.h"
#include "../language/Grammar.h"

void Sysout::printDictionaryEntries()
{
    std::cout << Dictionary::numNouns() << " nouns registered:";
    for(unsigned int nounFocus = 0; nounFocus < Dictionary::numNouns(); ++ nounFocus)
    {
        std::cout << " " << Dictionary::getNoun(nounFocus)->getPluralForm();
    }
    std::cout << std::endl;
    std::cout << Dictionary::numAdjuncts() << " adjuncts registered:";
    for(unsigned int adjunctFocus = 0; adjunctFocus < Dictionary::numAdjuncts(); ++ adjunctFocus)
    {
        std::cout << " " << Dictionary::getAdjunct(adjunctFocus)->getForm();
    }
    std::cout << std::endl;
}

std::string Sysout::toFriendlyString(gmr::WordType wordType)
{
    if(wordType == gmr::noun)
    {
        return "noun";
    }
    if(wordType == gmr::adjunct)
    {
        return "adjunct";
    }
    if(wordType == gmr::modifier)
    {
        return "modifier";
    }
    if(wordType == gmr::article)
    {
        return "article";
    }
    if(wordType == gmr::gibberish)
    {
        return "gibberish";
    }
    return "hyper-gibberish";
}

std::string Sysout::toFriendlyString(gmr::Plurality plurality)
{
    return plurality == gmr::singular ? "singular" : plurality == gmr::plural ? "plural" : plurality == gmr::ambiguous ? "ambiguous" : "lolwut???";
}

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

void Sysout::print(int i)
{
    std::cout << i;
}

void Sysout::println(int i)
{
    std::cout << i << std::endl;
}

void Sysout::println()
{
    std::cout << std::endl;
}

Sysout::Sysout() {}
