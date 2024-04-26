
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "hero.h"
#include "character.h"
#include "fighter.h"
#include "Sorcerer.h"
#include "item.h"



int main() {
    std::srand(std::time(nullptr));

    Hero hero("Annina", 300, 10, 10, 10);

    Fighter matthias("Matthias", 50, 100, 5, 5, 5);
    matthias.addInventory(new Item("Zaubertrank", 120));
    matthias.addInventory(new Item("Schwert", 80));

    Sorcerer pascal("Pascal", 100, 100, 5, 5, 5);
    pascal.addInventory(new Item("Diamant", 300));
    pascal.addInventory(new Item("Zauberstab", 80));

    if (hero.fight(matthias)) {
        if (hero.fight(pascal)) {
            for (int t = 0; t < 10; t++) {
                try {
                    Item* item = hero.sellItem(t);
                        std::cout << item << " wurde für " << item->getGold() << " Gold verkauft" << std::endl;
                } catch (InventoryEmptySlotException& e) {
                    //do nothing
                }
            }
        }
    }
}
