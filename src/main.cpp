#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "util/SequencedMap.h"

#include "Language.h"

void getInput(std::vector<std::string>* v)
{
    // Clear out the vector
    v->clear();

    // Extract a buffer for the input
    std::string line;
    std::getline(std::cin, line);
    std::stringstream sBuffer(line);

    // Get words
    std::string word;
    while(sBuffer >> word)
    {
        v->push_back(word);
    }
}

void splitWords(std::string str, std::vector<std::string>* v)
{
    v->clear();

    std::stringstream sBuffer(str);
    std::string word;
    while(sBuffer >> word)
    {
        v->push_back(word);
    }
}

void printVec(std::vector<std::string>* v)
{
    for(std::vector<std::string>::iterator it = v->begin(); it != v->end(); ++ it)
    {
        std::cout << *it << std::endl;
    }
}

SequencedMap<std::string, std::string> cmdByAlias;

bool alistatify(std::vector<std::string>* words)
{
    if(words->size() == 0)
    {
        return false;
    }

    // loop through all commands
    for(unsigned int cait = 0; cait < cmdByAlias.size(); ++ cait)
    {
        //
        std::cout << " Testing for " << cmdByAlias.first(cait) << std::endl;

        // get the words in its namecmdByAlias
        std::vector<std::string> cmdsWords;
        splitWords(cmdByAlias.first(cait), &cmdsWords);

        // check if we don't have enough input for this to be it
        if(words->size() < cmdsWords.size())
        {
            // skip
            continue;
        }

        //
        bool itIs = true;

        // loop through all command words
        std::vector<std::string>::iterator cmdsWordIt = cmdsWords.begin();
        std::vector<std::string>::iterator wordIt = words->begin();
        while(cmdsWordIt != cmdsWords.end())
        {
            // compare it to the input
            if(*cmdsWordIt != *wordIt)
            {
                itIs = false;
                break;
            }

            ++ cmdsWordIt;
            ++ wordIt;
        }

        //
        if(itIs)
        {
            // Do whatever

            // We did something!
            break;
        }
    }
}

int main()
{
    Sentence stnc;
    stnc.push_back("I");
    stnc.push_back("love");
    stnc.push_back("tuna");

    std::cout << stnc.at(0) << stnc.at(1) << stnc.at(2) << std::endl;

    cmdByAlias.append("eat", "MUNCH!");
    cmdByAlias.append("two words", "DOUBLE TROUBLE!");
    cmdByAlias.append("take a dump", "PLOP!");
    cmdByAlias.append("take", "KLEPTOMANIA!");

    std::cout << "Fuzzy Computing Machine" << std::endl;

    bool running = true;

    std::vector<std::string> v;

    while(running)
    {
        std::cout << "Enter something:" << std::endl;
        std::cout << "FCM:\\>";
        getInput(&v);
        std::cout << std::endl;
        std::cout << "You entered:" << std::endl;
        printVec(&v);
        std::cout << std::endl;
        std::cout << "Trying to recognize command..." << std::endl;

        alistatify(&v);

        std::cout << std::endl;
    }

    return 0;
}
