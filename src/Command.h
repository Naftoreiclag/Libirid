#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>
#include <vector>

class Command
{
    public:
        static Command* getCommand(std::string aliasName);
        static Command* erroneous() { return ERRONEOUS; }

        static Command* generateErroneous();

        Command* addAlias(unsigned int aliasId, std::string aliasName);
        Command* setErroneous();

        unsigned int getAlias(std::string aliasName);

        virtual unsigned int execute(std::vector<std::string>* v) {}
    protected:
        Command();
    private:
        static std::map<std::string, Command*> commandByAliasLookup;

        static Command* ERRONEOUS;

        std::map<std::string, unsigned int> aliasIdLookup;

        unsigned int id;
};

#endif // COMMAND_H
