#ifndef PROJECTVIDEOGAME_STATUSBAR_H
#define PROJECTVIDEOGAME_STATUSBAR_H


#include "Observer.h"
#include "Hero.h"

class HealthBar : public Observer {
public:
    HealthBar(Hero* hero);

    virtual ~HealthBar();

    virtual void update(int hp, int exp, int money, sf::Sprite& heartsSprite) override;
    virtual void attach() override;
    virtual void detach() override;

private:
    int lastHealth = 8;
    Hero* subject;
};

class ExperienceBar : public Observer {
public:
    ExperienceBar(Hero* hero);

    virtual ~ExperienceBar();

    virtual void update(int hp, int exp, int money, sf::Sprite& Sprite) override;
    virtual void attach() override;
    virtual void detach() override;

private:
    int lastExp = 0;
    Hero* subject;
};


#endif //PROJECTVIDEOGAME_STATUSBAR_H
