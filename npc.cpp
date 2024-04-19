

#include "npc.h"
#include <iostream>

NPC::NPC(const std::string& name, int health, int gold, int armor, int magicResistance)
        : Character(name, health, gold, armor, magicResistance) {}

NPC::~NPC() {
    if (health <= 0) {
        std::cout << name << " sagt nicht mehr viel, da " << name << " besiegt wurde." << std::endl;
    } else {
        std::cout << name << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
    }
}

Item NPC::retrieveRandomLoot() {
    for (int i = 0; i < 10; i++) {
        int dice = rand() % 10;
        Item item = removeInventory(dice);
        if (item.isIsValid()) {
            return item;
        }
    }
    return Item();
}
