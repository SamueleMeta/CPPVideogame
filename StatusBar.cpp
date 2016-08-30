#include "StatusBar.h"

HealthBar::HealthBar(Hero *hero) : subject(hero) {
    HealthBar::attach();
}

HealthBar::~HealthBar() {
    HealthBar::detach();
}

void HealthBar::attach() {
    subject->subscribe(this);
}

void HealthBar::detach() {
    subject->unsubscribe(this);
}

void HealthBar::update(int hp, int exp, int money, sf::Sprite& heartsSprite) {
    if(8-hp < 8 && hp != lastHealth) {
        heartsSprite.setTextureRect(sf::IntRect(0, (8 - hp) * 36, 150, 36));
        lastHealth--;
    }
}

ExperienceBar::ExperienceBar(Hero *hero) : subject(hero) {
    ExperienceBar::attach();
}

ExperienceBar::~ExperienceBar() {
    ExperienceBar::detach();
}

void ExperienceBar::attach() {
    subject->subscribe(this);
}

void ExperienceBar::detach() {
    subject->unsubscribe(this);
}

void ExperienceBar::update(int hp, int exp, int money, sf::Sprite& expSprite) {
    if(exp != lastExp) {
        expSprite.setTextureRect(sf::IntRect(0, exp * 59, 150, 59));
        lastExp++;
    }
}