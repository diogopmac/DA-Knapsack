#include "../headers/Algorithms.h"
#include <cmath>
#include <bitset>
#include <iostream>
#include <ostream>
#include <functional>

using namespace std;

Algorithms::Algorithms() = default;

Algorithms::~Algorithms() = default;

std::vector<Pallet *> Algorithms::brute_force(const Truck& truck) {
    vector<Pallet *> pallets = truck.getPallets();
    int n = pallets.size();
    if (n > 32) return {};

    vector<Pallet *> sol;

    double maxvalue = 0;

    for (int i = 0; i < (1 << n); i++) {
        bitset<32> binarySubset(i);
        double value = 0;
        double weight = 0;
        for (int k = 0; k < n; k++) {
            value += pallets[k]->getValue() * binarySubset[k];
            weight += pallets[k]->getWeight() * binarySubset[k];
        }
        if (value > maxvalue && weight <= truck.getCapacity()) {
            maxvalue = value;
            sol = {};
            for (int k = 0; k < n; k++) {
                if (binarySubset[k]) sol.push_back(pallets[k]);
            }
        }
    }
    return sol;
}

std::vector<Pallet *> Algorithms::backtracking(const Truck& truck) {
    const vector<Pallet *> &pallets = truck.getPallets();
    int n = pallets.size();
    double capacity = truck.getCapacity();

    vector<Pallet *> bestSolution;
    double maxValue = 0;

    vector<Pallet *> currentSolution;
    

    // Helper recursive function
    function<void(int, double, double)> backtrack = [&](int idx, double currWeight, double currValue) {
        if (idx == n) {
            if (currValue > maxValue) {
                maxValue = currValue;
                bestSolution = currentSolution;
            }
            return;
        }

        // Exclude current pallet
        backtrack(idx + 1, currWeight, currValue);

        // Include current pallet if it fits
        if (currWeight + pallets[idx]->getWeight() <= capacity) {
            currentSolution.push_back(pallets[idx]);
            backtrack(idx + 1, currWeight + pallets[idx]->getWeight(), currValue + pallets[idx]->getValue());
            currentSolution.pop_back();
        }
    };

    backtrack(0, 0.0, 0.0);
    return bestSolution;
}


std::vector<Pallet *> Algorithms::dynamic_program(const Truck& truck) {
    vector<Pallet *> sol;
    return sol;
}

std::vector<Pallet *> Algorithms::approximation(const Truck& truck) {
    vector<Pallet *> sol;
    return sol;
}

vector<Pallet *> Algorithms::int_linear_program(const Truck& truck) {
    vector<Pallet *> sol;
    return sol;
}
