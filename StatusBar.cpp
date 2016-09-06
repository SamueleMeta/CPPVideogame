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

void HealthBar::update() {
    sf::Sprite tmpSprite = subject->getHeartsSprite();
    if (subject->getHealth() >= 8) {
        tmpSprite.setTextureRect(sf::IntRect(0, 0, 150, 36));
        subject->setHeartsSprite(tmpSprite);
    } else {
        tmpSprite.setTextureRect(sf::IntRect(0, (8 - subject->getHealth()) * 36, 150, 36));
        subject->setHeartsSprite(tmpSprite);
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

void ExperienceBar::update() {
    sf::Sprite tmpSprite = subject->getExpSprite();
    tmpSprite.setTextureRect(sf::IntRect(0, subject->getExp() * 59, 150, 59));
    subject->setExpSprite(tmpSprite);
}

MoneyBar::MoneyBar(Hero *hero) : subject(hero) {
    MoneyBar::attach();
}

MoneyBar::~MoneyBar() {
    MoneyBar::detach();
}

void MoneyBar::attach() {
    subject->subscribe(this);
}

void MoneyBar::detach() {
    subject->unsubscribe(this);
}

void MoneyBar::update() {
    subject->text.setString(std::to_string(subject->getMoney()));
}

WeaponBar::WeaponBar(Hero *hero) : subject(hero) {
    WeaponBar::attach();
}

WeaponBar::~WeaponBar() {
    WeaponBar::detach();
}

void WeaponBar::attach() {
    subject->subscribe(this);
}

void WeaponBar::detach() {
    subject->unsubscribe(this);
}

void WeaponBar::update() {
    sf::Sprite tmpSprite = subject->getWeaponSprite();
    if (subject->isChangeToSword() && subject->isChangeToStick() && subject->isChangeToAxe())
        tmpSprite.setTextureRect(sf::IntRect(0, 0, 150, 76));
    if (subject->isChangeToSword() && subject->isChangeToStick() && !subject->isChangeToAxe())
        tmpSprite.setTextureRect(sf::IntRect(0, 380, 150, 76));
    if (subject->isChangeToSword() && !subject->isChangeToStick() && subject->isChangeToAxe())
        tmpSprite.setTextureRect(sf::IntRect(0, 456, 150, 76));
    if (!subject->isChangeToSword() && subject->isChangeToStick() && subject->isChangeToAxe())
        tmpSprite.setTextureRect(sf::IntRect(0, 532, 150, 76));
    subject->setWeaponSprite(tmpSprite);
}

PotionBar::PotionBar(Hero *hero) : subject(hero) {
    PotionBar::attach();
}

PotionBar::~PotionBar() {
    PotionBar::detach();
}

void PotionBar::attach() {
    subject->subscribe(this);
}

void PotionBar::detach() {
    subject->unsubscribe(this);
}

void PotionBar::update() {
    sf::Sprite tmpSprite = subject->getPotionsSprite();
    if (subject->getPotion()->getUseTime() <= 0) {
        tmpSprite.setTextureRect(sf::IntRect(0, 490, 150, 70));
    }
    subject->setPotionsSprite(tmpSprite);
}

