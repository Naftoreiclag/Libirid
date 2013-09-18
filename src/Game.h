#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#include "world/World.h"

class Game
{
    public:
        bool runCommandFromRawInput(std::vector<std::string>* inputWords);
        void start();
        Game();
    private:
        World* world;
        bool running;
};

#endif // GAME_H
