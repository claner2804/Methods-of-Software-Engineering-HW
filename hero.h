
#ifndef HERO_H_
#define HERO_H_

#include <string>
#include "character.h"
#include <memory>
#include <vector>

// forward declarations
class NPC;
class Item;


class Hero : public Character {
private:
    //gear array auf vector mit shared_ptr ändern
    std::vector<std::shared_ptr<Item> > gear;

public:
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance);

    //virtual destructor damit auch die kindklassen ihren speicher freigeben können
    virtual ~Hero();

    virtual void attack(Character& enemy);

    //std::shared_ptr<Item> sellItem(int index);
    std::shared_ptr<Item> sellItem(int index);

    bool fight(NPC& enemy);

    Item* getGear(int i) const;

    int addGear(Item* item);

    Item* removeGear(int slot);
};



#endif /* HERO_H_ */