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
    for (int i = 0; i < currentSize; ++i) {
        if (routes[i]->getRouteNum() == route.getRouteNum()) {
            throw runtime_error("Route with this route number already exists.");
        }
    }

    dynamicRA();
    routes[currentSize] = new ROUTE(route);
    ++currentSize;
}

void RoutesList::deleteRoute(int routeNumber) {
    bool found = false;
    for (int i = 0; i < currentSize; ++i) {
        if (routes[i]->getRouteNum() == routeNumber) {
            delete routes[i];
            for (int j = i; j < currentSize - 1; ++j) {
                routes[j] = routes[j + 1];
            }
            routes[currentSize - 1] = nullptr;
            --currentSize;
            found = true;
            cout << "Route with route number " << routeNumber << " deleted." << endl;
            break;
        }
    }
    if (!found) {
        cout << "No route with route number " << routeNumber << " found." << endl;
    }
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
    cout << "--------------------" << endl;
    for (int i = 0; i < currentSize; ++i) {
        cout << *routes[i] << endl;
        cout << "--------------------" << endl;

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

