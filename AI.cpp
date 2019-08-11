#include "AI.h"

AI::AI()
{
    // Constructor
    srand (time(NULL)); // Seeds random number generation
}

void AI::setTargetGrid(Grid *grid)
{
    gridPtr = grid;
}

void AI::aiTurn()
{
    // Calls the correct AI move for the selected difficulty
    if(difficulty == Impossible)
    {
        impossibleAITurn();
    }
    else
    {
        normalAITurn();
    }
}

void AI::normalAITurn()
{
    // AI logic for normal difficulty
    // Goes for the central square if it is available otherwise chooses a random square to fill
    int temp = gridPtr->checkChoice(symbol, 4);

    // If central square was taken then try random squares
    if(temp != 0)
    {
        bool invalid = true;
        int num = 0;

        do
        {
            num = rand() % 9;
            temp = gridPtr->checkChoice(symbol, num);
            // If the choice is valid then break the loop
            if(temp == 0)
            {
                invalid = false;
            }
        } while(invalid);
    }
}

void AI::impossibleAITurn()
{
    // AI logic for impossible difficulty
    int result = impMoveWin();

    if(result == 1)
    {
        result = impMoveBlock();
    }
    if(result == 1)
    {
        result = impMoveCentral();
    }
    if(result == 1)
    {
        result = impMoveOppCorner();
    }
    if(result == 1)
    {
        result = impMoveCorner();
    }
    if(result == 1)
    {
        impMoveSide();
    }
}

char AI::getSymbol()
{
    // Returns the symbol the AI player is using
    return this->symbol;
}

void AI::setSymbol(char playerSymbol)
{
    // Sets the AI symbol to the opposite of the player's
    if(playerSymbol == 'O')
    {
        symbol = 'X';
    }
    else
    {
        symbol = 'O';
    }

    opponentSymbol = playerSymbol;
}

void AI::setDifficulty()
{
    // ALlows the player to choose the difficulty and sets values accordingly
    std::string choice = " ";
    char choiceReal = ' ';

    std::cout << "\nThere are two difficulties to choose from, which would you like?" << std::endl;
    std::cout << "    1 - Normal\n    2 - Impossible\n" << std::endl;

    getline(std::cin, choice);
    // Takes the first character in the input as the player choice
    choiceReal = choice[0];

    switch(choiceReal)
    {
    case '1':
        difficulty = Normal;
        std::cout << "\nNormal difficulty has been selected" << std::endl;
        break;
    case '2':
        difficulty = Impossible;
        std::cout << "\nImpossible difficulty has been selected" << std::endl;
        break;
    default:
        difficulty = Normal;
        std::cout << "\nInvalid option, defaulting to Normal difficulty" << std::endl;
        break;
    }
}

