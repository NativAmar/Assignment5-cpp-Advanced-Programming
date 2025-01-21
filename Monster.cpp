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

Monster& Monster::operator-=(const Entity &other) {
    currentAmountOfLife -= other.getAttackValue();
    if (currentAmountOfLife <= 0)
        currentAmountOfLife = 0;
    return *this;
}

Monster & Monster::attack(Entity &other) {
    other.operator-=(*this);
    return *this;
}


