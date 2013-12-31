/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_FOLDER_H
#define NODE_FOLDER_H

#include "Node.h"

namespace node
{
    class Node_Folder : public Node
    {
        public:
            Node_Folder(std::string name, Node* parent);
            virtual ~Node_Folder();
        private:
    };
}

#endif // NODE_FOLDER_H
