#include <iostream>
#include <fstream>
#include "ROUTE.h"
#include "RoutesList.h"

void subMenu() {
    int subChoice;
    RoutesList Rlist;

    do {
        cout << "------ Task 1 MENU ------" << endl;
        cout << "1. Sort routes by route number" << endl;
        cout << "2. Display routes by route number" << endl;
        cout << "3. Display all routes(for practical usage)" << endl;
        cout << "0. Exit" << endl;
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            Rlist.sortRoutes();
            cout << "Routes sorted by route number." << endl;
            break;

        case 2:
            int routeNumber;
            cout << "Enter route number: ";
            cin >> routeNumber;
            Rlist.displayRoute(routeNumber);
            break;

        case 3:
            Rlist.displayAllRoutes();
            break;
        case 0:
            cout << "Exiting programm..." << endl;
            break;

        default:
            cout << "Invalid input!" << endl;
        }
    } while (subChoice != 0);

}

int main()
{
    int mainChoice;

    do {
        cout << "Choose a task:" << endl;
        cout << "1. Task 1" << endl;
        cout << "2. Task 2" << endl;
        cout << "0. Exit" << endl;
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            subMenu();
            break;

        case 2:
            break;

        case 0:
            cout << "Exiting programm..." << endl;
            break;

        default:
            cout << "Invalid input!" << endl;
        }
    } while (mainChoice != 0);

    return 0;

}

