#ifndef PROJECTVIDEOGAME_PROJECTILE_H
#define PROJECTVIDEOGAME_PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Character.h"

class Projectile {
public:

    Projectile();

    void update();

    float getMovementSpeed() const {
        return movementSpeed;
    }

    void setMovementSpeed(float movementSpeed) {
        Projectile::movementSpeed = movementSpeed;
    }

    int getDamage() const {
        return damage;
    }

    void setDamage(int damage) {
        Projectile::damage = damage;
    }

    int getLifeTime() const {
        return lifeTime;
    }

    void setLifeTime(int lifeTime) {
        Projectile::lifeTime = lifeTime;
    }

    int getCounterLifetime() const {
        return counterLifetime;
    }

    void setCounterLifetime(int counterLifetime) {
        Projectile::counterLifetime = counterLifetime;
    }

    int getCounterAnimation() const {
        return counterAnimation;
    }

    void setCounterAnimation(int counterAnimation) {
        Projectile::counterAnimation = counterAnimation;
    }

    bool isDestroy() const {
        return destroy;
    }

    void setDestroy(bool destroy) {
        Projectile::destroy = destroy;
    }


    bool isHostile() const {
        return hostile;
    }

    void setHostile(bool hostile) {
        Projectile::hostile = hostile;
    }


    Character::Direction getDirection() const {
        return direction;
    }

    void setDirection(Character::Direction direction) {
        Projectile::direction = direction;
    }

    sf::RectangleShape rect;
    sf::Sprite sprite;

private:
    float movementSpeed = 4.3;
    int damage = 1;
    int lifeTime = 90;
    Character::Direction direction;
    int counterLifetime = 0;
    int counterAnimation = 0;
    bool destroy = false;
    bool hostile = false;
};

#endif //PROJECTVIDEOGAME_PROJECTILE_H
