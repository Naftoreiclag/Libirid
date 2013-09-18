#include "Fuzzy.h"

#include "Game.h"

Game* Fuzzy::runningGame;

void Fuzzy::run()
{
    // Put like, a main menu here or something

    // Run a game
    runningGame = new Game();
    runningGame->run();
    delete runningGame;
}

Fuzzy::Fuzzy()
{
}

Fuzzy::~Fuzzy()
{
}
