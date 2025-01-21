//
// Created by Nativ on 18/01/2025.
//

#ifndef DRAGON_H
#define DRAGON_H
#include "Monster.h"


class Dragon: public Monster {

    public:

    //constructors
    Dragon() : Monster() {} ;
    Dragon(const string &name, int maxAmountOfLife, int attackValue) : Monster(name, maxAmountOfLife, attackValue) {};

    //destructor
    virtual ~Dragon();

    Dragon* clone() const {return new Dragon(*this); };

    //copy constructor and assignment operator
    Dragon(const Dragon &dragon) : Monster(dragon) {};
    Dragon &operator=(const Dragon &dragon);

    virtual string getType() const;

    Dragon& attack(Entity& other);

};



#endif //DRAGON_H
