#include "NPC.h"

void NPC::update() {
    sprite.setPosition(rect.getPosition());
}

void NPC::moveSprite(const int *level) {
    switch (direction) {
        case Direction::Up:
            if (collidesUp(level) || outOfbounds(Direction::Up) || collUp) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collUp = false;
                break;
            } else {
                rect.move(0, -speed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 3, 48, 48));
                break;
            }
        case Direction::Down:
            if (collidesDown(level) || outOfbounds(Direction::Down) || collDown) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collDown = false;
                break;
            } else {
                rect.move(0, speed);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 0, 48, 48));
                break;
            }
        case Direction::Left:
            if (collidesLeft(level) || outOfbounds(Direction::Left) || collLeft) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collLeft = false;
                break;
            } else {
                rect.move(-speed, 0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 1, 48, 48));
                break;
            }
        case Direction::Right:
            if (collidesRight(level) || outOfbounds(Direction::Right) || collRight) {
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
                direction = static_cast<Direction>(generateRandom(4));
                collRight = false;
                break;
            } else {
                rect.move(speed, 0);
                sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * 2, 48, 48));
                break;
            }
    }

    counterWalking++;

    if (counterWalking == 2) {
        counterWalking = 0;
    }

    counter++;
    if (counter >= movementLength) {
        direction = static_cast<Direction>(generateRandom(6));
        counter = 0;
    }
}

int NPC::generateRandom(int max) {
    int randomNumber = rand();
    int random = (randomNumber % (max + 1));
    return random;
}



