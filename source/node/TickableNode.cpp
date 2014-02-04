/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "TickableNode.h"

using namespace node;

TickableNode::TickableNode(std::string name, NodeType nodeType, Node* parent)
: Node(name, nodeType, parent)
{
}

TickableNode::~TickableNode()
{
    if(this->name.front() == '~')
    {
        this->forceTick();
    }
}

void TickableNode::tickIfReady()
{
    // If there is time left on the countdown
    if(countDown > 0)
    {
        // Decrease it by one
        this->decrementCountDown();

        // If the countdown is finished now
        if(countDown == 0)
        {
            // Then tick
            this->forceTick();
        }
    }

    // If the value is already zero when this function is called, then the tick will not be called
}

void TickableNode::forceTick()
{

}

unsigned int TickableNode::getCountDown()
{
    return countDown;
}

void TickableNode::decrementCountDown()
{
    // Only decrease the value if doing so will result in zero or a positive number
    // In essence, make sure countDown is never a negative number
    if(countDown > 0)
    {
        -- countDown;
    }
}

void TickableNode::setCountDown(unsigned int amount)
{
    countDown = amount;
}

bool TickableNode::getTickOnCreation()
{
    return tickOnCreation;
}

void TickableNode::setTickOnCreation(bool yesNo)
{
    tickOnCreation = yesNo;
}
