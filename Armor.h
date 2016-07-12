#ifndef PROJECTVIDEOGAME_ARMOR_H
#define PROJECTVIDEOGAME_ARMOR_H

class Armor {
public:
    Armor(int res, int swordR, int arrowR, bool isMagic, bool special) :
            resistence(res), swordR(swordR), arrowR(arrowR), magicR(isMagic), isSpecial(special){}

    virtual ~Armor() { }

    int getResistence() const {
        return resistence;
    }

    void setResistence(int resistence) {
        Armor::resistence = resistence;
    }

    int getSwordR() const {
        return swordR;
    }

    void setSwordR(int swordR) {
        Armor::swordR = swordR;
    }

    int getArrowR() const {
        return arrowR;
    }

    void setArrowR(int arrowR) {
        Armor::arrowR = arrowR;
    }

    bool isMagicR() const {
        return magicR;
    }

    void setMagicR(bool magicR) {
        Armor::magicR = magicR;
    }

    bool isIsSpecial() const {
        return isSpecial;
    }

    void setIsSpecial(bool isSpecial) {
        Armor::isSpecial = isSpecial;
    }

private:
    int resistence, swordR, arrowR;
    bool magicR, isSpecial;
};

#endif //PROJECTVIDEOGAME_ARMOR_H
