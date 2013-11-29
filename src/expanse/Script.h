/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SCRIPT_H
#define SCRIPT_H

#include "Node.h"

namespace exp
{
    class Script : public Node
    {
        public:
            Script(Node* node);
            virtual ~Script();
        protected:
        private:
    };
}

#endif // SCRIPT_H
