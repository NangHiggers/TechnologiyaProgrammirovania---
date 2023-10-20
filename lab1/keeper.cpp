#include "keeper.h"


Base::Base(const string& name, double cost, int quantity, const string& owner): name(name), cost(cost), quantity(quantity), owner(owner) {}

void Base::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "Cost: " << cost << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Owner: " << owner << endl;
}

Drum::Drum(const string& name, double cost, int quantity, const string& owner, const string& type): Base(name, cost, quantity, owner), type(type) {}

void Drum::displayInfo() const{
    cout << "Type: " << type << endl;
    Base::displayInfo();
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
string Stringed::getType() const{
    return "Stringed";
}

Brass::Brass(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& defects): Base(name, cost, quantity, owner), manufacturer(manufacturer), defects(defects) {}

void Brass::displayInfo() const{
    Base::displayInfo();
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Defects: " << defects << endl;
}
string Brass::getType() const{
    return "Brass";
}