/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
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
            Area(std::string name, Node* parent);
            virtual ~Area();
        protected:
        private:
    };
}

#endif // AREA_H
