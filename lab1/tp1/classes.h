#pragma once
#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Base {
public:
    Base(const string& name, double cost, int quantity, const string& owner);

    virtual ~Base();

    virtual void displayInfo() const;
    virtual void displayInfoToFile(ostream& output) const;
    virtual string getType() const = 0;
    virtual void edit();

protected:
    string name;
    double cost;
    int quantity;
    string owner;
};

class Drum : public Base {
public:
    Drum(const string& name, double cost, int quantity, const string& owner, const string& drumType);

    virtual void displayInfo() const override;
    virtual void displayInfoToFile(ostream& output) const override;
    virtual void edit() override;
    string getType() const override;

private:
    string drumType;
};

class Stringed : public Base {
public:
    Stringed(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& description);

    virtual void displayInfo() const override;
    virtual void displayInfoToFile(ostream& output) const override;
    virtual void edit() override;
    string getType() const override;

private:
    string manufacturer;
    string description;
};

class Brass : public Base {
public:
    Brass(const string& name, double cost, int quantity, const string& owner, const string& manufacturer, const string& defects);

    virtual void displayInfo() const override;
    virtual void displayInfoToFile(ostream& output) const override;
    virtual void edit() override;
    string getType() const override;

private:
    string manufacturer;
    string defects;
};

#endif
