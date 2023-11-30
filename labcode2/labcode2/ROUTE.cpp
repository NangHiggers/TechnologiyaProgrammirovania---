#include "ROUTE.h"
#include <iostream>

ROUTE::ROUTE(): RouteNum(0), StartingPoint(""), EndingPoint("") {}
ROUTE::ROUTE(int RouteNum, const string& StartingPoint, const string& EndingPoint): RouteNum(RouteNum), StartingPoint(StartingPoint), EndingPoint(EndingPoint) {}
ROUTE::~ROUTE(){}

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
    is >> route.StartingPoint;
    cout << "Enter Ending Point: ";
    is >> route.EndingPoint;
    return is;
}