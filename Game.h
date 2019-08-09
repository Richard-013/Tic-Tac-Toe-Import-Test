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
        void clearScreen();

        void gameIntro();

        void gameLoop();
        int round();

        bool checkWin(char symbol);
        void gameWin();
        void gameDraw();
        void gameOver();

        bool playAgain();

        int moveCounter = 0;
        bool gameEnd = false;

        Grid gridObj;
        Player playerObj;
        AI aiObj;
};

#endif // GAME_H
