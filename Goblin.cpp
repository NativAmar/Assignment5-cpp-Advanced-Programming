//
// Created by Nativ on 18/01/2025.
//

#include "Goblin.h"
#include "Fighter.h"

Goblin::~Goblin() = default;


Goblin& Goblin::operator=(const Goblin& rhs) {
    if (this == &rhs)
        return *this;
    Monster::operator=(rhs);
    return *this;
}

string Goblin::getType() const {
    return "Goblin";
}

Goblin & Goblin::attack(Entity &other) {
    Monster::attack(other);
    return *this;
}
