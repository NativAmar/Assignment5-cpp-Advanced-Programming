//
// Created by Nativ on 18/01/2025.
//

#include "Sorcerer.h"

Sorcerer::~Sorcerer() = default;

Sorcerer& Sorcerer::operator=(const Sorcerer& other) {
    if (this == &other)
        return *this;

    Player::operator=(other);
    return *this;
}

string Sorcerer::getType() const {
    return "Sorcerer";
}

// Sorcerer &Sorcerer::specialAttack(const Entity &other) {
//     //logic for value attack * 2
//     return *this;
// }

Sorcerer & Sorcerer::attack(Entity &other) {
    if (this->get_ReadyForSpecialAttack()) {
        //special attack use
        other.operator-=(2*attackValue);
        resetRoundCounter();
        return *this;
    }
    other.operator-=(*this);
    return *this;
}

double Sorcerer::getDamageMultiplier(const Entity &other) const {
    if (other.getType() == "Dragon")
        return 2.0;
    return 0.5;
}

