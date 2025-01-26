//
// Created by Nativ on 18/01/2025.
//

#include "Fighter.h"
#include "Monster.h"


Fighter::~Fighter() = default;

Fighter & Fighter::PlayerAttackedByGoblin(const Monster &other) {
    if (this->IsItPossibleUseTheSpecialAttack()) {
        this->resetRoundCounter();
        return *this;
    }
    int damage = static_cast<int>(std::round(2 * other.getAttackValue()));
    this->currentAmountOfLife -= damage;
    if (this->currentAmountOfLife < 0)
        this->currentAmountOfLife = 0;
    return *this;
}

Fighter & Fighter::PlayerAttackedByDragon(const Monster &other) {
    if (this->IsItPossibleUseTheSpecialAttack()) {
        this->resetRoundCounter();
        return *this;
    }
    int damage = static_cast<int>(std::round(0.5 * other.getAttackValue()));
    this->currentAmountOfLife -= damage;
    if (this->currentAmountOfLife < 0)
        this->currentAmountOfLife = 0;
    return *this;
}

Fighter& Fighter::operator=(const Fighter& other) {
    if (this == &other)
        return *this;
    Player::operator=(other);
    return *this;
}

string Fighter::getType() const {
    return "fighter";
}

Fighter& Fighter::PlayerAttackMonster(Monster &other) { //fighter attack monster
    other.MonsterAttackedByFighter(*this);
    return *this;
}

bool Fighter::IsItPossibleUseTheSpecialAttack() const {
    if (this->roundCounter == 0 || this->roundCounter == 4)
        return true;
    return false;
}
