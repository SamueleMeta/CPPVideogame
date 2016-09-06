#include "Character.h"

bool Character::collidesUp(const int *level) {
    int newY = static_cast<int>(rect.getPosition().y - speed + 24);
    int tile = level[static_cast<int>((rect.getPosition().x + 24) / 48) + static_cast<int>(newY / 48) * 19];
    checkCollision(tile);
}

bool Character::collidesDown(const int *level) {
    int newY = static_cast<int>(rect.getPosition().y + speed + 48);
    int tile = level[static_cast<int>((rect.getPosition().x + 24) / 48) + static_cast<int>(newY / 48) * 19];
    checkCollision(tile);
}

bool Character::collidesLeft(const int *level) {
    int newX = static_cast<int>(rect.getPosition().x - speed + 24);
    int tile = level[static_cast<int>(newX / 48) + static_cast<int>((rect.getPosition().y + 46) / 48) * 19];
    checkCollision(tile);
}

bool Character::collidesRight(const int *level) {
    int newX = static_cast<int>(rect.getPosition().x + speed + 24);
    int tile = level[static_cast<int>(newX / 48) + static_cast<int>((rect.getPosition().y + 46) / 48) * 19];
    checkCollision(tile);
}

bool Character::checkCollision(int tile) {
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

bool Character::outOfbounds(Direction direction) {
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
            if (static_cast<int>(rect.getPosition().x - speed) < 150)
                return true;
            return false;
        case Direction::Right:
            if (static_cast<int>(rect.getPosition().x + rect.getSize().x + speed) > 912)
                return true;
            return false;
    }
}