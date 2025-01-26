//
// Created by Nativ on 18/01/2025.
//

#ifndef GOBLIN_H
#define GOBLIN_H
#include "Monster.h"



class Goblin : public Monster {

public:
    Goblin() : Monster() {};
    Goblin(const string &name, int maxAmountOfLife, int attackValue) : Monster(name, maxAmountOfLife, attackValue) {};

    virtual ~Goblin();

    Goblin* clone() const {return new Goblin(*this);};

    //copy constructor and assignment operator
    Goblin(const Goblin &goblin) : Monster(goblin) {};
    Goblin &operator=(const Goblin &goblin);

    virtual string getType() const;

    Goblin& MonsterAttackPlayer(Player& player);
};



#endif //GOBLIN_H
