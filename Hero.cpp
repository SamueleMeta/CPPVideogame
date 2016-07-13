#include "Hero.h"

void Hero::update() {
    sprite.setPosition(rect.getPosition());
}

void Hero::moveSprite() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        rect.move(0,-speed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Up, 48, 48));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        rect.move(0,speed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Down, 48, 48));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        rect.move(-speed,0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Left, 48, 48));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        rect.move(speed,0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Right, 48, 48));
    }

    counterWalking++;

    if (counterWalking == 2){
        counterWalking = 0;
    }
}