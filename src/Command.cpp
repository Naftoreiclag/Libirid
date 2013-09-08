#include <map>
#include <string>
#include <vector>

#include "Command.h"

std::map<std::string, Command*> Command::commandByAliasLookup;

Command* Command::ERRONEOUS;

Command* Command::getCommand(std::string aliasName)
{
    std::map<std::string, Command*>::iterator it = commandByAliasLookup.find(aliasName);

    if(it == commandByAliasLookup.end())
    {
        return ERRONEOUS;
    }

    return it->second;
}

unsigned int Command::getAlias(std::string aliasName)
{
    std::map<std::string, unsigned int>::iterator it = aliasIdLookup.find(aliasName);

    if(it == aliasIdLookup.end())
    {
        return 0;
    }

    return it->second;
}

Command* Command::addAlias(unsigned int aliasId, std::string aliasName)
{
    Command::commandByAliasLookup.insert(std::pair<std::string, Command*>(aliasName, this));

    aliasIdLookup.insert(std::pair<std::string, unsigned int>(aliasName, aliasId));

    return this;
}

Command* Command::setErroneous()
{
    Command::ERRONEOUS = this;

    return this;
}

Command::Command()
{
    //ctor
}
