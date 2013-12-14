/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SCRIPTCOMMAND_H
#define SCRIPTCOMMAND_H

#include "Script.h"

namespace script
{
    typedef int (*CommandFunction)(int, int);

    class ScriptCommand : public Script
    {
        public:
            ScriptCommand(CommandFunction func);
            virtual ~ScriptCommand();
        public:
            void execute(int a, int b);
            CommandFunction function;
    };
}

#endif // SCRIPTCOMMAND_H
