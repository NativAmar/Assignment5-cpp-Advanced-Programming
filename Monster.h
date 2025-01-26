//
// Created by Nativ on 18/01/2025.
//

#ifndef MONSTER_H
#define MONSTER_H
#include "Entity.h"


class Monster : public Entity {

    public:
    //constructors
    Monster() : Entity() {};
    Monster(const string &name, int maxAmountOfLife, int attackValue) : Entity(name, maxAmountOfLife, attackValue) {};

    //destructor
    virtual ~Monster();

    virtual Monster* clone() const = 0;

    //copy constructor and assignment operator
    Monster(const Monster &monster) : Entity(monster) {};
    Monster& operator=(const Monster &monster);

    Monster& MonsterAttackedBySorcerer(const Player& player);
    Monster& MonsterAttackedByFighter(const Player& player);

    friend ostream& operator<<(ostream& os, const Monster& other);
};



#endif //MONSTER_H
