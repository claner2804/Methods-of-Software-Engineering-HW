
#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include "exceptions.h"

class Item {
private:
    std::string name;
    int gold;

public:

    Item(const std::string& name, int gold);

    //virtual destructor, damit auch die kindklassen ihren speicher freigeben können
    virtual ~Item();

    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
        else {
            throw InvalidArgumentException("Gold darf nicht negativ sein!");
        }
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if (name.size() > 0) {
            this->name = name;
        }
        else {
            throw InvalidArgumentException("Name darf nicht leer sein!");
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Item& item);

};





#endif /* ITEM_H_ */