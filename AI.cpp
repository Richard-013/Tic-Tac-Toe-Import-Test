#include "AI.h"

AI::AI()
{
    // Constructor
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
    int choice = 0;

    std::cout << "There are two difficulties to choose from, which would you like?" << std::endl;
    std::cout << "    1 - Normal\n    2 - Impossible\n" << std::endl;

    std::cin >> choice;

    switch(choice)
    {
    case 1:
        difficulty = Normal;
        std::cout << "\nNormal difficulty has been selected" << std::endl;
        break;
    case 2:
        difficulty = Impossible;
        std::cout << "\nImpossible difficulty has been selected" << std::endl;
        break;
    default:
        difficulty = Normal;
        std::cout << "\nInvalid option, defaulting to Normal difficulty" << std::endl;
        break;
    }
}
