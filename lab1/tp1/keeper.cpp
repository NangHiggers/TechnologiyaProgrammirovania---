#include "keeper.h"
#include "keeper.h"

Keeper::Keeper() {
    capacity = 10;
    instruments = new Base * [capacity];
    numInstruments = 0;
}

Keeper::Keeper(int capacity) {
    instruments = new Base * [capacity];
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
        cout << "Instrument added successfully." << endl;
    }
    else {
        cout << "Cannot add more instruments. Do you want to increase the capacity? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int newCapacity;
            cout << "Enter the new capacity: ";
            cin >> newCapacity;
            if (newCapacity <= capacity) {
                cout << "New capacity must be greater than the current capacity." << endl;
            }
            else {
                Base** newInstruments = new Base * [newCapacity];
                for (int i = 0; i < numInstruments; ++i) {
                    newInstruments[i] = instruments[i];
                }
                delete[] instruments;
                instruments = newInstruments;
                capacity = newCapacity;

                instruments[numInstruments] = instrument;
                numInstruments++;
                cout << "Instrument added successfully." << endl;
            }
        }
        else {
            cout << "Instrument not added." << endl;
        }
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
int Keeper::getNumInstruments() const {
    return numInstruments;
}

Base* Keeper::getInstrument(int index) const {
    if (index >= 0 && index < numInstruments) {
        return instruments[index];
    }
    else {
        //
        return nullptr; //
    }
}

void Keeper::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Capacity: " << capacity << endl;

        int numInstruments = getNumInstruments();
        for (int i = 0; i < numInstruments; ++i) {
            const Base* instrument = getInstrument(i);
            file << "Instrument " << i + 1 << " (" << instrument->getType() << "):" << endl;
            file << "---------------------------" << endl;
            instrument->displayInfoToFile(file);
            file << "---------------------------" << endl;
        }
        file.close();
        cout << "Instruments saved to " << filename << " successfully." << endl;
    }
    else {
        cout << "Failed to open the file for writing." << endl;
    }
}

void Keeper::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        string instrumentType;
        while (getline(file, line)) {
            if (line.find("Capacity:") != string::npos) {
                size_t colonPos = line.find(":");
                if (colonPos != string::npos) {
                    capacity = stoi(line.substr(colonPos + 1));
                    break;
                }
            }
            else if (line.find("Instrument") != string::npos) {
                size_t openParenthesisPos = line.find("(");
                size_t closeParenthesisPos = line.find(")");
                if (openParenthesisPos != string::npos && closeParenthesisPos != string::npos) {
                    instrumentType = line.substr(openParenthesisPos + 1, closeParenthesisPos - openParenthesisPos - 1);
                }
            }
            else if (line == "---------------------------") {
                string name, owner, drumType, manufacturer, defects, description;
                double cost;
                int quantity;

                while (getline(file, line) && line != "---------------------------") {
                    if (line.find("Name:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        name = line;
                    }
                    else if (line.find("Cost:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        cost = stod(line);
                    }
                    else if (line.find("Quantity:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        quantity = stoi(line);
                    }
                    else if (line.find("Owner:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        owner = line;
                    }
                    else if (line.find("Type of drum:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        drumType = line;
                    }
                    else if (line.find("Manufacturer:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        manufacturer = line;
                    }
                    else if (line.find("Defects:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        defects = line;
                    }
                    else if (line.find("Description:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        description = line;
                    }
                }
                if (instrumentType == "Drum") {
                    addInstrument(new Drum(name, cost, quantity, owner, drumType));
                }
                else if (instrumentType == "Stringed") {
                    addInstrument(new Stringed(name, cost, quantity, owner, manufacturer, description));
                }
                else if (instrumentType == "Brass") {
                    addInstrument(new Brass(name, cost, quantity, owner, manufacturer, defects));
                }
            }
        }
        file.close();
        cout << "Instruments loaded from " << filename << " successfully." << endl;
    }
    else {
        cout << "Failed to open the file for reading." << endl;
    }
}