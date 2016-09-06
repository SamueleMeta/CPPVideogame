#ifndef PROJECTVIDEOGAME_HERO_H
#define PROJECTVIDEOGAME_HERO_H

#include <string>
#include <list>
#include "Subject.h"
#include "Character.h"

class Hero : public Character, public Subject {
public:

    Hero(int lifeP, int strngth, int energy, std::string name, int mon, int lvl, int exp) :
            Character(lifeP, strngth, energy), name(name), money(mon), heroLevel(lvl), exp(exp) {
        rect.setSize(sf::Vector2f(64, 64));
        rect.setPosition(437, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 64, 0, 64, 64));
    }

    ~Hero() {
        delete weapon;
        delete potion;
    }

    void useWeapon();
    void hit();

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

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;


    bool outOfbounds(Direction direction);

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

    Direction getDirection() const {
        return direction;
    }

    void setDirection(Direction direction) {
        Hero::direction = direction;
    }


    bool isHasSword() const {
        return hasSword;
    }

    void setHasSword(bool hasSword) {
        Hero::hasSword = hasSword;
    }

    int getAdder() const {
        return adder;
    }

    void setAdder(int adder) {
        Hero::adder = adder;
    }


    const sf::Sprite &getHeartsSprite() const {
        return heartsSprite;
    }

    void setHeartsSprite(const sf::Sprite &heartsSprite) {
        Hero::heartsSprite = heartsSprite;
    }

    const sf::Sprite &getExpSprite() const {
        return expSprite;
    }

    void setExpSprite(const sf::Sprite &expSprite) {
        Hero::expSprite = expSprite;
    }

    Weapon *getWeapon() const {
        return weapon;
    }

    void setWeapon(Weapon *weapon) {
        Hero::weapon = weapon;
    }


    Potion *getPotion() const {
        return potion;
    }

    void setPotion(Potion *potion) {
        Hero::potion = potion;
    }

    bool isChangeToStick() const {
        return changeToStick;
    }

    void setChangeToStick(bool changeToStick) {
        Hero::changeToStick = changeToStick;
    }

    bool isChangeToAxe() const {
        return changeToAxe;
    }

    void setChangeToAxe(bool changeToAxe) {
        Hero::changeToAxe = changeToAxe;
    }

    bool isChangeToSword() const {
        return changeToSword;
    }

    void setChangeToSword(bool changeToSword) {
        Hero::changeToSword = changeToSword;
    }

    const sf::Sprite &getWeaponSprite() const {
        return weaponSprite;
    }

    void setWeaponSprite(const sf::Sprite &weaponSprite) {
        Hero::weaponSprite = weaponSprite;
    }

    const sf::Sprite &getPotionsSprite() const {
        return potionsSprite;
    }

    void setPotionsSprite(const sf::Sprite &potionsSprite) {
        Hero::potionsSprite = potionsSprite;
    }

private:
    std::string name;
    int money, heroLevel, exp;
    bool hasSword = false;
    int maxCounter = 2;
    int adder = 0;
    std::list <Observer*> observers;
    sf::Sprite heartsSprite;
    sf::Sprite expSprite;
    sf::Sprite weaponSprite;
    sf::Sprite potionsSprite;
    Weapon* weapon;
    Potion* potion;
    bool changeToSword = false;
    bool changeToAxe = false;
    bool changeToStick = false;
};

#endif //PROJECTVIDEOGAME_HERO_H
