#ifndef CMDSCRIPTLUA_H
#define CMDSCRIPTLUA_H

#include <string>

#include "Cmdstuff.h"

#include "CmdScript.h"

namespace cmd
{
    class CmdScriptLua : public CmdScript
    {
        public:
            CmdScriptLua(std::string* code);
        public:
            void execute();
        private:
            std::string* code;
    };
}

#endif // CMDSCRIPTLUA_H
