/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "CmdScriptInternal.h"

#include <string>

#include <iostream>

using namespace cmd;

CmdScriptInternal::CmdScriptInternal(CmdScriptInternalFunction func)
: CmdScript(SRT_INTERNAL),
func(func)
{
}

void CmdScriptInternal::execute()
{
    func("efjiawoklgjraeoigjd");
}
