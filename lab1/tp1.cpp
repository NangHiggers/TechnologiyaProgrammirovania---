#include <iostream>
#include <fstream>
#include "keeper.h"
#include "classes.h"

using namespace std;

void saveInstrumentsToFile(const Keeper& keeper, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        int numInstruments = keeper.getNumInstruments();
        for (int i = 0; i < numInstruments; ++i) {
            const Base* instrument = keeper.getInstrument(i);
            file << "Instrument " << i + 1 << " (" << instrument->getType() << "):" << endl;
            file << "---------------------------" << endl;
            instrument->displayInfoToFile(file);
            file << "---------------------------" << endl;
        }
        file.close();
        cout << "Instruments saved to " << filename << " successfully." << endl;
    } else {
        cout << "Failed to open the file for writing." << endl;
    }
}

void loadInstrumentsFromFile(Keeper& keeper, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        string instrumentType;
        while (getline(file, line)) {
            if (line.find("Instrument") != string::npos) {
                size_t openParenthesisPos = line.find("(");
                size_t closeParenthesisPos = line.find(")");
                if (openParenthesisPos != string::npos && closeParenthesisPos != string::npos) {
                    instrumentType = line.substr(openParenthesisPos + 1, closeParenthesisPos - openParenthesisPos - 1);
                }
            } else if (line == "---------------------------") {
                string name, owner, type, manufacturer, defects, description;
                double cost;
                int quantity;

                while (getline(file, line) && line != "---------------------------") {
                    if (line.find("Name:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        name = line;
                    } else if (line.find("Cost:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        cost = stod(line);
                    } else if (line.find("Quantity:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        quantity = stoi(line);
                    } else if (line.find("Owner:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        owner = line;
                    } else if (line.find("Type:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        type = line;
                    } else if (line.find("Manufacturer:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        manufacturer = line;
                    } else if (line.find("Defects:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        defects = line;
                    } else if (line.find("Description:") != string::npos) {
                        line = line.substr(line.find(":") + 2);
                        description = line;
                    }
                }

                if (instrumentType == "Drums") {
                    keeper.addInstrument(new Drum(name, cost, quantity, owner, instrumentType));
                } else if (instrumentType == "Stringed") {
                    keeper.addInstrument(new Stringed(name, cost, quantity, owner, manufacturer, description));
                } else if (instrumentType == "Brass") {
                    keeper.addInstrument(new Brass(name, cost, quantity, owner, manufacturer, defects));
                }
            }
        }
        file.close();
        cout << "Instruments loaded from " << filename << " successfully." << endl;
    } else {
        cout << "Failed to open the file for reading." << endl;
    }
}

int main(){
    bool flag = false;
    int capacity;
    string filename = "datafile.txt";

    int choice;
    do{
        cout << "<---------Menu---------->"<< endl; 
        cout << "1. Add instrument"<< endl; 
        cout << "2. Delete instrument"<< endl; 
        cout << "3. Show instruments"<< endl;
        cout << "4. Save instruments to file" << endl;
        cout << "5. Load instruments from file" << endl;
        cout << "8. Exit programm"<< endl; 
        cin >> choice;
        switch(choice){
            case 1:
                if (flag==false){
                    cout<<"First time using the programm, please select desired capacity : ";
                    cin >> capacity;
                    Keeper keeper(capacity);
                    flag=true;
                }
                if (flag){
                    int typeChoice;
                    cout << "Please choose what type of instrument you want to add: " << endl;
                    cout << "1. Drum" <<endl;
                    cout << "2. Stringed" <<endl;
                    cout << "3. Brass" <<endl;
                    cin >> typeChoice;

                    Base* newInstrument = nullptr;
                    
                    string name;
                    double cost;
                    int quantity;
                    string owner;
                    string type;
                    string manufacturer;
                    string description;
                    string defects;

                    switch(typeChoice){
                        case 1:
                            cout << "Enter name: ";
                            cin >> name;
                            cout << "Enter cost: ";
                            cin >> cost;
                            cout << "Enter quantity: ";
                            cin >> quantity;
                            cout << "Enter owner: ";
                            cin >> owner;
                            cout << "Enter type: ";
                            cin >> type;

                            Base* newInstrument = new Drum(name, cost, quantity, owner, type);
                            break;
                        case 2:
                            cout << "Enter name: ";
                            cin >> name;
                            cout << "Enter cost: ";
                            cin >> cost;
                            cout << "Enter quantity: ";
                            cin >> quantity;
                            cout << "Enter owner: ";
                            cin >> owner;
                            cout << "Enter manufacturer: ";
                            cin >> manufacturer;
                            cout << "Enter description: ";
                            cin >> description;

                            Base* newInstrument = new Stringed(name, cost, quantity, owner, manufacturer, description);
                            break;
                        case 3:
                            cout << "Enter name: ";
                            cin >> name;
                            cout << "Enter cost: ";
                            cin >> cost;
                            cout << "Enter quantity: ";
                            cin >> quantity;
                            cout << "Enter owner: ";
                            cin >> owner;
                            cout << "Enter manufacturer: ";
                            cin >> manufacturer;
                            cout << "Enter defects: ";
                            cin >> defects;

                            Base* newInstrument = new Brass(name, cost, quantity, owner, manufacturer, defects);
                            break;
                        default:
                            cout << "Incorrect choice, please try again." << endl;
                            continue;
                    }
                    keeper.addInstrument(newInstrument);
                
                }
                break;
            case 2:
                if (flag){
                    int index;

                    cout << "Enter index of instrument you want to delete: ";
                    cin >> index;
                    
                    if(index>=0 && index < keeper.getInstruments()){
                        keeper.removeInstrument(index);
                        cout << "Instrument was removed successfully!" << endl;
                    } else {
                        cout << "Error occured! Invalid instrument index." << endl;
                    }
                } else {
                    cout << "There is no instruments to delete. Please add instrument first." << endl;
                }
                break;
            case 3:
                if (flag) {
                    int numInstruments = keeper.getNumInstruments();
                    if (numInstruments == 0) {
                        cout << "No instruments in the keeper." << endl;
                        return;
                    }

                    cout << "List of instruments:" << endl;
                    for (int i = 0; i < numInstruments; ++i) {
                        const Base* instrument = keeper.getInstrument(i);
                        cout << "Instrument " << i + 1 << " (" << instrument->getType() << "):" << endl;
                        instrument->displayInfo();
                        cout << "---------------------------" << endl;
                    }
                } else {
                    cout << "No instruments to display. Please add instruments first." << endl;
                }
                break;
            default:
                cout << "Incorrect choice, please try again." << endl;
            case 4:
                saveInstrumentsToFile(keeper, filename);
                break;
            case 5:
                loadInstrumentsFromFile(keeper, filename);
                flag = true;
                break;

        }
    } while (choice != 8);

    return 0;
}