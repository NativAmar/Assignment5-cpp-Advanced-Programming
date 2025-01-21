#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <memory>

#include "Entity.h"
#include "Monster.h"

class Room {
    string room_id;
    int m_campfire;
    unique_ptr<Monster> roomMonster;//create Entity in the contractor method if there is a monster in the room
    vector<Room*> roomsAccess;//dynamic array of Room pointers
    int roomsCounter;
    static int roomsCapacity;

public:
    //constructors
    Room(const string &roomID, const string& monsterFirstChar,int campfire, int monsterCurrAmountOfLife, int monsterAttackValue);
    //copy constructor
    Room(const Room& other);
    //destructor
    ~Room();

    Room& operator=(const Room* other);
    Room* operator[](int index);
    const Room* operator[](int index) const;

    int getRoomCounter() const;
    bool setRoomAccess(Room* room, int index);

    string getID() const;
    friend class Game;

};
#endif