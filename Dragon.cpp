//
// Created by Nativ on 18/01/2025.
//

#include "Dragon.h"

Dragon::~Dragon() = default;

Dragon & Dragon::operator=(const Dragon &dragon) {
    if (this == &dragon)
        return *this;
    Monster::operator=(dragon);
    return *this;
}

string Dragon::getType() const {
    return "Dragon";
}

Dragon & Dragon::attack(Entity &other) {
    Monster::attack(other);
    return *this;
}





