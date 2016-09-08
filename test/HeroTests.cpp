#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../Hero.h"

TEST(HeroTest, DefaultConstructor){
    Hero hero(100, 10, "Hero", 20, 0);
    ASSERT_EQ(100, hero.getHealth());
    ASSERT_EQ(10, hero.getStrength());
    ASSERT_EQ("Hero", hero.getName());
    ASSERT_EQ(20, hero.getMoney());
    ASSERT_EQ(0, hero.getExp());
    ASSERT_EQ(64, hero.rect.getSize().x);
    ASSERT_EQ(64, hero.rect.getSize().y);
    ASSERT_EQ(437, hero.rect.getPosition().x);
    ASSERT_EQ(0, hero.rect.getPosition().y);
    ASSERT_EQ(nullptr, hero.getWeapon());
    ASSERT_EQ(nullptr, hero.getPotion());
}

TEST(HeroTest, OutOfBounds){
    Hero hero(100, 10, "Hero", 20, 0);
    hero.rect.setPosition(149,0);
    ASSERT_EQ(true, hero.outOfbounds(Character::Direction::Left));
    hero.rect.setPosition(400, -1);
    ASSERT_EQ(true, hero.outOfbounds(Character::Direction::Up));
    hero.rect.setPosition(1400, 50);
    ASSERT_EQ(true, hero.outOfbounds(Character::Direction::Right));
    hero.rect.setPosition(120, 960);
    ASSERT_EQ(true, hero.outOfbounds(Character::Direction::Down));
}

TEST(HeroTest, TileCollision){
    Hero hero(100, 10, "Hero", 20, 0);
    int tile = 514;
    ASSERT_EQ(true, hero.checkCollision(tile));
    tile = 744;
    ASSERT_EQ(true, hero.checkCollision(tile));
    tile = 49;
    ASSERT_EQ(false, hero.checkCollision(tile));
}


