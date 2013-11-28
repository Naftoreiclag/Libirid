/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef PORTAL_H
#define PORTAL_H

#include "Node.h"

namespace exp
{
    class Portal : public Node
    {
        public:
            Portal(Node* node);
            virtual ~Portal();
        protected:
        private:
    };
}

#endif // PORTAL_H
