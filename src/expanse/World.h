/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef WORLD_H
#define WORLD_H

#include "Node.h"

namespace exp
{
    class World : public Node
    {
        public:
            World(Node* node);
            virtual ~World();
        private:
    };
}

#endif // WORLD_H
