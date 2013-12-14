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
    class PlayerScript : public Node
    {
        public:
            PlayerScript(std::string name, Node* parent);
            virtual ~PlayerScript();
        protected:
        private:
    };
}

#endif // PLAYERSCRIPT_H
