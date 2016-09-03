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
    sf::Sprite tmpSprite = subject -> getHeartsSprite();
    tmpSprite.setTextureRect(sf::IntRect(0, ( 8 - subject -> getHealth()) * 36, 150, 36));
    subject -> setHeartsSprite(tmpSprite);
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
    sf::Sprite tmpSprite = subject -> getExpSprite();
    tmpSprite.setTextureRect(sf::IntRect(0, subject -> getExp() * 59, 150, 59));
    subject -> setExpSprite(tmpSprite);
}

MoneyBar::MoneyBar (Hero *hero) : subject(hero) {
    MoneyBar::attach();
}

MoneyBar::~MoneyBar () {
    MoneyBar::detach();
}

void MoneyBar::attach() {
    subject->subscribe(this);
}

void MoneyBar::detach() {
    subject->unsubscribe(this);
}

void MoneyBar::update() {
    subject -> text.setString(std::to_string( subject -> getMoney()));
}

