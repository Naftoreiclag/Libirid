#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "Command.h"

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

std::map<std::string, std::string> cmdByAlias;

bool alistatify(std::vector<std::string>* words)
{
    if(words->size() == 0)
    {
        return false;
    }

    // loop through all commands
    for(std::map<std::string, std::string>::iterator cait = cmdByAlias.begin(); cait != cmdByAlias.end(); ++ cait)
    {
        //
        std::cout << "- Testing for " << cait->first << std::endl;

        // get the words in its name
        std::vector<std::string> cmdsWords;
        splitWords(cait->first, &cmdsWords);

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
            std::cout << cait->second << std::endl;

            // We did something!
            break;
        }
    }
}

int main()
{
    cmdByAlias.insert(std::pair<std::string, std::string>("eat", "MUNCH!"));
    cmdByAlias.insert(std::pair<std::string, std::string>("two words", "DOUBLE TROUBLE!"));
    cmdByAlias.insert(std::pair<std::string, std::string>("take", "KLEPTOMANIA!"));
    cmdByAlias.insert(std::pair<std::string, std::string>("take a dump", "PLOP!"));

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
