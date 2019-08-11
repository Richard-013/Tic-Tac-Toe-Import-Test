#ifndef AI_H
#define AI_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Grid.h"

class AI
{
    public:
        AI();
        AI(Grid *grid);

        void aiTurn();

        char getSymbol();
        void setSymbol(char playerSymbol);

        void setDifficulty();

        void setTargetGrid(Grid *grid);

    private:
        enum difficultyScale{Normal = 1, Impossible = 2};

        void normalAITurn();
        void impossibleAITurn();

        // Moves for impossible difficulty AI to use
        int impMoveWin();
        int impMoveBlock();
        int impMoveFork();
        int impMoveBlockFork();
        int impMoveCentral();
        int impMoveOppCorner();
        int impMoveCorner();
        int impMoveSide();

        Grid *gridPtr;

        int difficulty = 0;
        char symbol = ' ';
        char opponentSymbol = ' ';
};

#endif // AI_H
