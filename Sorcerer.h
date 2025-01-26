//
// Created by Nativ on 18/01/2025.
//

#ifndef SORCERER_H
#define SORCERER_H
#include "Player.h"


class Sorcerer : public Player {
    //special ability once in 4 rounds
public:
    //constructors
    Sorcerer():Player(){};
    Sorcerer(const string& name, int maxAmountOfLife, int damageValue) : Player(name, maxAmountOfLife, damageValue) {};

    //destructor
    virtual ~Sorcerer();

    //copy constructor and assignment operator
    Sorcerer(const Sorcerer& other) : Player(other) {};
    Sorcerer& operator=(const Sorcerer& other);

    virtual string getType() const;

    bool IsItPossibleUseTheSpecialAttack() const;


    //Sorcerer& operator-=(const Entity& other);//reduce the currentAmountOfLife according to the received Monster's attackValue
    //Sorcerer& specialAttack(const Entity& other);//?

    //Sorcerer& attack(Entity &other);

    //double getDamageMultiplier(const Entity& other) const;

    Player &PlayerAttackMonster(Monster &other);

    Sorcerer &PlayerAttackedByGoblin(const Monster &other);

    Sorcerer &PlayerAttackedByDragon(const Monster &other);
};



#endif //SORCERER_H
