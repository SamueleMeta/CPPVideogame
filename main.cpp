#include <iostream>
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include "Hero.h"

int main()
{
    sf::Vector2u screenDimension (600, 400);

    // create the window
    sf::RenderWindow window(sf::VideoMode(screenDimension.x, screenDimension.y), "Videogame");

    // center camera
    sf::View view;
    view.reset(sf::FloatRect(0,0, screenDimension.x, screenDimension.y));
    view.setViewport(sf::FloatRect(0,0, 1.0f, 1.0f));
    sf::Vector2f position (screenDimension.x/2, screenDimension.y/2);
    sf::Vector2f viewSize = view.getSize();

    // load player texture
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("player.png")) {
        return EXIT_FAILURE;
    }

    Hero hero(100, 100, 80, "Castoro", 0, 1000, 0, Hero::Elf, Hero::Warrior);
    hero.sprite.setTexture(texturePlayer);

    // define the level with an array of tile indices
    const int level[] =
            {
                    48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
                    48, 144, 144, 144, 144, 144, 144, 144, 49, 1, 1, 1, 1, 1, 1, 1, 1, 49,
                    48, 144, 144, 144, 144, 144, 144, 144, 49, 1, 1, 1, 1, 1, 1, 1, 1, 49,
                    48, 144, 144, 144, 144, 144, 144, 144, 49, 1, 1, 1, 1, 1, 1, 1, 1, 49,
                    48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
                    48, 1, 1, 1, 1, 1, 1, 1, 49, 144, 144, 144, 144, 144, 144, 144, 144, 49,
                    48, 1, 1, 1, 1, 1, 1, 1, 49, 144, 144, 144, 144, 144, 144, 144, 144, 49,
                    48, 1, 1, 1, 1, 1, 1, 1, 49, 144, 144, 144, 144, 144, 144, 144, 144, 49,
                    48, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49,
            };

    // create the tilemap from the level definition
    TileMap map;
    if (!map.load("Dungeon_A2.png", sf::Vector2u(48, 48), level, 18, 9))
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

        // Should create a function to handle that?
        if(hero.rect.getPosition().x + 24 > screenDimension.x/2)
            position.x = hero.rect.getPosition().x + 24;
        if(hero.rect.getPosition().y + 24 > screenDimension.y/2)
            position.y = hero.rect.getPosition().y + 24;
        if(hero.rect.getPosition().x + viewSize.x/2 > 840)
            position.x = 864 - (viewSize.x/2);
        if(hero.rect.getPosition().y + viewSize.y/2 > 408)
            position.y = 432 - (viewSize.y/2);


        view.setCenter(position);

        window.setView(view);

        window.clear();

        // draw the map
        window.draw(map);

        // Update Player
        hero.update();
        hero.moveSprite();

        // Draw Player
        window.draw(hero.sprite);
        window.display();
    }

    return 0;
}