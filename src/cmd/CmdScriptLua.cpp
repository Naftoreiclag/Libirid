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
