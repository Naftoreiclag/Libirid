#ifndef SCRIPTLIBRARY_H
#define SCRIPTLIBRARY_H

#include <string>
#include <vector>

class ScriptLibrary
{
    private:
        ScriptLibrary();
        virtual ~ScriptLibrary();
    public:
        static ScriptLibrary* getInstance();

        std::string* loadLua(std::string path);
    private:
        static ScriptLibrary* instance;

        std::vector<std::string> luaScripts;
};

#endif // SCRIPTLIBRARY_H
