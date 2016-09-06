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
#include "Game.h"

int main() {

    enum Gamestate {
        Initialize, Pause, Playing
    };

    Gamestate gameState = Initialize;

    Game game;
    Settings settings;
    Strategy strategy;

    // Screen dimesions
    sf::Vector2u screenDimension(800, 600);

    // Create the window
    sf::RenderWindow window(sf::VideoMode(screenDimension.x, screenDimension.y), "Videogame", sf::Style::None);

    // Center the window
    sf::Vector2i positionWindow((sf::VideoMode::getDesktopMode().width / 2) - screenDimension.x / 2,
                                (sf::VideoMode::getDesktopMode().height / 2) - screenDimension.y / 2);
    window.setPosition(positionWindow);
    window.setFramerateLimit(60);

    int choosenCharacter = 0;

    game.setFont();

    sf::Text name;
    name.setColor(sf::Color::Black);

    std::string str;

    int chooseNPC = 0;

    if (gameState == Initialize) {
        settings.showSplash(window);
        window.clear();
        settings.showOptions(window, choosenCharacter);
        settings.inputName(str, name, window, game.font, choosenCharacter);
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

    game.loadTextures(choosenCharacter, chooseNPC);

    // Load music & sound effects
    game.setMusic();

    // Set Hero
    Hero hero(8, 100, str, 200, 0);
    hero.sprite.setTexture(game.texturePlayer);

    // Enemies
    std::vector<Item> items;
    game.setItems();

    // NPC
    NPC buddy(100, 1);
    buddy.rect.setPosition(200, 400);
    buddy.sprite.setTexture(game.textureNPC);

    // Vector of enemies
    std::vector<Mob> enemies;
    game.setEnemies();
    enemies.push_back(game.darkLord);
    enemies.push_back(game.assassin);
    enemies.push_back(game.zombie);
    enemies.push_back(game.chimera);
    enemies.push_back(game.chaosKnight);

    // Vector of projectiles
    std::vector<Projectile> projectileArray;
    Projectile projectile;
    projectile.sprite.setTexture(game.textureFireBall);

    // Personalize Hero
    game.setSprites(choosenCharacter);
    game.setHeroText(hero);
    game.personalizeHero(hero, choosenCharacter);
    game.setHeroBar(hero);

    // Mappa Background
    TileMap mapBackground;
    if (!mapBackground.load("TileMap.png", sf::Vector2u(48, 48), game.levelBackground, 19, 13))
        return -1;

    // Mappa Visibile
    TileMap mapVisible;
    if (!mapVisible.load("TileMap.png", sf::Vector2u(48, 48), game.levelVisible, 19, 13))
        return -1;

    // Inizializza gli observer
    ExperienceBar experienceBar(&hero);
    HealthBar healthBar(&hero);
    MoneyBar moneyBar(&hero);
    WeaponBar weaponBar(&hero);
    PotionBar potionBar(&hero);

    // Inizializza valori bool per animazione spada
    bool isAnimating = false;
    bool startAnimation = false;
    bool halfAnimation = false;

    // MAIN LOOP
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // Setting View
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

        // Draw the map
        window.draw(mapBackground);
        window.draw(mapVisible);

        sf::Time elapsedProjectile = game.clockProjectile.getElapsedTime();
        sf::Time elapsedAngry = game.clockAngry.getElapsedTime();
        sf::Time elapsedNPC = game.clockNPC.getElapsedTime();

        int enemyCounter = 0;

        // Weapon Animation
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            startAnimation = true;
        }

        // Game in pause
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            if (gameState == Playing) {
                gameState = Pause;
            } else if (gameState == Pause) {
                gameState = Playing;
            }
        }

        // Use potions
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && hero.getPotion()->getUseTime() > 0) {
            hero.setHealth(hero.getHealth() + hero.getPotion()->getRecovery());
            if (hero.getHealth() > 8)
                hero.setHealth(8);
            hero.getPotion()->setUseTime(hero.getPotion()->getUseTime() - 1);
            hero.notify();
        }

        // Weapon Animation
        if (gameState == Playing) {
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
            strategy.EnemyAttack(enemies, elapsedAngry, game.clockAngry, projectile, hero, game.soundShot,
                                 projectileArray);

            hero.update();
            hero.moveSprite(game.levelVisible);

            if (elapsedProjectile.asSeconds() >= 0.25) {
                game.clockProjectile.restart();
                strategy.HeroShot(hero, game.soundShot, projectileArray, projectile);
            }

            // NPC attack
            strategy.NPCAttack(buddy, elapsedNPC, game.clockNPC, projectile, enemies, game.soundShot, projectileArray);

            // Check projectile-enemy collision
            strategy.Projectile_EnemyCollision(enemies, projectile, projectileArray, items, game.coinItem);

            // Check weapons' collisions
            strategy.WeaponsCollisions(enemies, hero, isAnimating, items, game.coinItem, game.swordItem, game.stickItem,
                                       game.axeItem);

            // Check Hero - Item collisions
            strategy.Hero_ItemsCollisions(hero, items);

            // Collisions between NPC & enemies
            strategy.NPC_EnemiesCollisions(buddy, enemies);

            //Collisions between enemies
            strategy.EnemiesCollisions(enemies);

            // Hero - enemy projectile collisions
            strategy.Hero_ProjectileCollisions(projectileArray, hero);

            // Change weapon
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && hero.isChangeToSword())
                hero.setWeapon(&(game.sword));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && hero.isChangeToStick())
                hero.setWeapon(&(game.stick));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && hero.isChangeToAxe())
                hero.setWeapon(&(game.axe));

            // Update enemies
            for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
                enemies[enemyCounter].update();
                enemies[enemyCounter].moveSprite(game.levelVisible);
                enemyCounter++;
            }

            // Update NPC
            buddy.update();
            buddy.moveSprite(game.levelVisible);
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
                hero.setMoney(hero.getMoney() + items[counter].getValue());
                hero.notify();
                break;
            }
            counter++;
        }

        window.setView(window.getDefaultView());

        // Draw Status Bar
        window.draw(game.headSprite);
        window.draw(game.nameSprite);
        window.draw(hero.getHeartsSprite());
        window.draw(hero.getExpSprite());
        window.draw(game.moneySprite);
        window.draw(hero.getWeaponSprite());
        window.draw(hero.getPotionsSprite());
        window.draw(game.scrollsSprite);
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

        // GAME OVER
        if (hero.getHealth() <= 0) {
            settings.GameOver(window);
            return 0;
        }
    }

    return 0;
}