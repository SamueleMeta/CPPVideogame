#include "Strategy.h"

void Strategy::EnemyAttack(std::vector<Mob> &enemies, sf::Time &elapsedAngry, sf::Clock &clockAngry,
                           Projectile &projectile, Hero &hero, sf::Sound &soundShot,
                           std::vector<Projectile> &projectileArray) {

    // Angry enemies
    int angryCounter = 0;
    for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
        if (enemies[angryCounter].isAngry()) {
            if (elapsedAngry.asSeconds() >= 0.5) {
                clockAngry.restart();
                int randomNumber = rand();
                int tempRand = (randomNumber % 2) + 1;
                if (tempRand == 1) { // Fires and chases
                    projectile.setDamage(enemies[angryCounter].getStrength());
                    // Player to Right
                    if ((hero.rect.getPosition().x < enemies[angryCounter].rect.getPosition().x) &&
                        (fabs(hero.rect.getPosition().y - enemies[angryCounter].rect.getPosition().y) <= 50)) {
                        soundShot.play();
                        projectile.setHostile(true);
                        projectile.setDirection(Character::Direction::Left);
                        projectile.rect.setPosition(enemies[angryCounter].rect.getPosition().x +
                                                    enemies[angryCounter].rect.getSize().x / 2 -
                                                    projectile.rect.getSize().x / 2,
                                                    enemies[angryCounter].rect.getPosition().y +
                                                    enemies[angryCounter].rect.getSize().y / 2 -
                                                    projectile.rect.getSize().y / 2);
                        projectileArray.push_back(projectile);
                        projectile.setHostile(false);

                        enemies[angryCounter].setDirection(Character::Direction::Left);
                    }

                    // Player to Left
                    if ((hero.rect.getPosition().x > enemies[angryCounter].rect.getPosition().x) &&
                        (fabs(hero.rect.getPosition().y - enemies[angryCounter].rect.getPosition().y) <= 50)) {
                        soundShot.play();
                        projectile.setHostile(true);
                        projectile.setDirection(Character::Direction::Right);
                        projectile.rect.setPosition(enemies[angryCounter].rect.getPosition().x +
                                                    enemies[angryCounter].rect.getSize().x / 2 -
                                                    projectile.rect.getSize().x / 2,
                                                    enemies[angryCounter].rect.getPosition().y +
                                                    enemies[angryCounter].rect.getSize().y / 2 -
                                                    projectile.rect.getSize().y / 2);
                        projectileArray.push_back(projectile);
                        projectile.setHostile(false);

                        enemies[angryCounter].setDirection(Character::Direction::Right);
                    }

                    // Player to Top
                    if ((hero.rect.getPosition().y < enemies[angryCounter].rect.getPosition().y) &&
                        (fabs(hero.rect.getPosition().x - enemies[angryCounter].rect.getPosition().x) <= 50)) {
                        soundShot.play();
                        projectile.setHostile(true);
                        projectile.setDirection(Character::Direction::Up);
                        projectile.rect.setPosition(enemies[angryCounter].rect.getPosition().x +
                                                    enemies[angryCounter].rect.getSize().x / 2 -
                                                    projectile.rect.getSize().x / 2,
                                                    enemies[angryCounter].rect.getPosition().y +
                                                    enemies[angryCounter].rect.getSize().y / 2 -
                                                    projectile.rect.getSize().y / 2);
                        projectileArray.push_back(projectile);
                        projectile.setHostile(false);

                        enemies[angryCounter].setDirection(Character::Direction::Up);
                    }

                    // Player to Bottom
                    if ((hero.rect.getPosition().y > enemies[angryCounter].rect.getPosition().y) &&
                        (fabs(hero.rect.getPosition().x - enemies[angryCounter].rect.getPosition().x) <= 50)) {
                        soundShot.play();
                        projectile.setHostile(true);
                        projectile.setDirection(Character::Direction::Down);
                        projectile.rect.setPosition(enemies[angryCounter].rect.getPosition().x +
                                                    enemies[angryCounter].rect.getSize().x / 2 -
                                                    projectile.rect.getSize().x / 2,
                                                    enemies[angryCounter].rect.getPosition().y +
                                                    enemies[angryCounter].rect.getSize().y / 2 -
                                                    projectile.rect.getSize().y / 2);
                        projectileArray.push_back(projectile);
                        projectile.setHostile(false);

                        enemies[angryCounter].setDirection(Character::Direction::Down);
                    }
                } else if (tempRand == 2) { // Enemy Chases Player
                    if (hero.rect.getPosition().y < enemies[angryCounter].rect.getPosition().y) {
                        enemies[angryCounter].setDirection(Character::Direction::Up);
                    } else if (hero.rect.getPosition().x > enemies[angryCounter].rect.getPosition().x) {
                        enemies[angryCounter].setDirection(Character::Direction::Right);
                    } else if (hero.rect.getPosition().x < enemies[angryCounter].rect.getPosition().x) {
                        enemies[angryCounter].setDirection(Character::Direction::Left);
                    } else if (hero.rect.getPosition().y > enemies[angryCounter].rect.getPosition().y) {
                        enemies[angryCounter].setDirection(Character::Direction::Down);
                    }
                } else { // Enemy Chases Player
                    if (hero.rect.getPosition().x < enemies[angryCounter].rect.getPosition().x) {
                        enemies[angryCounter].setDirection(Character::Direction::Left);
                    } else if (hero.rect.getPosition().x > enemies[angryCounter].rect.getPosition().x) {
                        enemies[angryCounter].setDirection(Character::Direction::Right);
                    } else if (hero.rect.getPosition().y < enemies[angryCounter].rect.getPosition().y) {
                        enemies[angryCounter].setDirection(Character::Direction::Up);
                    } else if (hero.rect.getPosition().y > enemies[angryCounter].rect.getPosition().y) {
                        enemies[angryCounter].setDirection(Character::Direction::Down);
                    }
                }

            }
        }

        angryCounter++;
    }
}

