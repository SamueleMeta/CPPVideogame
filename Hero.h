#ifndef PROJECTVIDEOGAME_HERO_H
#define PROJECTVIDEOGAME_HERO_H

#include <string>
#include <list>
#include "Subject.h"
#include "Character.h"

class Hero : public Character, public Subject {
public:

    Hero(int lifeP, int strngth, std::string name, int mon, int exp) :
            Character(lifeP, strngth), name(name), money(mon), exp(exp) {
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

    void update();

    void moveSprite(const int *level);

    bool collidesUp(const int *level) override;

    bool collidesDown(const int *level) override;

    bool collidesLeft(const int *level) override;

    bool collidesRight(const int *level) override;

    virtual void subscribe(Observer *o) override;

    virtual void unsubscribe(Observer *o) override;

    virtual void notify() override;

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
    int money, exp;
    int maxCounter = 2;
    int adder = 0;
    std::list<Observer *> observers;
    sf::Sprite heartsSprite;
    sf::Sprite expSprite;
    sf::Sprite weaponSprite;
    sf::Sprite potionsSprite;
    Weapon *weapon;
    Potion *potion;
    bool changeToSword = false;
    bool changeToAxe = false;
    bool changeToStick = false;
};

#endif //PROJECTVIDEOGAME_HERO_H
