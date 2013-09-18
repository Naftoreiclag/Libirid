#ifndef FUZZY_H
#define FUZZY_H

#include "Game.h"

class Fuzzy
{
    public:
        static void run();
        static Game* runningGame;
    protected:
    private:

        Fuzzy();
        virtual ~Fuzzy();
};

#endif // FUZZY_H
