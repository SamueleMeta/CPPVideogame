#ifndef PROJECTVIDEOGAME_PROJECTILE_H
#define PROJECTVIDEOGAME_PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile {
public:
    enum Direction {Down, Left, Right, Up};

    Projectile();
    void update();

    Direction getUp() const {
        return Up;
    }

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

    int getDirection() const {
        return direction;
    }

    void setDirection(int direction) {
        Projectile::direction = direction;
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


    sf::RectangleShape rect;
    sf::Sprite sprite;

private:
    float movementSpeed = 0.7;
    int damage = 1;
    int lifeTime = 100;
    int direction = Up;
    int counterLifetime = 0;
    int counterAnimation = 0;
    bool destroy = false;
};

#endif //PROJECTVIDEOGAME_PROJECTILE_H
