#ifndef PROJECTVIDEOGAME_NPC_H
#define PROJECTVIDEOGAME_NPC_H

#include <string>
#include "Character.h"

class NPC : public Character {
public:
    enum NPCType {Channeler, Healer, Wanderer, Blacksmith, Merchant, Animal};

    NPC(int lPoints, int strgth, int energy, NPC::NPCType t, std::string name, int mon, bool host) :
            Character(lPoints, strgth, energy), npcType(t), name(name), money(mon), hostile(host) {
        rect.setSize(sf::Vector2f(48, 48));
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 0, 48, 48));
    }

    ~NPC() {}

    void update();

    void moveSprite(const int* level);

    int generateRandom(int max);

    bool collidesUp(const int* level);

    bool collidesDown(const int* level);

    bool collidesLeft(const int* level);

    bool collidesRight(const int* level);

    bool checkCollision(int tile);

    bool outOfbounds(Direction direction);

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

    Direction getDirection() const {
        return direction;
    }

    void setDirection(Direction direction) {
        NPC::direction = direction;
    }

private:
    NPC::NPCType npcType;
    std::string name;
    int money;
    bool hostile;
    int counter;
    int movementLength = 150;
};

#endif //PROJECTVIDEOGAME_NPC_H
