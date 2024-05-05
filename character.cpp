
#include "character.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "hero.h"
#include "exceptions.h"
#include <vector>
#include "item.h"
#include <memory>


//im Konstruktor wird geprüft, ob die Werte korrekt sind (RAII und Exceptions)
Character::Character(const std::string& name, int health, int gold, int armor, int magicResistance)
        //wenn health kleiner 0 ist, wird 0 gesetzt
        : name(name), health(health < 0 ? 0 : health), gold(gold), armor(armor), magicResistance(magicResistance) {

    if(gold < 0) {
        throw InvalidArgumentException("Invalid gold value!");
    }

    if(armor < 0) {
        throw InvalidArgumentException("Invalid armor value!");
    }

    if(magicResistance < 0) {
        throw InvalidArgumentException("Invalid magicResistance value!");
    }

}

//im destruktor speicher wieder freigeben
Character::~Character() {
    for (int i = 0; i < 10; i++) {
        if (inventory[i]) {
            //aus vector löschen und speicher freigeben
            inventory[i].reset();
        }
    }
}

Item* Character::getInventory(int i) const {
    if (i >= 0 && i < 10) {
        if( inventory[i]) {
            //Item zurückgeben
            return inventory[i].get();

        } else {
        throw InventoryEmptySlotException();
        }
    } else {
        throw InventoryInvalidSlotException();
    }
}

int Character::addInventory(std::shared_ptr<Item> item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i]) {
            inventory[i] = item;
            return i;
        }
    }
    throw InventoryFullException();
}



Item* Character::removeInventory(int slot) {
    if (slot >= 0 && slot < 10) {
        if (inventory[slot]) {
            //Item aus vector löschen und speicher freigeben
            inventory[slot].reset();
            //Item zurückgeben
            return inventory[slot].get();

        } else {
            throw InventoryEmptySlotException();
        }
    }
        throw InventoryInvalidSlotException();
}

    std::ostream &operator<<(std::ostream &out, const Character &character) {
        out << character.getName();
        return out;
}

std::ostream &operator<<(std::ostream &out, const Character *character) {
    out << character->getName();
    return out;
}
