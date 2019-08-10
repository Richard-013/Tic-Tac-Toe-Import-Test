#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

#include "Grid.h"

class Player
{
    public:
        Player();
        Player(Grid *grid);

        void playerTurn();

        char getSymbol();
        void chooseSymbol();

        void setName();
        std::string getName();

        void setTargetGrid(Grid *grid);

    private:
        int getInput();

        Grid *gridPtr;

        std::string name = "";
        char symbol = ' ';
};

#endif // PLAYER_H
