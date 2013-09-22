#ifndef TREE_H
#define TREE_H


class Tree
{
    public:
        Tree();
        void pickStick();
        void pickLeaf();
        virtual ~Tree();
    protected:
    private:
        unsigned char numSticks;
        unsigned short numLeaves;
};

#endif // TREE_H
