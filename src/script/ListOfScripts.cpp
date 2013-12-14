/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "ListOfScripts.h"
#ifndef NULL
#define NULL 0
#endif // NULL

/////////////////////////////////
// Singleton pattern
/////////////////////////////////

// Instance getting
ListOfScripts* ListOfScripts::instance;
ListOfScripts* ListOfScripts::getInstance()
{
    if(instance == NULL)
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
    ListOfScripts::instance = NULL;
}

///////////////////////////////////
//
///////////////////////////////////
