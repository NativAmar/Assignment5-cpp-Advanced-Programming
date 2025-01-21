#ifndef GAME_H
#define GAME_H

#include <memory>

#include "Room.h"
#include "Player.h"

class Game {
    Room *entryRoom;
    string configuration_file;
    vector<Room*> rooms;
    int roomCounter;
    unique_ptr<Player> playerEntity;

public:
    //constructors
    Game();
    Game(const string PlayerFirstChar, const string& configurationFile, int amountOfLife, int damage);

    //destructor
    ~Game();

    //delete all method
    void cleanAndClear();

    void addRoomToArray(Room *room);
    Room *getRoomByID(const string& roomID) const;

    //parse methods
    void parseFile(const string& configurationFile);
    void parseLine(const string& line);

    void initializer();//Game initializer
    void run();//execute method
};

#endif
