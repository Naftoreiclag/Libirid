#ifndef ENTITY_H
#define ENTITY_H

class Room;

class Entity
{
    public:
        Entity();
        virtual ~Entity();
    protected:
    private:
        Room* location;
};

#endif // ENTITY_H
