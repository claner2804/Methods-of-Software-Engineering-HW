

#include "sorcerer.h"
#include <iostream>

Sorcerer::Sorcerer(const std::string& name, int health, int gold, int armor, int magicResistance, int magicPower)
        : NPC(name, health, gold, armor, magicResistance), magicPower(magicPower) {

    if (magicPower < 0) {
        throw InvalidArgumentException("Magie darf nicht negativ sein!");
    }
}

Sorcerer::~Sorcerer() {
}


void Sorcerer::attack(Character& enemy) {
    int dice = 5 + std::rand() % 11 + magicPower - enemy.getMagicResistance();
    std::cout << name << " trifft " << enemy << " fuer " << dice << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - dice);
}