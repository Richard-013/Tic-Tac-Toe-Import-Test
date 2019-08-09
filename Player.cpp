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

    this->symbol = holderSymbol;
}
