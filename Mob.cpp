#include "Mob.h"

void Mob::update() {
    sprite.setPosition(rect.getPosition());
}

void Mob::moveSprite(const int* level) {
    switch(direction) {
        case Direction::Up:
            if(collidesUp(level) || outOfbounds(Direction::Up) || collUp) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collUp = false;
                break;
            } else {
                rect.move(0,-movementSpeed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
                break;
            }
        case Direction::Down:
            if(collidesDown(level) || outOfbounds(Direction::Down) || collDown) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collDown = false;
                break;
            } else {
                rect.move(0,movementSpeed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
                break;
            }
        case Direction::Left:
            if(collidesLeft(level) || outOfbounds(Direction::Left) || collLeft) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collLeft = false;
                break;
            } else {
                rect.move(-movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
                break;
            }
        case Direction::Right:
            if(collidesRight(level) || outOfbounds(Direction::Right) || collRight) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collRight = false;
                break;
            } else {
                rect.move(movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
                break;
            }
    }

    counterWalking++;

    if (counterWalking == 2){
        counterWalking = 0;
    }

    if(!isAngry()) {
        counter++;
        if (counter >= movementLength){
            direction = static_cast<Direction>(generateRandom(6));
            counter = 0;
        }
    }
}

int Mob::generateRandom(int max) {
    int randomNumber = rand();
    int random = (randomNumber % (max+1));
    return random;
}

bool Mob::outOfbounds(Direction direction) {
    switch (direction) {
        case Direction::Up:
            if (static_cast<int>(rect.getPosition().y - movementSpeed) < 0)
                return true;
            return false;
        case Direction::Down:
            if (static_cast<int>(rect.getPosition().y + rect.getSize().y + movementSpeed) > 624)
                return true;
            return false;
        case Direction::Left:
            if (static_cast<int>(rect.getPosition().x - movementSpeed) < 153)
                return true;
            return false;
        case Direction::Right:
            if (static_cast<int>(rect.getPosition().x + rect.getSize().x + movementSpeed) > 912)
                return true;
            return false;
    }
}

bool Mob::collidesUp(const int* level) {
    int newY = static_cast<int>(rect.getPosition().y - movementSpeed + 24);
    int tile = level[static_cast<int>((rect.getPosition().x + 24) / 48) + static_cast<int>(newY/ 48) * 19];
    checkCollision(tile);
}

bool Mob::collidesDown(const int* level) {
    int newY = static_cast<int>(rect.getPosition().y + movementSpeed + 48);
    int tile = level[static_cast<int>((rect.getPosition().x + 24)/48) + static_cast<int>(newY/48) * 19];
    checkCollision(tile);
}

bool Mob::collidesLeft(const int* level) {
    int newX = static_cast<int>(rect.getPosition().x - movementSpeed + 24);
    int tile = level[static_cast<int>(newX/48) + static_cast<int>((rect.getPosition().y + 46)/48) * 19];
    checkCollision(tile);
}

bool Mob::collidesRight(const int* level) {
    int newX = static_cast<int>(rect.getPosition().x + movementSpeed + 24);
    int tile = level[static_cast<int>(newX/48) + static_cast<int>((rect.getPosition().y + 46)/48) * 19];
    checkCollision(tile);
}

bool Mob::checkCollision(int tile) {
    switch (tile) {
        case 496:
            return true;
        case 460:
            return true;
        case 497:
            return true;
        case 609:
            return true;
        case 1080:
            return true;
        case 1081:
            return true;
        case 571:
            return true;
        case 839:
            return true;
        case 563:
            return true;
        case 603:
            return true;
        case 1110:
            return true;
        case 1109:
            return true;
        case 474:
            return true;
        case 514:
            return true;
        case 744:
            return true;
        case 745:
            return true;
        case 746:
            return true;
        case 747:
            return true;
        case 748:
            return true;
        case 749:
            return true;
        default:
            return false;
    }
}