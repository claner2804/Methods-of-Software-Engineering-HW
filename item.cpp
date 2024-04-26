
#include "item.h"
#include <iostream>

Item::Item(const std::string& name, int gold)
        : name(name), gold(gold >= 0 ? gold : 0) {
    std::cout << "Item " << name << " wurde erstellt!" << std::endl;
}


Item::~Item() {
    std::cout << "Item " << name << " wurde zerstoert!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName();
    return out;
}

std::ostream& operator<<(std::ostream& out, const Item* item) {
    out << item->getName();
    return out;
}