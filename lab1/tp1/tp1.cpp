#include <iostream>
#include <fstream>
#include "keeper.h"
#include "classes.h"
#include <conio.h>

using namespace std;

void displayMenu() {
    cout << "<---------Menu---------->" << endl;
    cout << "1. Add instrument" << endl;
    cout << "2. Delete instrument" << endl;
    cout << "3. Show instruments" << endl;
    cout << "4. Save instruments to file" << endl;
    cout << "5. Load instruments from file" << endl;
    cout << "8. Exit programm" << endl;
}

void commonChoices(string& name, double& cost, int& quantity, string& owner) {
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter cost: ";
    cin >> cost;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        throw invalid_argument("Invalid input for cost. Must be a number.");
    }
    cout << "Enter quantity: ";
    cin >> quantity;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        throw invalid_argument("Invalid input for quantity. Must be a number.");
    }
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
        system("cls");
        displayMenu();

        cin >> choice;
        cin.ignore();
        try {
            switch (choice) {
            case 1:
                if (flag == false) {
                    cout << "First time using the programm, please select desired capacity: ";
                    cin >> capacity;
                    keeper.setCapacity(capacity);
                    flag = true;
                }
                if (flag) {
                    int typeChoice;
                    cout << "Please choose what type of instrument you want to add: " << endl;
                    cout << "1. Drum" << endl;
                    cout << "2. Stringed" << endl;
                    cout << "3. Brass" << endl;
                    cout << "4. Cancel" << endl;
                    cin >> typeChoice;
                    cin.ignore();

                    Orchestra* newInstrument = nullptr;

                    string name;
                    double cost;
                    int quantity;
                    string owner;
                    string drumType;
                    string manufacturer;
                    string description;
                    string defects;
                    if (typeChoice > 0 && typeChoice < 4) {
                        commonChoices(name, cost, quantity, owner);
                    }
                    switch (typeChoice) {
                    case 1:

                        cout << "Enter type: ";
                        getline(cin, drumType);

                        newInstrument = new Drum(name, cost, quantity, owner, drumType);
                        break;
                    case 2:
                        cout << "Enter manufacturer: ";
                        getline(cin, manufacturer);
                        cout << "Enter description: ";
                        getline(cin, description);

                        newInstrument = new Stringed(name, cost, quantity, owner, manufacturer, description);
                        break;
                    case 3:
                        cout << "Enter manufacturer: ";
                        getline(cin, manufacturer);
                        cout << "Enter defects: ";
                        getline(cin, defects);

                        newInstrument = new Brass(name, cost, quantity, owner, manufacturer, defects);
                        break;
                    case 4:
                        cout << "Operation canceled, exiting menu..." << endl;
                        cin.ignore();
                        continue;
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
                    if (cin.fail()) {
                        cin.clear(); 
                        cin.ignore();
                        cerr << "Invalid input for index. Please enter a valid integer." << endl;
                    }
                    else {
                        try {
                            keeper.removeInstrument(index - 1);
                            cout << "Instrument was removed successfully!" << endl;
                        }
                        catch (const exception& e) {
                            cerr << "Exception in removing instrument: " << e.what() << endl;
                        }
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
                        Orchestra* instrument = keeper.getInstrument(i);
                        cout << "Instrument " << i + 1 << " (" << instrument->getType() << "):" << endl;
                        instrument->displayInfo();
                        cout << "---------------------------" << endl;
                    }

                    int editOption;
                    cout << "Choose an option:" << endl;
                    cout << "1. Edit an instrument" << endl;
                    cout << "2. Return to the main menu" << endl;
                    cin >> editOption;

                    if (editOption == 1) {
                        int editIndex;
                        cout << "Enter the index of the instrument you want to edit (1 to " << numInstruments << "): ";
                        cin >> editIndex;
                        cin.ignore();

                        if (editIndex >= 1 && editIndex <= numInstruments) {
                            Orchestra* instrumentToEdit = keeper.getInstrument(editIndex - 1);
                            instrumentToEdit->edit();
                        }
                        else {
                            cout << "Invalid instrument index." << endl;
                        }
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
            case 8:
                continue;
            default:
                cout << "Incorrect choice, please try again." << endl;

            }
        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }
        cout << "Press any key to continue...";
        cin.ignore();
    } while (choice != 8);

    return 0;
}