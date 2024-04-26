
#include "fighter.h"
#include <iostream>

Fighter::Fighter(const std::string& name, int health, int gold, int armor, int magicResistance, int strength)
        : NPC(name, health, gold, armor, magicResistance), strength(strength) {
    if (strength < 0) {
        throw InvalidArgumentException("Staerke darf nicht negativ sein!");
    }
}

Fighter::~Fighter() {
}


void Fighter::attack(Character& enemy) {
    int dice = 5 + std::rand() % 11 + strength - enemy.getArmor();
    std::cout << name << " trifft " << enemy << " fuer " << dice << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - dice);
}
