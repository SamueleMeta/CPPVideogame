#ifndef PROJECTVIDEOGAME_POTION_H
#define PROJECTVIDEOGAME_POTION_H

class Potion {
public:
    Potion (int rec, int uses) : recovery (rec), useTime(uses) { };

    virtual ~Potion() { }


    int getRecovery() const {
        return recovery;
    }

    void setRecovery(int recovery) {
        Potion::recovery = recovery;
    }

    int getUseTime() const {
        return useTime;
    }

    void setUseTime(int useTime) {
        Potion::useTime = useTime;
    }

private:
    int recovery;
    int useTime;
};

#endif //PROJECTVIDEOGAME_POTION_H
