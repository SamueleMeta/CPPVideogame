#ifndef PROJECTVIDEOGAME_STRATEGY_H
#define PROJECTVIDEOGAME_STRATEGY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Mob.h"
#include "Projectile.h"
#include "NPC.h"

class Strategy {
public:
    void EnemyAttack(std::vector<Mob> &enemies, sf::Time &elapsedAngry, sf::Clock &clockAngry, Projectile &projectile,
        Hero &hero, sf::Sound &soundShot, std::vector<Projectile> &projectileArray);

    void NPCAttack(NPC &npc, sf::Time &elapsedAngry, sf::Clock &clockAngry, Projectile &projectile,
        std::vector<Mob> &enemy, sf::Sound &soundShot, std::vector<Projectile> &projectileArray);
};


#endif //PROJECTVIDEOGAME_STRATEGY_H
