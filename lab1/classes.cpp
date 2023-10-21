#include "classes.h"

Base::Base(const string& name, double cost, int quantity, const string& owner): name(name), cost(cost), quantity(quantity), owner(owner) {}

void Base::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Cost: " << cost << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Owner: " << owner << endl;
}
void Base::displayInfoToFile(ostream& output) const {
    output << "Name: " << name << endl;
    output << "Cost: " << cost << endl;
    output << "Quantity: " << quantity <<endl;
    output << "Owner: " << owner << endl;
}

Drum::Drum(const string& name, double cost, int quantity, const string& owner, const string& type): Base(name, cost, quantity, owner), type(type) {}

void Drum::displayInfo() const{
    Base::displayInfo();
    cout << "Type: " << type << endl;
}
void Drum::displayInfoToFile(ostream& output) const {
    Base::displayInfoToFile(output);
    output << "Type: " << type << endl;
}
string Drum::getType() const{
    return "Drum";
}

Stringed::Stringed(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& description): Base(name, cost, quantity, owner), manufacturer(manufacturer), description(description) {}

void Stringed::displayInfo() const{
    Base::displayInfo();
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Description: " << description << endl;
}
void Stringed::displayInfoToFile(ostream& output) const {
    Base::displayInfoToFile(output);
    output << "Manufacturer: " << manufacturer << endl;
    output << "Description: " << description << endl;
}
string Stringed::getType() const{
    return "Stringed";
}

Brass::Brass(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& defects): Base(name, cost, quantity, owner), manufacturer(manufacturer), defects(defects) {}

void Brass::displayInfo() const{
    Base::displayInfo();
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Defects: " << defects << endl;
}
void Brass::displayInfoToFile(ostream& output) const {
    Base::displayInfoToFile(output);
    output << "Manufacturer: " << manufacturer << endl;
    output << "Defects: " << defects << endl;
}
string Brass::getType() const{
    return "Brass";
}