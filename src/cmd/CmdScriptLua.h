/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

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
