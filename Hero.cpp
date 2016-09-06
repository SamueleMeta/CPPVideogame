#include "Hero.h"
#include "TileMap.h"

void Hero::update() {
    sprite.setPosition(rect.getPosition());
}

void Hero::moveSprite(const int *level) {
    if (weapon->getType() == "sword") {
        adder = 192;
    } else if (weapon->getType() == "stick") {
        adder = 576;
    } else if (weapon->getType() == "axe") {
        adder = 384;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (collidesUp(level) || outOfbounds(Direction::Up)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            }
        } else {
            rect.move(0, -speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 0, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 3, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 6, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 9, 64, 64));
            }
        }
        direction = Direction::Up;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (collidesDown(level) || outOfbounds(Direction::Down)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            }
        } else {
            rect.move(0, speed);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 9, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 3, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 6, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 0, 64, 64));
            }
        }
        direction = Direction::Down;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (collidesLeft(level) || outOfbounds(Direction::Left)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            }
        } else {
            rect.move(-speed, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 9, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 0, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 6, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 3, 64, 64));
            }
        }
        direction = Direction::Left;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (collidesRight(level) || outOfbounds(Direction::Right)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
            }
        } else {
            rect.move(speed, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 9, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 0, 64, 64));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 3, 64, 64));
            } else {
                sprite.setTextureRect(sf::IntRect(adder + counterWalking * 64, 64 * 6, 64, 64));
            }
        }
        direction = Direction::Right;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 0, 64, 64));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 3, 64, 64));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 6, 64, 64));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sprite.setTextureRect(sf::IntRect(adder + 64, 64 * 9, 64, 64));
    }

    counterWalking++;

    if (counterWalking == maxCounter) {
        counterWalking = 0;
    }
}

bool Hero::collidesUp(const int *level) {
    int newY = static_cast<int>(rect.getPosition().y - speed + 32);
    int tile = level[static_cast<int>((rect.getPosition().x + 48) / 48) + static_cast<int>(newY / 48) * 19];
    checkCollision(tile);
}

bool Hero::collidesDown(const int *level) {
    int newY = static_cast<int>(rect.getPosition().y + speed + 48);
    int tile = level[static_cast<int>((rect.getPosition().x + 32) / 48) + static_cast<int>(newY / 48) * 19];
    checkCollision(tile);
}

bool Hero::collidesLeft(const int *level) {
    int newX = static_cast<int>(rect.getPosition().x - speed + 32);
    int tile = level[static_cast<int>(newX / 48) + static_cast<int>((rect.getPosition().y + 46) / 48) * 19];
    checkCollision(tile);
}

bool Hero::collidesRight(const int *level) {
    int newX = static_cast<int>(rect.getPosition().x + speed + 32);
    int tile = level[static_cast<int>(newX / 48) + static_cast<int>((rect.getPosition().y + 46) / 48) * 19];
    checkCollision(tile);
}

void Hero::useWeapon() {
    if (weapon->getType() == "sword") {
        adder = 192;
    } else if (weapon->getType() == "stick") {
        adder = 576;
    } else if (weapon->getType() == "axe") {
        adder = 384;
    }

    if (direction == Direction::Up) {
        sprite.setTextureRect(sf::IntRect(adder, 640, 64, 64));
    }

    if (direction == Direction::Down) {
        sprite.setTextureRect(sf::IntRect(adder, 64, 64, 64));
    }

    if (direction == Direction::Left) {
        sprite.setTextureRect(sf::IntRect(adder, 256, 64, 64));
    }

    if (direction == Direction::Right) {
        sprite.setTextureRect(sf::IntRect(adder, 448, 64, 64));
    }
}

void Hero::hit() {
    if (weapon->getType() == "sword") {
        adder = 192;
    } else if (weapon->getType() == "stick") {
        adder = 576;
    } else if (weapon->getType() == "axe") {
        adder = 384;
    }

    if (direction == Direction::Up) {
        sprite.setTextureRect(sf::IntRect(adder, 576, 64, 64));
    }

    if (direction == Direction::Down) {
        sprite.setTextureRect(sf::IntRect(adder, 0, 64, 64));
    }

    if (direction == Direction::Left) {
        sprite.setTextureRect(sf::IntRect(adder, 192, 64, 64));
    }

    if (direction == Direction::Right) {
        sprite.setTextureRect(sf::IntRect(adder, 384, 64, 64));
    }
}

void Hero::subscribe(Observer *o) {
    observers.push_back(o);
}

void Hero::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Hero::notify() {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++)
        (*itr)->update();
}