void Strategy::NPCAttack(NPC &npc, sf::Time &elapsedAngry, sf::Clock &clockAngry, Projectile &projectile,
                         std::vector<Mob> &enemy, sf::Sound &soundShot, std::vector<Projectile> &projectileArray) {

    if (enemy.size() > 0) {
        int counter = 0;
        if (elapsedAngry.asSeconds() >= 0.3) {
            clockAngry.restart();
            int randomNumber = rand();
            int tempRand = (randomNumber % 2) + 1;
            if (tempRand == 1) { // Fires and chases
                projectile.setDamage(npc.getStrength());

                // enemy to Right
                if ((enemy[counter].rect.getPosition().x < npc.rect.getPosition().x) &&
                    (fabs(enemy[counter].rect.getPosition().y - npc.rect.getPosition().y) <= 25)) {
                    soundShot.play();
                    projectile.setHostile(false);
                    projectile.setDirection(Character::Direction::Left);
                    projectile.rect.setPosition(npc.rect.getPosition().x +
                                                npc.rect.getSize().x / 2 -
                                                projectile.rect.getSize().x / 2,
                                                npc.rect.getPosition().y +
                                                npc.rect.getSize().y / 2 -
                                                projectile.rect.getSize().y / 2);
                    projectileArray.push_back(projectile);

                    npc.setDirection(Character::Direction::Left);
                }

                // enemy to Left
                if ((enemy[counter].rect.getPosition().x > npc.rect.getPosition().x) &&
                    (fabs(enemy[counter].rect.getPosition().y - npc.rect.getPosition().y) <= 25)) {
                    soundShot.play();
                    projectile.setHostile(false);
                    projectile.setDirection(Character::Direction::Right);
                    projectile.rect.setPosition(npc.rect.getPosition().x +
                                                npc.rect.getSize().x / 2 -
                                                projectile.rect.getSize().x / 2,
                                                npc.rect.getPosition().y +
                                                npc.rect.getSize().y / 2 -
                                                projectile.rect.getSize().y / 2);
                    projectileArray.push_back(projectile);

                    npc.setDirection(Character::Direction::Right);
                }

                // Player to Top
                if ((enemy[counter].rect.getPosition().y < npc.rect.getPosition().y) &&
                    (fabs(enemy[counter].rect.getPosition().x - npc.rect.getPosition().x) <= 25)) {
                    soundShot.play();
                    projectile.setHostile(false);
                    projectile.setDirection(Character::Direction::Up);
                    projectile.rect.setPosition(npc.rect.getPosition().x +
                                                npc.rect.getSize().x / 2 -
                                                projectile.rect.getSize().x / 2,
                                                npc.rect.getPosition().y +
                                                npc.rect.getSize().y / 2 -
                                                projectile.rect.getSize().y / 2);
                    projectileArray.push_back(projectile);

                    npc.setDirection(Character::Direction::Up);
                }

                // enemy to Bottom
                if ((enemy[counter].rect.getPosition().y > npc.rect.getPosition().y) &&
                    (fabs(enemy[counter].rect.getPosition().x - npc.rect.getPosition().x) <= 25)) {
                    soundShot.play();
                    projectile.setHostile(false);
                    projectile.setDirection(Character::Direction::Down);
                    projectile.rect.setPosition(npc.rect.getPosition().x +
                                                npc.rect.getSize().x / 2 -
                                                projectile.rect.getSize().x / 2,
                                                npc.rect.getPosition().y +
                                                npc.rect.getSize().y / 2 -
                                                projectile.rect.getSize().y / 2);
                    projectileArray.push_back(projectile);

                    npc.setDirection(Character::Direction::Down);
                }
            } else if (tempRand == 2) { // NPC Chases Enemy
                if (enemy[counter].rect.getPosition().y < npc.rect.getPosition().y) {
                    npc.setDirection(Character::Direction::Up);
                } else if (enemy[counter].rect.getPosition().x > npc.rect.getPosition().x) {
                    npc.setDirection(Character::Direction::Right);
                } else if (enemy[counter].rect.getPosition().x < npc.rect.getPosition().x) {
                    npc.setDirection(Character::Direction::Left);
                } else if (enemy[counter].rect.getPosition().y > npc.rect.getPosition().y) {
                    npc.setDirection(Character::Direction::Down);
                }
            } else { // Enemy Chases NPC
                if (enemy[counter].rect.getPosition().x < npc.rect.getPosition().x) {
                    npc.setDirection(Character::Direction::Left);
                } else if (enemy[counter].rect.getPosition().x > npc.rect.getPosition().x) {
                    npc.setDirection(Character::Direction::Right);
                } else if (enemy[counter].rect.getPosition().y < npc.rect.getPosition().y) {
                    npc.setDirection(Character::Direction::Up);
                } else if (enemy[counter].rect.getPosition().y > npc.rect.getPosition().y) {
                    npc.setDirection(Character::Direction::Down);
                }
            }

        }
    }
}


