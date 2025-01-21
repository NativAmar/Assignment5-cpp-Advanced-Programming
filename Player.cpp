//
// Created by Lenovo on 18/01/2025.
//

#include "Player.h"

Player::~Player() = default;

Player& Player::operator=(const Player& other) {
    if (this == &other)
        return *this;
    this->roundCounter = other.roundCounter;
    this->readyForSpecialAttack = other.readyForSpecialAttack;
    Entity::operator=(other);
    return *this;
}

//maybe should I delete this?
int Player::getRoundCounter() const {
    return roundCounter;
}

void Player::addToRoundCounter() {
    roundCounter++;
}

void Player::resetRoundCounter() {
    roundCounter = 0;
}

bool Player::get_ReadyForSpecialAttack() const {
    return this->readyForSpecialAttack;
}

bool Player::IsItPossibleUseTheSpecialAttack() const {
    if (roundCounter == 4 || roundCounter == 0)
        return true;
    return false;
}

//take care the different damage level depend on the Entities in the battle
Player& Player::operator-=(const Entity &other) {
    int damage = static_cast<int>(std::round(this->getDamageMultiplier(other) * other.getAttackValue()));
    currentAmountOfLife -= damage;

    if (currentAmountOfLife <= 0)
        currentAmountOfLife = 0;

    return *this;
}

ostream& operator<<(ostream& os, const Player& other) {
    os << other.name << " (" << other.currentAmountOfLife << "/" << other.maxAmountOfLife << ")" << " - " << other.attackValue;
    return os;
}


