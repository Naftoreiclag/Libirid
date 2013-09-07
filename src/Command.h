#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <map>

class Command
{
    public:
        // Creates and registers a new command
        static Command* newCommand(unsigned int id);

        static Command* getCommand(std::string alias);
        static Command* getCommand(unsigned int id);

        static Command* Erroneous(){ return ERRONEOUS; }

        Command* setEroneous();

        unsigned int getId(){ return id; }

        // Makes a new alias
        Command* addAlias(unsigned int aid, std::string name);
    protected:
    private:
        // Find a command based on id
        static std::map<unsigned int, Command*> idCommandMap;

        // Find an id based on alias
        static std::map<std::string, unsigned int> aliasIdMap;

        // The erroneous;
        static Command* ERRONEOUS;

        // Find an alias id based on alias for command
        std::map<std::string, unsigned int> aliasAidMap;

        // Constructor
        Command(unsigned int id);

        // Id
        unsigned int id;
};

#endif // COMMAND_H
