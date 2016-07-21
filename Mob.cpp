#include "Mob.h"

void Mob::update() {
    sprite.setPosition(rect.getPosition());
}

void Mob::moveSprite() {

    if (direction == Up){
        rect.move(0,-movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Up, 48, 48));
    }
    else if (direction == Down){
        rect.move(0,movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Down, 48, 48));
    }
    else if (direction == Left){
        rect.move(-movementSpeed,0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Left, 48, 48));
    }
    else if (direction == 4){
        rect.move(movementSpeed,0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 48, 48 * Right, 48, 48));
    }
    else{
        // No movement
    }

    counterWalking++;

    if (counterWalking == 2){
        counterWalking = 0;
    }

    counter++;
    if (counter >= movementLength){
        direction = generateRandom(6);
        counter = 0;
    }
}

int Mob::generateRandom(int max) {
    int randomNumber = rand();
    int random = (randomNumber % (max+1));
    return random;
}