void Strategy::HeroShot(Hero &hero, sf::Sound &soundShot, std::vector<Projectile> &projectileArray,
                        Projectile &projectile) {
    int shot = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        shot = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        shot = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shot = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shot = 4;
    }
    switch (shot) {
        case (1) :
            projectile.rect.setPosition(
                    hero.rect.getPosition().x + hero.rect.getSize().x / 2 - projectile.rect.getSize().x / 2,
                    hero.rect.getPosition().y + hero.rect.getSize().y / 2 -
                    projectile.rect.getSize().y / 2);
            projectile.setDirection(Character::Direction::Up);
            projectileArray.push_back(projectile);
            soundShot.play();
            break;
        case (2) :
            projectile.rect.setPosition(
                    hero.rect.getPosition().x + hero.rect.getSize().x / 2 - projectile.rect.getSize().x / 2,
                    hero.rect.getPosition().y + hero.rect.getSize().y / 2 -
                    projectile.rect.getSize().y / 2);
            projectile.setDirection(Character::Direction::Down);
            projectileArray.push_back(projectile);
            soundShot.play();
            break;
        case (3) :
            projectile.rect.setPosition(
                    hero.rect.getPosition().x + hero.rect.getSize().x / 2 - projectile.rect.getSize().x / 2,
                    hero.rect.getPosition().y + hero.rect.getSize().y / 2 -
                    projectile.rect.getSize().y / 2);
            projectile.setDirection(Character::Direction::Left);
            projectileArray.push_back(projectile);
            soundShot.play();
            break;
        case (4) :
            projectile.rect.setPosition(
                    hero.rect.getPosition().x + hero.rect.getSize().x / 2 - projectile.rect.getSize().x / 2,
                    hero.rect.getPosition().y + hero.rect.getSize().y / 2 -
                    projectile.rect.getSize().y / 2);
            projectile.setDirection(Character::Direction::Right);
            projectileArray.push_back(projectile);
            soundShot.play();
            break;

        default:
            break;
    }
}

