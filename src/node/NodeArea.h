/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef AREA_H
#define AREA_H

#include "Node.h"

namespace node
{
    class NodeArea : public Node
    {
        public:
            NodeArea(std::string name, Node* parent);
            virtual ~NodeArea();
        protected:
        private:
    };
}

#endif // AREA_H
