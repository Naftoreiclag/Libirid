/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "../../language/Grammar.h"
#include "../../util/Sysout.h"

#include <vector>
#include <string>

namespace cmd
{
namespace scr
{
    bool dance(std::string string)
    {
        Sysout::println("break it down!");
        Sysout::println(string);

        return true;
    }
}
}
