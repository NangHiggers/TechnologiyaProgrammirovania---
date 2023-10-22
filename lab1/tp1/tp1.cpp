﻿#include <iostream>
#include <fstream>
#include "keeper.h"
#include "classes.h"

using namespace std;

void commonChoices(string& name, double& cost, int& quantity, string& owner) {
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter cost: ";
    cin >> cost;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter owner: ";
    cin.ignore();
    getline(cin, owner);
}

int main() {
    bool flag = false;
    int capacity;
    Keeper keeper;
    string filename = "datafile.txt";

    int choice;
    do {
        cout << "<---------Menu---------->" << endl;
        cout << "1. Add instrument" << endl;
        cout << "2. Delete instrument" << endl;
        cout << "3. Show instruments" << endl;
        cout << "4. Save instruments to file" << endl;
        cout << "5. Load instruments from file" << endl;
        cout << "8. Exit programm" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            if (flag == false) {
                cout << "First time using the programm, please select desired capacity: ";
                cin >> capacity;
                keeper = Keeper(capacity);
                flag = true;
            }
            if (flag) {
                int typeChoice;
                cout << "Please choose what type of instrument you want to add: " << endl;
                cout << "1. Drum" << endl;
                cout << "2. Stringed" << endl;
                cout << "3. Brass" << endl;
                cin >> typeChoice;

                Base* newInstrument = nullptr;

                string name;
                double cost;
                int quantity;
                string owner;
                string drumType;
                string manufacturer;
                string description;
                string defects;

                commonChoices(name, cost, quantity, owner);

                switch (typeChoice) {
                case 1:

                    cout << "Enter type: ";
                    cin.ignore();
                    getline(cin, drumType);

                    newInstrument = new Drum(name, cost, quantity, owner, drumType);
                    break;
                case 2:
                    cout << "Enter manufacturer: ";
                    cin.ignore();
                    getline(cin, manufacturer);
                    cout << "Enter description: ";
                    cin.ignore();
                    getline(cin, description);

                    newInstrument = new Stringed(name, cost, quantity, owner, manufacturer, description);
                    break;
                case 3:
                    cout << "Enter manufacturer: ";
                    cin.ignore();
                    getline(cin, manufacturer);
                    cout << "Enter defects: ";
                    cin.ignore();
                    getline(cin, defects);

                    newInstrument = new Brass(name, cost, quantity, owner, manufacturer, defects);
                    break;
                default:
                    cout << "Incorrect choice, please try again." << endl;
                    continue;
                }
                keeper.addInstrument(newInstrument);
            }
            break;
        case 2:
            if (flag) {
                int index;

                cout << "Enter index of instrument you want to delete: ";
                cin >> index;

                index--;

                if (index >= 0 && index < keeper.getNumInstruments()) {
                    keeper.removeInstrument(index);
                    cout << "Instrument was removed successfully!" << endl;
                }
                else {
                    cout << "Error occured! Invalid instrument index." << endl;
                }
            }
            else {
                cout << "There is no instruments to delete. Please add instrument first." << endl;
            }
            break;
        case 3:
            if (flag) {
                int numInstruments = keeper.getNumInstruments();
                if (numInstruments == 0) {
                    cout << "No instruments in the keeper." << endl;
                    break;
                }

                cout << "List of instruments:" << endl;
                for (int i = 0; i < numInstruments; ++i) {
                    const Base* instrument = keeper.getInstrument(i);
                    cout << "Instrument " << i + 1 << " (" << instrument->getType() << "):" << endl;
                    instrument->displayInfo();
                    cout << "---------------------------" << endl;
                }
            }
            else {
                cout << "No instruments to display. Please add instruments first." << endl;
            }
            break;
        case 4:
            keeper.saveToFile(filename);
            break;
        case 5:
            keeper.loadFromFile(filename);
            flag = true;
            break;
        default:
            cout << "Incorrect choice, please try again." << endl;

        }
    } while (choice != 8);

    return 0;
}