//
// Created by Nativ on 18/01/2025.
//

#include "Fighter.h"


Fighter::~Fighter() = default;


// Fighter & Fighter::specialAttack(const Entity &other) {
//     //here I should set the next attack against the fighter to 0
//     //doing nothing , maybe should print somthing
//     roundCounter=0;
//     return *this;
// }

Fighter& Fighter::attack(Entity &other) {
    //special ability checked in the monster's classes
    other.operator-=(*this);
    return *this;
}

double Fighter::getDamageMultiplier(const Entity &other) const {
    if (other.getType() == "Dragon")
        return 0.5;
    return 2.0;
}

Fighter& Fighter::operator=(const Fighter& other) {
    if (this == &other)
        return *this;
    Player::operator=(other);
    return *this;
}

string Fighter::getType() const {
    return "Fighter";
}

Fighter & Fighter::operator-=(const Entity &other) {
    if (IsItPossibleUseTheSpecialAttack()) {
        //special ability use
        //print something about that?
        resetRoundCounter();
        return *this;
    }
    Player::operator-=(other);
    return *this;
}