int AI::impMoveWin()
{
    // Goes for a winning move if there is one available
    // First checks if the central square is taken and if it is, checks if there are any resulting winning moves
    if(gridPtr->viewSquare(4) == symbol)
    {
        int j = 8;
        for(int i = 0; i < 9; i++)
        {
            if(i == 4)
            {
                j--;
                continue;
            }
            else if(gridPtr->viewSquare(i) == symbol)
            {
                if(gridPtr->checkChoice(symbol, j) == 0)
                {
                    return 0;
                }
            }

            j--;
        }
    }

    // If the game cannot be won using a line that passes the central square, check the outside for a winning move
    // Checks from the top left square
    if(gridPtr->viewSquare(0) == symbol)
    {
        // Tries to take victory by completing the top row
        if(gridPtr->viewSquare(1) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 2) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(2) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 1) == 0)
            {
                return 0;
            }
        }

        // Tries to take victory by completing the left column
        if(gridPtr->viewSquare(3) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 6) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(6) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 3) == 0)
            {
                return 0;
            }
        }

        // Tries to take victory by completing a top-left to bottom-right diagonal
        if(gridPtr->viewSquare(8) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    // Checks from the top right square
    if(gridPtr->viewSquare(2) == symbol)
    {
        // Checks top row in the case that square 0 is not taken by the AI
        if(gridPtr->viewSquare(1) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 0) == 0)
            {
                return 0;
            }
        }

        // Tries to take victory by completing the right column
        if(gridPtr->viewSquare(5) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 8) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(8) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 5) == 0)
            {
                return 0;
            }
        }

        // Tries to take victory by completing a top-right to bottom-left diagonal
        if(gridPtr->viewSquare(6) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    // Checks from the bottom left square
    if(gridPtr->viewSquare(6) == symbol)
    {
        // Checks left column in the case that square 0 is not taken by the AI
        if(gridPtr->viewSquare(3) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 0) == 0)
            {
                return 0;
            }
        }

        // Tries to take victory by completing the bottom row
        if(gridPtr->viewSquare(7) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 8) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(8) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 7) == 0)
            {
                return 0;
            }
        }
    }

    // Checks from the bottom right square
    if(gridPtr->viewSquare(8) == symbol)
    {
        // Checks bottom row in the case that square 6 is not taken by the AI
        if(gridPtr->viewSquare(7) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 6) == 0)
            {
                return 0;
            }
        }

        // Checks right column in the case that square 2 is not taken by the AI
        if(gridPtr->viewSquare(5) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 2) == 0)
            {
                return 0;
            }
        }
    }

    // Checks central row
    if(gridPtr->viewSquare(3) == symbol)
    {
        if(gridPtr->viewSquare(5) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    // Checks central column
    if(gridPtr->viewSquare(1) == symbol)
    {
        if(gridPtr->viewSquare(7) == symbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int AI::impMoveBlock()
{
    // Blocks an opponents winning move
    // First checks if the central square is taken and if it is, checks if there are any resulting winning moves and blocks the first one it finds
    if(gridPtr->viewSquare(4) == opponentSymbol)
    {
        int j = 8;
        for(int i = 0; i < 9; i++)
        {
            if(i == 4)
            {
                j--;
                continue;
            }
            else if(gridPtr->viewSquare(i) == opponentSymbol)
            {
                if(gridPtr->checkChoice(symbol, j) == 0)
                {
                    return 0;
                }
            }

            j--;
        }
    }

    // If the game cannot be won by the opponent using a line that passes the central square, check the outside for a winning move
    // Checks from the top left square
    if(gridPtr->viewSquare(0) == opponentSymbol)
    {
        // Tries to prevent the opponent from taking victory by completing the top row
        if(gridPtr->viewSquare(1) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 2) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(2) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 1) == 0)
            {
                return 0;
            }
        }

        // Tries to prevent the opponent from taking victory by completing the left column
        if(gridPtr->viewSquare(3) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 6) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(6) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 3) == 0)
            {
                return 0;
            }
        }

        // Tries to prevent the opponent from taking victory by completing a top-left to bottom-right diagonal
        if(gridPtr->viewSquare(8) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    // Checks from the top right square
    if(gridPtr->viewSquare(2) == opponentSymbol)
    {
        // Checks top row in the case that square 0 is not taken by the opponent
        if(gridPtr->viewSquare(1) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 0) == 0)
            {
                return 0;
            }
        }

        // Tries to prevent the opponent from taking victory by completing the right column
        if(gridPtr->viewSquare(5) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 8) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(8) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 5) == 0)
            {
                return 0;
            }
        }

        // Tries to prevent the opponent from taking victory by completing a top-right to bottom-left diagonal
        if(gridPtr->viewSquare(6) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    // Checks from the bottom left square
    if(gridPtr->viewSquare(6) == opponentSymbol)
    {
        // Checks left column in the case that square 0 is not taken by the opponent
        if(gridPtr->viewSquare(3) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 0) == 0)
            {
                return 0;
            }
        }

        // Tries to prevent the opponent from taking victory by completing the bottom row
        if(gridPtr->viewSquare(7) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 8) == 0)
            {
                return 0;
            }
        }
        if(gridPtr->viewSquare(8) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 7) == 0)
            {
                return 0;
            }
        }
    }

    // Checks from the bottom right square
    if(gridPtr->viewSquare(8) == opponentSymbol)
    {
        // Checks bottom row in the case that square 6 is not taken by the opponent
        if(gridPtr->viewSquare(7) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 6) == 0)
            {
                return 0;
            }
        }

        // Checks right column in the case that square 2 is not taken by the opponent
        if(gridPtr->viewSquare(5) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 2) == 0)
            {
                return 0;
            }
        }
    }

    // Checks central row
    if(gridPtr->viewSquare(3) == opponentSymbol)
    {
        if(gridPtr->viewSquare(5) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    // Checks central column
    if(gridPtr->viewSquare(1) == opponentSymbol)
    {
        if(gridPtr->viewSquare(7) == opponentSymbol)
        {
            if(gridPtr->checkChoice(symbol, 4) == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int AI::impMoveCentral()
{
    // Takes the central square if it available
    if(gridPtr->checkChoice(symbol, 4) == 1)
    {
        return 1;
    }

    return 0;
}

int AI::impMoveOppCorner()
{
    // Takes a corner opposite to one the opponent has already taken
    // Checks if a corner is taken, and if it is then the AI attempts to fill the opposite corner square (relies on short-circuit evaluation not to run the checkChoice function early)
    if(gridPtr->viewSquare(8) == opponentSymbol && gridPtr->checkChoice(symbol, 0) == 0)
    {
        return 0;
    }
    else if(gridPtr->viewSquare(6) == opponentSymbol && gridPtr->checkChoice(symbol, 2) == 0)
    {
        return 0;
    }
    else if(gridPtr->viewSquare(2) == opponentSymbol && gridPtr->checkChoice(symbol, 6) == 0)
    {
        return 0;
    }
    else if(gridPtr->viewSquare(0) == opponentSymbol && gridPtr->checkChoice(symbol, 8) == 0)
    {
        return 0;
    }

    return 1;
}

int AI::impMoveCorner()
{
    // Takes any available corner square
    if(gridPtr->checkChoice(symbol, 0) == 0)
    {
        return 0;
    }
    else if(gridPtr->checkChoice(symbol, 2) == 0)
    {
        return 0;
    }
    else if(gridPtr->checkChoice(symbol, 6) == 0)
    {
        return 0;
    }
    else if(gridPtr->checkChoice(symbol, 8) == 0)
    {
        return 0;
    }

    return 1;
}

int AI::impMoveSide()
{
    // Takes any available side square
    if(gridPtr->checkChoice(symbol, 1) == 0)
    {
        return 0;
    }
    else if(gridPtr->checkChoice(symbol, 3) == 0)
    {
        return 0;
    }
    else if(gridPtr->checkChoice(symbol, 5) == 0)
    {
        return 0;
    }
    else if(gridPtr->checkChoice(symbol, 7) == 0)
    {
        return 0;
    }

    return 1;
}

