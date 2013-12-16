/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Script_Command.h"

using namespace script;

Script_Command::Script_Command(CommandFunction func)
: Script(),
function(func)
{
}

Script_Command::~Script_Command()
{
}

char Script_Command::execute(int a, int b)
{
    function(a, b);
}
