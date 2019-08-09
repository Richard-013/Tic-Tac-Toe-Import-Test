#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player
{
    public:
        Player();
        char getSymbol();
        void setName();
        std::string getName();

    protected:

    private:
        void chooseSymbol();
        int getInput();
        void playerTurn(char symbol);

        std::string name = "";
        char symbol = ' ';
};

#endif // PLAYER_H
