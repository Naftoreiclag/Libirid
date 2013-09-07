#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

void printVec(std::vector<std::string>* v)
{
    for(std::vector<std::string>::iterator it = v->begin(); it != v->end(); ++ it)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    // Commands
    Command::newCommand(0)->setEroneous();
    Command::newCommand(1)->addAlias(0, "eat")->addAlias(1, "consume")->addAlias(2, "swallow")->addAlias(3, "drink");
    Command::newCommand(2)->addAlias(0, "jump")->addAlias(1, "hop")->addAlias(2, "leap");
    Command::newCommand(3)->addAlias(0, "dance");
    Command::newCommand(4)->addAlias(0, "sing");


    std::cout << "Fuzzy Computing Machine" << std::endl;

    bool running = true;

    std::vector<std::string>* v = new std::vector<std::string>();

    while(running)
    {
        std::cout << "Enter something:" << std::endl;
        std::cout << ">";
        getInput(v);
        std::cout << std::endl;
        std::cout << "You entered:" << std::endl;
        printVec(v);
        std::cout << std::endl;
        std::cout << "Trying to recognize command..." << std::endl;
        Command* theCmd = Command::getCommand(v->at(0));

        if(theCmd == Command::Erroneous())
        {
            std::cout << "Failed!" << std::endl;
        }
        else
        {
            std::cout << "Command recognized!" << std::endl;

            unsigned int cmdId = theCmd->getId();
            std::string cmdName = theCmd->getAlias(0);
            unsigned int aliasId = theCmd->getAliasId(v->at(0));
            std::string aliasName = theCmd->getAlias(aliasId);

            std::cout << "\tCommand Id: " << cmdId << " (" << cmdName << ")" << std::endl;
            std::cout << "\tAlias used: " << aliasId << " (" << aliasName << ")" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
