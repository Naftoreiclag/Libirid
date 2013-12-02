/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

/* Singleton. This will hold all the scripts that can be accessed by user
 * inputs.
 */

#include <string>
#include <map>

#include "../language/Grammar.h"

namespace cmd
{
    // Word types
    namespace ScriptType
    {
        enum T
        {
            internal,
            lua
        };
    }

    class CmdScript
    {
        protected:
            CmdScript(ScriptType::T type);
            std::vector<std::string> aliases;
        public:
            void addAlias(std::string)
            void execute();
        private:
            ScriptType::T type;
    };

    class CmdScriptLua : public CmdScript
    {
        public:
            CmdScriptLua(std::string* code);
        public:
            void execute();
        private:
            std::string* code;
    };

    class CmdDictionary
    {
        private:
            CmdDictionary();
        public:
            // Get the current singleton instance, creating one if it does not exist
            static CmdDictionary* getInstance();

            //
            void addCmd(CmdScript* cmd);
            void getCmd(std::string userInput);
        private:
            static CmdDictionary* instance;

            std::vector<CmdScript*> registeredCmds;
    };
}

#endif // CMDDICTIONARY_H
