#ifndef KEEPER_H
#define KEEPER_H

#include "classes.h"

class Keeper{
public:
    Keeper(int capacity);
    ~Keeper();

    void addInstrument(Base* instrument);
    void removeInstrument(int index);
    void displayAllInstruments();
    int getNumInstruments();
    Base* getInstrument(int index);

private:
    Base** instruments;
    int capacity;
    int numInstruments;
};

#endif