#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#include "world/World.h"
#include "world/Player.h"

class Game
{
    public:
        Player* player;
        World* world;
        bool runCommandFromRawInput(std::vector<std::string>* inputWords);
        bool runCommandFromSudoInput(std::string sudoLine);
        void run();

        // Save to file
        void save();
        Game();
    private:
        bool running;
};

#endif // GAME_H
