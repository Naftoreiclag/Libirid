#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node(Node* parent);
        virtual ~Node();

        Node* getParent();
        void setParent(Node* node);

        Node* getSibling();

        Node* getChild();
        Node* addChild();
    private:
        Node* parent;
        Node* sibling;
        Node* child;
};

#endif // NODE_H
