/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef CMDSTUFF_H
#define CMDSTUFF_H

#include <string>

namespace cmd
{
    typedef bool (*CmdScriptInternalFunction)(std::string string);

    typedef unsigned char ScriptType;
}

#define SRT_INTERNAL     0x02
#define SRT_LUA          0x03

#endif // CMDSTUFF_H
