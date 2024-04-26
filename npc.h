
#ifndef NPC_H_
#define NPC_H_

#include "character.h"

class NPC: public Character {
public:
    NPC(const std::string& name, int health, int gold, int armor, int magicResistance);
    virtual ~NPC();

    Item* retrieveRandomLoot();
};

#endif /* NPC_H_ */