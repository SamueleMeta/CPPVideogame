#include "Strategy.h"
#include "NPC.h"

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
                        (abs(hero.rect.getPosition().y - enemies[angryCounter].rect.getPosition().y) <= 30)) {
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
                        (abs(hero.rect.getPosition().y - enemies[angryCounter].rect.getPosition().y) <= 30)) {
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
                        (abs(hero.rect.getPosition().x - enemies[angryCounter].rect.getPosition().x) <= 30)) {
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
                        (abs(hero.rect.getPosition().x - enemies[angryCounter].rect.getPosition().x) <= 30)) {
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

    if ( enemy.size() > 0) {
        int counter = 0;
        if (elapsedAngry.asSeconds() >= 0.3) {
            clockAngry.restart();
            int randomNumber = rand();
            int tempRand = (randomNumber % 2) + 1;
            if (tempRand == 1) { // Fires and chases
                projectile.setDamage(npc.getStrength());

                // enemy to Right
                if ((enemy[counter].rect.getPosition().x < npc.rect.getPosition().x) &&
                    (abs(enemy[counter].rect.getPosition().y - npc.rect.getPosition().y) <= 45)) {
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
                    (abs(enemy[counter].rect.getPosition().y - npc.rect.getPosition().y) <= 45)) {
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
                    (abs(enemy[counter].rect.getPosition().x - npc.rect.getPosition().x) <= 45)) {
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
                    (abs(enemy[counter].rect.getPosition().x - npc.rect.getPosition().x) <= 45)) {
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
        counter++;
    }
}
