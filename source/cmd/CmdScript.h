/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef CMDSCRIPT_H
#define CMDSCRIPT_H

#include "CmdStuff.h"

namespace cmd
{
    class CmdScript
    {
        protected:
            CmdScript(ScriptType type);
        public:
            void execute();
        private:
            ScriptType type;
    };
}

#endif // CMDSCRIPT_H
