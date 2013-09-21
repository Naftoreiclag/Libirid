#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

class World;
class Player;

class Game
{
    public:
        World* world;
        Player* player;
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
