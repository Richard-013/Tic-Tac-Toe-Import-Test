#ifndef GRID_H
#define GRID_H

#include <iostream>

class Grid
{
    public:
        Grid();
        bool checkWin(char symbol);
        void printGrid();
        int checkChoice(char symbol, int input);

    private:
        char grid[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Grid the game is played on and that is displayed to the user
        void replaceSquare(char symbol, int input);
};

#endif // GRID_H
