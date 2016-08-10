#include "Projectile.h"
#include <SFML/Graphics.hpp>

Projectile::Projectile() {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0, 0);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Projectile::update()
{
    if (direction == Character::Direction::Up) {
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 3 * 32, 32, 32));
    }
    if (direction == Character::Direction::Down) {
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 0, 32, 32));
    }
    if (direction == Character::Direction::Left) {
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 1 * 32, 32, 32));
    }
    if (direction == Character::Direction::Right) {
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 2 * 32, 32, 32));
    }

    counterLifetime++;
    if (counterLifetime >= lifeTime)
    {
        destroy = true;
    }

    counterAnimation++;
    if (counterAnimation >= 2)
    {
        counterAnimation = 0;
    }

    // Sprite set at Rect
    sprite.setPosition(rect.getPosition());
}