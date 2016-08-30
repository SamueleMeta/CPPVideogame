#include <iostream>
#include "SFML/Graphics.hpp"
#include "Settings.h"

int Settings::showSplash(sf::RenderWindow &window) {
    sf::Texture splashTexture;
    if (!splashTexture.loadFromFile("SplashScreen3.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(splashTexture);

    window.draw(sprite);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::KeyPressed ||
                event.type == sf::Event::EventType::MouseButtonPressed)
                return 0;
        }
    }
}


int Settings::showOptions(sf::RenderWindow &window) {
    sf::Texture optionsTexture;
    if (!optionsTexture.loadFromFile("Choose.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(optionsTexture);
    window.draw(sprite);
    window.display();


    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Mouse::getPosition(window).x > 40 && sf::Mouse::getPosition(window).x < 184 &&
                    sf::Mouse::getPosition(window).y > 156 && sf::Mouse::getPosition(window).y < 300 &&
                    sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        return 0;
        }
    }

}
