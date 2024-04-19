
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <string>



class Character {
protected:
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    Item inventory[10];

public:
    Character(const std::string& name, int health, int gold, int armor, int magicResistance);

    virtual ~Character() {}

    virtual void attack(Character& enemy) = 0;

    int getGold() const {
        return gold;
    }

    void setGold(int gold) {
        if (gold >= 0) {
            this->gold = gold;
        }
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        if (health < 0) {
            health = 0;
        }
        this->health = health;
    }

    const Item* getInventory(int i) const;

    const std::string& getName() const {
        return name;
    }

    int addInventory(const Item& item);
    Item removeInventory(int slot);

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        this->armor = armor;
    }

    int getMagicResistance() const {
        return magicResistance;
    }

    void setMagicResistance(int magicResistance) {
        this->magicResistance = magicResistance;
    }
};



std::ostream& operator<<(std::ostream& out, const Character& character);



#endif /* CHARACTER_H_ */