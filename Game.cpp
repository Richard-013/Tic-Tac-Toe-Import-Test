#include "Game.h"

Game::Game()
{
    // Constructor
}

void Game::runGame()
{
    // Starts the game and handles overall flow of events
    gameIntro();
    do
    {
        gameLoop();
    }while(playAgain());

    quitGame();
}

bool Game::checkWin(char symbol)
{
    // Returns a boolean, true for a win, false if not a win
    return gridObj.checkWin(symbol);
}

void Game::clearScreen()
{
    // Clears the console screen
    std::cout << std::string(100, '\n');
}

void Game::gameIntro()
{
    // Runs the game introduction
    // Gets the user to enter their name, choose a symbol, and set the difficulty
    std::cout << "Welcome to Tic-Tac-Toe, or Noughts and Crosses as some people may know it" << std::endl;
    std::cout << "May I take your name before we get started?\n" << std::endl;

    // Sets the name within the player object
    playerObj.setName();

    clearScreen();
    std::cout << "\nWelcome " << playerObj.getName() << "\n" << std::endl;

    // Sets the player's chosen symbol
    playerObj.chooseSymbol();
}

void Game::gameLoop()
{
    // Sets the game status to 0 i.e. game is running and should continue
    int status = 0;

    // Loops through the game loop until one of the end conditions is met
    while(status == 0)
    {
        status = round();
    }

    if(status == 1)
    {
        // Status code 1 means a player victory
        gameWin();
    }
    else if(status == 2)
    {
        // Status code 2 means the game ended with a draw
        gameDraw();
    }
    else
    {
        // Status code 3 means the game was won by the AI
        // No other code should be generated but if an unknown code is generated then it is treated as a player loss
        gameOver();
    }

    std::cout << "\nPress enter to continue\n" << std::endl;
    std::cin.ignore();
}

int Game::round()
{
    // Sets the screen for the player's turn by clearing it and displaying the grid as it currently stands
    clearScreen();
    gridObj.printGrid();
    playerObj.playerTurn();
    moveCounter++; // Move counter is incremented with every turn to prevent more moves than grid squares

    if(checkWin(playerObj.getSymbol()))
    {
        // Player win
        return 1;
    }
    else if(moveCounter == 9)
    {
        // Draw as the last player to go did not win and the move limit has been reached
        return 2;
    }

    // Setup process repeats for the AI turn
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

    // Game continues as no end condition was met
    return 0;
}

bool Game::playAgain()
{
    // Checks if the player wishes to play again, return true if they do, else returns false
    clearScreen();
    std::cout << "Would you like to play again?\n1 - Yes\n2 - No\n" << std::endl;

    std::string input = "";
    getline(std::cin, input);
    // Takes the first character in the input as the player choice
    char inputReal = input[0];

    if(inputReal == '1')
    {
        return true;
    }

    return false;
}

void Game::gameWin()
{
    // Runs when the player wins the match
    clearScreen();
    gridObj.printGrid();
    std::cout << "\nYou Won! Congratulations!" << std::endl;
}

void Game::gameDraw()
{
    // Runs when the player draws the match
    clearScreen();
    gridObj.printGrid();
    std::cout << "\nIt's a Draw! Maybe Next Time You'll Do It!" << std::endl;
}

void Game::gameOver()
{
    // Runs when the player loses the match
    clearScreen();
    gridObj.printGrid();
    std::cout << "\nYou Lost! Better Luck Next Time!" << std::endl;
}

void Game::quitGame()
{
    clearScreen();
    std::cout << "\nThank you for playing!\n" << std::endl;
    std::cout << "Press enter to quit" << std::endl;
    std::cin.ignore();
}


