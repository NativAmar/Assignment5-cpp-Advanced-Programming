//
// Created by Nativ on 18/01/2025.
//

#include "Sorcerer.h"
#include "Monster.h"

Sorcerer::~Sorcerer() = default;

Sorcerer& Sorcerer::operator=(const Sorcerer& other) {
    if (this == &other)
        return *this;

    Player::operator=(other);
    return *this;
}

string Sorcerer::getType() const {
    return "sorcerer";
}

bool Sorcerer::IsItPossibleUseTheSpecialAttack() const {
    if (this->roundCounter == 0 || this->roundCounter == 5)
        return true;
    return false;
}

Player& Sorcerer::PlayerAttackMonster(Monster &other) { //Sorcerer attack monster
    other.MonsterAttackedBySorcerer(*this);
    return *this;
}

Sorcerer& Sorcerer::PlayerAttackedByGoblin(const Monster &other) {
    int damage = static_cast<int>(std::round(0.5 * other.getAttackValue()));
    this->currentAmountOfLife -= damage;
    if (this->currentAmountOfLife <= 0)
        this->currentAmountOfLife = 0;
    return *this;
}

Sorcerer & Sorcerer::PlayerAttackedByDragon(const Monster &other) {
    int damage = static_cast<int>(std::round(2 * other.getAttackValue()));
    this->currentAmountOfLife -= damage;
    if (this->currentAmountOfLife <= 0)
        this->currentAmountOfLife = 0;
    return *this;
}

