#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    public:
        Player();
        char getSymbol();

    protected:

    private:
        char chooseSymbol();
        int getInput();
        void playerTurn(char symbol);

        std::string name = "";
        char symbol = ' ';
};

#endif // PLAYER_H
