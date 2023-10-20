#ifndef ORCHESTRA_H
#define ORCHESTRA_H

#include "keeper.h"

class Orchestra{
public:
    Orchestra(int capacity);
    ~Orchestra();

    void addInstrument(Base* instrument);
    void removeInstrument(int index);
    void displayAllInstruments();

private:
    Base** instruments;
    int capacity;
    int numInstruments;
};

#endif
