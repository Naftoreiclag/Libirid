/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "CmdScriptLua.h"

#include <string>

using namespace cmd;

CmdScriptLua::CmdScriptLua(std::string* code)
: CmdScript(ScriptType::lua),
code(code)
{
}

void CmdScriptLua::execute()
{
    //std::cout << "thisislua" << std::endl;
}
