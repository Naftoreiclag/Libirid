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
#include <vector>

#include "../language/Grammar.h"

namespace cmd
{
    //
    //typedef bool (*CppCmdFunction)(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias);

    //
    //typedef std::string* LuaScript;

    // Word types
    namespace ScriptType
    {
        enum T
        {
            internal,
            lua
        };
    }

    class CmdDictionary
    {
        private:
            CmdDictionary();
        public:
            // Get the current singleton instance, creating one if it does not exist
            static CmdDictionary* getInstance();

            //
            void loadCmdInternal();
            void loadCmdLua();
            void getCmd(std::string userInput);
        private:
            static CmdDictionary* instance;
    };

    class CmdScript
    {
        protected:
            CmdScript(ScriptType::T type);
        public:
            void execute();
        private:
            ScriptType::T type;
    };

    class CmdScriptLua : public CmdScript
    {
        public:
            CmdScriptLua(std::string code);
            void execute();
        private:
            std::string code;
    };
}

#endif // CMDDICTIONARY_H
