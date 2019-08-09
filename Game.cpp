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

/*std::string Game::gameIntro()
{
    std::string name = "";
    int marker = 0;

    std::cout << "Welcome to Tic-Tac-Toe, or Noughts and Crosses as some people may know it" << std::endl;
    std::cout << "May I take your name before we get started?\n" << std::endl;

    do
    {
        if(marker != 0)
        {
            std::cout << "\n\nI'm sorry, I didn't quite catch that, what was your name?\n" << std::endl;
            std::getline(std::cin, name);
        }
        else
        {
            std::getline(std::cin, name);
            marker++;
        }
    } while(name == "");

    clearScreen();
    std::cout << "\nWelcome " << name << "\n" << std::endl;

    return name;
}*/
