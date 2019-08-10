#ifndef AI_H
#define AI_H

#include <iostream>

class AI
{
    public:
        AI();

        void aiTurn();

        char getSymbol();
        void setSymbol(char playerSymbol);

        void setDifficulty();

    private:
        enum difficultyScale{Normal = 1, Impossible = 2};

        void normalAITurn();
        void impossibleAITurn();

        int difficulty = 0;
        char symbol = ' ';
};

#endif // AI_H
