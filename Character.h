#ifndef PROJECTVIDEOGAME_CHARACTER_H
#define PROJECTVIDEOGAME_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Potion.h"
#include "Weapon.h"

class Character {
public:

    enum class Direction {
        Up, Down, Left, Right
    };

    Character(int lifePoints, int strgth) : health(lifePoints), strength(strgth) { };

    virtual ~Character() { }

    virtual bool collidesUp(const int *level);

    virtual bool collidesDown(const int *level);

    virtual bool collidesLeft(const int *level);

    virtual bool collidesRight(const int *level);

    virtual bool checkCollision(int tile);

    virtual bool outOfbounds(Direction direction);

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        Character::health = health;
    }

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Character::strength = strength;
    }

    float getSpeed() const {
        return speed;
    }

    void setSpeed(float speed) {
        Character::speed = speed;
    }

    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;

protected:
    int health = 8;
    int strength;
    float speed = 2;
    int counterWalking = 0;
    Direction direction = Direction::Down;
};

#endif //PROJECTVIDEOGAME_CHARACTER_H