#include "Mob.h"

void Mob::update() {
    sprite.setPosition(rect.getPosition());
}

void Mob::moveSprite(const int* level) {
    switch(direction) {
        case Direction::Up:
            if(collidesUp(level) || outOfbounds(Direction::Up)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                break;
            } else {
                rect.move(0,-movementSpeed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
                break;
            }
        case Direction::Down:
            if(collidesDown(level) || outOfbounds(Direction::Down)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                break;
            } else {
                rect.move(0,movementSpeed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
                break;
            }
        case Direction::Left:
            if(collidesLeft(level) || outOfbounds(Direction::Left)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                break;
            } else {
                rect.move(-movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
                break;
            }
        case Direction::Right:
            if(collidesRight(level) || outOfbounds(Direction::Right)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
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
        case 1102:
            return true;
        case 1103:
            return true;
        case 1171:
            return true;
        case 1172:
            return true;
        case 1180:
            return true;
        case 1181:
            return true;
        case 1182:
            return true;
        case 1183:
            return true;
        case 1212:
            return true;
        case 1220:
            return true;
        case 1221:
            return true;
        case 1222:
            return true;
        case 1223:
            return true;
        case 1224:
            return true;
        case 1225:
            return true;
        case 1331:
            return true;
        default:
            return false;
    }
}