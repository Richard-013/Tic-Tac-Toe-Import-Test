#include "Game.h"

Game::Game()
{
    //ctor
}

bool Game::checkWin(char symbol)
{
    return this->gridObj.checkWin(symbol);
}

void Game::clearScreen()
{
    std::cout << std::string(100, '\n');
}

