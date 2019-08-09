#include "Grid.h"

Grid::Grid()
{
    //ctor
}

bool Grid::checkWin(char symbol)
{
    // Checks outer lines
    if(grid[0] == symbol)
    {
        if(grid[1] == symbol && grid[2] == symbol)
        {
            return true;
        }
        else if(grid[3] == symbol && grid[6] == symbol)
        {
            return true;
        }
    }
    else if(grid[8] == symbol)
    {
        if(grid[6] == symbol && grid[7] == symbol)
        {
            return true;
        }
        else if(grid[2] == symbol && grid[5] == symbol)
        {
            return true;
        }
    }

    // Checks lines that pass the central square of the grid
    if(grid[4] == symbol)
    {
        if(grid[3] == symbol && grid[5] == symbol)
        {
            return true;
        }
        else if(grid[1] == symbol && grid[7] == symbol)
        {
            return true;
        }
        else if(grid[0] == symbol && grid[8] == symbol)
        {
            return true;
        }
        else if(grid[2] == symbol && grid[6] == symbol)
        {
            return true;
        }
    }

    // No win condition found
    return false;
}

void Grid::printGrid()
{
    int row = 0;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "    " << this->grid[i + (row * 2)] << " | " << this->grid[i + (row * 2) + 1] << " | " << this->grid[i + (row * 2) + 2] << std::endl;

        if(row != 2)
        {
            std::cout << "   ---|---|---" << std::endl;
            row++;
        }
    }
}

int Grid::checkChoice(char symbol, int input)
{
    // First statement will be moved to getInput function
    //if(input == -1)
    //{
        // Tile outside of grid selected
        //return input;
    //}

    if(this->grid[input] == 'X' || this->grid[input] == 'O')
    {
        // Tile on grid is already occupied
        return -2;
    }
    else
    {
        // Selection is valid
        replaceSquare(symbol, input);
    }

    // Tile selection is valid
    return 0;
}

void Grid::replaceSquare(char symbol, int input)
{
    this->grid[input] = symbol;
}
