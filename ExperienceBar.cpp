//
// Created by mypc on 29/08/16.
//

#include "ExperienceBar.h"

ExperienceBar::ExperienceBar(Hero *hero) : subject(hero) {
    attach();
}

ExperienceBar::~ExperienceBar() {
    detach();
}

void ExperienceBar::attach() {
    subject->subscribe(this);
}

void ExperienceBar::detach() {
    subject->unsubscribe(this);
}

void ExperienceBar::update(int hp, int exp, int money, sf::Sprite& expSprite) {
    expSprite.setTextureRect(sf::IntRect(0, exp*59, 150, 59));
}