void Strategy::Projectile_EnemyCollision(std::vector<Mob> &enemies, Projectile &projectile,
                                         std::vector<Projectile> &projectileArray, std::vector<Item> &items,
                                         Item &coinItem) {
    int pcounter = 0;
    for (auto itr = projectileArray.begin(); itr != projectileArray.end(); itr++) {
        int ecounter = 0;
        for (auto itr2 = enemies.begin(); itr2 != enemies.end(); itr2++) {
            if (projectileArray[pcounter].rect.getGlobalBounds().intersects(
                    enemies[ecounter].rect.getGlobalBounds()) && !projectileArray[pcounter].isHostile()) {
                enemies[ecounter].setHealth(enemies[ecounter].getHealth() - 1);
                enemies[pcounter].setAngry(true);
                if (enemies[ecounter].getHealth() <= 0) {
                    enemies[ecounter].setAlive(false);
                    projectileArray[pcounter].setDestroy(true);
                    coinItem.setX(static_cast<int>(enemies[ecounter].rect.getPosition().x +
                                                   enemies[ecounter].rect.getSize().x / 2 - 12));
                    coinItem.setY(static_cast<int>(enemies[ecounter].rect.getPosition().y +
                                                   enemies[ecounter].rect.getSize().y / 2 - 12));
                    coinItem.rect.setPosition(coinItem.getX(), coinItem.getY());
                    coinItem.setValue(static_cast<int>(enemies[ecounter].getDropRate()));
                    items.push_back(coinItem);
                }
            }
            ecounter++;
        }
        pcounter++;
    }
}

