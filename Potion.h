#ifndef PROJECTVIDEOGAME_POTION_H
#define PROJECTVIDEOGAME_POTION_H

class Potion {
public:
    Potion(int health, int energy, int strength, bool special) :
            healthR(health), energyR(energy), strengthR(strength), isStrong(special) { };

    virtual ~Potion() { }


    int getHealthR() const {
        return healthR;
    }

    void setHealthR(int healthR) {
        Potion::healthR = healthR;
    }

    int getEnergyR() const {
        return energyR;
    }

    void setEnergyR(int energyR) {
        Potion::energyR = energyR;
    }

    int getStrengthR() const {
        return strengthR;
    }

    void setStrengthR(int strengthR) {
        Potion::strengthR = strengthR;
    }

    bool isIsStrong() const {
        return isStrong;
    }

    void setIsStrong(bool isStrong) {
        Potion::isStrong = isStrong;
    }

private:
    int healthR, energyR, strengthR;
    bool isStrong;
};

#endif //PROJECTVIDEOGAME_POTION_H
