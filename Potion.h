#ifndef PROJECTVIDEOGAME_POTION_H
#define PROJECTVIDEOGAME_POTION_H

class Potion {
public:
    Potion (int rec) : recovery (rec) { };

    virtual ~Potion() { }


    int getRecovery() const {
        return recovery;
    }

    void setRecovery(int recovery) {
        Potion::recovery = recovery;
    }

private:
    int recovery;
};

#endif //PROJECTVIDEOGAME_POTION_H