void Strategy::WeaponsCollisions(std::vector<Mob> &enemies, Hero &hero, bool &isAnimating, std::vector<Item> &items,
                                 Item &coinItem, Item &swordItem, Item &stickItem, Item &axeItem) {
    int pcounter = 0;
    for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
        if (isAnimating && (hero.getDirection() == Character::Direction::Down) &&
            fabs(hero.rect.getPosition().x - enemies[pcounter].rect.getPosition().x) < 48 &&
            enemies[pcounter].rect.getPosition().y - (hero.rect.getPosition().y + 64) < 10 &&
            enemies[pcounter].rect.getPosition().y - (hero.rect.getPosition().y + 64) > -40) {
            enemies[pcounter].setHealth(enemies[pcounter].getHealth() - hero.getWeapon()->getStrength());
            enemies[pcounter].setAngry(true);
            if (enemies[pcounter].getHealth() <= 0) {
                int randomNumber = rand();
                int tempRand = (randomNumber % 4) + 1;
                if (tempRand == 1 && enemies[pcounter].isAlive()) {
                    coinItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                   enemies[pcounter].rect.getSize().x / 2 - 12));
                    coinItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                   enemies[pcounter].rect.getSize().y / 2 - 12));
                    coinItem.rect.setPosition(coinItem.getX(), coinItem.getY());
                    coinItem.setValue(static_cast<int>(enemies[pcounter].getDropRate()));
                    items.push_back(coinItem);
                } else if (tempRand == 2 && enemies[pcounter].isAlive()) {
                    swordItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    swordItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    swordItem.rect.setPosition(swordItem.getX(), swordItem.getY());
                    items.push_back(swordItem);
                } else if (tempRand == 3 && enemies[pcounter].isAlive()) {
                    stickItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    stickItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    stickItem.rect.setPosition(stickItem.getX(), stickItem.getY());
                    items.push_back(stickItem);
                } else if (tempRand == 4 && enemies[pcounter].isAlive()) {
                    axeItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                  enemies[pcounter].rect.getSize().x / 2 - 24));
                    axeItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                  enemies[pcounter].rect.getSize().y / 2 - 24));
                    axeItem.rect.setPosition(axeItem.getX(), axeItem.getY());
                    items.push_back(axeItem);
                }
                enemies[pcounter].setAlive(false);
            }
        } else if (isAnimating && (hero.getDirection() == Character::Direction::Up) &&
                   fabs(hero.rect.getPosition().x - enemies[pcounter].rect.getPosition().x) < 48 &&
                   hero.rect.getPosition().y - (enemies[pcounter].rect.getPosition().y + 48) < 10 &&
                   hero.rect.getPosition().y - (enemies[pcounter].rect.getPosition().y + 48) > -40) {
            enemies[pcounter].setHealth(enemies[pcounter].getHealth() - hero.getWeapon()->getStrength());
            enemies[pcounter].setAngry(true);
            if (enemies[pcounter].getHealth() <= 0) {
                int randomNumber = rand();
                int tempRand = (randomNumber % 4) + 1;
                if (tempRand == 1 && enemies[pcounter].isAlive()) {
                    coinItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                   enemies[pcounter].rect.getSize().x / 2 - 12));
                    coinItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                   enemies[pcounter].rect.getSize().y / 2 - 12));
                    coinItem.rect.setPosition(coinItem.getX(), coinItem.getY());
                    coinItem.setValue(static_cast<int>(enemies[pcounter].getDropRate()));
                    items.push_back(coinItem);
                } else if (tempRand == 2 && enemies[pcounter].isAlive()) {
                    swordItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    swordItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    swordItem.rect.setPosition(swordItem.getX(), swordItem.getY());
                    items.push_back(swordItem);
                } else if (tempRand == 3 && enemies[pcounter].isAlive()) {
                    stickItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    stickItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    stickItem.rect.setPosition(stickItem.getX(), stickItem.getY());
                    items.push_back(stickItem);
                } else if (tempRand == 4 && enemies[pcounter].isAlive()) {
                    axeItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                  enemies[pcounter].rect.getSize().x / 2 - 24));
                    axeItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                  enemies[pcounter].rect.getSize().y / 2 - 24));
                    axeItem.rect.setPosition(axeItem.getX(), axeItem.getY());
                    items.push_back(axeItem);
                }
                enemies[pcounter].setAlive(false);
            }
        } else if (isAnimating && (hero.getDirection() == Character::Direction::Left) &&
                   fabs(hero.rect.getPosition().y - enemies[pcounter].rect.getPosition().y) < 48 &&
                   hero.rect.getPosition().x - (enemies[pcounter].rect.getPosition().x + 48) < 10 &&
                   hero.rect.getPosition().x - (enemies[pcounter].rect.getPosition().x + 48) > -30) {
            enemies[pcounter].setHealth(enemies[pcounter].getHealth() - hero.getWeapon()->getStrength());
            enemies[pcounter].setAngry(true);
            if (enemies[pcounter].getHealth() <= 0) {
                int randomNumber = rand();
                int tempRand = (randomNumber % 4) + 1;
                if (tempRand == 1 && enemies[pcounter].isAlive()) {
                    coinItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                   enemies[pcounter].rect.getSize().x / 2 - 12));
                    coinItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                   enemies[pcounter].rect.getSize().y / 2 - 12));
                    coinItem.rect.setPosition(coinItem.getX(), coinItem.getY());
                    coinItem.setValue(static_cast<int>(enemies[pcounter].getDropRate()));
                    items.push_back(coinItem);
                } else if (tempRand == 2 && enemies[pcounter].isAlive()) {
                    swordItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    swordItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    swordItem.rect.setPosition(swordItem.getX(), swordItem.getY());
                    items.push_back(swordItem);
                } else if (tempRand == 3 && enemies[pcounter].isAlive()) {
                    stickItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    stickItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    stickItem.rect.setPosition(stickItem.getX(), stickItem.getY());
                    items.push_back(stickItem);
                } else if (tempRand == 4 && enemies[pcounter].isAlive()) {
                    axeItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                  enemies[pcounter].rect.getSize().x / 2 - 24));
                    axeItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                  enemies[pcounter].rect.getSize().y / 2 - 24));
                    axeItem.rect.setPosition(axeItem.getX(), axeItem.getY());
                    items.push_back(axeItem);
                }
                enemies[pcounter].setAlive(false);
            }
        } else if (isAnimating && (hero.getDirection() == Character::Direction::Right) &&
                   fabs(hero.rect.getPosition().y - enemies[pcounter].rect.getPosition().y) < 48 &&
                   enemies[pcounter].rect.getPosition().x - (hero.rect.getPosition().x + 64) < 10 &&
                   enemies[pcounter].rect.getPosition().x - (hero.rect.getPosition().x + 64) > -30) {
            enemies[pcounter].setHealth(enemies[pcounter].getHealth() - hero.getWeapon()->getStrength());
            enemies[pcounter].setAngry(true);
            if (enemies[pcounter].getHealth() <= 0) {
                int randomNumber = rand();
                int tempRand = (randomNumber % 4) + 1;
                if (tempRand == 1 && enemies[pcounter].isAlive()) {
                    coinItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                   enemies[pcounter].rect.getSize().x / 2 - 12));
                    coinItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                   enemies[pcounter].rect.getSize().y / 2 - 12));
                    coinItem.rect.setPosition(coinItem.getX(), coinItem.getY());
                    coinItem.setValue(static_cast<int>(enemies[pcounter].getDropRate()));
                    items.push_back(coinItem);
                } else if (tempRand == 2 && enemies[pcounter].isAlive()) {
                    swordItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    swordItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    swordItem.rect.setPosition(swordItem.getX(), swordItem.getY());
                    items.push_back(swordItem);
                } else if (tempRand == 3 && enemies[pcounter].isAlive()) {
                    stickItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                    enemies[pcounter].rect.getSize().x / 2 - 24));
                    stickItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                    enemies[pcounter].rect.getSize().y / 2 - 24));
                    stickItem.rect.setPosition(stickItem.getX(), stickItem.getY());
                    items.push_back(stickItem);
                } else if (tempRand == 4 && enemies[pcounter].isAlive()) {
                    axeItem.setX(static_cast<int>(enemies[pcounter].rect.getPosition().x +
                                                  enemies[pcounter].rect.getSize().x / 2 - 24));
                    axeItem.setY(static_cast<int>(enemies[pcounter].rect.getPosition().y +
                                                  enemies[pcounter].rect.getSize().y / 2 - 24));
                    axeItem.rect.setPosition(axeItem.getX(), axeItem.getY());
                    items.push_back(axeItem);
                }
                enemies[pcounter].setAlive(false);
            }
        }
        pcounter++;
    }
}

