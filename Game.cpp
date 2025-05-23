#include "Game.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "Fighter.h"
#include "Sorcerer.h"
#include "invalidRoom.h"

using namespace std;


Game::Game() {
    entryRoom = new Room("","", 0, 0, 0);
    configuration_file = "";
    roomCounter = 0;
}

Game::Game(const string PlayerFirstChar,const string& configurationFile, int amountOfLife, int damage) {
        entryRoom = new Room("", "", 0, 0, 0);
        configuration_file = configurationFile;
        if (PlayerFirstChar == "F")
            playerEntity = unique_ptr<Fighter>(new Fighter("Fighter", amountOfLife, damage));
        else
            playerEntity = unique_ptr<Sorcerer>(new Sorcerer("Sorcerer", amountOfLife, damage));
        roomCounter = 0;
}

Game::~Game() {
    cleanAndClear();
}

void Game::cleanAndClear() {
    for (Room* room : rooms) {
        delete room; // Deleting the room objects
    }
    rooms.clear(); // Clearing the vector
}

void Game::addRoomToArray(Room *room) {
    if (room)
        rooms.push_back(room);
    roomCounter++;
}

Room* Game::getRoomByID(const string& roomID) const {
    for (int i = 0; i < roomCounter; ++i) {
        if (rooms[i]->getID() == roomID) {
            return rooms[i];
        }
    }
    return nullptr;
}

void Game::parseLine(const string& line) {
    istringstream s(line);
    vector<string> tokens;
    string token;
    string roomID, monsterFirstChar;
    int campfire, monsterLife, monsterDamage;

    // Tokenize the line
    while (s >> token) {
        tokens.push_back(token);
    }

    // Handle cases based on the number of tokens
    if (tokens.size() == 3) {
        // Format: roomID, campfire, No Monster
        roomID = tokens[0];
        campfire = stoi(tokens[1]);
        Room* newRoom = new Room(roomID, "", campfire, 0, 0);
        addRoomToArray(newRoom);
        //Set room access for rooms with connections
        Room* finalRoomAddress = getRoomByID(roomID.substr(0, roomID.length() - 1));
        if (finalRoomAddress == nullptr) {
            throw out_of_range("Invalid room");
        }
        finalRoomAddress->setRoomAccess(newRoom, stoi(&roomID.back()));
    }
    else if (tokens.size() == 5) {
        // Format: roomID, campfire, monsterFirstChar, monsterLife, monsterDamage
        roomID = tokens[0];
        campfire = stoi(tokens[1]);
        monsterFirstChar = tokens[2];
        monsterLife = stoi(tokens[3]);
        monsterDamage = stoi(tokens[4]);
        Room* newRoom = new Room(roomID, monsterFirstChar, campfire, monsterLife, monsterDamage);
        addRoomToArray(newRoom);
        //Set room access for rooms with connections
        Room* finalRoomAddress = getRoomByID(roomID.substr(0, roomID.length() - 1));
        if (finalRoomAddress == nullptr) {
            throw invalidRoom();
        }
        finalRoomAddress->setRoomAccess(newRoom, stoi(&roomID.back()));
    }
    else { //wrong line type
        throw invalid_argument("Invalid line format: Unexpected number of elements.");
    }
}

void Game::parseFile(const string& configurationFile) {
    ifstream file(configuration_file);
    string line;
    if (!file) {
        throw invalid_argument("File '" + configurationFile + "' not accessible.");
    }
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
            parseLine(line);
    }
}


void Game::initializer() {
    try {
        addRoomToArray(entryRoom);
        parseFile(configuration_file);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
        cleanAndClear();
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
        cleanAndClear();
    }
    catch (bad_alloc& e) {
        cout << "Memory problem" << endl;
        cleanAndClear();
    }
    catch (invalidRoom& e) {
        cout<< e.what() << endl;
        cleanAndClear();
    }
}

