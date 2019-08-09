#include "Player.h"

Player::Player()
{
    //ctor
}

void Player::chooseSymbol()
{
    std::string input = "";
    char inputReal = ' ';
    char holderSymbol = ' ';

    do
    {
        std::cout << "\nPlease choose your symbol:\n    1 - O\n    2 - X" << std::endl;
        getline(std::cin, input);
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
    return this->symbol;
}

void Player::setName()
{
    std::string tempName = "";
    int marker = 0;

    do
    {
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
    return this->name;
}

int Player::getInput()
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
