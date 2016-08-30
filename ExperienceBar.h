//
// Created by mypc on 29/08/16.
//

#ifndef PROJECTVIDEOGAME_EXPERIENCEBAR_H
#define PROJECTVIDEOGAME_EXPERIENCEBAR_H

#include "Observer.h"
#include "Hero.h"

class ExperienceBar : public Observer {
public:
    ExperienceBar(Hero* hero);

    virtual ~ExperienceBar();

    virtual void update(int hp, int exp, int money, sf::Sprite& Sprite) override;
    virtual void attach() override;
    virtual void detach() override;

private:
    Hero* subject;
};

#endif //PROJECTVIDEOGAME_EXPERIENCEBAR_H
