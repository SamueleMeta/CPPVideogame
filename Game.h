#ifndef PROJECTVIDEOGAME_GAME_H
#define PROJECTVIDEOGAME_GAME_H

#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"
#include "StatusBar.h"
#include "Mob.h"

const int erba = 1044;
const int trsp = 1300;

class Game {
public:
    Game(int health = 40, int strength = 1, float drop1 = 1, float drop2 = 2, float drop3 = 3, float drop4 = 5,
         int swordS = 20, int axeS = 40, int stickS = 15,
         int red = 8, int redU = 2, int green = 1, int greenU = 8, int blue = 4, int blueU = 4, std::string s = "sword",
         std::string a = "axe", std::string u = "stick") :
            darkLord(health, strength, drop4), assassin(health, strength, drop2), zombie(health, strength, drop3),
            chimera(health, strength, drop1), chaosKnight(health, strength, drop2), sword(swordS, s), axe(axeS, a),
            stick(stickS, u),
            redPotion(red, redU), greenPotion(green, greenU), bluePotion(blue, blueU), coinItem("coin"), axeItem("axe"),
            swordItem("sword"),
            stickItem("stick") { }

    ~Game() { }

    int loadTextures(int hero, int npc);

    void setItems();

    void setEnemies();

    void setSprites(int choose);

    void personalizeHero(Hero &hero, int choose);

    void setHeroBar(Hero &hero);

    void setHeroText(Hero &hero);

    void setFont();

    int setMusic();

    // Textures
    sf::Texture texturePlayer;
    sf::Texture textureNPC;
    sf::Texture textureAssassin;
    sf::Texture textureDarkLord;
    sf::Texture textureChaos;
    sf::Texture textureChimera;
    sf::Texture textureZombie;
    sf::Texture textureFireBall;
    sf::Texture textureCoin;
    sf::Texture textureProfile;
    sf::Texture textureName;
    sf::Texture textureHeart;
    sf::Texture textureExp;
    sf::Texture textureMoney;
    sf::Texture textureSword;
    sf::Texture textureStick;
    sf::Texture textureAxe;
    sf::Texture textureWeapon;
    sf::Texture texturePotion;
    sf::Texture textureScroll;

    // Sprites
    sf::Sprite headSprite;
    sf::Sprite nameSprite;
    sf::Sprite heartsSprite;
    sf::Sprite expSprite;
    sf::Sprite moneySprite;
    sf::Sprite weaponsSprite;
    sf::Sprite potionsSprite;
    sf::Sprite scrollsSprite;

    // Weapons
    Weapon sword;
    Weapon axe;
    Weapon stick;

    // Potions
    Potion redPotion;
    Potion bluePotion;
    Potion greenPotion;

    // Items
    Item coinItem;
    Item swordItem;
    Item stickItem;
    Item axeItem;

    // Enemies
    Mob darkLord;
    Mob assassin;
    Mob zombie;
    Mob chimera;
    Mob chaosKnight;

    // Clocks
    sf::Clock clockProjectile;
    sf::Clock clockAngry;
    sf::Clock clockNPC;

    // Music
    sf::Music music;
    sf::SoundBuffer bufferShot;
    sf::Sound soundShot;

    // Font
    sf::Font font;

    // Level Background
    const int levelBackground[247] =
            {
                    1044, 1044, 1044, 1044, 1052, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053,
                    1053, 1053, 1054,
                    erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 849, 850, 850, 850, 850, 850, 850, 850, 850, 851, erba, erba,
                    erba,
                    erba, erba, erba, erba, erba, erba, 852, 857, 857, 857, 857, 857, 857, 857, 857, 853, erba, erba,
                    erba,
                    erba, erba, erba, erba, erba, erba, 852, 857, 855, 855, 855, 855, 855, 855, 855, 856, erba, erba,
                    erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba,
            };

    // Level Visible
    const int levelVisible[247] =
            {
                    trsp, trsp, trsp, trsp, trsp, trsp, 496, trsp, trsp, 484, trsp, trsp, 460, trsp, 497, trsp, trsp,
                    460, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 1080, trsp, trsp, trsp, 609, trsp, trsp, trsp,
                    trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 474,
                    trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, 1081, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 514,
                    trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 563, trsp, trsp, trsp, trsp, 1110, trsp, trsp,
                    trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 603, trsp, trsp, trsp, trsp, 1109, trsp, trsp,
                    trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, 571, trsp, trsp, 839, trsp, trsp, trsp, 744, 745, 746, trsp, trsp,
                    trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 747, 748, 749, trsp, trsp,
                    trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp,
            };

};


#endif //PROJECTVIDEOGAME_GAME_H
