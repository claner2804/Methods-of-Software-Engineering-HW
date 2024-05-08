
#include "hero.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "character.h"
#include "npc.h"
#include "exceptions.h"
#include "item.h"
#include <memory>
#include <vector>

Hero::Hero(const std::string& name, int health, int gold, int armor, int magicResistance)
        : Character(name, health, gold, armor, magicResistance) {

}


Hero::~Hero() {
    for (int i = 0; i < 2; i++) {
        if (gear[i]) {
            gear[i].reset();
        }
    }
    std::cout << name << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
}

Item* Hero::getGear(int i) const {
    if (i >= 0 && i < 2) {
        if( gear[i]) {
            //gear zurückgeben
            return gear[i].get();

        } else {
            throw InventoryEmptySlotException();
        }
    } else {
        throw InventoryInvalidSlotException();
    }
}


int Hero::addGear(Item* item) {
    for (int i = 0; i < 2; i++) {
        if (!gear[i]) {
            //Item in gear speichern
            gear[i] = std::shared_ptr<Item>(item);
            return i;
        }
    }
    //kein freier Slot gefunden
    throw InventoryFullException();
}



Item* Hero::removeGear(int slot) {
    if (slot >= 0 && slot < 2) {
        if (gear[slot]) {
            //Item aus vector löschen und speicher freigeben
            gear[slot].reset();
            //Item zurückgeben
            return gear[slot].get();
        } else {
            throw InventoryEmptySlotException();
        }
    }
    throw InventoryInvalidSlotException();
}



void Hero::attack(Character& enemy) {
    int dice = 15 + std::rand() % 11 - enemy.getArmor();
    std::cout << name << " trifft " << enemy << " fuer " << dice << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - dice);
}


std::shared_ptr<Item> Hero::sellItem(int index) {
    //überprüfen ob index im gültigen bereich liegt
    if (index < 0 || index >= inventory.size()) {
        //wenn nicht exception werfen
        throw InventoryInvalidSlotException();
    }
    //überprüfen ob item an der stelle existiert
    if (!inventory[index]) {
        //wenn nicht exception werfen
        throw InventoryEmptySlotException();
    }
    //shared_ptr auf item an der stelle index holen
    std::shared_ptr<Item> item = inventory[index];
    //gold des heros um den goldwert des items erhöhen
    setGold(gold += item->getGold());
    //item aus dem vector löschen
    inventory.erase(inventory.begin() + index);
    //item zurückgeben
    return item;
}




bool Hero::fight(NPC& enemy) {
    while (health > 0 && enemy.getHealth() > 0) {
        attack(enemy);
        if (enemy.getHealth() > 0) {
            enemy.attack(*this);
        }
    }
    if (enemy.getHealth() <= 0) {
        std::cout << enemy << " fiel in Ohnmacht! " << name << " hat noch " << health << " Lebenspunkte uebrig!" << std::endl;
        Item* loot = enemy.retrieveRandomLoot();
        if (loot) {
            try {
                addInventory(std::shared_ptr<Item>(loot));
                std::cout << "Gegenstand " << loot << " wurde zum Inventar von " << name << " hinzugefügt."
                          << std::endl;
            } catch (InventoryFullException &e) {
                std::cout << "Im Inventar von " << name << " ist leider kein Platz mehr für " << loot << "." << std::endl;
            }
        } else {
            std::cout << "Es konnte kein Gegenstand erbeutet werden." << std::endl;
        }
        return true;
    } else {
        std::cout << name << " fiel in Ohnmacht! GAME OVER!" << std::endl;
        return false;
    }
}

