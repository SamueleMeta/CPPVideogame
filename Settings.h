#ifndef PROJECTVIDEOGAME_SETTINGS_H
#define PROJECTVIDEOGAME_SETTINGS_H

#include <SFML/Graphics.hpp>

class Settings {
public:
    int showSplash(sf::RenderWindow &window);

    int showOptions(sf::RenderWindow &window, int &choosen);

    int inputName(std::string &str, sf::Text &name, sf::RenderWindow &window, sf::Font &font, int const choosen);

    int chooseNPC(sf::RenderWindow &window, int &choose);

    int GameOver(sf::RenderWindow &window);
};


#endif //PROJECTVIDEOGAME_SETTINGS_H
