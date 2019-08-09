#include "Game.h"

Game::Game()
{
    //ctor
}

void Game::runGame()
{
    std::cout << checkWin('X') << std::endl;
    gridObj.printGrid();
    gameIntro();
    gameLoop();
}

bool Game::checkWin(char symbol)
{
    return gridObj.checkWin(symbol);
}

void Game::clearScreen()
{
    std::cout << std::string(100, '\n');
}

void Game::gameIntro()
{
    std::cout << "Welcome to Tic-Tac-Toe, or Noughts and Crosses as some people may know it" << std::endl;
    std::cout << "May I take your name before we get started?\n" << std::endl;

    playerObj.setName();

    clearScreen();
    std::cout << "\nWelcome " << playerObj.getName() << "\n" << std::endl;
}

void Game::gameLoop()
{
    int status = 0;

    while(gameEnd == false)
    {
        status = round();
        if(status > 0)
        {
            break;
        }
    }

    if(status == 1)
    {
        gameWin();
    }
    else if(status == 2)
    {
        gameDraw();
    }
    else
    {
        gameOver();
    }
}

int Game::round()
{
    clearScreen();
    gridObj.printGrid();
    playerObj.playerTurn();
    moveCounter++;

    if(checkWin(playerObj.getSymbol()))
    {
        // Player win
        return 1;
    }
    else if(moveCounter == 9)
    {
        // Draw
        return 2;
    }

    clearScreen();
    gridObj.printGrid();
    aiObj.aiTurn();
    moveCounter++;

    if(checkWin(aiObj.getSymbol()))
    {
        // AI Win
        return 3;
    }
    else if(moveCounter == 9)
    {
        // Draw
        return 2;
    }

    // Game continues
    return 0;
}

void Game::gameWin()
{
    clearScreen();
    gridObj.printGrid();
    std::cout << "\nYou Won! Congratulations!" << std::endl;
}

void Game::gameDraw()
{
    clearScreen();
    gridObj.printGrid();
    std::cout << "\nIt's a Draw! Maybe Next Time You'll Do It!" << std::endl;
}

void Game::gameOver()
{
    clearScreen();
    gridObj.printGrid();
    std::cout << "\nYou Lost! Better Luck Next Time!" << std::endl;
}




