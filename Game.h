#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

#include "Grid.h"
#include "Player.h"
#include "AI.h"

class Game
{
    public:
        Game();
        void runGame();

    private:
        bool checkWin(char symbol);
        void clearScreen();
        void gameIntro();

        void round();

        bool checkGameOver();
        void gameWin();
        void gameDraw();
        void gameOver();

        int moveCounter = 0;
        bool gameEnd = false;
        Grid gridObj;
        Player playerObj;
        AI aiObj;
};

#endif // GAME_H
