#include "Hero.h"
#include "TileMap.h"

void Hero::update() {
    sprite.setPosition(rect.getPosition());
}

void Hero::moveSprite(const int* level) {
    int adder = 0;
    if(hasSword == true) {
        adder = 192;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (collidesUp(level) || outOfbounds(Direction::Up)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            }
        }
        else {
            rect.move(0, -speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 0, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 3, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 6, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 9, 64, 64));
            }
        }
        direction = Direction::Up;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (collidesDown(level) || outOfbounds(Direction::Down)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            }
        }
        else {
            rect.move(0, speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 9, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 3, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 6, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 0, 64, 64));
            }
        }
        direction = Direction::Down;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if(collidesLeft(level) || outOfbounds(Direction::Left)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            }
        }
        else {
            rect.move(-speed, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 9, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 0, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 6, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 3, 64, 64));
            }
        }
        direction = Direction::Left;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(collidesRight(level) || outOfbounds(Direction::Right)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            }
        }
        else {
            rect.move(speed, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 9, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 0, 64, 64));
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 3, 64, 64));
            }
            else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking*64, 64 * 6, 64, 64));
            }
        }
        direction = Direction::Right;
    }

    counterWalking++;

    if (counterWalking == maxCounter){
        counterWalking = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
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
        case 1220:
            return true;
        case 1221:
            return true;
        case 1222:
            return true;
        case 1223:
            return true;
        case 1331:
            return true;
        default:
            return false;
    }
}

void Hero::useWeapon(sf::RenderWindow& window) {
    if (direction == Direction::Up) {
        sprite.setTextureRect(sf::IntRect(192, 576 + 64 * counterSword, 64, 64));
    }

    if (direction == Direction::Down) {
        sprite.setTextureRect(sf::IntRect(192, 64, 64, 64));
    }

    if (direction == Direction::Left) {
        sprite.setTextureRect(sf::IntRect(192, 256, 64, 64));
        sprite.setTextureRect(sf::IntRect(192, 320, 64, 64));
    }

    if (direction == Direction::Right) {
        sprite.setTextureRect(sf::IntRect(192, 448, 64, 64));
        sprite.setTextureRect(sf::IntRect(192, 512, 64, 64));
    }

    counterSword++;

    if (counterSword == maxCounter){
        counterSword = 0;
    }
}

void Hero::subscribe(Observer *o) {
    observers.push_back(o);
}

void Hero::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Hero::notify(sf::Sprite& Sprite) {
    for(auto itr = std::begin(observers); itr != std::end(observers); itr++)
        (*itr)->update(health, exp, money, Sprite);
}