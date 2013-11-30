/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_H
#define NODE_H

/* Nodes. THE COMMENTS ARE SUPER CREEPY!!!
 *
 */

#include <string>

typedef unsigned char NodeType;

#define NT_EXPANSE          0x02
#define NT_WORLD            0x03
#define NT_AREA             0x04
#define NT_ENTITY           0x05
#define NT_PORTAL           0x06
#define NT_SCRIPT           0x07
#define NT_PLAYERSCRIPT     0x08
#define NT_STRINGVALUE      0x09
#define NT_LONGVALUE        0x0A
#define NT_INTEGERVALUE     0x0B
#define NT_SHORTVALUE       0x0C
#define NT_BYTEVALUE        0x0D

#ifdef DEBUG
//#define private public
#endif // DEBUG

class Node
{
    protected:
        Node(std::string name, NodeType nodeType, Node* parent);
    public:
        // Name
        std::string getName();

        //
        Node* getChild(std::string name);

        //
        NodeType getType();

        //
        virtual ~Node();

        // Returns parent
        Node* getParent();

        // Adopts a parent
        // - New parent calls adoptChild(me);
        void setParent(Node* newParent);

        // Returns the first child
        Node* getFirstChild();

        // Adopts a child
        // - New child knows who his siblings are
        // - Old parent knows that he is no longer her child
        // - I know that he is my new son
        // - New child knows that I am his new parent
        void adoptChild(Node* newChild);

        // Forgets a child
        // - I know that he is no longer my child
        // - My children know that he is no longer their sibling.
        // ! Disowned child does NOT know that he has been disowned, and still thinks that I am his parent!
        void forgetChild(Node* childToDisown);

        // Returns sibling
        Node* getSibling();

        // Sets the sibling
        void setSibling(Node* newSibling);

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

#endif // NODE_H
