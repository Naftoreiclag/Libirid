/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef EXPANSE_H
#define EXPANSE_H

#include "Node.h"

namespace exp
{
    class Expanse : public Node
    {
        public:
            Expanse();
            virtual ~Expanse();
            #ifdef DEBUG
            void sayFoo();
            #endif
        private:

    };
}

#endif // EXPANSE_H
