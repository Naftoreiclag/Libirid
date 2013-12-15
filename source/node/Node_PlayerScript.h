/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_PLAYERSCRIPT_H
#define NODE_PLAYERSCRIPT_H

#include "Node.h"

namespace node
{
    class Node_PlayerScript : public Node
    {
        public:
            Node_PlayerScript(std::string name, Node* parent);
            virtual ~Node_PlayerScript();
        protected:
        private:
    };
}

#endif // NODE_PLAYERSCRIPT_H
