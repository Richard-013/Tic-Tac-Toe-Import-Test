#ifndef GRID_H
#define GRID_H


class Grid
{
    public:
        Grid();
        bool checkWin(char symbol);

    protected:

    private:
        char grid[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Grid the game is played on and that is displayed to the user
        int checkChoice(int input);
        void printGrid();
        bool replaceSquare(char symbol, int input);
};

#endif // GRID_H
