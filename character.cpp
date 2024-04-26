
#include "character.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "hero.h"
#include "exceptions.h"


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

    //inventory auf nullptr setzen damit keine undefinierten Werte enthalten sind
    memset(inventory, 0, sizeof(inventory));
}

//im destruktor speicher wieder freigeben
Character::~Character() {
    for (int i = 0; i < 10; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}

Item* Character::getInventory(int i) const {
    if (i >= 0 && i < 10) {
        if( inventory[i]) {
            return inventory[i];
        } else {
        throw InventoryEmptySlotException();
        }
    } else {
        throw InventoryInvalidSlotException();
    }
}

int Character::addInventory(Item* item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i]) {
            inventory[i] = item;
            return i;
        }
    }
    //kein freier Slot gefunden
   throw InventoryFullException();
}



Item* Character::removeInventory(int slot) {
    if (slot >= 0 && slot < 10) {
        if (inventory[slot]) {
            Item *tmp = inventory[slot];
            //mit nullptr inventory slot leeren
            inventory[slot] = nullptr;
            //Item zurückgeben
            return tmp;
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
