#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Hero.h"

int main()
{
    sf::Vector2u screenDimension (1024, 768);

    // create the window
    sf::RenderWindow window(sf::VideoMode(screenDimension.x, screenDimension.y), "Tilemap");

    // center camera
    sf::View view;
    view.reset(sf::FloatRect(0,0, screenDimension.x, screenDimension.y));

    view.setViewport(sf::FloatRect(0,0, 1.0f, 1.0f));

    sf::Vector2f position (screenDimension.x/2, screenDimension.y/2);

    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("player.png")) {
        return EXIT_FAILURE;
    }

    Hero hero(100, 100, 80, "Castoro", 0, 1000, 0, Hero::Elf, Hero::Warrior);
    hero.sprite.setTexture(texturePlayer);

    // define the level with an array of tile indices

    const int levelBackground[] =
            {
                    6, 6, 6, 6, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
                    48, 144, 144, 144, 144, 144, 144, 144, 49, 0, 0, 0, 0, 0, 0, 0, 0, 49,
                    48, 144, 145, 144, 144, 144, 144, 144, 49, 3, 3, 3, 3, 3, 3, 3, 1, 49,
                    48, 144, 160, 144, 144, 144, 144, 144, 49, 0, 1, 1, 1, 0, 0, 0, 1, 49,
                    48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
                    48, 0, 1, 0, 3, 0, 2, 2, 49, 0, 1, 1, 1, 1, 2, 0, 1, 49,
                    48, 0, 1, 0, 3, 0, 2, 2, 49, 0, 1, 1, 1, 1, 1, 1, 1, 49,
                    48, 0, 1, 0, 3, 2, 2, 2, 49, 0, 0, 0, 1, 1, 1, 1, 1, 49,
                    48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
            };


    const int level[] =
            {
                    48, 141, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
                    48, 144, 144, 144, 144, 144, 144, 144, 49, -1, -1, -1, -1, -1, -1, -1, -1, 49,
                    48, 144, 145, 144, 144, 144, 144, 144, 49, 3, 3, 3, 3, 3, 3, 3, 1, 49,
                    48, 144, 160, 144, 144, 144, 144, 144, 49, 0, 1, 1, 1, 0, 0, 0, 1, 49,
                    48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
                    48, 0, 1, 0, 3, 0, 2, 2, 49, 0, 1, 1, 1, 1, 2, 0, 1, 49,
                    48, 0, 1, 0, 3, 0, 2, 2, 49, 0, 1, 1, 1, 1, 1, 1, 1, 49,
                    48, 0, 1, 0, 3, 2, 2, 2, 49, 0, 0, 0, 1, 1, 1, 1, 1, 49,
                    48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
            };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("Dungeon_A2.png", sf::Vector2u(48, 48), level, 18, 9))
        return -1;

    TileMap mapB;
    if (!mapB.load("Outside_A2.png", sf::Vector2u(48, 48), levelBackground, 18, 9))
        return -1;

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

        if(hero.rect.getPosition().x + 24 > screenDimension.x/2)
            position.x = hero.rect.getPosition().x + 24;
        if(hero.rect.getPosition().y + 24 > screenDimension.y/2)
            position.y = hero.rect.getPosition().y + 24;

        view.setCenter(position);

        window.setView(view);

        // draw the map
        window.clear();
        window.draw(mapB);
        window.draw(map);

        // Update Player
        hero.update();
        hero.moveSprite();

        // Draw Player
        window.draw(hero.sprite);
        //window.draw(Player1.rect);
        window.display();
    }

    return 0;
}