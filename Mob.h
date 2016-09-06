#ifndef PROJECTVIDEOGAME_MOB_H
#define PROJECTVIDEOGAME_MOB_H

#include "Character.h"
#include "Hero.h"

class Mob : public Character {
public:

    Mob(int lPoints, int strgth, float drop) : Character(lPoints, strgth), dropRate(drop) {
        rect.setSize(sf::Vector2f(48, 48));
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 0, 48, 48));
    }

    ~Mob() { }

    void update();

    void moveSprite(const int *level);

    int generateRandom(int max);

    bool outOfbounds(Direction direction) override;


    float getDropRate() const {
        return dropRate;
    }

    void setDropRate(float dropRate) {
        Mob::dropRate = dropRate;
    }


    bool isAlive() const {
        return alive;
    }

    void setAlive(bool alive) {
        Mob::alive = alive;
    }

    bool isAngry() const {
        return angry;
    }

    void setAngry(bool angry) {
        Mob::angry = angry;
    }


    Direction getDirection() const {
        return direction;
    }

    void setDirection(Direction direction) {
        Mob::direction = direction;
    }


    bool isCollLeft() const {
        return collLeft;
    }

    void setCollLeft(bool collLeft) {
        Mob::collLeft = collLeft;
    }

    bool isCollDown() const {
        return collDown;
    }

    void setCollDown(bool collDown) {
        Mob::collDown = collDown;
    }

    bool isCollUp() const {
        return collUp;
    }

    void setCollUp(bool collUp) {
        Mob::collUp = collUp;
    }

    bool isCollRight() const {
        return collRight;
    }

    void setCollRight(bool collRight) {
        Mob::collRight = collRight;
    }

private:
    float dropRate;
    float movementSpeed = 1.7;
    int movementLength = 100;
    int counter = 0;
    bool alive = true;
    bool angry = false;
    bool collUp = false;
    bool collDown = false;
    bool collLeft = false;
    bool collRight = false;
};

#endif //PROJECTVIDEOGAME_MOB_H
