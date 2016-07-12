#ifndef PROJECTVIDEOGAME_NPC_H
#define PROJECTVIDEOGAME_NPC_H

#include <string>
#include "Character.h"

class NPC : public Character {
public:
    enum NPCType {Channeler, Healer, Wanderer, Blacksmith, Merchant, Animal};

    NPC(int lPoints, int strgth, int energy, NPC::NPCType t, std::string name, int mon, bool host) :
            Character(lPoints, strgth, energy), npcType(t), name(name), money(mon), hostile(host) {}

    ~NPC() {}

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        NPC::name = name;
    }

    int getMoney() const {
        return money;
    }

    void setMoney(int money) {
        NPC::money = money;
    }

    bool isHostile() const {
        return hostile;
    }

    void setHostile(bool hostile) {
        NPC::hostile = hostile;
    }

    NPCType getNpcType() const {
        return npcType;
    }

    void setNpcType(NPCType npcType) {
        NPC::npcType = npcType;
    }

private:
    NPC::NPCType npcType;
    std::string name;
    int money;
    bool hostile;
};

#endif //PROJECTVIDEOGAME_NPC_H
