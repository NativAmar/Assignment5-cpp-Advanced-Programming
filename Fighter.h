//
// Created by Nativ on 18/01/2025.
//

#ifndef FIGHTER_H
#define FIGHTER_H
#include "Player.h"


class Fighter : public Player {

public:
    //constructors
    Fighter(): Player() {};
    Fighter(const string &name, int maxAmountOfLife, int damageValue) : Player(name, maxAmountOfLife, damageValue) {};

    //destructor
    virtual ~Fighter();

    //copy constructor and assignment operator
    Fighter(const Fighter& other) : Player(other) {};
    Fighter& operator=(const Fighter& other);

    virtual string getType() const;

    Fighter &PlayerAttackMonster(Monster &other);

    bool IsItPossibleUseTheSpecialAttack() const;

    Fighter& PlayerAttackedByGoblin(const Monster &other);
    Fighter& PlayerAttackedByDragon(const Monster &other);

};



#endif //FIGHTER_H
