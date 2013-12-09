/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node.h"

#define MACRO_CHILD_ITERATOR Node* child = firstChild; child != NULL; child = child->sibling

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

using namespace exp;

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

// Deleter. Also deletes all children, and their children's children and so on
Node::~Node()
{
    for(MACRO_CHILD_ITERATOR)
    {
        delete child;
    }
}

// Type
NodeType Node::getType()
{
    return nodeType;
}

// Name
std::string Node::getName()
{
    return name;
}

// Get first DIRECT (i.e. not a grandchild or nephew) child named "name"
Node* Node::getChild(std::string name)
{
    for(MACRO_CHILD_ITERATOR)
    {
        if(child->getName() == name)
        {
            return child;
        }
    }

    return NULL;
}

// Get first descendant (a child, grandchild, nephew, grandnephew... etc)
Node* Node::getDescendant(std::string name)
{
    for(MACRO_CHILD_ITERATOR)
    {
        if(child->getName() == name)
        {
            return child;
        }
        else
        {
            Node* returnVal = child->getDescendant(name);

            if(returnVal != NULL)
            {
                return returnVal;
            }
        }
    }

    return NULL;
}

// Parent
Node* Node::getParent() { return parent; }

// Adopts a parent
// - New parent calls adoptChild(me);
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

// Returns the first child
Node* Node::getFirstChild() { return firstChild; }

// Adopts a child
// - New child knows who his siblings are
// - Old parent knows that he is no longer her child
// - I know that he is my new son
// - New child knows that I am his new parent
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

// Forgets a child
// - I know that he is no longer my child
// - My children know that he is no longer their sibling.
// ! Disowned child does NOT know that he has been disowned, and still thinks that I am his parent!
void Node::forgetChild(Node* childToDisown)
{
    // Iterate through all children
    Node* previousNode = NULL;
    for(MACRO_CHILD_ITERATOR)
    {
        // If this one is the one to disown
        if(child == childToDisown)
        {
            // If nobody is before it (i.e. the first one)
            if(previousNode == NULL)
            {
                // Make my child to be his sibling
                firstChild = child->getSibling();
            }

            // Any other spot but first
            else
            {
                // The previous child's sibling is now the childToDisown's sibling
                previousNode->setSibling(child->getSibling());
            }

            // Stop checking
            break;
        }

        // Remember previous node
        previousNode = child;
    }
}

// Returns sibling
Node* Node::getSibling() { return sibling; }

// Sets the sibling
void Node::setSibling(Node* newSibling) { sibling = newSibling; }

#ifdef DEBUG
void Node::printHeirachy(int layer)
{
    std::string indent = std::string(layer, ' ');


    std::cout << indent << getName();
    std::cout << std::endl;

    for(Node* child = firstChild; child != NULL; child = child->sibling)
    {
        child->printHeirachy(layer + 2);
    }
}

#endif // DEBUG
