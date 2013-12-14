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

#include "Cmdstuff.h"

namespace cmd
{
    class CmdScript;

    class CmdDictionary
    {
        private:
            CmdDictionary();
        public:
            // Get the current singleton instance, creating one if it does not exist
            static CmdDictionary* getInstance();

            // Destroyer
            ~CmdDictionary();

            //
            CmdScript* newCmdScriptInternal(CmdScriptInternalFunction func);
            //CmdScript* newCmdScriptLua(std::string* code);

            // Returns the command script based on input
            CmdScript* getCmd(std::string userInput);
        private:
            // The static singleton instance
            static CmdDictionary* instance;

            std::vector<CmdScript*> registeredCmds;
    };
}

#endif // CMDDICTIONARY_H
