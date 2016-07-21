#include "Hero.h"
#include "TileMap.h"

void Hero::update() {
    sprite.setPosition(rect.getPosition());
}

void Hero::moveSprite(const int* level) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (collides(level) || outOfbounds()) {
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
            direction = Up;
        } else {
            rect.move(0, -speed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
            direction = Up;
        }
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        int newY = static_cast<int>(rect.getPosition().y + speed + 48);
        int tile = level[static_cast<int>((rect.getPosition().x + 24)/48) + static_cast<int>(newY/48) * 19];
        if (tile != 6 && tile != 9 && tile != 10 && tile !=11 && tile != 12 && tile !=13 && tile != 14 ) {
            rect.move(0, speed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
            direction = Down;
        }
        else
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        int newX = static_cast<int>(rect.getPosition().x - speed + 24);
        int tile = level[static_cast<int>(newX/48) + static_cast<int>((rect.getPosition().y + 46)/48) * 19];
        if(tile != 6 && tile != 9 && tile != 10 && tile !=11 && tile != 12 && tile !=13 && tile != 14 ) {
            rect.move(-speed, 0);
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
            direction = Left;
        }
        else
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        int newX = static_cast<int>(rect.getPosition().x + speed + 24);
        int tile = level[static_cast<int>(newX/48) + static_cast<int>((rect.getPosition().y + 46)/48) * 19];
        if(tile != 6 && tile != 9 && tile != 10 && tile !=11 && tile != 12 && tile !=13 && tile != 14 ) {
            rect.move(speed, 0);
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
            direction = Right;
        }
        else
            sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
    }

    counterWalking++;

    if (counterWalking == 2){
        counterWalking = 0;
    }
}

bool Hero::outOfbounds() {
    if (static_cast<int>(rect.getPosition().y - speed) < 0)
        return true;
    return false;
}

bool Hero::collides(const int* level) {
    int newY = static_cast<int>(rect.getPosition().y - speed + 24);
    int tile = level[static_cast<int>((rect.getPosition().x + 24) / 48) + static_cast<int>(newY/ 48) * 19];
    switch (tile) {
        case 6:
            return true;
        case 9:
            return true;
        case 10:
            return true;
        case 11:
            return true;
        case 12:
            return true;
        case 13:
            return true;
        case 14:
            return true;
        default:
            return false;
    }
}