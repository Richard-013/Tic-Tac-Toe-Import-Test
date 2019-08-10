#include "Player.h"

Player::Player()
{
    // Constructor
}

void Player::setTargetGrid(Grid *grid)
{
    gridPtr = grid;
}

void Player::chooseSymbol()
{
    // Allows the player to choose whether they are noughts or crosses
    std::string input = " ";
    char inputReal = ' ';
    char holderSymbol = ' ';

    do
    {
        // Loops until valid input is given
        std::cout << "\nPlease choose your symbol:\n    1 - O\n    2 - X\n" << std::endl;
        getline(std::cin, input);
        // Takes the first character in the input as the player choice
        inputReal = input[0];

        if(inputReal == '1')
        {
            holderSymbol = 'O';
            break;
        }
        else if(inputReal == '2')
        {
            holderSymbol = 'X';
            break;
        }
    } while(true);

    symbol = holderSymbol;
}

char Player::getSymbol()
{
    // Returns the symbol the player has chosen
    return this->symbol;
}

void Player::setName()
{
    // Allows the user to set their name
    std::string tempName = "";
    int marker = 0;

    do
    {
        // Loops until the user gives a name instead of leaving the field empty
        if(marker != 0)
        {
            std::cout << "\n\nI'm sorry, I didn't quite catch that, what was your name?\n" << std::endl;
            std::getline(std::cin, tempName);
        }
        else
        {
            std::getline(std::cin, tempName);
            std::cout << tempName << std::endl;
            marker++;
        }
    } while(tempName == "");

    name = tempName;
}

std::string Player::getName()
{
    // Returns the player's chosen name
    return this->name;
}

int Player::getInput()
{
    // Gets input from the user to select a square on the grid
    std::string input = " ";
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

void Player::playerTurn()
{

}