void Game::run() {

    Room* currentRoom = entryRoom;

    while (currentRoom != nullptr) {
        cout << *playerEntity << endl;
        if (currentRoom->m_campfire == 0 && currentRoom->roomMonster == nullptr) {
            cout << "You arrive to an empty room " << endl;
        }
        if (currentRoom->m_campfire > 0) {
            cout << "You sit by the campfire and heal " << currentRoom->m_campfire << " health " << endl;
            *playerEntity += currentRoom->m_campfire;
            playerEntity->addToRoundCounter();
        }
        string compareRes;
        if (currentRoom->roomMonster != nullptr) {
            if (playerEntity->operator>(*(currentRoom->roomMonster))) {
                compareRes = "smaller";
            }
            else if (playerEntity->operator<(*(currentRoom->roomMonster))) {
                compareRes = "larger";
            }
            else {
                compareRes = "equally sized";
            }
            cout << "You encounter a " << compareRes << " " << currentRoom->roomMonster->getType() << " " <<  endl;
            cout << *(currentRoom->roomMonster) << endl;
            while (currentRoom->roomMonster->getCurrentAmountOfLife() != 0 || playerEntity->getCurrentAmountOfLife() != 0) {
                (playerEntity)->PlayerAttackMonster(*(currentRoom->roomMonster));
                if (playerEntity->getType()=="sorcerer") {
                    if (playerEntity->IsItPossibleUseTheSpecialAttack())
                        cout << "You deal " << playerEntity->getAttackValue() * 2 << " damage to the "<< currentRoom->roomMonster->getType() << " and leave it with " << currentRoom->roomMonster->getCurrentAmountOfLife() << " health " << endl;
                    else
                        cout << "You deal " << playerEntity->getAttackValue()<< " damage to the "<< currentRoom->roomMonster->getType() << " and leave it with " << currentRoom->roomMonster->getCurrentAmountOfLife() << " health " << endl;
                }
                else
                    cout << "You deal " << playerEntity->getAttackValue() << " damage to the "<< currentRoom->roomMonster->getType() << " and leave it with " << currentRoom->roomMonster->getCurrentAmountOfLife() << " health " << endl;
                if (currentRoom->roomMonster->getCurrentAmountOfLife() == 0) {
                    cout << "You defeat the " << currentRoom->roomMonster->getType() << " and go on with your journey " << endl;
                    break;
                }
                currentRoom->roomMonster->MonsterAttackPlayer(*playerEntity);
                if (playerEntity->getType()=="fighter") {
                    if (playerEntity->IsItPossibleUseTheSpecialAttack())
                        cout << "The " << currentRoom->roomMonster->getType() << " deals 0 damage to you and leaves you with " << playerEntity->getCurrentAmountOfLife() << " health " << endl;
                    else if (currentRoom->roomMonster->getType() == "dragon")
                        cout << "The " << currentRoom->roomMonster->getType() << " deals " << currentRoom->roomMonster->getAttackValue() * 0.5 << " damage to you and leaves you with " << playerEntity->getCurrentAmountOfLife() << " health " << endl;
                    else
                        cout << "The " << currentRoom->roomMonster->getType() << " deals " << currentRoom->roomMonster->getAttackValue() * 2 << " damage to you and leaves you with " << playerEntity->getCurrentAmountOfLife() << " health " << endl;
                }
                else { // Sorcerer
                    if (currentRoom->roomMonster->getType() == "dragon")
                        cout << "The " << currentRoom->roomMonster->getType() << " deals " << currentRoom->roomMonster->getAttackValue() * 2 << " damage to you and leaves you with " << playerEntity->getCurrentAmountOfLife() << " health " << endl;

                    else //goblin
                        cout << "The " << currentRoom->roomMonster->getType() << " deals " << currentRoom->roomMonster->getAttackValue() * 0.5 << " damage to you and leaves you with " << playerEntity->getCurrentAmountOfLife() << " health " << endl;

                }
                if (playerEntity->getCurrentAmountOfLife() == 0) {
                    cout << "You lost to the dungeon " << endl;
                    //exit and delete all
                    cleanAndClear();
                    return;
                }
                playerEntity->addToRoundCounter();
            }
        }
        if (currentRoom->roomsCounter == 0 && !currentRoom->roomsAccess.data()) { // there is no rooms to enter
            cout << "The room continues and opens up to the outside. You won against the dungeon " << endl;
            cleanAndClear();
            return;
        }
        if (currentRoom->roomsCounter == 1) { //one room is possible
            cout << "You see a single corridor ahead of you labeled " << currentRoom->roomsCounter - 1 << " " <<  endl;
            int choice;
            cin >> choice;
            playerEntity->addToRoundCounter();
            currentRoom = (*currentRoom)[choice];
        }
        else { //more than one possible room
            cout << "You see corridors labeled from 0 to " << currentRoom->roomsCounter - 1 << ". Which one will you choose? " << endl;
            int choose;
            cin >> choose;
            playerEntity->addToRoundCounter();
            currentRoom = (*currentRoom)[choose];
        }
    }
}
