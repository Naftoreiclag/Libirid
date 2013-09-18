#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#include "world/World.h"
#include "world/Player.h"

class Game
{
    public:
        bool runCommandFromRawInput(std::vector<std::string>* inputWords);
        void run();
        Game();
    private:
        Player* player;
        World* world;
        bool running;
};

#endif // GAME_H
