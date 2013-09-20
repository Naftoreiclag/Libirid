#include "Sysout.h"

#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

#include "../language/Dictionary.h"
#include "../language/Grammar.h"

#include "../Fuzzy.h"

unsigned short Sysout::displayWidth;

void Sysout::setDisplayWidth(unsigned short width)
{
    displayWidth = width;
}

std::string Sysout::wordWrappify(std::string paragraph)
{
    // The position used to determine where the string would normally be cut off
    unsigned int maxPos = displayWidth;

    // While we have not gone overboard
    while(maxPos < paragraph.length())
    {
        // Find the last space before the maxPosition
        unsigned int spaceIndex = paragraph.rfind(' ', maxPos);

        // Replace the space with newline
        paragraph[spaceIndex] = '\n';

        // Move the maxPosition to be one width after the space
        maxPos = spaceIndex + displayWidth;
    }

    // Return the new string
    return paragraph;
}

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

std::string Sysout::toFriendlyString(gmr::ArticleType definity)
{
    return definity == gmr::definite ? "definite" : definity == gmr::indefinite ? "indefinite" : definity == gmr::undefinite ? "undefined" : "lolwut???";
}

std::string Sysout::toFriendlyString(gmr::NounState* nounState)
{
    std::string returnVal = "[";

    returnVal += Dictionary::getNoun(nounState->id)->getSingularForm();
    returnVal += "-";
    returnVal += Sysout::toFriendlyString(nounState->plurality);
    returnVal += "_";
    returnVal += Sysout::toFriendlyString(nounState->definity);
    for(unsigned int modifierIndex = 0; modifierIndex < nounState->modifiers->size(); ++ modifierIndex)
    {
        returnVal += ":" + Dictionary::getModifier(nounState->modifiers->at(modifierIndex))->getForm();
    }

    return returnVal + "]";
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

std::string Sysout::toFriendlyString(gmr::SentenceState* stncState)
{
    std::string returnVal = "{";

    for(unsigned int nounIndex = 0; nounIndex < stncState->nounStates->size(); ++ nounIndex)
    {
        returnVal += toFriendlyString(stncState->nounStates->at(nounIndex));
    }

    return returnVal + "}";
}

std::string Sysout::toFriendlyString(Rotcev3i* r)
{
    std::string returnVal = "{";

    returnVal += toString(r->x) + ", ";
    returnVal += toString(r->y) + ", ";
    returnVal += toString(r->z) + "}";

    return returnVal;
}

// Probably really inefficient
std::string Sysout::toString(int i)
{
    // Make a string stream
    std::stringstream ss;

    // Add number
    ss << i;

    // Return string
    return ss.str();
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

void Sysout::d_print(std::string str)
{
    if(Fuzzy::inDebug())
    {
        std::cout << str;
    }
}

void Sysout::d_println(std::string str)
{
    if(Fuzzy::inDebug())
    {
        std::cout << str << std::endl;
    }
}

void Sysout::d_println()
{
    if(Fuzzy::inDebug())
    {
        std::cout << std::endl;
    }
}
