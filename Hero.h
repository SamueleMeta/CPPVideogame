#ifndef PROJECTVIDEOGAME_HERO_H
#define PROJECTVIDEOGAME_HERO_H

#include <string>
#include "Character.h"

class Hero : public Character {
public:
    enum Direction {
        Down, Left, Right, Up
    };
    enum Race {
        Human, Elf, Dwarf
    };
    enum Class {
        Paladin, Bandit, Mage, Thief, Hunter, Sorcerer, Knight, Warrior
    };


    Hero(int lifeP, int strngth, int energy, std::string name, int mon, int lvl, int exp, Hero::Race r, Hero::Class c) :
            Character(lifeP, strngth, energy), name(name), money(mon), heroLevel(lvl), exp(exp), race(r), classType(c) {
        rect.setSize(sf::Vector2f(48, 48));
        rect.setPosition(0, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 0, 48, 48));
    }

    ~Hero() { }

    /*
    int levelUp();

    virtual void useWeapon(Character &tmpEnemy);

    virtual void useSpecial(Character &tmpEnemy);

    virtual void useScroll(Character &tmpEnemy);

    */

    void update();

    void moveSprite(const int* level);

    bool collidesUp(const int* level);

    bool collidesDown(const int* level);

    bool collidesLeft(const int* level);

    bool collidesRight(const int* level);

    bool checkCollision(int tile);

    bool outOfbounds(Hero::Direction direction);

    Class getClassType() const {
        return classType;
    }

    void setClassType(Class classType) {
        Hero::classType = classType;
    }

    int getMoney() const {
        return money;
    }

    void setMoney(int money) {
        Hero::money = money;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Hero::name = name;
    }

    int getHeroLevel() const {
        return heroLevel;
    }

    void setHeroLevel(int heroLevel) {
        Hero::heroLevel = heroLevel;
    }

    int getExp() const {
        return exp;
    }

    void setExp(int exp) {
        Hero::exp = exp;
    }

    Race getRace() const {
        return race;
    }

    void setRace(Race race) {
        Hero::race = race;
    }


    Direction getDirection() const {
        return direction;
    }

    void setDirection(Direction direction) {
        Hero::direction = direction;
    }

private:
    std::string name;
    int money, heroLevel, exp;
    Hero::Race race;
    Hero::Class classType;
    int counterWalking;
    Hero::Direction direction;


};

#endif //PROJECTVIDEOGAME_HERO_H
