#include "keeper.h"

Keeper::Keeper(int capacity){
    instruments = new Base*[capacity];
    numInstruments = 0;
}

Keeper::~Keeper() {
    for (int i = 0; i < numInstruments; ++i) {
        delete instruments[i];
    }
    delete[] instruments;
}

void Keeper::addInstrument(Base* instrument) {
    if (numInstruments < capacity) {
        instruments[numInstruments] = instrument;
        numInstruments++;
    } else {
        //user input capacity = capacity is limited?
        //or capacity is not limited and dynamically rearranged? 
    }
}

void Keeper::removeInstrument(int index) {
    if (index >= 0 && index < numInstruments) {
        delete instruments[index];
        for (int i = index; i < numInstruments - 1; i++) {
            instruments[i] = instruments[i + 1];
        }
        numInstruments--;
    }
}

void Keeper::displayAllInstruments() {
    for (int i = 0; i < numInstruments; ++i) {
        instruments[i]->displayInfo();
    }
}
int Keeper::getNumInstruments(){
        return numInstruments;
    }

Base* Keeper::getInstrument(int index) {
        if (index >= 0 && index < numInstruments) {
            return instruments[index];
        } else {
            //
            return nullptr; //
        }
    }