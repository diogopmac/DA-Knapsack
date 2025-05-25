#include "../headers/Menu.h"

#include <iostream>
#include <ostream>
#include <limits>
#include <chrono>

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::duration;

Menu::Menu() = default;

Menu::~Menu() = default;

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

    int backtracking = 0;
    while (backtracking != 1 && backtracking != 2 && backtracking != 3) {
        backtracking = getIntValue("Select option:\n"
                                   "[1] Brute Force\n"
                                   "[2] Backtracking (no Pruning)\n"
                                   "[3] Backtracking (Pruning)\n");
    }

    vector<Pallet *> solution;
    auto t1 = high_resolution_clock::now();

    switch (backtracking) {
        case 1: {
            solution = solver.brute_force(truck);
            break;
        }
        case 2: {
            solution = solver.backtracking_no_pruning(truck);
            break;
        }
        case 3: {
            solution = solver.backtracking_pruning(truck);
            break;
        }
    }

    auto t2 = high_resolution_clock::now();

    cout << "========================================\n";

    if (solution.empty()) {
        cout << "Input too big! No solution found!" << endl;
    }
    else {
        duration<double, std::milli> ms_double = t2 - t1;
        cout << "Time taken: " << ms_double.count() << " ms" << endl;
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

    auto t1 = high_resolution_clock::now();
    vector<Pallet *> solution = solver.dynamic_program(truck);
    auto t2 = high_resolution_clock::now();

    cout << "========================================\n";

    if (solution.empty()) {
        cout << "Input too big! No solution found!" << endl;
    } else {
        duration<double, std::milli> ms_double = t2 - t1;
        cout << "Time taken: " << ms_double.count() << " ms" << endl;
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

    auto t1 = high_resolution_clock::now();
    vector<Pallet *> solution = solver.approximation(truck);
    auto t2 = high_resolution_clock::now();

    cout << "========================================\n";


    if (solution.empty()) {
        cout << "Input too big! No solution found!" << endl;
    } else {
        duration<double, std::milli> ms_double = t2 - t1;
        cout << "Time taken: " << ms_double.count() << " ms" << endl;
        cout << "========================================\n";
        for (auto p : solution) {
            cout << endl;
            cout << "Pallet number: " << p->getId() << endl;
            cout << "Weight: " << p->getWeight() << " Value: " << p->getValue() << endl;
        }
        cout << "========================================\n";
    }
}

void Menu::ILPMenu() {
    if (!truck.isLoaded()) {
        cout << "No truck loaded!" << endl;
        return;
    }

    cout << "========================================\n";

    auto t1 = high_resolution_clock::now();
    vector<Pallet *> solution = solver.int_linear_program(truck);
    auto t2 = high_resolution_clock::now();

    cout << "========================================\n";

    if (solution.empty()) {
        cout << "Input too big! No solution found!" << endl;
    } else {
        duration<double, std::milli> ms_double = t2 - t1;
        cout << "Time taken: " << ms_double.count() << " ms" << endl;
        cout << "========================================\n";
        for (auto p : solution) {
            cout << endl;
            cout << "Pallet number: " << p->getId() << endl;
            cout << "Weight: " << p->getWeight() << " Value: " << p->getValue() << endl;
        }
        cout << "========================================\n";
    }
}

void Menu::ReportMenu() {
    vector<Pallet *> solution;
    duration<double, std::milli> ms_double;

    auto t1 = high_resolution_clock::now();
    solution = solver.brute_force(truck);
    auto t2 = high_resolution_clock::now();
    cout << "Brute Force: ";
    if (solution.empty()) cout << "No solution found!" << endl;
    else {
        ms_double = t2 - t1;
        cout << ms_double.count() << " ms" << endl;
    }

    t1 = high_resolution_clock::now();
    solution = solver.backtracking_no_pruning(truck);
    t2 = high_resolution_clock::now();
    cout << "Backtracking (no Pruning): ";
    if (solution.empty()) cout << "No solution found!" << endl;
    else {
        ms_double = t2 - t1;
        cout << ms_double.count() << " ms" << endl;
    }

    t1 = high_resolution_clock::now();
    solution = solver.backtracking_pruning(truck);
    t2 = high_resolution_clock::now();
    cout << "Backtracking (Pruning): ";
    if (solution.empty()) cout << "No solution found!" << endl;
    else {
        ms_double = t2 - t1;
        cout << ms_double.count() << " ms" << endl;
    }

    t1 = high_resolution_clock::now();
    solution = solver.dynamic_program(truck);
    t2 = high_resolution_clock::now();
    cout << "Dynamic Programming: ";
    if (solution.empty()) cout << "No solution found!" << endl;
    else {
        ms_double = t2 - t1;
        cout << ms_double.count() << " ms" << endl;
    }

    t1 = high_resolution_clock::now();
    solver.approximation_by_ratio(truck);
    t2 = high_resolution_clock::now();
    cout << "Approximation (by Ratio): ";
    ms_double = t2 - t1;
    cout << ms_double.count() << " ms" << endl;

    t1 = high_resolution_clock::now();
    solver.approximation_by_value(truck);
    t2 = high_resolution_clock::now();
    cout << "Approximation (by Value): ";
    ms_double = t2 - t1;
    cout << ms_double.count() << " ms" << endl;

    t1 = high_resolution_clock::now();
    solution = solver.int_linear_program(truck);
    t2 = high_resolution_clock::now();
    cout << "Integer Linear Programming: ";
    if (solution.empty()) cout << "No solution found!" << endl;
    else {
        ms_double = t2 - t1;
        cout << ms_double.count() << " ms" << endl;
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
                "[6] Report Menu (All Algorithms)\n"
                "[7] Exit" << endl;
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
                ILPMenu();
                waitForEnter();
                break;
            case 6:
                ReportMenu();
                waitForEnter();
                break;
            case 7:
                cout << "Leaving" << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    } while (option != 7);
}

