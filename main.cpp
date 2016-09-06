#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TileMap.h"
#include "Hero.h"
#include "Mob.h"
#include "NPC.h"
#include "Projectile.h"
#include "Settings.h"
#include "StatusBar.h"
#include "Strategy.h"
#include "Potion.h"
#include "Scroll.h"

int main() {

    enum Gamestate {
        Initialize, Pause, Playing
    };

    Gamestate gameState = Initialize;

    Settings settings;

    Strategy strategy;

    const int erba = 1044;
    const int trsp = 1300;
    bool isAnimating = false;
    bool startAnimation = false;
    bool halfAnimation = false;

    sf::Vector2u screenDimension(800, 600);

    // create the window
    sf::RenderWindow window(sf::VideoMode(screenDimension.x, screenDimension.y), "Videogame", sf::Style::None);

    sf::Vector2i positionWindow((sf::VideoMode::getDesktopMode().width / 2) - screenDimension.x / 2,
                                (sf::VideoMode::getDesktopMode().height / 2) - screenDimension.y / 2);
    window.setPosition(positionWindow);
    window.setFramerateLimit(60);

    int choosenCharacter = 0;

    sf::Font font;
    font.loadFromFile("PrinceValiant.ttf");

    sf::Text name;
    name.setColor(sf::Color::Black);

    std::string str;

    int chooseNPC = 0;

    if (gameState == Initialize) {
        settings.showSplash(window);
        window.clear();
        settings.showOptions(window, choosenCharacter);
        settings.inputName(str, name, window, font, choosenCharacter);
        name.setCharacterSize(18);
        name.setPosition(12, 180);
        window.clear();
        settings.chooseNPC(window, chooseNPC);
        gameState = Playing;
    }

    // center camera
    sf::View view;
    view.reset(sf::FloatRect(0, 0, screenDimension.x, screenDimension.y));
    view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
    sf::Vector2f position(screenDimension.x / 2, screenDimension.y / 2);
    sf::Vector2f viewSize = view.getSize();

    // Clock for projectiles
    sf::Clock clockProjectile;

    // Clock for angry enemies
    sf::Clock clockAngry;
    // Clock for NPC
    sf::Clock clockNPC;

    // load player texture
    sf::Texture texturePlayer;
    if (choosenCharacter == 0) {
        if (!texturePlayer.loadFromFile("HeroTile.png")) {
            return EXIT_FAILURE;
        }
    } else if ( choosenCharacter == 1){
        if (!texturePlayer.loadFromFile("WitchTile.png")) {
            return EXIT_FAILURE;
        }
    }
    else if ( choosenCharacter == 2){
        if (!texturePlayer.loadFromFile("CoolHeroTile.png")) {
            return EXIT_FAILURE;
        }
    }

    // load NPC texture
    sf::Texture textureNPC;
    if (chooseNPC == 0) {
        if (!textureNPC.loadFromFile("Sheep.png")) {
            return EXIT_FAILURE;
        }
    }
    else if (chooseNPC == 1) {
        if (!textureNPC.loadFromFile("Dog.png")) {
            return EXIT_FAILURE;
        }
    }
    else if (chooseNPC == 2) {
        if (!textureNPC.loadFromFile("Cock.png")) {
            return EXIT_FAILURE;
        }
    }

    // load enemy texture
    sf::Texture textureAssassin;
    if (!textureAssassin.loadFromFile("Assassin.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture textureDarkLord;
    if (!textureDarkLord.loadFromFile("DarkLord.png")) {
        return EXIT_FAILURE;
    }

    sf::Texture textureChaos;
    if (!textureChaos.loadFromFile("ChaosKnight.png")) {
        return EXIT_FAILURE;
    }

    sf::Texture textureChimera;
    if (!textureChimera.loadFromFile("Chimera.png")) {
        return EXIT_FAILURE;
    }

    sf::Texture textureZombie;
    if (!textureZombie.loadFromFile("Zombie.png")) {
        return EXIT_FAILURE;
    }

    // load fireball texture
    sf::Texture textureFireBall;
    if (!textureFireBall.loadFromFile("fireball.png")) {
        return EXIT_FAILURE;
    }

    // load coin texture
    sf::Texture textureCoin;
    if (!textureCoin.loadFromFile("coin.png")) {
        return EXIT_FAILURE;
    }

    // load profile texture
    sf::Texture textureProfile;
    if (!textureProfile.loadFromFile("Head.png")) {
        return EXIT_FAILURE;
    }

    // load name texture
    sf::Texture textureName;
    if (!textureName.loadFromFile("Name.png")) {
        return EXIT_FAILURE;
    }

    // load heart texture
    sf::Texture textureHeart;
    if (!textureHeart.loadFromFile("Hearts.png")) {
        return EXIT_FAILURE;
    }

    // load experience texture
    sf::Texture textureExp;
    if (!textureExp.loadFromFile("Experience.png")) {
        return EXIT_FAILURE;
    }

    // load money texture
    sf::Texture textureMoney;
    if (!textureMoney.loadFromFile("Money.png")) {
        return EXIT_FAILURE;
    }

    // load Sword texture
    sf::Texture textureSword;
    if (!textureSword.loadFromFile("Sword48.png")) {
        return EXIT_FAILURE;
    }

    // load Stick texture
    sf::Texture textureStick;
    if (!textureStick.loadFromFile("Catalyst48.png")) {
        return EXIT_FAILURE;
    }

    // load Axe texture
    sf::Texture textureAxe;
    if (!textureAxe.loadFromFile("Axe48.png")) {
        return EXIT_FAILURE;
    }

    // load weapon texture
    sf::Texture textureWeapon;
    if (!textureWeapon.loadFromFile("WeaponsSheet.png")) {
        return EXIT_FAILURE;
    }

    // load potion texture
    sf::Texture texturePotion;
    if (!texturePotion.loadFromFile("PotionsSheet.png")) {
        return EXIT_FAILURE;
    }

    // load scroll texture
    sf::Texture textureScroll;
    if (!textureScroll.loadFromFile("Scrolls.png")) {
        return EXIT_FAILURE;
    }

    // Load music
    sf::Music music;
    if (!music.openFromFile("Elite4Cut.ogg")) {
        return EXIT_FAILURE;
    }

    // Weapons
    Weapon sword(2, "sword");
    Weapon axe(100, "axe");
    Weapon stick(1, "stick");

    // Potions
    Potion redPotion(8);
    Potion bluePotion(4);
    Potion greenPotion(1);

    // Play music
    music.play();
    music.setLoop(true);
    music.setVolume(20);

    // Sound effects
    sf::SoundBuffer bufferShot;
    if (!bufferShot.loadFromFile("shot.ogg"))
        return -1;
    sf::Sound soundShot;
    soundShot.setBuffer(bufferShot);
    soundShot.setVolume(10);

    Hero hero(8, 100, 80, str, 200, 1000, 0);

    hero.sprite.setTexture(texturePlayer);

    std::vector<Item> items;

    Item coinItem;
    coinItem.setType("coin");
    coinItem.rect.setSize(sf::Vector2f(32, 32));
    coinItem.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    coinItem.sprite.setTexture(textureCoin);

    Item swordItem;
    swordItem.setType("sword");
    swordItem.rect.setSize(sf::Vector2f(48, 48));
    swordItem.sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    swordItem.sprite.setTexture(textureSword);

    Item stickItem;
    stickItem.setType("stick");
    stickItem.rect.setSize(sf::Vector2f(48, 48));
    stickItem.sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    stickItem.sprite.setTexture(textureStick);

    Item axeItem;
    axeItem.setType("axe");
    axeItem.rect.setSize(sf::Vector2f(48, 48));
    axeItem.sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    axeItem.sprite.setTexture(textureAxe);

    NPC buddy(100, 20, 8, NPC::Animal, "Foffy", 0, false);
    buddy.rect.setPosition(200, 400);
    buddy.sprite.setTexture(textureNPC);

    // Vector of enemies
    std::vector<Mob> enemies;

    //First enemy
    Mob darkLord(8, 8, 10, Mob::Undead, 4, 2, false);
    darkLord.rect.setPosition(200, 400);
    darkLord.sprite.setTexture(textureDarkLord);
    enemies.push_back(darkLord);

    //Second enemy
    Mob assassin(40, 2, 9, Mob::Samurai, 2, 1, false);
    assassin.rect.setPosition(300, 500);
    assassin.sprite.setTexture(textureAssassin);
    enemies.push_back(assassin);

    //Third enemy
    Mob zombie(40, 2, 9, Mob::Samurai, 3, 1, false);
    zombie.rect.setPosition(700, 350);
    zombie.sprite.setTexture(textureZombie);
    enemies.push_back(zombie);

    //Fourth enemy
    Mob chimera(40, 2, 9, Mob::Samurai, 5, 1, false);
    chimera.rect.setPosition(500, 550);
    chimera.sprite.setTexture(textureChimera);
    enemies.push_back(chimera);

    //Fifth enemy
    Mob chaosKnight(40, 2, 9, Mob::Samurai, 10, 1, false);
    chaosKnight.rect.setPosition(500, 200);
    chaosKnight.sprite.setTexture(textureChaos);
    enemies.push_back(chaosKnight);

    // Vector of projectiles
    std::vector<Projectile> projectileArray;
    Projectile projectile;
    projectile.sprite.setTexture(textureFireBall);

    // Head sprite
    sf::Sprite headSprite;
    headSprite.setTexture(textureProfile);
    headSprite.setTextureRect(sf::IntRect(choosenCharacter * 150, 0, 150, 164));
    headSprite.setPosition(0, 0);

    // Name sprite
    sf::Sprite nameSprite;
    nameSprite.setTexture(textureName);
    nameSprite.setTextureRect(sf::IntRect(0, 0, 150, 54));
    nameSprite.setPosition(0, 164);

    // Hearts sprite
    sf::Sprite heartsSprite;
    heartsSprite.setTexture(textureHeart);
    heartsSprite.setTextureRect(sf::IntRect(0, 0, 150, 36));
    heartsSprite.setPosition(0, 218);

    // Experience sprite
    sf::Sprite expSprite;
    expSprite.setTexture(textureExp);
    expSprite.setTextureRect(sf::IntRect(0, 0, 150, 59));
    expSprite.setPosition(0, 254);

    // Money sprite
    sf::Sprite moneySprite;
    moneySprite.setTexture(textureMoney);
    moneySprite.setTextureRect(sf::IntRect(0, 0, 150, 61));
    moneySprite.setPosition(0, 313);

    // Weapons sprite
    sf::Sprite weaponsSprite;
    weaponsSprite.setTexture(textureWeapon);
    weaponsSprite.setTextureRect(sf::IntRect(0, 0, 150, 76));
    weaponsSprite.setPosition(0, 374);

    // Potions sprite
    sf::Sprite potionsSprite;
    potionsSprite.setTexture(texturePotion);
    potionsSprite.setTextureRect(sf::IntRect(0, 0, 150, 70));
    potionsSprite.setPosition(0, 450);

    // Scrolls sprite
    sf::Sprite scrollsSprite;
    scrollsSprite.setTexture(textureScroll);
    scrollsSprite.setTextureRect(sf::IntRect(0, 0, 150, 80));
    scrollsSprite.setPosition(0, 520);

    // Money text
    hero.text.setFont(font);
    hero.text.setString(std::to_string(hero.getMoney()));
    hero.text.setCharacterSize(30);
    hero.text.setColor(sf::Color::Red);
    hero.text.setPosition(80, 315);

    switch (choosenCharacter) {
        case 0:
            hero.setWeapon(&sword);
            weaponsSprite.setTextureRect(sf::IntRect(0, 76, 150, 76));
            hero.setPotion(&bluePotion);
            potionsSprite.setTextureRect(sf::IntRect(0, 280, 150, 70));
            hero.setChangeToSword(true);
            break;
        case 1:
            hero.setWeapon(&stick);
            weaponsSprite.setTextureRect(sf::IntRect(0, 152, 150, 76));
            hero.setPotion(&redPotion);
            potionsSprite.setTextureRect(sf::IntRect(0, 420, 150, 70));
            hero.setChangeToStick(true);
            break;
        case 2:
            hero.setWeapon(&axe);
            weaponsSprite.setTextureRect(sf::IntRect(0, 228, 150, 76));
            hero.setPotion(&greenPotion);
            potionsSprite.setTextureRect(sf::IntRect(0, 210, 150, 70));
            hero.setChangeToAxe(true);
            break;
    }

    // Set Hearts and Exp sprites
    hero.setHeartsSprite(heartsSprite);
    hero.setExpSprite(expSprite);
    hero.setWeaponSprite(weaponsSprite);

    // Define the level with an array of tile indices
    const int levelBackground[] =
            {
                    1044, 1044, 1044, 1044, 1052, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1053, 1054,
                    erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 849, 850, 850, 850, 850, 850, 850, 850, 850, 851, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 857, 857, 857, 857, 857, 857, 857, 857, 853, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 857, 855, 855, 855, 855, 855, 855, 855, 856, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
                    erba, erba, erba, erba, erba, erba, 852, 853, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba, erba,
            };

    // create the tilemap from the level definition
    TileMap mapBackground;
    if (!mapBackground.load("TileMap.png", sf::Vector2u(48, 48), levelBackground, 19, 13))
        return -1;

    const int levelVisible[] =
            {
                    trsp, trsp, trsp, trsp, trsp, trsp, 496, trsp, trsp, 484, trsp, trsp, 460, trsp, 497, trsp, trsp, 460, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 1080, trsp, trsp, trsp, 609, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 474, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, 1081, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 514, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 563, trsp, trsp, trsp, trsp, 1110, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 603, trsp, trsp, trsp, trsp, 1109, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, 571, trsp, trsp, 839, trsp, trsp, trsp, 744, 745, 746, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, 747, 748, 749, trsp, trsp, trsp, trsp,
                    trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp, trsp,
            };

    // create the tilemap from the level definition
    TileMap mapVisible;
    if (!mapVisible.load("TileMap.png", sf::Vector2u(48, 48), levelVisible, 19, 13))
        return -1;

    ExperienceBar experienceBar(&hero);
    HealthBar healthBar(&hero);
    MoneyBar moneyBar(&hero);
    WeaponBar weaponBar(&hero);

    // run the main loop
    while (window.isOpen()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // Should create a function to handle that?
        if (hero.rect.getPosition().x + 24 > screenDimension.x / 2)
            position.x = hero.rect.getPosition().x + 24;
        if (hero.rect.getPosition().y + 24 > screenDimension.y / 2)
            position.y = hero.rect.getPosition().y + 24;
        if (hero.rect.getPosition().x + viewSize.x / 2 > 888)
            position.x = 912 - (viewSize.x / 2);
        if (hero.rect.getPosition().y + viewSize.y / 2 > 600)
            position.y = 624 - (viewSize.y / 2);

        view.setCenter(position);

        window.setView(view);

        window.clear();

        // draw the map
        window.draw(mapBackground);
        window.draw(mapVisible);

        sf::Time elapsedProjectile = clockProjectile.getElapsedTime();

        sf::Time elapsedAngry = clockAngry.getElapsedTime();
        sf::Time elapsedNPC = clockNPC.getElapsedTime();

        int enemyCounter = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            hero.setHasSword(true);
            startAnimation = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            if (gameState == Playing) {
                gameState = Pause;
            } else if (gameState == Pause) {
                gameState = Playing;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            hero.setHealth(hero.getHealth() - 1);
            if (hero.getHealth() < 1) {
                hero.setHealth(8);
            }
            hero.notify();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            hero.setExp(hero.getExp() + 1);
            if (hero.getExp() > 19) {
                hero.setExp(0);
            }
            hero.notify();
        }

        if (gameState == Playing) {
            // Weapon Animation
            if (startAnimation) {
                if (!isAnimating) {
                    hero.useWeapon();
                    isAnimating = true;
                    halfAnimation = true;
                } else {
                    if (halfAnimation) {
                        hero.hit();
                        halfAnimation = false;
                        isAnimating = false;
                        startAnimation = false;
                    }
                }
            }

            // Enemies attack
            strategy.EnemyAttack(enemies, elapsedAngry, clockAngry, projectile, hero, soundShot, projectileArray);

            hero.update();
            hero.moveSprite(levelVisible);

            if (elapsedProjectile.asSeconds() >= 0.25) {
                clockProjectile.restart();
                strategy.HeroShot(hero, soundShot, projectileArray, projectile);
            }

            // NPC attack
            strategy.NPCAttack(buddy, elapsedNPC, clockNPC, projectile, enemies, soundShot, projectileArray);

            // Check projectile-enemy collision
            strategy.Projectile_EnemyCollision(enemies, projectile, projectileArray, items, coinItem);

            // Check weapons' collisions
            strategy.WeaponsCollisions(enemies, hero, isAnimating, items, coinItem, swordItem, stickItem, axeItem);

            // Check Hero - Item collisions
            strategy.Hero_ItemsCollisions(hero, items);

            // Collisions between NPC & enemies
            strategy.NPC_EnemiesCollisions(buddy, enemies);

            //Collisions between enemies
            strategy.EnemiesCollisions(enemies);

            // Hero - enemy projectile collisions
            strategy.Hero_ProjectileCollisions(projectileArray, hero);

            // Change weapon
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B) && hero.isChangeToSword())
                hero.setWeapon(&sword);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::N) && hero.isChangeToStick())
                hero.setWeapon(&stick);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M) && hero.isChangeToAxe())
                hero.setWeapon(&axe);

            // Update enemies
            for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
                enemies[enemyCounter].update();
                enemies[enemyCounter].moveSprite(levelVisible);
                enemyCounter++;
            }

            // Update NPC
            buddy.update();
            buddy.moveSprite(levelVisible);
        }

        // Draw Player
        window.draw(hero.sprite);

        // Draw FireBalls
        int counter = 0;
        for (auto itr = projectileArray.begin(); itr != projectileArray.end(); itr++) {
            projectileArray[counter].update();
            window.draw(projectileArray[counter].sprite);
            counter++;
        }

        // Draw Enemies
        enemyCounter = 0;
        for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
            window.draw(enemies[enemyCounter].sprite);
            enemyCounter++;
        }

        // Draws items
        counter = 0;
        for (auto itr = items.begin(); itr != items.end(); itr++) {
            items[counter].sprite.setPosition(items[counter].rect.getPosition());
            window.draw(items[counter].sprite);
            counter++;
        }

        // Draw NPC
        window.draw(buddy.sprite);

        // Delete dead enemies
        counter = 0;
        for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
            if (!enemies[counter].isAlive()) {
                enemies.erase(itr);
                hero.setExp(hero.getExp() + 1);
                if (hero.getExp() > 19) {
                    hero.setExp(0);
                }
                hero.notify();
                break;
            }
            counter++;
        }

        // Delete tooken items
        counter = 0;
        for (auto itr = items.begin(); itr != items.end(); itr++) {
            if (items[counter].isTooken()) {
                items.erase(itr);
                hero.setMoney(hero.getMoney()+ items[counter].getValue());
                hero.notify();
                break;
            }
            counter++;
        }

        window.setView(window.getDefaultView());

        // Draw Status Bar
        window.draw(headSprite);
        window.draw(nameSprite);
        window.draw(hero.getHeartsSprite());
        window.draw(hero.getExpSprite());
        window.draw(moneySprite);
        window.draw(hero.getWeaponSprite());
        window.draw(potionsSprite);
        window.draw(scrollsSprite);
        window.draw(name);
        window.draw(hero.text);

        // Delete projectiles
        counter = 0;
        for (auto itr = projectileArray.begin(); itr != projectileArray.end(); itr++) {
            if (projectileArray[counter].isDestroy()) {
                projectileArray.erase(itr);
                break;
            }
            counter++;
        }

        window.display();

        /*if ( hero.getHealth() <= 0){
            settings.GameOver(window);
            return 0;
        }*/
    }

    return 0;
}