/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef CMDSCRIPTINTERNAL_H
#define CMDSCRIPTINTERNAL_H

#include <string>

#include "Cmdstuff.h"

#include "CmdScript.h"

namespace cmd
{
    class CmdScriptInternal : public CmdScript
    {
        public:
            CmdScriptInternal(CmdScriptInternalFunction func);
        public:
            void execute();
            CmdScriptInternalFunction func;
    };
}

#endif // CMDSCRIPTINTERNAL_H
