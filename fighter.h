

#ifndef FIGHTER_H_
#define FIGHTER_H_

#include "npc.h"

class Fighter: public NPC {
private:
    int strength;

public:
    Fighter(const std::string& name, int health, int gold, int armor, int magicResistance, int strength);
    virtual ~Fighter();

    virtual void attack(Character& enemy) override;

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        if (strength >= 0) {
            this->strength = strength;
        }
        else {
            throw InvalidArgumentException("Staerke darf nicht negativ sein!");
        }
    }

};

#endif /* FIGHTER_H_ */