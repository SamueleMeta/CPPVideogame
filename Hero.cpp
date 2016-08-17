#include "Hero.h"
#include "TileMap.h"

void Hero::update() {
    sprite.setPosition(rect.getPosition());
}

void Hero::moveSprite(const int* level) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (collidesUp(level) || outOfbounds(Direction::Up)) {
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(48, 48*0, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.setTextureRect(sf::IntRect(48, 48*1, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.setTextureRect(sf::IntRect(48, 48*2, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
            }
        }
        else {
            rect.move(0, -speed);
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*0, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*1, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*2, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (collidesDown(level) || outOfbounds(Direction::Down)) {
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(48, 48*3, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.setTextureRect(sf::IntRect(48, 48*1, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.setTextureRect(sf::IntRect(48, 48*2, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
            }
        }
        else {
            rect.move(0, speed);
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*3, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*1, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*2, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if(collidesLeft(level) || outOfbounds(Direction::Left)) {
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(counterWalking, 48*3, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(counterWalking, 48*0, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.setTextureRect(sf::IntRect(counterWalking, 48*2, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
            }
        }
        else {
            rect.move(-speed, 0);
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*3, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*0, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*2, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(collidesRight(level) || outOfbounds(Direction::Right)) {
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(counterWalking, 48*3, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(counterWalking, 48*0, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.setTextureRect(sf::IntRect(counterWalking, 48*1, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
            }
        }
        else {
            rect.move(speed, 0);
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*3, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*0, 48, 48));
            }
            else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48*1, 48, 48));
            }
            else {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
            }
        }
    }

    counterWalking++;

    if (counterWalking == 2){
        counterWalking = 0;
    }
}

bool Hero::outOfbounds(Direction direction) {
    switch (direction) {
        case Direction::Up:
            if (static_cast<int>(rect.getPosition().y - speed) < 0)
                return true;
            return false;
        case Direction::Down:
            if (static_cast<int>(rect.getPosition().y + rect.getSize().y + speed) > 624)
                return true;
            return false;
        case Direction::Left:
            if (static_cast<int>(rect.getPosition().x - speed) < 0)
                return true;
            return false;
        case Direction::Right:
            if (static_cast<int>(rect.getPosition().x + rect.getSize().x + speed) > 912)
                return true;
            return false;
    }
}

bool Hero::collidesUp(const int* level) {
    int newY = static_cast<int>(rect.getPosition().y - speed + 24);
    int tile = level[static_cast<int>((rect.getPosition().x + 24) / 48) + static_cast<int>(newY/ 48) * 19];
    checkCollision(tile);
}

bool Hero::collidesDown(const int* level) {
    int newY = static_cast<int>(rect.getPosition().y + speed + 48);
    int tile = level[static_cast<int>((rect.getPosition().x + 24)/48) + static_cast<int>(newY/48) * 19];
    checkCollision(tile);
}

bool Hero::collidesLeft(const int* level) {
    int newX = static_cast<int>(rect.getPosition().x - speed + 24);
    int tile = level[static_cast<int>(newX/48) + static_cast<int>((rect.getPosition().y + 46)/48) * 19];
    checkCollision(tile);
}

bool Hero::collidesRight(const int* level) {
    int newX = static_cast<int>(rect.getPosition().x + speed + 24);
    int tile = level[static_cast<int>(newX/48) + static_cast<int>((rect.getPosition().y + 46)/48) * 19];
    checkCollision(tile);
}

bool Hero::checkCollision(int tile) {
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