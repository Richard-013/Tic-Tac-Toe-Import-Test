#include "Game.h"

Game::Game()
{
    //ctor
}

void Game::runGame()
{
    std::cout << checkWin('X') << std::endl;
    this->gridObj.printGrid();
    gameIntro();
}

bool Game::checkWin(char symbol)
{
    return this->gridObj.checkWin(symbol);
}

void Game::clearScreen()
{
    std::cout << std::string(100, '\n');
}

void Game::gameIntro()
{
    std::cout << "Welcome to Tic-Tac-Toe, or Noughts and Crosses as some people may know it" << std::endl;
    std::cout << "May I take your name before we get started?\n" << std::endl;

    this->playerObj.setName();

    clearScreen();
    std::cout << "\nWelcome " << this->playerObj.getName() << "\n" << std::endl;
}
