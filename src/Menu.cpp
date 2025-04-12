//
// Created by diogo on 07/04/2025.
//

#include "../headers/Menu.h"

#include <iostream>
#include <ostream>

using namespace std;

Menu::Menu() = default;

Menu::~Menu() {}

int Menu::getIntValue(const string &s) {
    int ret;
    while (true) {
        cout << s;
        if (cin >> ret) break;
        cout << "ERROR: Wrong input!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return ret;
}

void Menu::truckInformation() {
    if (truck.getNumPallets() == 0 || truck.getPallets().size() == 0) {
        cout << "No truck loaded!" << endl;
    }
    else {
        cout << "========================================\n";
        cout << "Currently loaded Truck: \n";
        cout << "Truck capacity: " << truck.getCapacity() << endl;
        cout << "Pallets loaded: " << truck.getPallets().size() << endl;

        for (auto p : truck.getPallets()) {
            cout << endl;
            cout << "Pallet number: " << p->getId() << endl;
            cout << "Weight: " << p->getWeight() << " Value: " << p->getValue() << endl;
        }
        cout << "========================================\n";
        cout << endl;
    }
}



void Menu::MainMenu() {
    int option;

    do {
        cout << "==========================================\n";
        cout << "Delivery Truck Pallet Packing Optimization\n";
        cout << "==========================================\n";
        cout << "[0] Load a Truck\n"
                "[1] Show Loaded Truck\n" // TEMP
                "[2] Exhaustive (Brute Force) Approach\n"
                "[3] Dynamic Programming Approach\n"
                "[4] Approximation Algorithms\n"
                "[5] Integer Linear Programming Algorithm\n"
                "[6] Exit" << endl;
        cout << "========================================\n";
        cout << "Select an option: ";

        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number between 0 and 6: ";
        }
        switch (option) {
            case 0: {
                const int truckNumber = getIntValue("Enter Truck number: ");
                reader.readTrucks("../docs/TruckAndPallets_" + to_string(truckNumber) + ".csv", truck);
                reader.readPallets("../docs/Pallets_" + to_string(truckNumber) + ".csv", truck);
                break;
            }
            case 1: {
                truckInformation();
                break;
            }
            case 2:
                cout << "WIP" << endl;
                break;
            case 3:
                cout << "WIP" << endl;
                break;
            case 4:
                cout << "WIP" << endl;
                break;
            case 5:
                cout << "WIP" << endl;
                break;
            case 6:
                cout << "Leaving" << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (option != 6);
}

