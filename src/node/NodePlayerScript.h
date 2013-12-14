/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef PLAYERSCRIPT_H
#define PLAYERSCRIPT_H

#include "Node.h"

namespace node
{
    class NodePlayerScript : public Node
    {
        public:
            NodePlayerScript(std::string name, Node* parent);
            virtual ~NodePlayerScript();
        protected:
        private:
    };
}

#endif // PLAYERSCRIPT_H
