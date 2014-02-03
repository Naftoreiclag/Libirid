/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_SCRIPT_H
#define NODE_SCRIPT_H

#include "TickableNode.h"

namespace node
{
    class Node_Script : public TickableNode
    {
        public:
            Node_Script(std::string name, Node* parent);
            virtual ~Node_Script();
        protected:
        private:
    };
}

#endif // NODE_SCRIPT_H
