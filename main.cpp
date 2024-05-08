
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hero.h"
#include "character.h"
#include "fighter.h"
#include "sorcerer.h"
#include "item.h"
#include <memory>



int main() {
    std::srand(std::time(nullptr));


    Hero hero("Annina", 300, 10, 10, 10);

    Fighter matthias("Matthias", 50, 100, 5, 5, 5);
    matthias.addInventory(std::make_shared<Item>("Rüstung", 50));
    matthias.addInventory(std::make_shared<Item>("Schwert", 80));

    try {
        std::make_shared<Item>("", 50);
    } catch (InvalidArgumentException& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        std::make_shared<Item>("Schlüssel", -123);
    } catch (InvalidArgumentException& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        matthias.setGold(-100);
    } catch (InvalidArgumentException& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        matthias.setStrength(-200);
    } catch (InvalidArgumentException& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    Sorcerer pascal("Pascal", 100, 100, 5, 5, 5);
    pascal.addInventory(std::make_shared<Item>("Diamant", 300));
    pascal.addInventory(std::make_shared<Item>("Zauberstab", 80));


    try {
        pascal.setMagicPower(-200);
    } catch (InvalidArgumentException& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    try {
        pascal.setMagicResistance(-100);
    } catch (InvalidArgumentException& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }


    if (hero.fight(matthias)) {
        if (hero.fight(pascal)) {
            for (int t = 0; t < 10; t++) {
                try {
                    std::shared_ptr<Item> item = hero.sellItem(t);
                    if (item != nullptr) {
                        std::cout << item << " wurde für " << item->getGold() << " Gold verkauft" << std::endl;
                    }
                } catch (InventoryEmptySlotException& e) {
                    //do nothing
                }
            }
        }
    }
}
