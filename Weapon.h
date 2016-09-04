#ifndef PROJECTVIDEOGAME_WEAPON_H
#define PROJECTVIDEOGAME_WEAPON_H

class Weapon {
public:
    Weapon (int strngt, std::string type) : strength(strngt), type(type) {}

    virtual ~Weapon() {}

    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Weapon::strength = strength;
    }

protected:
    int strength;
    std::string type;
};

#endif //PROJECTVIDEOGAME_WEAPON_H
