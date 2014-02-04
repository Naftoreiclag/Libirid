/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef TICKABLENODE_H
#define TICKABLENODE_H

#include "Node.h"

namespace node
{
    class TickableNode: public Node
    {
        protected:
            // Nodes themselves are not instantainable, so you need to make a subclass of this.
            TickableNode(std::string name, NodeType nodeType, Node* parent);
        public:
            // Deleter. Also deletes all children, and their children's children and so on
            virtual ~TickableNode();

        // Ticking
        public:
            // Decrement countdown and tick if the value is zero
            void tickIfReady();

            // Force a tick
            // Override this function to add some sort of functionality to the ticks
            virtual void forceTick();

        // Time remaining until tick
        // When it reaches zero then it will immediately tick
        public:
            unsigned int getCountDown();
            void decrementCountDown();
            void setCountDown(unsigned int amount);
        private:
            unsigned int countDown;

        // Whether or not to be created ready to tick or not (i.e. created with countDown of 1)
        private:
            bool tickOnCreation;
        public:
            bool getTickOnCreation();
            void setTickOnCreation(bool yesNo);
    };
}

#endif // TICKABLENODE_H
