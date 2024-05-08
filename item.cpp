
#include <iostream>
#include "item.h"

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "Item: " << item.getName() << ", Gold: " << item.getGold();
    return os;
}

Item::Item(const std::string& name, int gold)
        : name(name), gold(gold >= 0 ? gold : 0) {
    std::cout << "Item " << name << " wurde erstellt!" << std::endl;

    if (name.size() == 0) {
        throw InvalidArgumentException("Name darf nicht leer sein!");
    }

    if (gold < 0) {
        throw InvalidArgumentException("Gold darf nicht negativ sein!");
    }
}



Item::~Item() {
    std::cout << "Item " << name << " wurde zerstoert!" << std::endl;
}

