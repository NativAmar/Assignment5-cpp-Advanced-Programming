//
// Created by Nativ on 18/01/2025.
//

#include "Monster.h"
#include "Fighter.h"


Monster::~Monster() = default;

Monster & Monster::operator=(const Monster &monster) {
    if (this == &monster)
        return *this;
    Entity::operator=(monster);
    return *this;
}

Monster & Monster::MonsterAttackedBySorcerer(const Player &other) {
    if (other.IsItPossibleUseTheSpecialAttack())
        this->currentAmountOfLife -= other.getAttackValue() * 2;
    else
        this->currentAmountOfLife -= other.getAttackValue();
    if(this->currentAmountOfLife < 0)
        this->currentAmountOfLife = 0;
    return *this;
}

Monster & Monster::MonsterAttackedByFighter(const Player &other) {
    this->currentAmountOfLife -= other.getAttackValue();
    if(this->currentAmountOfLife < 0)
        this->currentAmountOfLife = 0;
    return *this;
}

ostream& operator<<(ostream& os, const Monster& other) {
    os << other.name << " (" << other.currentAmountOfLife << "/" << other.maxAmountOfLife << ")" << " - " << other.attackValue;
    return os;
}


