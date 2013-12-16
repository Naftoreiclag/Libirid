/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SCRIPT_COMMAND_H
#define SCRIPT_COMMAND_H

#include "Script.h"

namespace script
{
    typedef int (*CommandFunction)(int, int);

    class Script_Command : public Script
    {
        public:
            Script_Command(CommandFunction func);
            virtual ~Script_Command();
        public:
            char execute(int a, int b);
            CommandFunction function;
    };
}

#endif // SCRIPT_COMMAND_H
