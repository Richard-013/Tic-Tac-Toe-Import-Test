#include <iostream>
#include <string>

enum difficulty{Normal = 1, Impossible = 2};
char grid[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool checkWin(char symbol);
int normalGame(std::string playerName);
int impossibleGame(std::string playerName);

std::string gameIntro()
{
    std::string name = "";

    std::cout << "Welcome to Tic-Tac-Toe, or Noughts and Crosses as some people may know it" << std::endl;
    std::cout << "May I take your name before we get started?\n" << std::endl;

    std::getline(std::cin, name);

    std::cout << "\nWelcome " << name << std::endl;

    return name;
}

int setDifficulty()
{
    int choice = 0;

    std::cout << "There are two difficulties to choose from, which would you like?" << std::endl;
    std::cout << "1 - Normal\n2 - Impossible\n" << std::endl;

    std::cin >> choice;

    switch(choice)
    {
    case 1:
        std::cout << "\nNormal difficulty has been selected" << std::endl;
        break;
    case 2:
        std::cout << "\nImpossible difficulty has been selected" << std::endl;
        break;
    default:
        std::cout << "\nInvalid option, defaulting to Normal difficulty" << std::endl;
        choice = 2;
        break;
    }

    return choice;
}

void clearScreen()
{
    std::cout << std::string(100, '\n');
}

void printGrid()
{
    int row = 0;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "    " << grid[i + (row * 2)] << " | " << grid[i + (row * 2) + 1] << " | " << grid[i + (row * 2) + 2] << std::endl;

        if(row != 2)
        {
            std::cout << "   ---|---|---" << std::endl;
            row++;
        }
    }
}

int main()
{
    clearScreen();

    std::string playerName = gameIntro();
    int difficulty = setDifficulty();

    std::cout << "Press Enter to Begin" << std::endl;
    std::cin.ignore();
    std::cin.ignore();
    clearScreen();

    printGrid();

    if(difficulty == Impossible)
    {
        impossibleGame(playerName);
    }
    else
    {
        normalGame(playerName);
    }

    return 0;
}

bool checkWin(char symbol)
{
    // Checks outer lines
    if(grid[0] == symbol)
    {
        if(grid[1] == symbol && grid[2] == symbol)
        {
            return true;
        }
        else if(grid[3] == symbol && grid[6] == symbol)
        {
            return true;
        }
    }
    else if(grid[8] == symbol)
    {
        if(grid[6] == symbol && grid[7] == symbol)
        {
            return true;
        }
        else if(grid[2] == symbol && grid[5] == symbol)
        {
            return true;
        }
    }

    // Checks lines that pass the central square of the grid
    if(grid[4] == symbol)
    {
        if(grid[3] == symbol && grid[5] == symbol)
        {
            return true;
        }
        else if(grid[1] == symbol && grid[7] == symbol)
        {
            return true;
        }
        else if(grid[0] == symbol && grid[8] == symbol)
        {
            return true;
        }
        else if(grid[2] == symbol && grid[6] == symbol)
        {
            return true;
        }
    }

    // No win condition found
    return false;
}

int normalGame(std::string playerName)
{
    bool gameOver = false;
    bool playerWin = false;
    bool validMove = false;
    return 0;
}

int impossibleGame(std::string playerName)
{
    bool gameOver = false;
    bool playerWin = false;
    bool validMove = false;
    return 0;
}
