#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../Mob.h"

TEST(MobTest, DefaultConstructor) {
    Mob enemy(40, 2, 6);
    ASSERT_EQ(40, enemy.getHealth());
    ASSERT_EQ(2, enemy.getStrength());
    ASSERT_EQ(6, enemy.getDropRate());
    ASSERT_EQ(48, enemy.rect.getSize().x);
    ASSERT_EQ(48, enemy.rect.getSize().y);
}

TEST(MobTest, OutOfBounds){
    Mob enemy(40, 2, 6);
    enemy.rect.setPosition(149,0);
    ASSERT_EQ(true, enemy.outOfbounds(Character::Direction::Left));
    enemy.rect.setPosition(400, -1);
    ASSERT_EQ(true, enemy.outOfbounds(Character::Direction::Up));
    enemy.rect.setPosition(1400, 50);
    ASSERT_EQ(true, enemy.outOfbounds(Character::Direction::Right));
    enemy.rect.setPosition(120, 960);
    ASSERT_EQ(true, enemy.outOfbounds(Character::Direction::Down));
}

TEST(MobTest, TileCollision){
    Mob enemy(40, 2, 6);
    int tile = 514;
    ASSERT_EQ(true, enemy.checkCollision(tile));
    tile = 744;
    ASSERT_EQ(true, enemy.checkCollision(tile));
    tile = 49;
    ASSERT_EQ(false, enemy.checkCollision(tile));
}

