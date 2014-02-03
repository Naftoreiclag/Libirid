/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_H
#define NODE_H

/* Nodes
 *
 */

#include <string>

typedef unsigned char NodeType;

#define NT_EXPANSE          0x02
#define NT_WORLD            0x03
#define NT_AREA             0x04
#define NT_ENTITY           0x05
#define NT_PORTAL           0x06

#define NT_FOLDER           0x07

#define NT_SCRIPT           0x10
#define NT_PLAYERSCRIPT     0x11

#define NT_STRINGVALUE      0x22
#define NT_BYTEVALUE        0x23
#define NT_16VALUE          0x24
#define NT_32VALUE          0x25
#define NT_64VALUE          0x26
#define NT_128VALUE         0x27
#define NT_256VALUE         0x28
#define NT_512VALUE         0x29
#define NT_1024VALUE        0x2A

namespace node
{
    class Node
    {
        protected:
            // Nodes themselves are not instantainable, so you need to make a subclass of this.
            Node(std::string name, NodeType nodeType, Node* parent);
        public:
            // Deleter. Also deletes all children, and their children's children and so on
            virtual ~Node();

            // Type
            NodeType getType();

            // Name
            std::string getName();

            // Get first DIRECT (i.e. not a grandchild or nephew) child named "name"
            Node* getChild(std::string name);

            // Get first descendant (a child, grandchild, nephew, grandnephew... etc)
            Node* getDescendant(std::string name);

            // Fill a vector with descendants (i.e. a child, grandchild, great-grandchild... etc) that are of a particular type
            void getDescendants(std::vector<Node*> descendants, NodeType nodeType);

            // Parent
            Node* getParent();

            // Adopts a parent
            void setParent(Node* newParent);

            // Returns the first child
            Node* getFirstChild();

            // Adopts a child
            void adoptChild(Node* newChild);

            // Forgets a child
            void forgetChild(Node* childToDisown);

            // Returns sibling
            Node* getSibling();

            #ifdef DEBUG
            void printHeirachy(int layer);
            #endif // DEBUG
        private:
            std::string name;

            NodeType nodeType;

            Node* parent;
            Node* firstChild;
            Node* sibling;
    };
}

#endif // NODE_H
