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

{

}
