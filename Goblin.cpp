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
    return "goblin";
}

Goblin& Goblin::MonsterAttackPlayer(Player &player) {
    player.PlayerAttackedByGoblin(*this);
    return *this;
}
