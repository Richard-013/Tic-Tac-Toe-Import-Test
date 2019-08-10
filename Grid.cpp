#include "Grid.h"

Grid::Grid()
{
    // Constructor
}

bool Grid::checkWin(char symbol)
{
    // Checks outer lines for three symbols in a row
    if(grid[0] == symbol)
    {
        if(grid[1] == symbol && grid[2] == symbol)
        {
            // Top row
            return true;
        }
        else if(grid[3] == symbol && grid[6] == symbol)
        {
            // Left column
            return true;
        }
    }
    else if(grid[8] == symbol)
    {
        if(grid[6] == symbol && grid[7] == symbol)
        {
            // Bottom row
            return true;
        }
        else if(grid[2] == symbol && grid[5] == symbol)
        {
            // Right column
            return true;
        }
    }

    // Checks lines that pass the central square of the grid for three symbols in a row
    if(grid[4] == symbol)
    {
        if(grid[3] == symbol && grid[5] == symbol)
        {
            // Middle row
            return true;
        }
        else if(grid[1] == symbol && grid[7] == symbol)
        {
            // Middle column
            return true;
        }
        else if(grid[0] == symbol && grid[8] == symbol)
        {
            // Top left to bottom right diagonal
            return true;
        }
        else if(grid[2] == symbol && grid[6] == symbol)
        {
            // Top right to bottom left diagonal
            return true;
        }
    }

    // No win condition met
    return false;
}

void Grid::printGrid()
{
    // Prints the grid with columns and rows divided
    int row = 0;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "    " << grid[i + (row * 2)] << " | " << grid[i + (row * 2) + 1] << " | " << grid[i + (row * 2) + 2] << std::endl;

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

    if(grid[input] == 'X' || grid[input] == 'O')
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
    // Places the given symbol in the selected square on the grid
    grid[input] = symbol;
}
