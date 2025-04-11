//
// Created by diogo on 07/04/2025.
//

#include "../headers/menu.h"

#include <iostream>
#include <ostream>

using namespace std;

Menu::Menu() = default;

Menu::~Menu() {}

void Menu::MainMenu() {
    int option;

    do {
        cout << "========================================\n";
        cout << "Delivery Truck Pallet Packing Optimization\n";
        cout << "========================================\n";
        cout << "[1] Load a Truck\n" // TEMP
                "[2] Exhaustive (Brute Force) Approach\n"
                "[3] Dynamic Programming Approach\n"
                "[4] Approximation Algorithms\n"
                "[5] Integer Linear Programming Algorithm\n"
                "[6] Exit" << endl;
        cout << "========================================\n";
        cin >> option;
        switch (option) {
            case 1:
                cout << "WIP" << endl;
                break;
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

