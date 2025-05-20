//
// Created by diogo on 07/04/2025.
//

#include "../headers/Menu.h"

#include <iostream>
#include <ostream>
#include <limits>

using namespace std;

Menu::Menu() = default;

Menu::~Menu() {}

void Menu::waitForEnter() {
    cout << "Press Enter to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string input;
    getline(cin, input);

    clearScreen();
}

void Menu::clearScreen() {
    for (int i = 0; i<8; i++) cout << endl;
}


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
        cout << "Currently loaded Truck: " << truck.getId() << " \n";
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

int Menu::loadTruck() {
    const int truckNumber = getIntValue("Enter Truck number: ");
    if (reader.readTrucks(
        ((truckNumber < 10)  ? "../docs/TruckAndPallets_0" : "../docs/TruckAndPallets_") +
        to_string(truckNumber) + ".csv", truck)
        ||
        reader.readPallets(
        ((truckNumber < 10 ) ? "../docs/Pallets_0" : "../docs/Pallets_") +
        to_string(truckNumber) + ".csv", truck) != 0) return 1;
    truck.setId(truckNumber);
    return 0;
}

void Menu::BruteForceMenu() {
    if (!truck.isLoaded()) {
        cout << "No truck loaded!" << endl;
        return;
    }

    vector<Pallet *> solution = solver.brute_force(truck);

    if (solution.empty()) {
        cout << "Input too big! No solution found!" << endl;
    }
    else {
        cout << "========================================\n";
        for (auto p : solution) {
            cout << endl;
            cout << "Pallet number: " << p->getId() << endl;
            cout << "Weight: " << p->getWeight() << " Value: " << p->getValue() << endl;
        }
        cout << "========================================\n";
    }
}

void Menu::DynamicProgrammingMenu() {
    if (!truck.isLoaded()) {
        cout << "No truck loaded!" << endl;
        return;
    }

    vector<Pallet *> solution = solver.dynamic_program(truck);

    if (solution.empty()) {
        cout << "Input too big! No solution found!" << endl;
    } else {
        cout << "========================================\n";
        for (auto p : solution) {
            cout << endl;
            cout << "Pallet number: " << p->getId() << endl;
            cout << "Weight: " << p->getWeight() << " Value: " << p->getValue() << endl;
        }
        cout << "========================================\n";
    }
}


void Menu::ApproximationMenu() {
    if (!truck.isLoaded()) {
        cout << "No truck loaded!" << endl;
        return;
    }

    cout << "========================================\n";

    vector<Pallet *> solution = solver.approximation(truck);

    if (solution.empty()) {
        cout << "Input too big! No solution found!" << endl;
    } else {
        cout << "========================================\n";
        for (auto p : solution) {
            cout << endl;
            cout << "Pallet number: " << p->getId() << endl;
            cout << "Weight: " << p->getWeight() << " Value: " << p->getValue() << endl;
        }
        cout << "========================================\n";
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
                while (loadTruck() != 0) {
                    cout << "No such truck!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                waitForEnter();
                break;
            }
            case 1: {
                truckInformation();
                waitForEnter();
                break;
            }
            case 2:
                BruteForceMenu();
                waitForEnter();
                break;
            case 3:
                DynamicProgrammingMenu();
                waitForEnter();
                break;
            case 4:
                ApproximationMenu();
                waitForEnter();
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

