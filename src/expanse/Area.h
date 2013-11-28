/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef AREA_H
#define AREA_H

#include "Node.h"

namespace exp
{
    class Area : public Node
    {
        public:
            Area(NodeType type, Node* node);
            virtual ~Area();
        protected:
        private:
    };
}

#endif // AREA_H
