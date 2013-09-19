#ifndef FUZZY_H
#define FUZZY_H

#include "Game.h"

class Fuzzy
{
    public:
        static bool inDebug();
        static void run();
        static Game* runningGame;
    private:
        static bool debugMode;
};

#endif // FUZZY_H
