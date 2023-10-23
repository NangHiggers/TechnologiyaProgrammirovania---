#pragma once
#ifndef KEEPER_H
#define KEEPER_H

#include "classes.h"

class Keeper {
public:
    Keeper();
    Keeper(int capacity);
    ~Keeper();

    void addInstrument(Orchestra* instrument);
    void removeInstrument(int index);
    void displayAllInstruments();
    int getNumInstruments() const;
    Orchestra* getInstrument(int index) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    void setCapacity(int newCapacity);

private:
    Orchestra** instruments;
    int capacity;
    int numInstruments;
};

#endif