void Strategy::Hero_ItemsCollisions(Hero &hero, std::vector<Item> &items) {
    int pcounter = 0;
    for (auto itr = items.begin(); itr != items.end(); itr++) {
        if (items[pcounter].getType() == "coin" &&
            hero.rect.getGlobalBounds().intersects(items[pcounter].rect.getGlobalBounds())) {
            items[pcounter].setTooken(true);
        } else if ((items[pcounter].getType() == "sword" || items[pcounter].getType() == "stick" ||
                    items[pcounter].getType() == "axe") &&
                   hero.rect.getGlobalBounds().intersects(items[pcounter].rect.getGlobalBounds()) &&
                   sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
            items[pcounter].setTooken(true);
            if (items[pcounter].getType() == "sword") {
                hero.setChangeToSword(true);
                hero.notify();
            }
            if (items[pcounter].getType() == "axe") {
                hero.setChangeToAxe(true);
                hero.notify();
            }
            if (items[pcounter].getType() == "stick") {
                hero.setChangeToStick(true);
                hero.notify();
            }
        }
        pcounter++;
    }
}

void Strategy::NPC_EnemiesCollisions(NPC &buddy, std::vector<Mob> &enemies) {
    int pcounter = 0;
    for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
        if (fabs(buddy.rect.getPosition().x - enemies[pcounter].rect.getPosition().x) < 55 &&
            buddy.rect.getPosition().y - enemies[pcounter].rect.getPosition().y < 55 &&
            buddy.rect.getPosition().y - enemies[pcounter].rect.getPosition().y > 0) {
            buddy.setCollUp(true);
            enemies[pcounter].setCollDown(true);
        }
        if (fabs(buddy.rect.getPosition().x - enemies[pcounter].rect.getPosition().x) < 55 &&
            enemies[pcounter].rect.getPosition().y - buddy.rect.getPosition().y < 55 &&
            enemies[pcounter].rect.getPosition().y - buddy.rect.getPosition().y > 0) {
            buddy.setCollDown(true);
            enemies[pcounter].setCollUp(true);
        }
        if (fabs(buddy.rect.getPosition().y - enemies[pcounter].rect.getPosition().y) < 55 &&
            enemies[pcounter].rect.getPosition().x - buddy.rect.getPosition().x < 55 &&
            enemies[pcounter].rect.getPosition().x - buddy.rect.getPosition().x > 0) {
            buddy.setCollRight(true);
            enemies[pcounter].setCollLeft(true);
        }
        if (fabs(buddy.rect.getPosition().y - enemies[pcounter].rect.getPosition().y) < 55 &&
            buddy.rect.getPosition().x - enemies[pcounter].rect.getPosition().x < 55 &&
            buddy.rect.getPosition().x - enemies[pcounter].rect.getPosition().x > 0) {
            buddy.setCollLeft(true);
            enemies[pcounter].setCollRight(true);
        }
        pcounter++;
    }
}

