/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "CmdDictionary.h"

// Singleton pattern
CmdDictionary* CmdDictionary::instance
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
}


void CmdDictionary::getCommand(std::string userInput)
{

}
