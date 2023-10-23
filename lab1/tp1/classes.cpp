#include "classes.h"

Orchestra::Orchestra(const string& name, double cost, int quantity, const string& owner) : name(name), cost(cost), quantity(quantity), owner(owner) {
    if (cost < 0) {
        throw invalid_argument("Cost cannot be negative.");
    }
    if (quantity < 0) {
        throw invalid_argument("Quantity cannot be negative.");
    }

    cout << "Called Orchestra constructor" << endl;
}

Orchestra::~Orchestra() {
    cout << "Called Orchestra destructor" << endl;
}

void Orchestra::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Cost: " << cost << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Owner: " << owner << endl;
}
void Orchestra::edit() {
    cout << "Select the parameter to edit:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Cost" << endl;
    cout << "3. Quantity" << endl;
    cout << "4. Owner" << endl;
}
ostream& Orchestra::displayInfoToFile(ostream& output) const {
    output << "Name: " << name << endl;
    output << "Cost: " << cost << endl;
    output << "Quantity: " << quantity << endl;
    output << "Owner: " << owner << endl;
    return output;
}

Drum::Drum(const string& name, double cost, int quantity, const string& owner, const string& drumType) : Orchestra(name, cost, quantity, owner), drumType(drumType) {
    cout << "Called Drum constructor" << endl;
}

Drum::~Drum() {
    cout << "Called Drum destructor" << endl;
}

void Drum::displayInfo() const {
    Orchestra::displayInfo();
    cout << "Type of drum: " << drumType << endl;
}
void Drum::edit() {
    int editParameter;
    Orchestra::edit();
    cout << "5. Drum Type" << endl;
    cin >> editParameter;

    switch (editParameter) {
    case 1: {
        string newName;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, newName);
        name = newName;
        break;
    }
    case 2: {
        double newCost;
        cout << "Enter new cost: ";
        cin >> newCost;
        cost = newCost;
        break;
    }
    case 3: {
        int newQuantity;
        cout << "Enter new quantity: ";
        cin >> newQuantity;
        quantity = newQuantity;
        break;
    }
    case 4: {
        string newOwner;
        cout << "Enter new owner: ";
        cin.ignore();
        getline(cin, newOwner);
        owner = newOwner;
        break;
    }
    case 5: {
        string newDrumType;
        cout << "Enter new drum type: ";
        cin.ignore();
        getline(cin, newDrumType);
        drumType = newDrumType;
        break;
    }
    default:
        cout << "Invalid parameter choice." << endl;
    }
}
ostream& Drum::displayInfoToFile(ostream& output) const {
    Orchestra::displayInfoToFile(output);
    output << "Type of drum: " << drumType << endl;
    return output;
}
string Drum::getType() const {
    return "Drum";
}

Stringed::Stringed(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& description) : Orchestra(name, cost, quantity, owner), manufacturer(manufacturer), description(description) {
    cout << "Called Stringed constructor" << endl;
}
Stringed::~Stringed() {
    cout << "Called Stringed destructor" << endl;
}

void Stringed::displayInfo() const {
    Orchestra::displayInfo();
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Description: " << description << endl;
}
void Stringed::edit() {
    int editParameter;
    Orchestra::edit();
    cout << "5. Manufacturer" << endl;
    cout << "6. Description" << endl;
    cin >> editParameter;

    switch (editParameter) {
    case 1: {
        string newName;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, newName);
        name = newName;
        break;
    }
    case 2: {
        double newCost;
        cout << "Enter new cost: ";
        cin >> newCost;
        cost = newCost;
        break;
    }
    case 3: {
        int newQuantity;
        cout << "Enter new quantity: ";
        cin >> newQuantity;
        quantity = newQuantity;
        break;
    }
    case 4: {
        string newOwner;
        cout << "Enter new owner: ";
        cin.ignore();
        getline(cin, newOwner);
        owner = newOwner;
        break;
    }
    case 5: {
        string newManufacturer;
        cout << "Enter new manufacturer: ";
        cin.ignore();
        getline(cin, newManufacturer);
        manufacturer = newManufacturer;
        break;
    }
    case 6: {
        string newDescription;
        cout << "Enter new description: ";
        cin.ignore();
        getline(cin, newDescription);
        description = newDescription;
        break;
    }
    default:
        cout << "Invalid parameter choice." << endl;
    }
}
ostream& Stringed::displayInfoToFile(ostream& output) const {
    Orchestra::displayInfoToFile(output);
    output << "Manufacturer: " << manufacturer << endl;
    output << "Description: " << description << endl;
    return output;
}
string Stringed::getType() const {
    return "Stringed";
}

Brass::Brass(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& defects) : Orchestra(name, cost, quantity, owner), manufacturer(manufacturer), defects(defects) {
    cout << "Called Brass constructor" << endl;
}
Brass::~Brass() {
    cout << "Called Brass destructor" << endl;
}

void Brass::displayInfo() const {
    Orchestra::displayInfo();
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Defects: " << defects << endl;
}
void Brass::edit() {
    int editParameter;
    Orchestra::edit();
    cout << "5. Manufacturer" << endl;
    cout << "6. Defects" << endl;
    cin >> editParameter;

    switch (editParameter) {
    case 1: {
        string newName;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, newName);
        name = newName;
        break;
    }
    case 2: {
        double newCost;
        cout << "Enter new cost: ";
        cin >> newCost;
        cost = newCost;
        break;
    }
    case 3: {
        int newQuantity;
        cout << "Enter new quantity: ";
        cin >> newQuantity;
        quantity = newQuantity;
        break;
    }
    case 4: {
        string newOwner;
        cout << "Enter new owner: ";
        cin.ignore();
        getline(cin, newOwner);
        owner = newOwner;
        break;
    }
    case 5: {
        string newManufacturer;
        cout << "Enter new manufacturer: ";
        cin.ignore();
        getline(cin, newManufacturer);
        manufacturer = newManufacturer;
        break;
    }
    case 6: {
        string newDefects;
        cout << "Enter new defects: ";
        cin.ignore();
        getline(cin, newDefects);
        defects = newDefects;
        break;
    }
    default:
        cout << "Invalid parameter choice." << endl;
    }
}
ostream& Brass::displayInfoToFile(ostream& output) const {
    Orchestra::displayInfoToFile(output);
    output << "Manufacturer: " << manufacturer << endl;
    output << "Defects: " << defects << endl;
    return output;
}
string Brass::getType() const {
    return "Brass";
}

ostream& operator<<(ostream& output, const Orchestra& obj) {
    return obj.displayInfoToFile(output);
}
