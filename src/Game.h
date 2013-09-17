#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game
{
    public:
        bool alistatify(std::vector<std::string>* inputWords);
        void start();
        Game();
    private:
        bool running;
};

#endif // GAME_H
