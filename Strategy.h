#ifndef PROJECTVIDEOGAME_STRATEGY_H
#define PROJECTVIDEOGAME_STRATEGY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Mob.h"
#include "Projectile.h"
#include "NPC.h"
#include "StatusBar.h"

class Strategy {
public:
    void EnemyAttack(std::vector<Mob> &enemies, sf::Time &elapsedAngry, sf::Clock &clockAngry, Projectile &projectile,
                     Hero &hero, sf::Sound &soundShot, std::vector<Projectile> &projectileArray);

    void NPCAttack(NPC &npc, sf::Time &elapsedAngry, sf::Clock &clockAngry, Projectile &projectile,
                   std::vector<Mob> &enemy, sf::Sound &soundShot, std::vector<Projectile> &projectileArray);

    void HeroShot(Hero &hero, sf::Sound &soundShot, std::vector<Projectile> &projectileArray,
                  Projectile &projectile);

    void Projectile_EnemyCollision(std::vector<Mob> &enemies, Projectile &projectile,
                                   std::vector<Projectile> &projectileArray, std::vector<Item> &items, Item &coinItem);

    void WeaponsCollisions(std::vector<Mob> &enemies, Hero &hero, bool &isAnimating, std::vector<Item> &items,
                           Item &coinItem, Item &swordItem, Item &stickItem, Item &axeItem);

    void Hero_ItemsCollisions(Hero &hero, std::vector<Item> &items);

    void NPC_EnemiesCollisions(NPC &buddy, std::vector<Mob> &enemies);

    void EnemiesCollisions(std::vector<Mob> &enemies);

    void Hero_ProjectileCollisions(std::vector<Projectile> &projectileArray, Hero &hero);
};

#endif //PROJECTVIDEOGAME_STRATEGY_H
