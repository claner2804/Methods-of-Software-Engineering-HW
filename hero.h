
#ifndef HERO_H_
#define HERO_H_

#include "item.h"
#include <string>
#include "character.h"

// forward declarations
class NPC;


class Hero : public Character {
private:
    Item gear[2];

public:
    Hero(const std::string& name, int health, int gold, int armor, int magicResistance);

    virtual ~Hero();

    virtual void attack(Character& enemy) override;

    Item sellItem(int index);

    bool fight(NPC& enemy);

    const Item* getGear(int i) const {
        if (i >= 0 && i < 2) {
            return &gear[i];
        } else {
            return nullptr;
        }
    }

    int addGear(const Item& item);
    Item removeGear(int slot);
};



#endif /* HERO_H_ */