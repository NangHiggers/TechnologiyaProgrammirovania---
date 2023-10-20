#ifndef KEEPER_H
#define KEEPER_H

#include <string>
#include <iostream>

using namespace std;

class Base{
public:
    Base(const string& name, double cost, int quantity, const string& owner): name(name), cost(cost), quantity(quantity), owner(owner) {}
    
    virtual void displayInfo() const;
    virtual string getType() const=0;

protected:
    string name;
    double cost;
    int quantity;
    string owner;
};

class Drum : public Base{
public:
    Drum(const string& name, double cost, int quantity, const string& owner, const string& type);
    
    virtual void displayInfo() const override;
    string getType() const override;

private:
    string type;
};

class Stringed : public Base{
public:
    Stringed(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& description);
    
    virtual void displayInfo() const override;
    string getType() const override;

private:
    string manufacturer;
    string description;
};

class Brass : public Base{
public:
    Brass(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& defects);

    virtual void displayInfo() const override;
    string getType() const override;

private:
    string manufacturer;
    string defects;
};

#endif