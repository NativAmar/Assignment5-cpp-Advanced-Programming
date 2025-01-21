//
// Created by Nativ on 18/01/2025.
//

#ifndef FIGHTER_H
#define FIGHTER_H
#include "Player.h"


class Fighter : public Player {
    //special ability once in 4 rounds
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

    Fighter& operator-=(const Entity &other);//reduce the currentAmountOfLife according to the received Monster's attackValue
    //Fighter& specialAttack(const Entity & other);

    Fighter& attack(Entity &other);

    double getDamageMultiplier(const Entity& other) const;

};



#endif //FIGHTER_H
