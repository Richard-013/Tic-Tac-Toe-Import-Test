#include "AI.h"

AI::AI()
{
    //ctor
}

void AI::aiTurn()
{
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

}

void AI::impossibleAITurn()
{

}

char AI::getSymbol()
{
    // Returns the symbol the AI player is using
    return this->symbol;
}

void AI::aiTurn()
{

}
