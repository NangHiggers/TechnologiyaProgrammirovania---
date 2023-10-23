#pragma once
#ifndef KEEPER_H
#define KEEPER_H

#include "classes.h"

class Keeper {
public:
    Keeper();
    Keeper(int capacity);
    ~Keeper();

    void addInstrument(Base* instrument);
    void removeInstrument(int index);
    void displayAllInstruments();
    int getNumInstruments() const;
    Base* getInstrument(int index) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    void setCapacity(int newCapacity);

private:
    Base** instruments;
    int capacity;
    int numInstruments;
};

#endif