void Strategy::EnemiesCollisions(std::vector<Mob> &enemies) {
    int incounter = 0;
    int pcounter = 0;
    for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
        incounter = 0;
        for (auto initr = enemies.begin(); initr != enemies.end(); initr++) {
            if (itr != initr) {
                if (fabs(enemies[incounter].rect.getPosition().x - enemies[pcounter].rect.getPosition().x) < 55 &&
                    enemies[incounter].rect.getPosition().y - enemies[pcounter].rect.getPosition().y < 55 &&
                    enemies[incounter].rect.getPosition().y - enemies[pcounter].rect.getPosition().y > 0) {
                    enemies[incounter].setCollUp(true);
                    enemies[pcounter].setCollDown(true);
                }
                if (fabs(enemies[incounter].rect.getPosition().x - enemies[pcounter].rect.getPosition().x) < 55 &&
                    enemies[pcounter].rect.getPosition().y - enemies[incounter].rect.getPosition().y < 55 &&
                    enemies[pcounter].rect.getPosition().y - enemies[incounter].rect.getPosition().y > 0) {
                    enemies[incounter].setCollDown(true);
                    enemies[pcounter].setCollUp(true);
                }
                if (fabs(enemies[incounter].rect.getPosition().y - enemies[pcounter].rect.getPosition().y) < 55 &&
                    enemies[pcounter].rect.getPosition().x - enemies[incounter].rect.getPosition().x < 55 &&
                    enemies[pcounter].rect.getPosition().x - enemies[incounter].rect.getPosition().x > 0) {
                    enemies[incounter].setCollRight(true);
                    enemies[pcounter].setCollLeft(true);
                }
                if (fabs(enemies[incounter].rect.getPosition().y - enemies[pcounter].rect.getPosition().y) < 55 &&
                    enemies[incounter].rect.getPosition().x - enemies[pcounter].rect.getPosition().x < 55 &&
                    enemies[incounter].rect.getPosition().x - enemies[pcounter].rect.getPosition().x > 0) {
                    enemies[incounter].setCollLeft(true);
                    enemies[pcounter].setCollRight(true);
                }
            }
            incounter++;
        }
        pcounter++;
    }
}

void Strategy::Hero_ProjectileCollisions(std::vector<Projectile> &projectileArray, Hero &hero) {
    int pcounter = 0;
    for (auto itr = projectileArray.begin(); itr != projectileArray.end(); itr++) {
        if (projectileArray[pcounter].rect.getGlobalBounds().intersects(hero.rect.getGlobalBounds()) &&
            projectileArray[pcounter].isHostile()) {
            hero.setHealth(hero.getHealth() - 1);
            hero.notify();
            projectileArray[pcounter].setDestroy(true);
        }
        pcounter++;
    }
}