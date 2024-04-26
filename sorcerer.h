
#ifndef SORCERER_H_
#define SORCERER_H_

#include "npc.h"

class Sorcerer: public NPC {
private:
    int magicPower;

public:
    Sorcerer(const std::string& name, int health, int gold, int armor, int magicResistance, int magicPower);
    virtual ~Sorcerer();

    virtual void attack(Character& enemy) override;

    int getMagicPower() const {
        return magicPower;
    }
    void setMagicPower(int magicPower) {
        if (magicPower >= 0) {
            this->magicPower = magicPower;
        }
        else {
            throw InvalidArgumentException("Magie darf nicht negativ sein!");
        }
    }
};

#endif /* SORCERER_H_ */