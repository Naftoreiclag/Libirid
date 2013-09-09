#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include "util/SequencedMap.h"
#include "util/Sysout.h"

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
        Sysout::println(*it);
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
        Sysout::print(" Testing for ");
        Sysout::println(cmdByAlias.first(cait));

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

    Sysout::print(stnc.at(0));
    Sysout::print(stnc.at(1));
    Sysout::print(stnc.at(2));
    Sysout::println();

    cmdByAlias.append("eat", "MUNCH!");
    cmdByAlias.append("two words", "DOUBLE TROUBLE!");
    cmdByAlias.append("take a dump", "PLOP!");
    cmdByAlias.append("take", "KLEPTOMANIA!");

    Sysout::println("Fuzzy Computing Machine");

    bool running = true;

    std::vector<std::string> v;

    while(running)
    {
        Sysout::println("Enter something:");
        Sysout::print("FCM:\\>");
        getInput(&v);
        Sysout::println();
        Sysout::println("You entered:");
        printVec(&v);
        Sysout::println();
        Sysout::println("Trying to recognize command...");

        alistatify(&v);

        std::cout << std::endl;
    }

    return 0;
}
