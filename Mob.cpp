#include "Mob.h"

void Mob::update() {
    sprite.setPosition(rect.getPosition());
}

void Mob::moveSprite(const int* level) {
    switch(direction) {
        case Up:
            if(collidesUp(level) || outOfbounds(Up)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Up, 48, 48));
                direction = static_cast<Mob::Direction>(generateRandom(4));
                break;
            } else {
                rect.move(0,-movementSpeed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Up, 48, 48));
                break;
            }
        case Down:
            if(collidesDown(level) || outOfbounds(Down)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Down, 48, 48));
                direction = static_cast<Mob::Direction>(generateRandom(4));
                break;
            } else {
                rect.move(0,movementSpeed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Down, 48, 48));
                break;
            }
        case Left:
            if(collidesLeft(level) || outOfbounds(Left)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Left, 48, 48));
                direction = static_cast<Mob::Direction>(generateRandom(4));
                break;
            } else {
                rect.move(-movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Left, 48, 48));
                break;
            }
        case Right:
            if(collidesRight(level) || outOfbounds(Right)) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Right, 48, 48));
                direction = static_cast<Mob::Direction>(generateRandom(4));
                break;
            } else {
                rect.move(movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Right, 48, 48));
                break;
            }
        default:
            break;
    }

    counterWalking++;

    if (counterWalking == 2){
        counterWalking = 0;
    }

    counter++;
    if (counter >= movementLength){
        direction = static_cast<Mob::Direction>(generateRandom(6));
        counter = 0;
    }
}

int Mob::generateRandom(int max) {
    int randomNumber = rand();
    int random = (randomNumber % (max+1));
    return random;
}

bool Mob::outOfbounds(Mob::Direction direction) {
    switch (direction) {
        case Up:
            if (static_cast<int>(rect.getPosition().y - movementSpeed) < 0)
                return true;
            return false;
        case Down:
            if (static_cast<int>(rect.getPosition().y + rect.getSize().y + movementSpeed) > 624)
                return true;
            return false;
        case Left:
            if (static_cast<int>(rect.getPosition().x - movementSpeed) < 0)
                return true;
            return false;
        case Right:
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