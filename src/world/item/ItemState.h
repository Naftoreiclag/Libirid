#ifndef ITEMSTATE_H
#define ITEMSTATE_H

class Inventory;

class ItemState
{
    public:
        ItemState();
        virtual ~ItemState();
    protected:
    private:
        Inventory* location;
};

#endif // ITEMSTATE_H
