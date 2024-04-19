
#include "hero.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "character.h"
#include "npc.h"

Hero::Hero(const std::string& name, int health, int gold, int armor, int magicResistance)
        : Character(name, health, gold, armor, magicResistance) {}


Hero::~Hero() {
    std::cout << name << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
}

void Hero::attack(Character& enemy) {
    int dice = 15 + std::rand() % 11 - enemy.getArmor();
    std::cout << name << " trifft " << enemy << " fuer " << dice << " Lebenspunkte!" << std::endl;
    enemy.setHealth(enemy.getHealth() - dice);
}


Item Hero::sellItem(int index) {
    if (index >= 0 && index < 10) {
        if (inventory[index].isIsValid()) {
            Item item = inventory[index];
            setGold(gold += inventory[index].getGold());
            inventory[index].setIsValid(false);
            return item;
        }
    }
    return Item();
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
        Item loot = enemy.retrieveRandomLoot();
        if (loot.isIsValid()) {
            if (addInventory(loot) >= 0) {
                std::cout << "Gegenstand " << loot << " wurde zum Inventar von " << name << " hinzugefügt." << std::endl;
            } else {
                std::cout << "Im Inventar von " << name << " ist leider kein Platz mehr für " << loot << "." <<std::endl;
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


int Hero::addGear(const Item& item) {
    for (int i = 0; i < 2; i++) {
        if (!gear[i].isIsValid()) {
            gear[i] = item;
            return i;
        }
    }
    return -1;
}

Item Hero::removeGear(int slot) {
    if (slot >= 0 && slot < 2) {
        Item tmp = gear[slot];
        gear[slot].setIsValid(false);
        return tmp;
    }
    return Item();
}