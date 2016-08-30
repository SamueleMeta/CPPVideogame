#ifndef PROJECTVIDEOGAME_SUBJECT_H
#define PROJECTVIDEOGAME_SUBJECT_H

#include "SFML/Graphics.hpp"
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}

    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify(sf::Sprite& Sprite) = 0;
};
#endif //PROJECTVIDEOGAME_SUBJECT_H
