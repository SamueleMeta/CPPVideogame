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


int Settings::showOptions(sf::RenderWindow &window, int &choosen) {
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
            if (sf::Mouse::getPosition(window).x > 40 && sf::Mouse::getPosition(window).x < 185 &&
                sf::Mouse::getPosition(window).y > 156 && sf::Mouse::getPosition(window).y < 300 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen = 0;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 329 && sf::Mouse::getPosition(window).x < 473 &&
                     sf::Mouse::getPosition(window).y > 156 && sf::Mouse::getPosition(window).y < 300 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen = 1;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 615 && sf::Mouse::getPosition(window).x < 761 &&
                     sf::Mouse::getPosition(window).y > 156 && sf::Mouse::getPosition(window).y < 300 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choosen = 2;
                return 0;
            }
        }
    }

}

int Settings::inputName(std::string &str, sf::Text &name, sf::RenderWindow &window, sf::Font &font, int const choosen) {
    sf::Texture nameTexture;
    if (!nameTexture.loadFromFile("InsertName.png")){
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(nameTexture);

    sf::Texture PGTexture;
    if (!PGTexture.loadFromFile("144Portrait.png")){
        return EXIT_FAILURE;
    }
    sf::Sprite PGSprite;
    PGSprite.setTexture(PGTexture);
    PGSprite.setTextureRect(sf::IntRect(choosen * 144, 0, 144, 144));
    PGSprite.setPosition(62, 228);

    while (true) {
        sf::Event inputName;
        while (window.pollEvent(inputName)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                return 0;
            if (inputName.type == sf::Event::TextEntered) {
                if (inputName.text.unicode == '\b') {
                    if (str.size() > 0)
                        str.erase(str.size() - 1, 1);
                }
                else if (inputName.text.unicode < 128 && str.size() < 10)
                    str += static_cast<char>(inputName.text.unicode);
            }
            name.setString(str);
            name.setFont(font);
            name.setPosition(272, 330);
        }
        window.clear();
        window.draw(sprite);
        window.draw(PGSprite);
        window.draw(name);
        window.display();
    }
}

int Settings::chooseNPC(sf::RenderWindow &window, int &choose) {
    sf::Texture NPCTexture;
    if (!NPCTexture.loadFromFile("alternativa.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(NPCTexture);
    window.draw(sprite);
    window.display();

    sf::Event event;
    while (true) {
        while (window.pollEvent(event)) {
            if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 800 &&
                sf::Mouse::getPosition(window).y > 162 && sf::Mouse::getPosition(window).y < 308 &&
                sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choose = 0;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 800 &&
                     sf::Mouse::getPosition(window).y > 308 && sf::Mouse::getPosition(window).y < 454 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choose = 1;
                return 0;
            }
            else if (sf::Mouse::getPosition(window).x > 0 && sf::Mouse::getPosition(window).x < 800 &&
                     sf::Mouse::getPosition(window).y > 454 && sf::Mouse::getPosition(window).y < 600 &&
                     sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                choose = 2;
                return 0;
            }
        }
    }
}

int Settings::GameOver(sf::RenderWindow &window) {
    sf::Texture GOTexture;
    if (!GOTexture.loadFromFile("GameOver.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(GOTexture);

    window.clear();
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