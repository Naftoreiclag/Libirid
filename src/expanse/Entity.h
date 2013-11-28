/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "Node.h"

namespace exp
{
    class Entity : public Node
    {
        public:
            Entity(Node* node);
            virtual ~Entity();
        protected:
        private:
    };
}

#endif // ENTITY_H
