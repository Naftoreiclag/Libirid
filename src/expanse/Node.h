#ifndef NODE_H
#define NODE_H

/* Nodes. THE COMMENTS ARE SUPER CREEPY!!!
 *
 */

class Node
{
    public:
        Node(Node* parent);
        virtual ~Node();

        Node* getParent();

        // Adopts a parent
        // - New parent calls adoptChild(me);
        void setParent(Node* newParent);

        Node* getChild();

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

        Node* getSibling();
        void setSibling(Node* newSibling);
    private:
        Node* parent;
        Node* child;
        Node* sibling;
};

#endif // NODE_H
