#ifndef GAME_H
#define GAME_H

#include <string>
#include "Grid.h"
#include "Player.h"
#include "AI.h"

class Game
{
    public:
        Game();

    protected:

    private:
        bool checkWin(char symbol);
        void clearScreen();
        std::string gameIntro();
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
