#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player
{
    public:
        Player();

        void playerTurn();

        char getSymbol();
        void chooseSymbol();

        void setName();
        std::string getName();

    private:
        int getInput();

        std::string name = "";
        char symbol = ' ';
};

#endif // PLAYER_H
