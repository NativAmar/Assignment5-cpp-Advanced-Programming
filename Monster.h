//
// Created by Nativ on 18/01/2025.
//

#ifndef MONSTER_H
#define MONSTER_H
#include "Entity.h"


class Monster : public Entity {
    //The monster's damage value depends on the enemy she is facing

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

    Monster& operator-=(const Entity& other);
    Monster& attack(Entity& other);

};



#endif //MONSTER_H
