/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "CmdDictionary.h"

#include <iostream>

#include "CmdScript.h"
#include "CmdScriptInternal.h"

using namespace cmd;

// Singleton pattern
CmdDictionary* CmdDictionary::instance;
CmdDictionary* CmdDictionary::getInstance()
{
    if(instance == NULL)
    {
        instance = new CmdDictionary();
    }

    return instance;
}

CmdDictionary::CmdDictionary()
{
}

CmdDictionary::~CmdDictionary()
{
    CmdDictionary::instance = NULL;
}

CmdScript* CmdDictionary::newCmdScriptInternal(CmdScriptInternalFunction func)
{
    CmdScriptInternal* cmd = new CmdScriptInternal(func);

    registeredCmds.push_back(cmd);

    return cmd;
}
/*
CmdScript* CmdDictionary::newCmdScriptLua(std::string* code)
{
    CmdScriptLua* cmd = new CmdScriptLua(code);

    registeredCmds.push_back(cmd);

    return cmd;
}*/
