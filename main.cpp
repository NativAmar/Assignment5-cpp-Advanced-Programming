//#include <iostream>

#include "Game.h"

int main(int argc, char const *argv[])
{
    string playerFirstChar = argv[2];
    int amountOfLife = stoi(argv[3]);
    int damageLevel = stoi(argv[4]);
    const string inputFile = argv[5];
    Game game{playerFirstChar, inputFile, amountOfLife, damageLevel};

    game.initializer();
    game.run();
    return 0;
}
