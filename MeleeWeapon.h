#ifndef PROJECTVIDEOGAME_MELEEWEAPON_H
#define PROJECTVIDEOGAME_MELEEWEAPON_H

#include "Weapon.h"

class MeleeWeapon : public Weapon {
public:
    MeleeWeapon(int strght, bool magic, bool pois, bool burn, int strike, int slash, int thrust, bool daedric) :
            Weapon(strght, magic, pois, burn), strikeD(strike), slashD(slash), thrustD(thrust), isDaedric(daedric) {}

    ~MeleeWeapon() {}

    int getStrikeD() const {
        return strikeD;
    }

    void setStrikeD(int strikeD) {
        MeleeWeapon::strikeD = strikeD;
    }

    int getSlashD() const {
        return slashD;
    }

    void setSlashD(int slashD) {
        MeleeWeapon::slashD = slashD;
    }

    int getThrustD() const {
        return thrustD;
    }

    void setThrustD(int thrustD) {
        MeleeWeapon::thrustD = thrustD;
    }

    bool isIsValirian() const {
        return isDaedric;
    }

    void setIsValirian(bool isValirian) {
        MeleeWeapon::isDaedric = isValirian;
    }

private:
    int strikeD, slashD, thrustD;
    bool isDaedric;
};

#endif //PROJECTVIDEOGAME_MELEEWEAPON_H
