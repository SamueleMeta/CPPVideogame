#ifndef PROJECTVIDEOGAME_SCROLL_H
#define PROJECTVIDEOGAME_SCROLL_H

class Scroll {
public:
    Scroll(int cost, int damage, bool paralizing, bool tiring, bool blinding) :
            cost(cost), magicD(damage), isParalising(paralizing), isTiring(tiring), isBlinding(blinding) {}

    virtual ~Scroll() {}

    int getCost() const {
        return cost;
    }

    void setCost(int cost) {
        Scroll::cost = cost;
    }

    bool isIsParalising() const {
        return isParalising;
    }

    void setIsParalising(bool isParalising) {
        Scroll::isParalising = isParalising;
    }

    int getMagicD() const {
        return magicD;
    }

    void setMagicD(int magicD) {
        Scroll::magicD = magicD;
    }

    bool isIsTiring() const {
        return isTiring;
    }

    void setIsTiring(bool isTiring) {
        Scroll::isTiring = isTiring;
    }

    bool isIsBlinding() const {
        return isBlinding;
    }

    void setIsBlinding(bool isBlinding) {
        Scroll::isBlinding = isBlinding;
    }

private:
    int cost, magicD;
    bool isParalising, isTiring, isBlinding;
};

#endif //PROJECTVIDEOGAME_SCROLL_H
