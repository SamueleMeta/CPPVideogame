#ifndef PROJECTVIDEOGAME_MOB_H
#define PROJECTVIDEOGAME_MOB_H

#include "Character.h"
#include "Hero.h"

class Mob : public Character {
public:
    enum EnemyType {Ogre, Orc, Willowisp, Succubus, Soldier, Skeleton, Undead, Samurai, Demon, Spirit, Abomination, Dragon};

    Mob(int lPoints, int strgth, int energy, Mob::EnemyType t, float drop, int lvl, bool boss) :
            Character(lPoints, strgth, energy), enemyType(t), dropRate(drop), level(lvl), isBoss(boss) {
        rect.setSize(sf::Vector2f(48, 48));
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 0, 48, 48));
    }

    ~Mob() {}

    /*void drop(Hero& hero);

    virtual void useWeapon(Character& tmpEnemy);

    virtual void useSpecial(Character& tmpEnemy);

    virtual void useScroll(Character& tmpEnemy);
     */

    void update();

    void moveSprite(const int* level);

    int generateRandom(int max);

    bool collidesUp(const int* level);

    bool collidesDown(const int* level);

    bool collidesLeft(const int* level);

    bool collidesRight(const int* level);

    bool checkCollision(int tile);

    bool outOfbounds(Direction direction);

    EnemyType getEnemyType() const {
        return enemyType;
    }

    void setEnemyType(EnemyType enemyType) {
        Mob::enemyType = enemyType;
    }

    float getDropRate() const {
        return dropRate;
    }

    void setDropRate(float dropRate) {
        Mob::dropRate = dropRate;
    }

    int getLevel() const {
        return level;
    }

    void setLevel(int level) {
        Mob::level = level;
    }

    bool isIsBoss() const {
        return isBoss;
    }

    void setIsBoss(bool isBoss) {
        Mob::isBoss = isBoss;
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

private:
    Mob::EnemyType enemyType;
    float dropRate;
    int level;
    bool isBoss;
    float movementSpeed = 1.7;
    int movementLength = 100;
    int counter = 0;
    bool alive = true;
    bool angry = true;
};

#endif //PROJECTVIDEOGAME_MOB_H
