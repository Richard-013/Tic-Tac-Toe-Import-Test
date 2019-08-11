#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Grid.h"
#include "Player.h"
#include "AI.h"

int main()
{
    // Creates Game object
    Game gameObj;
    // Runs the game via game object
    gameObj.runGame();

    return 0;
}
