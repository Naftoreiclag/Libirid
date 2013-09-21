#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room
{
    public:
        std::string getDescription(int seed);
        Room();
        virtual ~Room();
    protected:
    private:
};

#endif // ROOM_H
