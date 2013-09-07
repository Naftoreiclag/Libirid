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

class CmdEat: public Command
{
    public:
        void execute()
        {
            std::cout << "munch munch munch" << std::endl;
        }
};

class CmdErroneous: public Command
{
    public:
        void execute()
        {
            std::cout << "This is an erroneous statement!" << std::endl;
        }
};

int main()
{
    //CommandFunction cf = new

    // Commands


    (new CmdErroneous())->setErroneous();
    (new CmdEat())->addAlias(0, "hi");

    Command* cm = Command::getCommand("hi");
    cm->execute();
    cm = Command::getCommand("Aaron");
    cm->execute();

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
        /*Command* theCmd = Command::getCommand(v->at(0));

        if(theCmd == Command::erroneous())
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
        }*/

        std::cout << std::endl;
    }

    return 0;
}
