/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
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
            Portal(std::string name, Node* parent, std::string exitAreaName);
            virtual ~Portal();
        protected:
        private:
    };
}

#endif // PORTAL_H
