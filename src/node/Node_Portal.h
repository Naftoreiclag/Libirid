/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_PORTAL_H
#define NODE_PORTAL_H

#include "Node.h"

namespace node
{
    class Node_Portal : public Node
    {
        public:
            Node_Portal(std::string name, Node* parent, std::string exitAreaName);
            virtual ~Node_Portal();
        protected:
        private:
    };
}

#endif // NODE_PORTAL_H
