#include "Sysin.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void Sysin::getWords(std::vector<std::string>* wordList)
{
    // Clear out the vector
    wordList->clear();

    // Extract a buffer for the input
    std::string line;
    std::getline(std::cin, line);
    std::stringstream sBuffer(line);

    // Get words
    std::string word;
    while(sBuffer >> word)
    {
        wordList->push_back(word);
    }
}

// Constructor
Sysin::Sysin() {}
