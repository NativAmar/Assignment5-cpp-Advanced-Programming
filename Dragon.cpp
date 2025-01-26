//
// Created by Nativ on 18/01/2025.
//

#include "Dragon.h"

#include "Player.h"

Dragon::~Dragon() = default;

Dragon & Dragon::operator=(const Dragon &dragon) {
    if (this == &dragon)
        return *this;
    Monster::operator=(dragon);
    return *this;
}

string Dragon::getType() const {
    return "dragon";
}

Dragon& Dragon:: MonsterAttackPlayer(Player &player) {
    player.PlayerAttackedByDragon(*this);
    return *this;
}

