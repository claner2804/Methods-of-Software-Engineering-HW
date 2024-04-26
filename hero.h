
#ifndef HERO_H_
#define HERO_H_

#include <string>
#include "character.h"

// forward declarations
class NPC;
class Item;


class Hero : public Character {
private:
    Item* gear[2];

public:
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance);

    //virtual destructor damit auch die kindklassen ihren speicher freigeben können
    virtual ~Hero();

    virtual void attack(Character& enemy) override;

    Item* sellItem(int index);

    bool fight(NPC& enemy);

    Item* getGear(int i) const;

    int addGear(Item* item);

    Item* removeGear(int slot);
};



#endif /* HERO_H_ */