

#include "sorcerer.h"
#include <iostream>

Sorcerer::Sorcerer(const std::string& name, int health, int gold, int armor, int magicResistance, int magicPower)
        : NPC(name, health, gold, armor, magicResistance), magicPower(magicPower) {}

Sorcerer::~Sorcerer() {
    // TODO Auto-generated destructor stub
}


void Sorcerer::attack(Character& enemy) {
    int dice = 5 + std::rand() % 11 + magicPower - enemy.getMagicResistance();
    std::cout << name << " trifft " << enemy << " fuer " << dice << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - dice);
}