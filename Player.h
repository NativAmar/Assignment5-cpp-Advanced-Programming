//
// Created by Nativ on 18/01/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


class Player: public Entity {
    //special ability field?
protected:
    //will be controlled at the Game class
    int roundCounter;
    bool readyForSpecialAttack;

    public:
    //Constructors
    Player() : Entity(), roundCounter(0), readyForSpecialAttack(true) {};
    //initialized rounctCounter with -1 for the first round in the game
    Player(const string &name, int maxAmountOfLife, int damageValue) : Entity(name, maxAmountOfLife, damageValue), roundCounter(-1),readyForSpecialAttack(true){};

    //Destructor
    virtual ~Player();

    //copy constructor and assignment operator
    Player(const Player& other) : Entity(other), roundCounter(other.roundCounter), readyForSpecialAttack(other.readyForSpecialAttack) {};
    Player& operator=(const Player& other);

    int getRoundCounter() const;
    void addToRoundCounter();
    void resetRoundCounter();
    bool get_ReadyForSpecialAttack() const;

    virtual bool IsItPossibleUseTheSpecialAttack() const=0;

    friend ostream& operator<<(ostream& os, const Player& other);

    virtual Player& PlayerAttackedByGoblin(const Monster &monster)=0;
    virtual Player& PlayerAttackedByDragon(const Monster &monster)=0;

    virtual bool operator<(const Entity& other) const;
    virtual bool operator>(const Entity& other) const;
    
};



#endif //PLAYER_H
