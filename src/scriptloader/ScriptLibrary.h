#ifndef SCRIPTLIBRARY_H
#define SCRIPTLIBRARY_H

#include <string>
#include <map>

class ScriptLibrary
{
    private:
        ScriptLibrary();
        virtual ~ScriptLibrary();
    public:
        static ScriptLibrary* getInstance();

        std::string* getLuaCode(std::string path);
    private:
        static ScriptLibrary* instance;

        std::map<std::string, std::string> luaScripts;
};

#endif // SCRIPTLIBRARY_H
