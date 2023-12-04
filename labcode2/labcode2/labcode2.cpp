#include <iostream>
#include <fstream>
#include "ROUTE.h"
#include "RoutesList.h"

void subMenu() {
    int subChoice;
    int routeNumber;
    RoutesList Rlist;
    ROUTE newRoute;

    do {
        cout << "------ Task 1 MENU ------" << endl;
        cout << "1. Add route" << endl;
        cout << "2. Delete route" << endl;
        cout << "3. Sort routes by route number" << endl;
        cout << "4. Display routes by route number" << endl;
        cout << "5. Insert route in list" << endl;
        cout << "6. Edit route entry by route number" << endl;
        cout << "7. Display all routes(for practical usage)" << endl;
        cout << "0. Exit" << endl;
        cin >> subChoice;

        switch (subChoice) {
        case 1:
            cout << "Enter details for a route:\n";
            cin >> newRoute;
            try {
                Rlist.addRoute(newRoute);
            }
            catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;

        case 2:
            cout << "Enter route number to delete: ";
            cin >> routeNumber;
            Rlist.deleteRoute(routeNumber);
            break;
        case 3:
            Rlist.sortRoutes();
            cout << "Routes sorted by route number." << endl;
            break;

        case 4:
            cout << "Enter route number: ";
            cin >> routeNumber;
            Rlist.displayRoute(routeNumber);
            break;

        
        case 5:
            int position;
            cout << "Enter position to insert the route: ";
            cin >> position;
            position -= 1;
            cout << "Enter details for a route:\n";
            cin >> newRoute;
            try {
                Rlist.insertRoute(position, newRoute);
            }
            catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        case 6:
            int editRouteNumber;
            int editChoice;

            cout << "Enter route number to edit: ";
            cin >> editRouteNumber;

            cout << "Choose the attribute to edit:\n";
            cout << "1. Starting Point\n";
            cout << "2. Starting Point\n";
            cout << "3. Ending Point\n";
            cin >> editChoice;

            switch (editChoice) {
            case 1: {
                int newRouteNumber;
                cout << "Enter new route number: ";
                cin >> newRouteNumber;
                Rlist.editRouteNumber(editRouteNumber, newRouteNumber);
                break;
            }
            case 2: {
                string newStartingPoint;
                cout << "Enter new starting point: ";
                cin.ignore();
                getline(cin, newStartingPoint);
                Rlist.editStartingPoint(editRouteNumber, newStartingPoint);
                break;
            }
            case 3: {
                string newEndingPoint;
                cout << "Enter new ending point: ";
                cin.ignore();
                getline(cin, newEndingPoint);
                Rlist.editEndingPoint(editRouteNumber, newEndingPoint);
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
            break;

        case 7:
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

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool startsAndEndsWithVowels(const string& word) {
    if (word.empty()) return false;

    string cleanWord = word;
    while (!cleanWord.empty() && !isalpha(cleanWord.front())) {
        cleanWord.erase(0, 1);
    }
    while (!cleanWord.empty() && !isalpha(cleanWord.back())) {
        cleanWord.pop_back();
    }

    return (isVowel(cleanWord.front()) && isVowel(cleanWord.back()));
}

int main()
{
    int mainChoice;
    ifstream inputFile("input.txt");
    string word;

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

            if (!inputFile) {
                cerr << "Unable to open input file." << endl;
                return 1;
            }
            cout << "Words that starts and ends with vowels:" << endl;
            cout << "--------------------" << endl;
            while (inputFile >> word) {
                if (word.length() > 1 && startsAndEndsWithVowels(word)) {
                    cout << word << endl;
                    cout << "--------------------" << endl;
                }
            }

            inputFile.close();
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
