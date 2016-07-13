#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../Hero.h"

TEST(HeroTest, DefaultConstructor){
    Hero hero(100, 10, 50, "Hero", 20, 1, 0, Hero::Human, Hero::Warrior);
    ASSERT_EQ(100, hero.getHealth());
    ASSERT_EQ(10, hero.getStrength());
    ASSERT_EQ(50, hero.getEnergy());
    ASSERT_EQ("Hero", hero.getName());
    ASSERT_EQ(20, hero.getMoney());
    ASSERT_EQ(1, hero.getHeroLevel());
    ASSERT_EQ(0, hero.getExp());
    ASSERT_EQ(Hero::Human, hero.getRace());
    ASSERT_EQ(Hero::Warrior, hero.getClassType());
    ASSERT_EQ(32, hero.rect.getSize().x);
    ASSERT_EQ(32, hero.rect.getSize().y);
    ASSERT_EQ(400, hero.rect.getPosition().x);
    ASSERT_EQ(200, hero.rect.getPosition().y);
}