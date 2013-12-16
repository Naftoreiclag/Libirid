/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SCRIPT_NODE_H
#define SCRIPT_NODE_H

#include "Script.h"

/* A script that takes node arguments
 *
 */

namespace script
{
    // A pointer to a function that accepts certain node-like arguments
    typedef int (*NodeFunction)(int, int);

    class Script_Node : public Script
    {
        public:
            Script_Node(NodeFunction func);
            virtual ~Script_Node();
        public:
            char execute(int a, int b);
            NodeFunction function;
    };
}

#endif // SCRIPT_NODE_H
