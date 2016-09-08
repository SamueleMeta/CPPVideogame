#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "../NPC.h"

TEST(NPCTest, DefaultConstructor) {
    NPC buddy(40, 2);
    ASSERT_EQ(2, buddy.getStrength());
    ASSERT_EQ(40, buddy.getHealth());
    ASSERT_EQ(48, buddy.rect.getSize().x);
    ASSERT_EQ(48, buddy.rect.getSize().y);
}

TEST(NPCTest, OutOfBounds){
    NPC buddy(40, 2);
    buddy.rect.setPosition(149,0);
    ASSERT_EQ(true, buddy.outOfbounds(Character::Direction::Left));
    buddy.rect.setPosition(400, -1);
    ASSERT_EQ(true, buddy.outOfbounds(Character::Direction::Up));
    buddy.rect.setPosition(1400, 50);
    ASSERT_EQ(true, buddy.outOfbounds(Character::Direction::Right));
    buddy.rect.setPosition(120, 960);
    ASSERT_EQ(true, buddy.outOfbounds(Character::Direction::Down));
}

TEST(NPCTest, TileCollision){
    NPC buddy(40, 2);
    int tile = 514;
    ASSERT_EQ(true, buddy.checkCollision(tile));
    tile = 744;
    ASSERT_EQ(true, buddy.checkCollision(tile));
    tile = 49;
    ASSERT_EQ(false, buddy.checkCollision(tile));
}
