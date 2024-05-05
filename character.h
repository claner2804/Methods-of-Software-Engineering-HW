
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include "exceptions.h"
#include <iostream>
#include <vector>

//forward declaration, weil wir hier nur pointer auf item haben
class Item;

class Character {
protected:
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;

    //vector mit shared_ptr statt array, weil wir die größe nicht kennen
    std::vector<std::shared_ptr<Item>> inventory;


public:
    Character(const std::string& name, int health, int gold, int armor, int magicResistance);

    //virtual destructor, damit auch die kindklassen ihren speicher freigeben können
    virtual ~Character();

    virtual void attack(Character& enemy) = 0;

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

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        if (health < 0) {
            health = 0;
        }
        this->health = health;
    }


    Item* getInventory(int i) const;

    const std::string& getName() const {
        return name;
    }

    int addInventory(std::shared_ptr<Item> item);

    Item* removeInventory(int slot);

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        if (armor >= 0) {
            this->armor = armor;
        }
        else {
            throw InvalidArgumentException("Armor darf nicht negativ sein!");
        }
    }

    int getMagicResistance() const {
        return magicResistance;
    }

    void setMagicResistance(int magicResistance) {
        if (magicResistance >= 0) {
            this->magicResistance = magicResistance;
        }
        else {
            throw InvalidArgumentException("Magie Resistenz darf nicht negativ sein!");
        }
    }


};



std::ostream& operator<<(std::ostream& out, const Character& character);
std::ostream& operator<<(std::ostream& out, const Character* character);


#endif /* CHARACTER_H_ */