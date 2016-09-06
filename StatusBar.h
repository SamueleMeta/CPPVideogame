#ifndef PROJECTVIDEOGAME_STATUSBAR_H
#define PROJECTVIDEOGAME_STATUSBAR_H


#include "Observer.h"
#include "Hero.h"

class HealthBar : public Observer {
public:
    HealthBar(Hero* hero);

    virtual ~HealthBar();

    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

private:
    Hero* subject;
};


class ExperienceBar : public Observer {
public:
    ExperienceBar(Hero* hero);

    virtual ~ExperienceBar();

    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

private:
    Hero* subject;
};

class MoneyBar : public Observer {
public:
    MoneyBar(Hero* hero);

    virtual ~MoneyBar();

    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

private:
    Hero* subject;
};

class WeaponBar : public Observer {
public:
    WeaponBar(Hero* hero);

    virtual ~WeaponBar();

    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

private:
    Hero* subject;
};

class PotionBar : public Observer {
public:
    PotionBar(Hero* hero);

    virtual ~PotionBar();

    virtual void update() override;
    virtual void attach() override;
    virtual void detach() override;

private:
    Hero* subject;
};

class Item {
public:
    Item(){};
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape rect;

    bool isTooken() const {
        return tooken;
    }

    void setTooken(bool tooken) {
        Item::tooken = tooken;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Item::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Item::y = y;
    }

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        Item::value = value;
    }

    const std::string &getType() const {
        return type;
    }

    void setType(const std::string &type) {
        Item::type = type;
    }

private:
    int x, y;
    int value;
    bool tooken = false;
    std::string type;
};
#endif //PROJECTVIDEOGAME_STATUSBAR_H
