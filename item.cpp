
#include "item.h"

Item::Item(const std::string& name, int gold)
        : name(name), gold(gold >= 0 ? gold : 0), isValid(true) {}

Item::Item()
        : name(), gold(), isValid(false) {}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName();
    return out;
}