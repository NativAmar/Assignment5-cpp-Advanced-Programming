#include "Room.h"
#include <stdexcept>

#include "Dragon.h"
#include "Goblin.h"

using namespace std;

int Room::roomsCapacity = 9;

Room::Room(const string &roomID, const string& monsterFirstChar,int campfire, int monsterCurrAmountOfLife, int monsterAttackValue): room_id(roomID) ,m_campfire(campfire), roomMonster(nullptr), roomsCounter(0) {
    if (monsterCurrAmountOfLife < 0 || monsterAttackValue < 0) {
        throw invalid_argument("Invalid input for room creation");
    }
    if (monsterCurrAmountOfLife != 0 && monsterAttackValue != 0) {
        //create the room's monster
        if (monsterFirstChar == "D") {
            roomMonster = unique_ptr<Dragon>(new Dragon("Dragon", monsterCurrAmountOfLife, monsterAttackValue));
        }
        else if (monsterFirstChar == "G") {
            roomMonster = unique_ptr<Goblin>(new Goblin("Goblin", monsterCurrAmountOfLife, monsterAttackValue));
        }
    }
}

//copy constructor
Room::Room(const Room &other) {
    //copy simple fields
    this->room_id = other.room_id;
    this->m_campfire = other.m_campfire;
    this->roomsCounter = other.roomsCounter;
    this->roomsAccess = other.roomsAccess;

    if (other.roomMonster)
        this->roomMonster = unique_ptr<Monster>(other.roomMonster->clone());
    else
        this->roomMonster = nullptr;
}

Room::~Room() {
    roomsAccess.clear();//handle the rooms memory at the Game destructor
}

// Assignment Operator
Room &Room::operator=(const Room *other) {
    if (this != other) {
        room_id = other->room_id;
        m_campfire = other->m_campfire;
        roomsAccess = other->roomsAccess;
        roomsCounter = other->roomsCounter;

        if (other->roomMonster) {
            roomMonster = unique_ptr<Monster>(other->roomMonster->clone());
        } else {
            roomMonster = nullptr;
        }
    }
    return *this;
}

Room *Room::operator[](int index) {
    if (roomsCounter == 0 || index >= static_cast<int>(roomsAccess.size())) {
        throw out_of_range("Index out of range");
    } else {
        return this->roomsAccess[index];
    }
}

const Room *Room::operator[](int index) const {
    if (roomsCounter == 0 || index >= static_cast<int>(roomsAccess.size())) {
        throw out_of_range("Index out of range");
    } else {
        return this->roomsAccess[index];
    }
}

int Room::getRoomCounter() const {
    return roomsCounter;
}

// Set access to a specific room
bool Room::setRoomAccess(Room* room, int index) {
    if (index < 0 || index >= roomsCapacity) {
        throw out_of_range("Index out of range");
    }
    if (!room) {
        throw invalid_argument("Invalid input: room is null");
    }

    // Ensure the vector can accommodate the specified index
    if (index >= static_cast<int>(roomsAccess.size())) {
        roomsAccess.resize(index + 1, nullptr);
    }

    roomsAccess[index] = room;
    roomsCounter = index + 1;
    return true; // Assignment successful
}

string Room::getID() const {
    return room_id;
}
