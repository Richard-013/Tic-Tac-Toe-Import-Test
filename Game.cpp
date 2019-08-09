#include "Game.h"

Game::Game()
{
    //ctor
}

bool Game::checkWin(char symbol)
{
    return this->gridObj.checkWin(symbol);
}

