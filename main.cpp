
#include "Game.h"

int main(int argc, char const *argv[])
{
    string playerFirstChar = argv[1];
    int amountOfLife = stoi(argv[2]);
    int damageLevel = stoi(argv[3]);
    const string inputFile = argv[4];
    try {

        Game game{playerFirstChar, inputFile, amountOfLife, damageLevel};

        game.initializer();
        game.run();
    }
    catch (bad_alloc &e) { //constructor fail
        cout << "Memory problem" << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

