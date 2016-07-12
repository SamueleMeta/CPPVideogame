#ifndef PROJECTVIDEOGAME_RANGEDWEAPON_H
#define PROJECTVIDEOGAME_RANGEDWEAPON_H

#include "Weapon.h"

class RangedWeapon : public Weapon {
public:
    RangedWeapon(int strgth, bool magic, bool pois, bool burn, int arrows, int prec, bool elfic) :
            Weapon(strgth, magic, pois, burn), arrows(arrows), precision(prec), isElfic(elfic){}

    ~RangedWeapon() {}


    int getArrows() const {
        return arrows;
    }

    void setArrows(int arrows) {
        RangedWeapon::arrows = arrows;
    }

    int getPrecision() const {
        return precision;
    }

    void setPrecision(int precision) {
        RangedWeapon::precision = precision;
    }

    bool isIsElfic() const {
        return isElfic;
    }

    void setIsElfic(bool isElfic) {
        RangedWeapon::isElfic = isElfic;
    }

private:
    int arrows, precision;
    bool isElfic;
};

#endif //PROJECTVIDEOGAME_RANGEDWEAPON_H
