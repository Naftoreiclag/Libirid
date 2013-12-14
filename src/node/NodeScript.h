/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SCRIPT_H
#define SCRIPT_H

#include "Node.h"

namespace node
{
    class NodeScript : public Node
    {
        public:
            NodeScript(std::string name, Node* parent);
            virtual ~NodeScript();
        protected:
        private:
    };
}

#endif // SCRIPT_H
