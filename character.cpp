
#include "character.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "hero.h"


Character::Character(const std::string& name, int health, int gold, int armor, int magicResistance)
        : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {}


const Item* Character::getInventory(int i) const {
    if (i >= 0 && i < 10) {
        return &inventory[i];
    } else {
        return nullptr;
    }
}

int Character::addInventory(const Item& item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i].isIsValid()) {
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}

Item Character::removeInventory(int slot) {
    if (slot >= 0 && slot < 10) {
        Item tmp = inventory[slot];
        inventory[slot].setIsValid(false);
        return tmp;
    }
    return Item();
}

std::ostream& operator<<(std::ostream& out, const Character& character) {
    out << character.getName();
    return out;
}
