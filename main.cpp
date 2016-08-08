#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TileMap.h"
#include "Hero.h"
#include "Mob.h"
#include "Projectile.h"

int main() {

    const int lakeSX = 3;
    const int lake = 4;
    const int lakeDX = 5;
    const int transp = 8;

    sf::Vector2u screenDimension (800, 600);

    // create the window
    sf::RenderWindow window(sf::VideoMode(screenDimension.x, screenDimension.y), "Videogame");

    // center camera
    sf::View view;
    view.reset(sf::FloatRect(0,0, screenDimension.x, screenDimension.y));
    view.setViewport(sf::FloatRect(0,0, 1.0f, 1.0f));
    sf::Vector2f position (screenDimension.x/2, screenDimension.y/2);
    sf::Vector2f viewSize = view.getSize();

    // Clock
    sf::Clock clock;

    // load player texture
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("WandererMale.png")) {
        return EXIT_FAILURE;
    }

    // load enemy texture
    sf::Texture textureAssassin;
    if(!textureAssassin.loadFromFile("Assassin.png")) {
        return EXIT_FAILURE;
    }
    sf::Texture textureDarkLord;
    if(!textureDarkLord.loadFromFile("DarkLord.png")) {
        return EXIT_FAILURE;
    }

    // load fireball texture
    sf::Texture textureFireBall;
    if (!textureFireBall.loadFromFile("fireball.png")) {
        return EXIT_FAILURE;
    }

    // load healthbar texture
    sf::Texture textureHealthbar;
    if (!textureHealthbar.loadFromFile("healthBar.png")) {
        return EXIT_FAILURE;
    }

    // Load music
    sf::Music music;
    if (!music.openFromFile("music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play music
    music.play();
    music.setLoop(true);

    // Sound effects
    sf::SoundBuffer bufferShot;
    if (!bufferShot.loadFromFile("shot.ogg"))
        return -1;
    sf::Sound soundShot;
    soundShot.setBuffer(bufferShot);

    Hero hero(100, 100, 80, "Castoro", 0, 1000, 0, Hero::Elf, Hero::Warrior);
    hero.sprite.setTexture(texturePlayer);

    // Vector of enemies
    std::vector<Mob> enemies;

    //First enemy
    Mob darkLord(60, 8, 10, Mob::Undead, 0.5, 2, false);
    darkLord.rect.setPosition(200, 400);
    darkLord.sprite.setTexture(textureDarkLord);
    enemies.push_back(darkLord);

    //Second enemy
    Mob assassin(40, 2, 9, Mob::Samurai, 0.5, 1, false);
    assassin.rect.setPosition(300, 400);
    assassin.sprite.setTexture(textureAssassin);
    enemies.push_back(assassin);

    // Vector of projectiles
    std::vector<Projectile> projectileArray;
    Projectile projectile;
    projectile.sprite.setTexture(textureFireBall);

    // Health bar
    sf::Sprite healthBar;
    healthBar.setTexture(textureHealthbar);
    healthBar.setTextureRect(sf::IntRect(0, 0, 130, 20));
    healthBar.setPosition(0,0);

    // Define the level with an array of tile indices
    const int levelBackground[] =
            {
                    lakeSX, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lake, lakeDX,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 0, 0, 0, 0, 0, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 0, 0, 0, 0, 0, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
            };

    // create the tilemap from the level definition
    TileMap mapBackground;
    if (!mapBackground.load("SuperTile.png", sf::Vector2u(48, 48), levelBackground, 19, 13))
        return -1;

    const int levelVisible[] =
            {
                    transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp, transp,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 11, 12, 23, 23, 23, 23, 6, 23, 23, 23,
                    23, 23, 6, 23, 23, 10, 23, 23, 23, 13, 14, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 9, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 10, 23, 23, 6, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 9, 23, 23, 23, 23,
                    23, 23, 11, 12, 0, 0, 0, 0, 0, 0, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 13, 14, 0, 0, 0, 0, 0, 0, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 10, 10, 10, 23, 23,
                    23, 23, 23, 6, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 9, 9, 9, 23, 23,
                    23, 23, 23, 23, 23, 23, 23, 23, 23, 1, 2, 23, 23, 23, 23, 23, 23, 23, 23,
            };

    // create the tilemap from the level definition
    TileMap mapVisible;
    if (!mapVisible.load("SuperTile.png", sf::Vector2u(48, 48), levelVisible, 19, 13))
        return -1;

    int lifecounter = 1;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }


        // Should create a function to handle that?
        if(hero.rect.getPosition().x + 24 > screenDimension.x/2)
            position.x = hero.rect.getPosition().x + 24;
        if(hero.rect.getPosition().y + 24 > screenDimension.y/2)
            position.y = hero.rect.getPosition().y + 24;
        if(hero.rect.getPosition().x + viewSize.x/2 > 888)
            position.x = 912 - (viewSize.x/2);
        if(hero.rect.getPosition().y + viewSize.y/2 > 600)
            position.y = 624 - (viewSize.y/2);


        view.setCenter(position);

        window.setView(view);

        window.clear();

        sf::Time elapsed = clock.getElapsedTime();

        if(elapsed.asSeconds() >= 0.25) {
            clock.restart();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                projectile.rect.setPosition(
                        hero.rect.getPosition().x + hero.rect.getSize().x / 2 - projectile.rect.getSize().x / 2,
                        hero.rect.getPosition().y + hero.rect.getSize().y / 2 - projectile.rect.getSize().y / 2);
                projectile.setDirection(hero.getDirection());
                projectileArray.push_back(projectile);
                healthBar.setTextureRect(sf::IntRect(0, lifecounter * 20, 130, 20));
                lifecounter++;
                soundShot.play();
            }
        }

        int pcounter = 0;
        for(auto itr = projectileArray.begin(); itr != projectileArray.end(); itr++){
            int ecounter = 0;
            for(auto itr2 = enemies.begin(); itr2 != enemies.end(); itr2++) {
                if (projectileArray[pcounter].rect.getGlobalBounds().intersects(enemies[ecounter].rect.getGlobalBounds())) {
                    enemies[ecounter].setAlive(false);
                    projectileArray[pcounter].setDestroy(true);
                }

            }
            pcounter++;
        }

        // draw the map
        window.draw(mapBackground);
        window.draw(mapVisible);

        // draw health bar
        window.draw(healthBar);

        // Update Player
        hero.update();
        hero.moveSprite(levelVisible);

        // Update Enemies
        int enemyCounter = 0;
        for(auto itr = enemies.begin(); itr != enemies.end(); itr++){
            enemies[enemyCounter].update();
            enemies[enemyCounter].moveSprite(levelVisible);
            enemyCounter++;
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
        for(auto itr = enemies.begin(); itr != enemies.end(); itr++){
            window.draw(enemies[enemyCounter].sprite);
            enemyCounter++;
        }

        // Delete dead enemies
        counter = 0;
        for (auto itr = enemies.begin(); itr != enemies.end(); itr++) {
            if (enemies[counter].isAlive() == false) {
                enemies.erase(itr);
                break;
            }
            counter++;
        }

        // Delete projectiles
        counter = 0;
        for (auto itr = projectileArray.begin(); itr != projectileArray.end(); itr++) {
            if (projectileArray[counter].isDestroy() == true) {
                projectileArray.erase(itr);
                break;
            }
            counter++;
        }

        window.display();
    }

    return 0;
}
