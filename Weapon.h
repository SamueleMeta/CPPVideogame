#ifndef PROJECTVIDEOGAME_WEAPON_H
#define PROJECTVIDEOGAME_WEAPON_H

class Weapon {
public:
    Weapon(int strngth, bool magic, bool poisoned, bool burning) :
            strength(strngth), isMagic(magic), isPoisoned(poisoned), isBurning(burning){}

    virtual ~Weapon() {}


    int getStrength() const {
        return strength;
    }

    void setStrength(int strength) {
        Weapon::strength = strength;
    }

    bool isIsBurning() const {
        return isBurning;
    }

    void setIsBurning(bool isBurning) {
        Weapon::isBurning = isBurning;
    }

    bool isIsPoisoned() const {
        return isPoisoned;
    }

    void setIsPoisoned(bool isPoisoned) {
        Weapon::isPoisoned = isPoisoned;
    }

    bool isIsMagic() const {
        return isMagic;
    }

    void setIsMagic(bool isMagic) {
        Weapon::isMagic = isMagic;
    }

protected:
    int strength;
    bool isMagic, isPoisoned, isBurning;
};

#endif //PROJECTVIDEOGAME_WEAPON_H
