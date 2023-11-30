#include "RoutesList.h"
#include "iostream"

using namespace std;

RoutesList::RoutesList() : routes(nullptr), currentSize(0){ }
RoutesList::~RoutesList() {
    for (int i = 0; i < currentSize; ++i) {
        delete routes[i];
    }
    delete[] routes;
}

void RoutesList::dynamicRA() {
    ROUTE** temp = new ROUTE * [currentSize + 1];

    for (int i = 0; i < currentSize; ++i) {
        temp[i] = routes[i];
    }

    delete[] routes;

    routes = temp;
}

void RoutesList::addRoute(const ROUTE& route) {
    dynamicRA();

    routes[currentSize] = new ROUTE(route);
    ++currentSize;
}

void RoutesList::displayRoute(int routeNumber) const {
    bool found = false;
    for (int i = 0; i < currentSize; ++i) {
        if (routes[i]->getRouteNum() == routeNumber) {
            cout << *routes[i];
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No route with such number" << endl;
    }
}

void RoutesList::displayAllRoutes() const {
    if (currentSize == 0) {
        cout << "No saved route." << endl;
        return;
    }

    cout << "All routes:" << endl;
    for (int i = 0; i < currentSize; ++i) {
        cout << "Route number " << i + 1 << ":" << endl;
        cout << *routes[i] << endl;
    }
}

void RoutesList::sortRoutes() {
    for (int i = 0; i < currentSize - 1; ++i) {
        for (int j = 0; j < currentSize - i - 1; ++j) {
            if (routes[j]->getRouteNum() > routes[j + 1]->getRouteNum()) {
                ROUTE* temp = routes[j];
                routes[j] = routes[j + 1];
                routes[j + 1] = temp;
            }
        }
    }
}

