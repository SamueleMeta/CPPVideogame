#ifndef PROJECTVIDEOGAME_CHARACTER_H
#define PROJECTVIDEOGAME_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Potion.h"
#include "Weapon.h"
#include "Scroll.h"

class Character {
public:

    enum class Direction { Up, Down, Left, Right };

    Character(int lifePoints, int strgth, int energy) : health(lifePoints), strength(strgth), energy(energy){};

    virtual ~Character() {}

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

    int getEnergy() const {
        return energy;
    }

    void setEnergy(int energy) {
        Character::energy = energy;
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
    int strength, energy;
    //int energyMax = 100;
    float speed = 0.2;
    int counterWalking = 0;
    Direction direction = Direction::Down;
    int counterSword = 0;
};

#endif //PROJECTVIDEOGAME_CHARACTER_H