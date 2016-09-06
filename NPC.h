#ifndef PROJECTVIDEOGAME_NPC_H
#define PROJECTVIDEOGAME_NPC_H

#include <string>
#include "Character.h"

class NPC : public Character {
public:

    NPC(int lPoints, int strgth) : Character(lPoints, strgth) {
        rect.setSize(sf::Vector2f(48, 48));
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 0, 48, 48));
    }

    ~NPC() { }

    void update();

    void moveSprite(const int *level);

    int generateRandom(int max);

    Direction getDirection() const {
        return direction;
    }

    void setDirection(Direction direction) {
        NPC::direction = direction;
    }

    bool isCollRight() const {
        return collRight;
    }

    void setCollRight(bool collRight) {
        NPC::collRight = collRight;
    }

    bool isCollLeft() const {
        return collLeft;
    }

    void setCollLeft(bool collLeft) {
        NPC::collLeft = collLeft;
    }

    bool isCollDown() const {
        return collDown;
    }

    void setCollDown(bool collDown) {
        NPC::collDown = collDown;
    }

    bool isCollUp() const {
        return collUp;
    }

    void setCollUp(bool collUp) {
        NPC::collUp = collUp;
    }

private:
    int counter;
    int movementLength = 150;
    bool collUp = false;
    bool collDown = false;
    bool collLeft = false;
    bool collRight = false;
};

#endif //PROJECTVIDEOGAME_NPC_H
