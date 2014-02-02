/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_EXPANSE_H
#define NODE_EXPANSE_H

#include "Node.h"

namespace node
{
    class Node_Expanse : public Node
    {
        public:
            Node_Expanse(long long age);
            virtual ~Node_Expanse();
        private:
            long long age;
        public:
            void incrementAge();
            long long getAge();
    };
}

#endif // NODE_EXPANSE_H
