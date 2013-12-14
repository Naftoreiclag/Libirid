/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_AREA_H
#define NODE_AREA_H

#include "Node.h"

namespace node
{
    class Node_Area : public Node
    {
        public:
            Node_Area(std::string name, Node* parent);
            virtual ~Node_Area();
        protected:
        private:
    };
}

#endif // NODE_AREA_H
