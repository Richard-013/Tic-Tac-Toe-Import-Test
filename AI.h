#ifndef AI_H
#define AI_H


class AI
{
    public:
        AI();

    private:
        enum difficultyScale{Normal = 1, Impossible = 2};

        int setDifficulty();
        void setSymbol();
        void aiTurn(char symbol);
        void normalAITurn(char symbol);
        void impossibleAITurn(char symbol);

        int difficulty = 0;
        char symbol = ' ';
};

#endif // AI_H
