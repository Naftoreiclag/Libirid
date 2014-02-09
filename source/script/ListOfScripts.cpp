/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "ListOfScripts.h"

using namespace script;

/////////////////////////////////
// Singleton pattern
/////////////////////////////////

// Instance getting
ListOfScripts* ListOfScripts::instance;
ListOfScripts* ListOfScripts::getInstance()
{
    if(instance == nullptr)
    {
        instance = new ListOfScripts();
    }

    return instance;
}

// Constructor
ListOfScripts::ListOfScripts()
{
}

// Destructor
ListOfScripts::~ListOfScripts()
{
    ListOfScripts::instance = nullptr;
}

///////////////////////////////////
//
///////////////////////////////////
