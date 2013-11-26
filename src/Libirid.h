#ifndef LIBIRID_H
#define LIBIRID_H

#include "Game.h"

class Libirid
{
    public:
        static bool inDebug();
        static void run();
        static Game* runningGame;
    private:
        static bool debugMode;
};

#endif // LIBIRID_H
