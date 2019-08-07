#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

enum difficulty{Normal = 1, Impossible = 2};
char grid[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool checkWin(char symbol);

char chooseSymbol();

int getInput();
int checkChoice(int input);

int setDifficulty();
int normalGame(std::string playerName);
int impossibleGame(std::string playerName);

void clearScreen();
void printGrid();
void replaceSquare(char symbol, int input);

void playerTurn(char symbol);
void normalAITurn(char symbol);
void impossibleAITurn(char symbol);

std::string gameIntro();

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
    srand (time(NULL));

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

char chooseSymbol()
{
    std::string input = "";
    char inputReal = ' ';
    char symbol = ' ';
    std::cout << "\nPlease choose your symbol:\n    1 - O\n    2 - X" << std::endl;
    getline(std::cin, input);
    inputReal = input[0];

    if(inputReal == '1')
    {
        symbol = 'O';
    }
    else
    {
        symbol = 'X';
    }

    return symbol;
}

int getInput()
{
    std::string input = "";
    char inputReal = ' ';
    int output = -1;
    char options[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    getline(std::cin, input);
    inputReal = input[0];

    for(int i = 0; i < 9; i++)
    {
        if(inputReal == options[i])
        {
            output = i;
            break;
        }
    }

    // Returns grid index of chosen square
    return output;
}

int checkChoice(int input)
{
    if(input == -1)
    {
        // Tile outside of grid selected
        return input;
    }
    if(grid[input] == 'X' || grid[input] == 'O')
    {
        // Tile on grid is already occupied
        return -2;
    }

    // Tile selection is valid
    return input;
}

int setDifficulty()
{
    int choice = 0;

    std::cout << "There are two difficulties to choose from, which would you like?" << std::endl;
    std::cout << "    1 - Normal\n    2 - Impossible\n" << std::endl;

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

int normalGame(std::string playerName)
{
    bool gameOver = false;
    bool playerWin = false;
    bool aiWin = false;
    char symbol = ' ';
    char aiSymbol = ' ';
    int moveCounter = 0;

    symbol = chooseSymbol();
    if(symbol == 'O')
    {
        aiSymbol = 'X';
    }
    else
    {
        aiSymbol = 'O';
    }

    do
    {
        clearScreen();
        printGrid();
        playerTurn(symbol);
        moveCounter++;

        if(checkWin(symbol))
        {
            playerWin = true;
            gameOver = true;
            break;
        }
        else if(moveCounter == 9)
        {
            gameOver = true;
            break;
        }

        clearScreen();
        printGrid();
        normalAITurn(aiSymbol);
        moveCounter++;

        if(checkWin(aiSymbol))
        {
            aiWin = true;
            gameOver = true;
            break;
        }
        else if(moveCounter == 9)
        {
            gameOver = true;
            break;
        }

    }while(gameOver != true);

    if(playerWin == true)
    {
        // Player Wins
        clearScreen();
        printGrid();
        std::cout << "\nYou Won! Congratulations!" << std::endl;
    }
    else if(aiWin == true)
    {
        // AI Wins
        clearScreen();
        printGrid();
        std::cout << "\nYou Lost! Better Luck Next Time!" << std::endl;
    }
    else
    {
        // Draw
        clearScreen();
        printGrid();
        std::cout << "\nIt's a Draw! Maybe Next Time You'll Do It!" << std::endl;
    }

    return 0;
}

int impossibleGame(std::string playerName)
{
    bool gameOver = false;
    bool playerWin = false;
    return 0;
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

void replaceSquare(char symbol, int input)
{
    grid[input] = symbol;
}

void playerTurn(char symbol)
{
    int userInput = -1;

    do
    {
        std::cout << "\nYou are " << symbol << std::endl;
        std::cout << "Please choose a square: ";
        userInput = checkChoice(getInput());
        if(userInput == -1)
        {
            std::cout << "Invalid grid position, please select a valid square" << std::endl;
        }
        else if(userInput == -2)
        {
            std::cout << "Grid position already taken, please select a different square" << std::endl;
        }
        else
        {
            std::cout << "Valid selection of square: " << userInput + 1 << std::endl;
            replaceSquare(symbol, userInput);
            break;
        }
    }while(true);
}

void normalAITurn(char symbol)
{
    if(grid[4] == '5')
    {
        replaceSquare(symbol, 4);
    }
    else
    {
        bool invalid = true;
        int num = 0;
        char options[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

        do
        {
            num = rand() % 9;
            std::cout << num << "  " << checkChoice(num) << std::endl;
            if(grid[num] == options[num] || checkChoice(num) != -2)
            {
                replaceSquare(symbol, num);
                invalid = false;
            }
        } while(invalid);
    }
}

void impossibleAITurn(char symbol)
{

}

std::string gameIntro()
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
}
