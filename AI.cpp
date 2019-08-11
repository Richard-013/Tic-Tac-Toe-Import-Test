#include "AI.h"

AI::AI()
{
    // Constructor
    srand (time(NULL)); // Seeds random number generation
}

void AI::setTargetGrid(Grid *grid)
{
    gridPtr = grid;
}

void AI::aiTurn()
{
    // Calls the correct AI move for the selected difficulty
    if(difficulty == Impossible)
    {
        impossibleAITurn();
    }
    else
    {
        normalAITurn();
    }
}

void AI::normalAITurn()
{
    // AI logic for normal difficulty
    // Goes for the central square if it is available otherwise chooses a random square to fill
    int temp = gridPtr->checkChoice(symbol, 4);

    // If central square was taken then try random squares
    if(temp != 0)
    {
        bool invalid = true;
        int num = 0;

        do
        {
            num = rand() % 9;
            temp = gridPtr->checkChoice(symbol, num);
            // If the choice is valid then break the loop
            if(temp == 0)
            {
                invalid = false;
            }
        } while(invalid);
    }
}

void AI::impossibleAITurn()
{
    // AI logic for impossible difficulty
}

char AI::getSymbol()
{
    // Returns the symbol the AI player is using
    return this->symbol;
}

void AI::setSymbol(char playerSymbol)
{
    // Sets the AI symbol to the opposite of the player's
    if(playerSymbol == 'O')
    {
        symbol = 'X';
    }
    else
    {
        symbol = 'O';
    }
}

void AI::setDifficulty()
{
    // ALlows the player to choose the difficulty and sets values accordingly
    std::string choice = " ";
    char choiceReal = ' ';

    std::cout << "\nThere are two difficulties to choose from, which would you like?" << std::endl;
    std::cout << "    1 - Normal\n    2 - Impossible\n" << std::endl;

    getline(std::cin, choice);
    // Takes the first character in the input as the player choice
    choiceReal = choice[0];

    switch(choiceReal)
    {
    case '1':
        difficulty = Normal;
        std::cout << "\nNormal difficulty has been selected" << std::endl;
        break;
    case '2':
        difficulty = Impossible;
        std::cout << "\nImpossible difficulty has been selected" << std::endl;
        break;
    default:
        difficulty = Normal;
        std::cout << "\nInvalid option, defaulting to Normal difficulty" << std::endl;
        break;
    }
}

int impMoveWin()
{
    // Goes for a winning move if there is one available
    return 1;
}

int impMoveBlock()
{
    // Blocks an opponents winning move
    return 1;
}

int impMoveFork()
{
    // Creates a fork where there are two ways of winning
    return 1;
}

int impMoveBlockFork()
{
    // Blocks an opponents chance to make a fork
    return 1;
}

int impMoveCentral()
{
    // Takes the central square if it available
    return 1;
}

int impMoveOppCorner()
{
    // Takes a corner opposite to one the opponent has already taken
    return 1;
}

int impMoveCorner()
{
    // Takes any available corner square
    return 1;
}

int impMoveSide()
{
    // Takes any available side square
    return 1;
}

