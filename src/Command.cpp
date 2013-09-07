#include <map>
#include <string>

#include "Command.h"

std::map<unsigned int, Command*> Command::idCommandMap;
std::map<std::string, unsigned int> Command::aliasIdMap;
Command* Command::ERRONEOUS;

Command* Command::newCommand(unsigned int id)
{
    Command* newCmd = new Command(id);

    idCommandMap.insert(std::pair<unsigned int, Command*>(id, newCmd));

    return newCmd;
}

Command* Command::setEroneous()
{
    ERRONEOUS = this;

    return this;
}

Command* Command::getCommand(std::string alias)
{
    std::map<std::string, unsigned int>::iterator it = aliasIdMap.find(alias);

    if(it == aliasIdMap.end())
    {
        return ERRONEOUS;
    }

    return getCommand(it->second);
}

Command* Command::getCommand(unsigned int id)
{
    std::map<unsigned int, Command*>::iterator it = idCommandMap.find(id);

    if(it == idCommandMap.end())
    {
        return ERRONEOUS;
    }

    return it->second;
}

unsigned int Command::getAliasId(std::string alias)
{
    std::map<std::string, unsigned int>::iterator it = aliasAidMap.find(alias);

    if(it == aliasAidMap.end())
    {
        return 0;
    }

    return it->second;
}

std::string Command::getAlias(unsigned int aid)
{
    for(std::map<std::string, unsigned int>::iterator it = aliasAidMap.begin(); it != aliasAidMap.end(); ++ it)
    {
        if(it->second == aid)
        {
            return it->first;
        }
    }

    return "ERRONEOUS";
}

// Adds an alias
Command* Command::addAlias(unsigned int aid, std::string name)
{
    // Add an entry to the static map to point to this command
    aliasIdMap.insert(std::pair<std::string, unsigned int>(name, this->id));

    // Add an entry to local map to get the aid
    aliasAidMap.insert(std::pair<std::string, unsigned int>(name, aid));

    // Return this
    return this;
}

Command::Command(unsigned int id)
: id(id)
{
    //ctor
}
