#include "Hero.h"

void Hero::update() {
    sprite.setPosition(rect.getPosition());
}

void Hero::moveSprite() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rect.move(0,-speed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rect.move(0,speed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 0, 48, 48));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rect.move(-speed,0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rect.move(speed,0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
    }

    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Left)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && energy > 0){
        speed = 0.75;
        rect.move(-speed,0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
        energy-= energyMax/300;

    }

    speed = 0.5;

    counterWalking++;

    if (counterWalking == 2)
    {
        counterWalking = 0;
    }
}