/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node.h"

#ifdef DEBUG
#include "../util/Sysout.h"
#include <iostream>
#include <string>
#endif // DEBUG

//#define NULL (void *)0

Node::Node(Node* parent)
: parent(NULL),
child(NULL),
sibling(NULL)
{
    // Tell parent to adopt me
    setParent(parent);
}

Node::~Node()
{
}

Node* Node::getParent() { return parent; }
void Node::setParent(Node* newParent)
{
    #ifdef DEBUG
    Sysout::println("parent assigned: ");
    if(parent != NULL) std::cout << "old: " << parent->name << std::endl;
    else               std::cout << "old: " << "NULL" << std::endl;
    if(newParent != NULL) std::cout << "new: " << newParent->name << std::endl;
    else                  std::cout << "new: " << "NULL" << std::endl;
    #endif // DEBUG

    // If the new parent is nobody
    if(newParent == NULL)
    {
        // If current parent is already nobody
        if(parent == NULL)
        {
            // Do nothing
        }

        // If the current parent is somebody
        else
        {
            // Tell current parent to forget me
            parent->forgetChild(this);

            // My parent is nobody
            parent = NULL;
        }
    }

    // If the new parent is somebody
    else
    {
        // Tell new parent to adopt me
        newParent->adoptChild(this);
    }
}

Node* Node::getChild() { return child; }
void Node::adoptChild(Node* newChild)
{
    // If child is not orphan
    if(newChild->parent != NULL)
    {
        // Tell child's parent to disown child
        newChild->parent->forgetChild(newChild);
    }

    // Tell the child about his brother
    newChild->sibling = child;

    // Tell child that his parent is me
    newChild->parent = this;

    // My child is him
    child = newChild;
}
#ifdef DEBUG
void Node::forgetChild(Node* childToDisown)
{
    std::cout << "I am " << name << " and I will disown " << childToDisown->name << "." << std::endl;

    // Iterate through all children
    Node* previousNode = NULL;
    for(Node* node = child; node != NULL; node = node->sibling)
    {
        std::cout << "checking if " << node->name << " is " << childToDisown->name << "." << std::endl;
        // If this one is the one to disown
        if(node == childToDisown)
        {
            std::cout << "it is!" << std::endl;
            // If nobody is before it (i.e. the first one)
            if(previousNode == NULL)
            {
                // Make my child to be his sibling
                std::cout << "since it is first, my new first child will be his sibling" << std::endl;
                child = node->getSibling();
            }

            // Any other spot but first
            else
            {
                // The previous child's sibling is now the childToDisown's sibling
                std::cout << "since it is not first, the previous child, " << previousNode->name << " will now have a new sibling." << std::endl;
                previousNode->setSibling(node->getSibling());
            }

            break;
        }

        previousNode = node;
    }
}
#endif // DEBUG

#ifndef DEBUG
void Node::forgetChild(Node* childToDisown)
{
    // Iterate through all children
    Node* previousNode = NULL;
    for(Node* node = child; node != NULL; node = node->sibling)
    {
        // If this one is the one to disown
        if(node == childToDisown)
        {
            // If nobody is before it (i.e. the first one)
            if(previousNode == NULL)
            {
                // Make my child to be his sibling
                child = node->getSibling();
            }

            // Any other spot but first
            else
            {
                // The previous child's sibling is now the childToDisown's sibling
                previousNode->setSibling(node->getSibling());
            }
        }
    }
}
#endif // !DEBUG

Node* Node::getSibling() { return sibling; }
void Node::setSibling(Node* newSibling) { sibling = newSibling; }

#ifdef DEBUG
void Node::printHeirachy(int layer)
{
    std::string indent = std::string(layer, ' ');


    std::cout << indent << name;
    //if(sibling != NULL) std::cout << ": " << sibling->name;
    std::cout << std::endl;

    //Sysout::println(indent + "Node");
    //Sysout::println(indent + "[");
    for(Node* node = child; node != NULL; node = node->sibling)
    {
        node->printHeirachy(layer + 2);
    }
    //Sysout::println(indent + "]");
}

void Node::setName(std::string str)
{
    name = str;
}
#endif // DEBUG
