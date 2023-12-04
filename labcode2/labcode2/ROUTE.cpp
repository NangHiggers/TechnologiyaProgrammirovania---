#include "ROUTE.h"
#include <iostream>

ROUTE::ROUTE() : RouteNum(0), StartingPoint(""), EndingPoint("") { cout << "called for unparometrized route constructor" << endl; }
ROUTE::ROUTE(int RouteNum, const string& StartingPoint, const string& EndingPoint) : RouteNum(RouteNum), StartingPoint(StartingPoint), EndingPoint(EndingPoint) {
    cout << "called for parometrized route constructor" << endl;
}
ROUTE::~ROUTE() { cout << "called for destructor" << endl; }
string ROUTE::getStartingPoint() const {
    return StartingPoint;
}

string ROUTE::getEndingPoint() const {
    return EndingPoint;
}

int ROUTE::getRouteNum() const {
    return RouteNum;
}

void ROUTE::setStartingPoint(const string& StartingPoint) {
    this->StartingPoint = StartingPoint;
}

void ROUTE::setEndingPoint(const string& EndingPoint) {
    this->EndingPoint = EndingPoint;
}

void ROUTE::setRouteNum(int RouteNum) {
    this->RouteNum = RouteNum;
}

ostream& operator<<(ostream& os, const ROUTE& route) {
    os << "Route Number: " << route.RouteNum << endl;
    os << "Starting Point: " << route.StartingPoint << endl;
    os << "Ending Point: " << route.EndingPoint << endl;
    return os;
}

istream& operator>>(istream& is, ROUTE& route) {
    cout << "Enter Route Number: ";
    is >> route.RouteNum;

    cout << "Enter Starting Point: ";
    is.ignore();
    getline(is, route.StartingPoint);

    cout << "Enter Ending Point: ";
    getline(is, route.EndingPoint);

    return is;
}