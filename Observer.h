#ifndef PROJECTVIDEOGAME_OBSERVER_H
#define PROJECTVIDEOGAME_OBSERVER_H

#include <SFML/Graphics.hpp>

class Observer {
public:
    virtual ~Observer() {}

    virtual void update (int health, int exp, int money, sf::Sprite& Sprite) = 0;

    virtual void attach () = 0;

    virtual void detach () = 0;
};
#endif //PROJECTVIDEOGAME_OBSERVER_H
