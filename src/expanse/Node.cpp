/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node.h"

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

Node::Node(std::string name, NodeType nodeType, Node* parent)
: name(name),
nodeType(nodeType),
parent(NULL),
firstChild(NULL),
sibling(NULL)
{
    // Tell parent to adopt me
    setParent(parent);
}

Node::~Node()
{
    for(Node* node = firstChild; node != NULL; node = node->sibling)
    {
        delete node;
    }
}

std::string Node::getName()
{
    return name;
}

NodeType Node::getType()
{
    return nodeType;
}

Node* Node::getParent() { return parent; }
void Node::setParent(Node* newParent)
{
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

Node* Node::getChild(std::string name)
{
    return NULL;
}

Node* Node::getFirstChild() { return firstChild; }
void Node::adoptChild(Node* newChild)
{
    // If child is not orphan
    if(newChild->parent != NULL)
    {
        // Tell child's parent to disown child
        newChild->parent->forgetChild(newChild);
    }

    // Tell the child about his brother
    newChild->sibling = firstChild;

    // Tell child that his parent is me
    newChild->parent = this;

    // My first child is him
    firstChild = newChild;
}
void Node::forgetChild(Node* childToDisown)
{
    // Iterate through all children
    Node* previousNode = NULL;
    for(Node* node = firstChild; node != NULL; node = node->sibling)
    {
        // If this one is the one to disown
        if(node == childToDisown)
        {
            // If nobody is before it (i.e. the first one)
            if(previousNode == NULL)
            {
                // Make my child to be his sibling
                firstChild = node->getSibling();
            }

            // Any other spot but first
            else
            {
                // The previous child's sibling is now the childToDisown's sibling
                previousNode->setSibling(node->getSibling());
            }

            // Stop checking
            break;
        }

        // Remember previous node
        previousNode = node;
    }
}

Node* Node::getSibling() { return sibling; }
void Node::setSibling(Node* newSibling) { sibling = newSibling; }

#ifdef DEBUG
void Node::printHeirachy(int layer)
{
    std::string indent = std::string(layer, ' ');


    std::cout << indent << getName();
    std::cout << std::endl;

    for(Node* node = firstChild; node != NULL; node = node->sibling)
    {
        node->printHeirachy(layer + 2);
    }
}

#endif // DEBUG
