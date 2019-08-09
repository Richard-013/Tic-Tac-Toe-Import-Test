#ifndef GRID_H
#define GRID_H


class Grid
{
    public:
        Grid();

    protected:

    private:
        char grid[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Grid the game is played on and that is displayed to the user
        bool checkWin(char symbol);
        int checkChoice(int input);
        void printGrid();
        bool replaceSquare(char symbol, int input);
};

#endif // GRID_H
